
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "std_lib_facilities.h"

bool is_in_statement = false; //allows commas in input stream for two-input functions

struct Token {	//defines token, the way the program interprets the input
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { } //for operators
	Token(char ch, double val) :kind(ch), value(val) { } //for numbers
	Token(char ch, string n): kind(ch), name(n), value(0) { } //for variables
};

class Token_stream {
	bool full; //stores whether stream is full
	Token buffer; //stores token
public:
	Token_stream() :full(0), buffer(0) { } //provides way to initialize token stream

	Token get(); //provides way to get token
	void unget(Token t) { buffer=t; full=true; }//returns token to buffer

	void ignore(char);
};

const char let = 'L'; //to define constants
const char quit = 'Q'; //to quit
const char print = ';'; //to print result
const char number = '8'; //8 represents all numbers
const char name = 'a';
const char pow_c = 'p';
const string pow_s = "pow";
const char sqrt_c = 's';
const string sqrt_s = "sqrt";
const char letkw = '#';
const string quitkw = "exit";

Token Token_stream::get()
{
	if (full) { full=false; return buffer; } //empties buffer
	char ch;
	cin >> ch;
	switch (ch) {
	case ',': if(!is_in_statement) error("unexpected ,");
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch); //operators represent themselves
	case letkw: return Token(let);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();//after identifying number type, returns it to token stream
		double val;
		cin >> val; //returns actual value from stream
		return Token(number,val); //number token defined above
	}
	default: //tries to interpret token as command, if unsuccessful throws error
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch; //reads in full command
			cin.unget();
			if (s == pow_s)	return Token(pow_c);
			if (s == sqrt_s) return Token(sqrt_c);//commands defined above
			if (s == quitkw) return Token(quit);
			return Token(name,s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c) //ignores everything in input stream until it finds input character
{
	if (full && c==buffer.kind) { //if input in buffer, return buffer
		full = false;
		return;
	}
	full = false; //clear buffer

	char ch;
	while (cin>>ch)
		if (ch==c) return; //look for c in input stream, ignoring everything that doesn't match
}

struct Variable { //for custom variables
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names; //stores custom variables

double get_value(string s) //get value of variable from array
{
	for (int i = 0; i<names.size(); ++i) //look for variable name in array
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s); //if not found, return exception
}

void set_value(string s, double d) //edit value of variable
{
	for (int i = 0; i<=names.size(); ++i) //looks for variable in array
		if (names[i].name == s) {
			names[i].value = d; //if found, change its value
			return;
		}
	error("set: undefined name ",s); //in case variable isn't found
}

bool is_declared(string s) //checks if variable already declared
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}



Token_stream ts;

double expression(); //declaraction so primary() can use
double primary();

double power()
{
        is_in_statement = true;
	double b = primary();
        double exponent = primary();
	Token t = ts.get(); //needs to check whether parenthesis is closed again
        if (t.kind != ')') error("')' expected"); //makes sure parentheses are closed
        if (b==0&&exponent==0) error("0^0 not allowed"); //checks for 0^0
        if (fmod(exponent,1)!=0) error("exponent not integer"); //checks if exponent is integer
        is_in_statement = false;
        return pow(b,exponent);
}

double primary() //for () and negative numbers
{
	Token t = ts.get();
	switch (t.kind) {
	case ',': //can separate expressions if in multivariable operator
	case '(':
	{	double d = expression(); //starts new expression
		t = ts.get(); //checks if parenthesis closed
		if (t.kind != ')' && (!is_in_statement && t.kind == ',')) error("')' expected"); //makes sure parentheses are closed
		return d;
	}
	case '-':
		return - primary(); //takes negative of primary
	case number:
		return t.value; //returns numbers and checks for oprerators, starting with multiplication
	case name:
		return get_value(t.name); //deals with variables
        case sqrt_c:
                {
			double b = primary();
        	        if (b<0) error("negative number base");//checks for sqrt(-1) and friends 
			return sqrt(b);
                }
        case pow_c:
                {
			return power();
                }
	default:
		error("primary expected"); //in case of invalid primary
	}
}

double term() //for multiplication and division
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*': //multiplication
			left *= primary();
			break;
		case '/':
		{	double d = primary(); //get right tearm early to check for divide by zero errors
			if (d == 0) error("divide by zero");
			left /= d;//if not 0, the program can divide
			break;
		}
		default:
		{
			ts.unget(t); //if not multiplication/division, returns left side for expression to deal with
			return left;
		}
		}
	}
}

double expression() //for addition and subtraction
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+': //addition
			left += term();
			break;
		case '-': //subtraction
			left -= term();
			break;
		default:
			ts.unget(t); //if no addition or subtraction left, expression is complete and ready to return
			return left;
		}
	}
}

double declaration()//declares new variable
{
	Token t = ts.get();
	if (t.kind != name) error ("name expected in declaration"); //throws error if name undefined (token kind is not name)
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice"); //prevents declaration of variable multiple times
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name); //makes sure syntax is followed
	double d = expression(); //finds value of variable, can deal with expressions, not just numbers
	names.push_back(Variable(name,d));//stores constant in the vector
	return d;
}

double statement() //checks whether command is declaration or expression
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	default://if no let command, interpret as expression
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print); //cleans input stream by ignoring everything before print command
}

const string prompt = "> ";//defines prompt indicator for user interface
const string result = "= ";//defines result indicator

void calculate()
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return; //if quit command entered, stop
		ts.unget(t);
		cout << result << statement() << endl; //prints out result
	}
	catch(runtime_error& e) { //catch runtime errors
		cerr << e.what() << endl;
		clean_up_mess(); //cleans input stream
	}
}

int main()

	try {
		names.push_back(Variable("k",1000));
		calculate();//calculate expression or variable
		return 0;
	}
	catch (exception& e) { //defined exceptions go here
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=print) ; //dumps input stream 
		return 1;
	}
	catch (...) { //unknown exceptions go here
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=print); //dumps input stream
		return 2;
	}
