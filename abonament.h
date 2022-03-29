#ifndef ABONAMENT_H_INCLUDED
#define ABONAMENT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Abonament {
    protected:
        string nume_abonament;
        float pret;
        int perioada;
    public:
        Abonament() : nume_abonament(""), pret(0), perioada(0) {}
        Abonament(string name, float price, int period): nume_abonament(name), pret(price), perioada(period) {}
        Abonament(const Abonament & abonament)
        {
            this->nume_abonament = abonament.nume_abonament;
            this->pret = abonament.pret;
            this->perioada = abonament.perioada;
        }
        friend istream& operator>> (istream&, Abonament&);
        friend ostream& operator<< (ostream&, const Abonament&);
        Abonament& operator= (const Abonament& abonament)
        {
            this->nume_abonament = abonament.nume_abonament;
            this->pret = abonament.pret;
            this->perioada = abonament.perioada;
            return *this;
        }
        void SetNumeAbonament(string name) {nume_abonament = name;}
        void SetPret(float price) {pret = price;}
        void SetPerioada(int period) {perioada = period; }
        string GetNumeAbonament() {return nume_abonament;}
        float GetPret() {return pret;}
        int GetPerioada() {return perioada;}
        virtual void SetReducere(int discount) {}
        virtual int GetReducere() {}
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

#endif // ABONAMENT_H_INCLUDED