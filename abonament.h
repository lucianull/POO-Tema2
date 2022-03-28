

#ifndef POO_TEMA_LABORATOR_2_ABONAMENT_H
#define POO_TEMA_LABORATOR_2_ABONAMEBT_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Abonament {
    protected:
        string nume_abonament;
        float pret;
        int perioada;
    public:
        Abonament() : nume_abonament(""), pret(0), perioada(0) {}
        Abonament(string name, float price, int period) : nume_abonament(name), pret(price), perioada(period) {}
        Abonament(const Abonament &abonament): nume_abonament(abonament.nume_abonament), pret(abonament.pret), perioada(abonament.perioada) {}
        void SetNumeAbonament(string nume_abonament) {this->nume_abonament = nume_abonament; }
        void SetPret(float pret) { this->pret = pret; }
        void SetPerioada(int perioada) { this->perioada = perioada; }
        string GetNumeAbonament() { return nume_abonament; }
        float GetPret() { return pret; }
        int GetPerioada() { return perioada; }
        Abonament& operator= (const Abonament& abonament)
        {
            this->nume_abonament = abonament.nume_abonament;
            this->pret = abonament.pret;
            this->perioada = abonament.perioada;
            return *this;
        }
        friend istream& operator>>(istream& in, Abonament&);
        friend ostream& operator<<(ostream& out, const Abonament&);
};

istream& operator>> (istream& in, Abonament& abonament)
{
    in >> abonament.nume_abonament >> abonament.pret >> abonament.perioada;
    return in;
}

ostream& operator<< (ostream& out, const Abonament& abonament)
{
    out << abonament.nume_abonament << ' ' << abonament.pret << ' ' << abonament.perioada;
    return out;
}

#endif