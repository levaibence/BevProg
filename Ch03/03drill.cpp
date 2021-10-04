#include "std_lib_facilities.h"

int main(){
	cout<<"Enter the name of the person you want to write to (followed by 'enter'):\n";
	string first_name;
	cin>>first_name;
	cout<<"Dear "<<first_name<<",\n";

	cout<<"\tHow are you? I am doing fine. We have not seen each other in a long time.\n";	
	cout<<"Please enter another friend's name (followed by 'enter'):\n";
	string friend_name;
	cin>>friend_name;

	cout<<"Have you seen "<<friend_name<<" lately?\n";
	cout<<"Please enter m if the friend is male and f is the friend is female:\n";
	char friend_sex = 0;
	cin>>friend_sex;

	if(friend_sex == 'm') cout<<"If you see "<<friend_name<<" please ask him to call me.\n";
	if(friend_sex == 'f') cout<<"If you see "<<friend_name<<" please ask her to call me.\n";

	cout<<"Please enter the age of the recipient\n";
	int age;
	cin>>age;
	if(age <= 0||age >=110) simple_error("you're kidding!");

	cout<<"I hear you just had a birthday and you are "<<age<<" years old.\n";
	if(age<12) cout<<"Next year you will be "<<age+1<<".\n";
	if(age==17) cout<<"Next year you will be able to vote.\n";
	if(age>70) cout<<"I hope you are enjoying retirement.\n";

	cout<<"Yours sincerely,\n\n\nBence Lévai";
	return 0;
}
