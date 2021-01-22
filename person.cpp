#include <iostream>
#include <iomanip>
#include "person.hpp"

using namespace std;



Person::Person(string n, string g, unsigned short int a)
:name(n), geschlecht(g), alter(a){}

Person::Person(const Person& p)

{}

Person::Person(Person&& p)
:name(p.name), geschlecht(p.geschlecht), alter(p.alter)
{p.alter=0;}

void Person::operator=(const Person& p)
{
    if(this!=&p)
    {
        this->name = p.name;
        this->geschlecht = p.geschlecht;
        this->alter = p.alter;
    }
}

void Person::operator=(Person&& p)
{
    this->name = p.name;
    this->geschlecht = p.geschlecht;
    this->alter = p.alter;

    p.alter = 0;
}

ostream& operator<<(ostream& os, const Person& p)
{
    os<<p.name<<", "<<p.geschlecht<<", Alter: "<<p.alter;
    return os;
}
