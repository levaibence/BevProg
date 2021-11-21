#include "std_lib_facilities.h"

enum class Month {
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
// simple Date (use Month type)
class Date {
public:
	Date(int y, Month m, int d); // check for valid date and initialize
	void add_day(int n);
	int year() {return y;}
	Month month() {return m;}
	int day() {return d;}
private:
	int y; // year
	Month m;
	int d; // day
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
	int month=int(m); //store int value of next month
	while (d > 31||d < 0) //keep incrementing months until date is valid
	{
		if (d>31) {d-=31; month++;}
		else {d+=31; month--;}
	}


	while (month > 12||month < 0) //once done, do the same thing with years
        {
                if (month>12) {month-=12; y++;}
                else {month+=12; y--;}
	}
	m = Month(month); //sets month to its new value

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
