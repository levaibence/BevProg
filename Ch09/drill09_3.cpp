#include "std_lib_facilities.h"

class Date {
	int y, m, d; // year, month, day
public:
	Date(int y, int m, int d); // check for valid date and initialize
	void add_day(int n); // increase the Date by n days
	int month() { return m; }
	int day() { return d; }
	int year() { return y; }
};


Date::Date(int year, int month, int day) //initializes dates
{
	if (month>12||month<1) error("Invalid month value!");
	if (day>31||day<1) error("Invalid day value!"); //checks for invalid values before initializations
	Date::y = year;
	Date::m = month;
	Date::d = day;
	return;
}

void Date::add_day(int n) //adds n days to the date in question
{
	d += n;
	while (d > 31||d < 0) //keep incrementing months until date is valid
	{
		if (d>31) {d-=31; m++;}
		else {d+=31; m--;}
	}
	while (m > 12||m < 0) //once done, do the same thing with years
        {
                if (m>12) {m-=12; y++;}
                else {m+=12; y--;}
	}
	return;
}

ostream& operator<<(ostream& os, Date& d) //overload operator to work with date data type
{
        return os << d.year() << ". " << d.month() << ". " << d.day() << ".";
}


int main()
{
	try
	{
		Date today {1978, 6, 25}; //define today
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
