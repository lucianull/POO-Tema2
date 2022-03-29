#ifndef ABONAT_H_INCLUDED
#define ABONAT_H_INCLUDED

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "abonament_premium.h"
#include "persoana.h"

using namespace std;

class Abonat : public Persoana {
    protected:
        string nr_telefon;
        Abonament* x;
    public:
        Abonat(): Persoana(), nr_telefon(""), x(NULL) {}
        Abonat(int id, string nume, string cnp, string nr_telefon, string nume_abonament, float pret, int perioada, int reducere=0)
        {
            this->id = id;
            this->nume = nume;
            this->cnp = cnp;
            this->nr_telefon = nr_telefon;
            if(reducere == 0)
            {
                this->x = new Abonament();
                this->x->SetNumeAbonament(nume_abonament);
                this->x->SetPerioada(perioada);
                this->x->SetPret(pret);
            }
            else
            {
                this->x = new Abonament_Premium();
                this->x->SetNumeAbonament(nume_abonament);
                this->x->SetPerioada(perioada);
                this->x->SetPret(pret);
                this->x->SetReducere(reducere);
            }
        }
        Abonat(const Abonat& abonat)
        {
            this->id = abonat.id;
            this->nume = abonat.nume;
            this->cnp = abonat.cnp;
            this->nr_telefon = abonat.nr_telefon;
            if(abonat.x->GetReducere())
            {
                this->x = new Abonament_Premium;
                this->x->SetNumeAbonament(abonat.x->GetNumeAbonament());
                this->x->SetPret(abonat.x->GetPret());
                this->x->SetPerioada(abonat.x->GetPerioada());
                this->x->SetReducere(abonat.x->GetReducere());
            }
            else
            {
                this->x = new Abonament;
                this->x->SetNumeAbonament(abonat.x->GetNumeAbonament());
                this->x->SetPret(abonat.x->GetPret());
                this->x->SetPerioada(abonat.x->GetPerioada());
            }
        }
        friend istream& operator>> (istream& in, Abonat&);
        friend ostream& operator<< (ostream& out, const Abonat&);
};

istream& operator>> (istream& in, Abonat& abonat)
{
    string s;
    getline(in, s);
    char *p = strtok(&s[0], " ");
    vector < string > v;
    while(p != NULL)
    {
        v.push_back(p);
        p = strtok(NULL, " ");
    }
    abonat.id = atoi(v[0].c_str());
    abonat.nume = v[1];
    abonat.cnp = v[2];
    abonat.nr_telefon = v[3];
    abonat.x->SetNumeAbonament(v[4]);
    abonat.x->SetPret(strtof(v[5].c_str(), NULL));
    abonat.x->SetPerioada(atoi(v[6].c_str()));
    if(v.size() > 7)
        abonat.x->SetReducere(atoi(v[7].c_str()));
    return in;
}

ostream& operator<< (ostream& out, const Abonat& abonat)
{
    out << abonat.id << ' ' << abonat.nume << ' ' << abonat.cnp << ' ' << abonat.nr_telefon << ' ' << abonat.x->GetNumeAbonament() << ' ' << abonat.x->GetPret() << ' ' << abonat.x->GetPerioada();
    if(abonat.x->GetReducere())
        out << ' ' << abonat.x->GetReducere();
    return out;
}

#endif // ABONAT_H_INCLUDED