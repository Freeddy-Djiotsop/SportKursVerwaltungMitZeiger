#include <iostream>
#include <iomanip>
#include "sportkurs.hpp"
#include "person.hpp"



using namespace std;

float Sportkurs::durchschnitt() const
{
    float s=0;

    if(this->teilnehmer)
    {
        for(unsigned int i=0; i<this->teilnehmer; i++)
            s += this->person[i].alter;

        s /=this->teilnehmer;
    }

    return s;
}


Sportkurs::Sportkurs(string kn, string tn, unsigned int m)//Ausgabe unnötig
:kName(kn), tName(tn), maxteilnehmer(m), teilnehmer(0), person(nullptr){}


Sportkurs::Sportkurs(const Sportkurs& k)//Copy-Konstruktor
:kName(k.kName), tName(k.tName), maxteilnehmer(k.maxteilnehmer), teilnehmer(k.teilnehmer)
{
    this->person = new Person[this->teilnehmer];

    for(unsigned int i=0; i<this->teilnehmer; i++)
        this->person[i] = k.person[i];
}

Sportkurs::Sportkurs(Sportkurs&& k)//Move-Konstruktor
:kName(k.kName), tName(k.tName), maxteilnehmer(k.maxteilnehmer), teilnehmer(k.teilnehmer), person(k.person)
//alle Daten mit Initialisiererliste belegen
{
    //Daten Löschen der temporaere Objekt;
    k.maxteilnehmer = 0;
    k.teilnehmer = 0;
    k.person = nullptr;
}

Sportkurs::~Sportkurs()
{
    delete [] this->person;
}

void Sportkurs::operator=(const Sportkurs& k)
{
    if(this!=&k)
    {
        this->kName = k.kName;
        this->tName = k.tName;
        this->maxteilnehmer = k.maxteilnehmer;
        this->teilnehmer = k.teilnehmer;

        delete [] this->person;//freigabe

        for(unsigned int i=0; i<this->teilnehmer; i++)//Kopie erstellen
            this->person[i] = k.person[i];
    }
}

void Sportkurs::operator=(Sportkurs&& k)
{
    this->kName = k.kName;
    this->tName = k.tName;
    this->maxteilnehmer = k.maxteilnehmer;
    this->teilnehmer = k.teilnehmer;

    delete [] this->person;//Speicherplatz freigeben

    this->person = k.person;//neue Daten bzw Speicherplatz

    //Daten Löschen der temporaere Objekt;
    k.maxteilnehmer = 0;
    k.teilnehmer = 0;
    k.person = nullptr;
}

void Sportkurs::addPerson(const Person& p)
{
    if(teilnehmer+1>maxteilnehmer)
        cout<<"Der Sportkurs "<<this->kName<<"ist voll"<<endl;

    else
    {

        if(this->teilnehmer==0)
        {
            this->teilnehmer=1;
            this->person = new Person[1];
            this->person[0] = p;//neue Person hinzugefügt
        }
        else
        {
            Person* tmpPerson = new Person[this->teilnehmer];
            for(unsigned int i=0; i<this->teilnehmer; i++)
                tmpPerson[i]= this->person[i];


            this->teilnehmer++;
            delete [] this->person;
            this->person = new Person[this->teilnehmer];

            for(unsigned int i=0; i<this->teilnehmer-1; i++)
                this->person[i] = tmpPerson[i];
            this->person[this->teilnehmer-1] = p;//neue Person hinzugefügt

            delete [] tmpPerson;//Kopie freigeben

        }

    }
}


void vergleicheTeilnehmer(const Sportkurs& a, const Sportkurs& b)
{
    if(a.teilnehmer>b.teilnehmer)
        cout<<a.kName<<" hat mehr teilnehmer"<<endl;
    else if (a.teilnehmer<b.teilnehmer)
        cout<<b.kName<<" hat mehr teilnehmer"<<endl;
    else//wenn a nicht > b oder nicht < b, dann ist a=b
        cout<<a.kName<<" und "<<b.kName<<" haben gleiche Anzahl Teilnehmer"<<endl;
}

ostream& operator<<(ostream& os, const Sportkurs& k)
{
    os<<k.kName<<", "<<k.tName<<", "<<k.maxteilnehmer<<", "<<k.teilnehmer;
    os<<", Altersschnitt: "<<setprecision(3)<<k.durchschnitt()<<endl;

    for(unsigned int i=0; i<k.teilnehmer; i++)
        os<<k.person[i]<<endl;

    os<<endl;

    return os;
}

istream& operator>>(istream& is, Sportkurs& k)
{
    is>>k.kName>>k.tName>>k.maxteilnehmer;
    return is;
}

