#ifndef PERSOANA_H_INCLUDED
#define PERSOANA_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Persoana {
    protected:
        int id;
        string nume, cnp;
    public:
        Persoana(): id(0), nume(""), cnp("") {}
        Persoana(int ID, string name, string CNP): id(ID), nume(name), cnp(CNP) {}
        Persoana(const Persoana& person)
        {
            this->id = person.id;
            this->nume = person.nume;
            this->cnp = person.cnp;
        }
        friend istream& operator>> (istream&, Persoana&);
        friend ostream& operator<< (ostream&, const Persoana&);
        Persoana& operator= (const Persoana& person)
        {
            this->id = person.id;
            this->nume = person.nume;
            this->cnp = person.cnp;
            return *this;
        }
        void SetId(int ID) {id = ID;}
        void SetNume(string name) {nume = name;}
        void SetCnp(string CNP) {cnp = CNP;}
        int GetId() {return id;}
        string GetNume() {return nume;}
        string GetCnp() {return cnp;}
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


#endif // PERSOANA_H_INCLUDED