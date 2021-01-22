#ifndef SPORTKURS_HPP_INCLUDED
#define SPORTKURS_HPP_INCLUDED


class Person;

class Sportkurs
{

private:
    std::string kName;
    std::string tName;
    unsigned int teilnehmer;
    unsigned int maxteilnehmer;
    Person* person;


    float durchschnitt() const;

public:

    Sportkurs():teilnehmer(0), person(nullptr){}

    Sportkurs(std::string, std::string, unsigned int);


    Sportkurs(const Sportkurs&);

    Sportkurs(Sportkurs&&);

    ~Sportkurs();

    void operator=(const Sportkurs&);

    void operator=(Sportkurs&&);

    void addPerson(const Person&);
    void addPerson(const std::string&);


    friend std::ostream& operator<<(std::ostream&, const Sportkurs&);

    friend std::istream& operator>>(std::istream&, Sportkurs&);

    friend void vergleicheTeilnehmer(const Sportkurs&, const Sportkurs&);

};

#endif // SPORTKURS_HPP_INCLUDED
