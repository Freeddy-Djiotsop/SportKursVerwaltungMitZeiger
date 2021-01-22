#include <iostream>
#include <utility>
#include "person.hpp"
#include "sportkurs.hpp"



using namespace std;

int main()
{
	Sportkurs aerobic("Aerobic", "Tom", 2);
	aerobic.addPerson(Person("Tim", "m", 26));
	aerobic.addPerson(Person("Julia", "w", 22));
	aerobic.addPerson(Person("Seb", "m", 23));

	Sportkurs fussball("Fussball", "Volker", 24);
	fussball.addPerson(Person("Wanda", "w", 21));
	fussball.addPerson(Person("Mats", "m", 18));

	Sportkurs quidditch("Quidditch", "Harry", 14);
	quidditch.addPerson(Person("Oliver", "m", 23));
	quidditch.addPerson(Person("Katie", "w", 19));
	quidditch.addPerson(Person("Fred", "m", 28));

	Sportkurs s;
	cout << "Bitte Sportkurs eingeben: ";
	cin >> s;

	cout << s << endl;
	cout << aerobic << endl;
	cout << fussball << endl;
	cout << quidditch << endl;

	vergleicheTeilnehmer(quidditch, aerobic);

	Sportkurs s2(move(quidditch));
	cout << "Quidditch:" << endl << quidditch << endl;
	cout << "Kopie Quidditch:" << endl << s2 << endl;

	fussball = move(aerobic);
	cout << "Aerobic:" << endl << aerobic << endl;
	cout << "Zuweisung Fussball:" << endl << fussball << endl;


	return 0;
}
