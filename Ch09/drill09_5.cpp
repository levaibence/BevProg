#include "std_lib_facilities.h"

enum class Month {
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
// simple Date (use Month type)
class Date {
public:
	int day() const {return d;} // const member: can’t modify the object
	Month month() const {return m;} // const member: can’t modify the object
	int year() const {return y;} // const member: can’t modify the object

	void add_day(int n); // non-const member: can modify the object
	void add_month(int n); // non-const member: can modify the object
	void add_year(int n); // non-const member: can modify the object

	Date(int year, Month month, int day); //constructor function
private:
	int y; // year
	Month m;
	int d; // day of month
};


Date::Date(int year, Month month, int day) //initializes dates
{
	if (int(month)>12||int(month)<1) error("Invalid month value!");
	if (day>31||day<1) error("Invalid day value!"); //checks for invalid values before initializations
	Date::y = year;
	Date::m = month;
	Date::d = day;
	return;
}

void Date::add_day(int n) //adds n days to the date in question
{
	d += n;
	int overflow_factor = d<0 ? (d+1)/31 : (d-1)/31; //the amount of times the number of days exceeds the day limit (ex: 67 overflows twice, -37 overflows -1 times), the -/+1 fixes off by one errors at multiples of 31
	d -= overflow_factor*31; //removes excess days from day count
	add_month(overflow_factor); //adds as many months as necessary

	return;
}

void Date::add_month(int n) //adds n months to the date in question
{
        int month=int(m); //store int value of next month
        month += n;
	int overflow_factor = month<0 ? (month+1)/12 : (month-1)/12; //calculate overflow factor for months, to see how many years to add
	month -= overflow_factor*12;
	m = Month(month); //sets month to its new value
	add_year(overflow_factor); //adds the overflow factor as years

        return;
}

void Date::add_year(int n)
{
	y += n;
	return;
}

ostream& operator<<(ostream& os, Month m) //overload << to work with month
{
	switch(m)
	{
		case Month::jan: {os << "January"; break;}
                case Month::feb: {os << "February"; break;}
                case Month::mar: {os << "March"; break;}
                case Month::apr: {os << "April"; break;}
                case Month::may: {os << "May"; break;}
                case Month::jun: {os << "June"; break;}
                case Month::jul: {os << "July"; break;}
                case Month::aug: {os << "August"; break;}
                case Month::sep: {os << "September"; break;}
                case Month::oct: {os << "October"; break;}
                case Month::nov: {os << "November"; break;}
                case Month::dec: {os << "December"; break;}
	}
	return os;
}


ostream& operator<<(ostream& os, Date& d) //do same for year
{
        return os << d.year() << ". " << d.month() << " " << d.day() << ".";
}


int main()
{
	try
	{
		Date today {1978, Month::jun, 25}; //define today
		Date tomorrow = today;
		tomorrow.add_day(1); //increment today to get tomorrow
		cout << "Today: " << today << "\nTomorrow: " << tomorrow << endl;
		return 0;
	}
	catch (exception& e)
	{
		cerr << "Error: " << e.what() << '\n';
		keep_window_open();
	        return 1;
	}
}
