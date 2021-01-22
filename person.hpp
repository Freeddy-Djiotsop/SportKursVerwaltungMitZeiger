#ifndef PERSON_HPP_INCLUDED
#define PERSON_HPP_INCLUDED



class Person
{
    friend class Sportkurs;
private:
    std::string name;
    std::string geschlecht;
    unsigned short int alter;

    Person(){}

public:
    Person(std::string, std::string, unsigned short int);
    Person(const Person&);
    Person(Person&&);

    ~Person(){}

    void operator=(const Person&);
    void operator=(Person&&);

    friend std::ostream& operator<<(std::ostream&, const Person&);
};




#endif // PERSON_HPP_INCLUDED
