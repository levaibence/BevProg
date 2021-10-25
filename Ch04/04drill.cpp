#include "std_lib_facilities.h"
#include "float.h"

bool quit=0;
const int base=10;
const string valid_units[]={"m","cm","in","ft","."};
const double cm_in_m=100,in_in_ft=12,cm_in_in=2.54;

struct Measure
{
	double value;
	string unit;
};

Measure to_m(Measure input)//converts any length into meters
{
	Measure output;
	if(input.unit=="m") return input;
	if(input.unit=="cm") {output={input.value/cm_in_m, "m"}; return output;}
        if(input.unit=="in") {output={input.value/cm_in_m*cm_in_in, "m"}; return output;}
        if(input.unit=="ft") {output={input.value/cm_in_m*cm_in_in*in_in_ft, "m"}; return output;}
	cerr<<"Invalid unit!";
}

string getunit()
{
	string output;
	char a;
	while (cin)
	{
		cin>>a;
		if (a==',')
		{
			cin.putback(a);
			return output;
		}
                output+=a;
	}
}

Measure input()
{
	char a;
	double y=0;
	bool neg=0,valid=0;
	int i=1,j=0,digits=0;
	string unit;
	while (cin)
	{
		cin>>a;
		switch(a)
		{
			case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
			{
				y*=base;
				if (neg) y-=a-'0'; else y+=a-'0';
				i++;
				break;
			}
			case '.':
			{
				digits=i; //finds how many digits the final number should have
				break;
			}
			case ',':
			{
				if(!digits) digits=i;
				y/=pow(base,i-digits);
				Measure output={y,unit};
				return output;
			}
			case '|': {quit=1; return {0,"0"};}
			case '-':
			{
				if (i==1) {neg=1; break;}
			}
			default:
			{
				cin.putback(a); //checks if character is a unit of measurement, if not, throws error
				unit=getunit();
				while(valid_units[j]!=".")
				{
					if(valid_units[j]==unit) {valid=1; break;}
					j++;
				}
				if(!valid) cerr<<"Invalid input!\n";
			}
		}
	}
}

int main()
{
	double min=DBL_MAX,max=-DBL_MAX,sum=0;
	Measure a,am;
	int i,j;
	vector<Measure> valuelist;

	while(cin)
	{
		cout<<"Enter an integer followed by a comma, then press enter:\n";

		a=input();
		am=to_m(a);
		if (quit) break;
		if (am.value>max) {max=am.value; cout<<"the largest so far\n";}
		if (am.value<min) {min=am.value; cout<<"the smallest so far\n";}
		sum+=am.value;
		valuelist.push_back(am);

/*		b=input();
		if(quit) break;

		if(a==b) cout << "The values are equal.\n";
		else if (a>b) cout << "The smaller value is: " << b << "\nThe larger value is: " << a << endl;
		else cout<<"The smaller value is: "<<a<<"\nThe larger value is: "<<b<<endl;
		if (abs(a-b)<0.01) cout << "The numbers are almost equal.\n";   */
	}

	int imin;
	for(i=0;i<valuelist.size()-1;i++) //sorting the vector
	{
		imin=i;
		for(j=0;j<valuelist.size();j++)
		{
			if(valuelist[i].value<valuelist[min].value) imin=i;
		}
		if(imin!=i) swap(valuelist[imin],valuelist[i]);
	}

	cout<<"Statistics:\nSum: "<<sum<<"m\nSmallest value: "<<min<<"m\nLargest value: "<<max<<"m\nNumber of values: "<<valuelist.size()<<"\nList of values:\n";
	for(i=0;i<valuelist.size();i++) cout<<valuelist[i].value<<"m\n";
	return 0;
}

