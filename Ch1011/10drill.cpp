#include "../std_lib_facilities.h"
#include "vector"

//-------- Definitions

struct Point
{
	int x,y;
};

vector<Point> original_points,processed_points;

//-------- Overliading operators

istream& operator>>(istream& is, Point& p) //defines >> for point data type
{
	char c[3];
	int ix,iy;

	if (is >> c[0] && c[0] != '(' ) //error handling: check proper input
	{
		is.unget();
		is.clear(); //clear stream
		cerr << "Invalid input format at " << original_points.size() << ": ( expected" << endl; //show error with location
	}

	is >> ix >> c[1] >> iy >> c[2] && c[0]; // rest of the input, split off from first if for readibility and efficiency

	if (is && c[2] != ')') cerr<< "Invalid input format at " << original_points.size() << ": ) expected" << endl; //show error with location
	if (!is) //if input unsuccessful, terminate
	{
		if (is.eof()) return is; //if end of file encountered, return without assigning value to point vector
		error("Point input exception"); //uh oh
	}

	p.x = ix;
	p.y = iy;

	return is;
}

ostream& operator<<(ostream& os, Point& p)//define output format
{
	return os << '(' << p.x << ',' << p.y << ')';
}


//-------- Defining functions

void print_vector(vector<Point> v) //print out the contents of vector, onto console
{
	for (int i=0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
	return;
}

void fprint_vector(vector<Point> v, string file) //print out the contents of vector, into file
{
        ofstream os{file};

	for (int i=0; i < v.size(); ++i)
        {
                os << v[i] << endl;
        }
        return;
}

vector<Point> file_to_vector(string file) //read coordinates from properly formatted file and put them into a vector
{
	ifstream is {file};
	Point p;
	vector<Point> v;

	if (!is) error("Unable to open file named ",file); //if there are immediate problems with input, give up

	while(is)
	{
		is >> p;
		v.push_back(p);
	}
	return v;
}

bool compare_value(vector<Point> a, vector<Point> b)
{
	if (a.size() != b.size()) return 0; //don't run algorithm if vector sizes are different

	for (int i=0; i < a.size(); ++i)
	{
		if (a[i].x != b[i].x) return 0; //if either x or y value differs anywhere, the contents are different
		if (a[i].y != b[i].y) return 0;
	}

	return 1; // if we get here, we know the vectors have both the same size and the same numbers in them
}

//-------- main()

int main()
{
	try
	{
        	Point pin;
		cout << "Please enter seven (x,y) pairs: ";
		while(cin && original_points.size()<7)
		{
			cin >> pin;
			original_points.push_back(pin); //enter into vector
		}

		//print contents of vector into mydata.txt
		fprint_vector(original_points, "mydata.txt");

		vector<Point> processed_points = file_to_vector("mydata.txt");

		//prints contents of vectors
		cout << "List of original points:" << endl;
		print_vector(original_points);
		cout << "List of processed points" << endl;
		print_vector(processed_points);

		//compare values
		if (compare_value(original_points, processed_points)) cerr << "Something's wrong!";
		return 0;
	}

	catch (exception& e)
        {
                cerr << "Error: " << e.what() << '\n';
                keep_window_open();
                return 1;
        }
}
