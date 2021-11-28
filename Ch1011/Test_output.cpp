#include "../std_lib_facilities.h"

int main()
{
	int birth_year = 2001, age = 20;


	cout << "Decimal:\t" << showbase << birth_year << endl;
	cout << "Hexadecimal:\t" << hex << birth_year << endl;
	cout << "Octal:\t\t" << oct << birth_year << endl;

	cout << "Age:\t\t" << dec << age << endl;

/*	int a,b,c,d;
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t'<< c << '\t' << d << '\n' ;
	az input az "1234" számsorozatot először decimálisan, másodszor oktálisan, harmadszor és negyedszer hexadecimálisan értelmezte.
	mivel a flagek egyszerre csak egy stream tartalmára értelmezhetőek, ezért a cout stream decimális maradt, annak ellenére hogy a cin streamben többször is megváltoztattuk a számrendszer értékét.
	ennek köszönhetően a kimenet decimális formában jelenik meg. */

	double x = 1234567.89;
	cout << "Defaultfloat:\t" << defaultfloat << x << endl;
	cout << "Fixed:\t\t" << fixed << x << endl;
	cout << "Scientific:\t" << scientific << x << endl;
	//Ebben az esetben a fixed a legpontosabb, mivel minden számjegyet megmutat a felhasználónak, míg a defaultfloat két, a scientific egy számjegyet hagy el.

	//A fixed point nem minden esetben célirányos, nagy számoknál a scientific tömörebben képes kifejezni, kisebb de sokszor irreleváns precizitásvesztéssel.
	//A defaultfloat a kettő között próbál kompromisszumot keresni, kisebb számoknál fixed point, nagyobbaknál scientific megjelenítést alkalmaz.

	string header[4] = {"Vezeteknév", "Keresztnev", "Telefonszam", "Email-cim"},s = "█",separator_row = "█▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n";
	string table[4][5] = {
		{"Levai","Kovacs","Nagy","Feher","Kassai"},
		{"Bence","Peter","Andrea","Istvan","Lajos"},
		{"06-30-2458328","06-20-2339898","06-30-3229338","06-70-0937611","06-20-1990734"},
		{"levai.bence@gmail.com","kakos20000911@freemail.hu","nagy.andrea.118@gmail.com","feherpistike2002@gmail.com","demon.lord.thaegos@hotmail.com"}
	};
	cout << endl << s << setw(10) << header[0] << left << s << setw(10) << header[1] << left << s << setw(13) << header[2] << left << s << setw(32) << header[3] << left << s << endl;
	cout << separator_row;
	for (int i=0; i<5; ++i)
	{
		cout << s << setw(10) << table[0][i] << left << s << setw(10) << table[1][i] << left << s << setw(13) << table[2][i] << left << s << setw(32) << table[3][i] << left << s << endl;
	}
	return 0;
}

