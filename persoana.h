

#ifndef POO_TEMA_LABORATOR_2_PERSOANA_H
#define POO_TEMA_LABORATOR_2_PERSOANA_H

#include <string>

using namespace std;

class Persoana {
    protected:
        int id;
        string nume, cnp;
    public:
        Persoana(): id(0), nume(""), cnp("") {}
        Persoana(int ID, string name, string CNP): id(ID), nume(name), cnp(CNP) {}
        Persoana(const Persoana &person): id(person.id), nume(person.nume), cnp(person.cnp) {}
        void SetId(int id) { this->id = id; }
        void SetNume(string nume) { this->nume = nume; }
        void SetCnp(string cnp) { this->cnp = cnp; }
        int GetId() { return id; }
        string GetNume() { return nume; }
        string GetCnp() { return cnp; }
        Persoana& operator= (const Persoana& person)
        {
            this->id = person.id;
            this->nume = person.nume;
            this->cnp = person.cnp;
            return *this;
        }
        friend istream& operator>> (istream&, Persoana&);
        friend ostream& operator<< (ostream&, const Persoana&);
};

istream& operator>> (istream& in, Persoana& person)
{
    in >> person.id >> person.nume >> person.cnp;
    return in;
}

ostream& operator<< (ostream& out, const Persoana& person)
{
    out << person.id << ' ' << person.nume << ' ' << person.cnp;
    return out;
}

#endif