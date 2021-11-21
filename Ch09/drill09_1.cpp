#include "std_lib_facilities.h"

// simple Date (too simple?)
struct Date {
	int y; // year
	int m; // month in year
	int d; // day of month
};

ostream& operator<<(ostream& os, Date& dd)
{
        return os << dd.y << ". " << dd.m << ". " << dd.d << ".";
}

void init_day(Date& dd, int y, int m, int d)
{
	if (m>12||m<1) error("Invalid month value!");
	if (d>31||d<1) error("Invalid day value!");
	dd.y = y;
	dd.m = m;
	dd.d = d;

	return;
	// check that (y,m,d) is a valid date
	// if it is, use it to initialize dd
}

void add_day(Date& dd, int n)
{
	// increase dd by n days
	dd.d += n;
	while (dd.d > 31||dd.d < 0) //keep incrementing months until date is valid
	{
		if (dd.d>31) {dd.d-=31; dd.m++;}
		else {dd.d+=31; dd.m--;}
	}
	while (dd.m > 12||dd.m < 0) //once done, do the same thing with years
        {
                if (dd.m>12) {dd.m-=12; dd.y++;}
                else {dd.m+=12; dd.y--;}
	}
	return;
}

int main()
{
	try
	{
		Date today; //define named object
		init_day(today, 1978, 6, 25); // oops! (no day 2005 in year 12)
		Date tomorrow = today;
		add_day(tomorrow,1);
		cout << "Today: " << today << "\nTomorrow: " << tomorrow << endl;
		return 0;
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
	        return 1;
	}
}
