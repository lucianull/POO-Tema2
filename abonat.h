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
        Abonat(int ID, string name, string CNP, string nr_telefon, string nume_abonament, float pret, int perioada, int reducere=0) : Persoana(ID, name, CNP)
        {
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
            if(dynamic_cast<Abonament_Premium*> (abonat.x))
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
        Abonat& operator= (const Abonat& abonat)
        {
            this->nr_telefon = abonat.nr_telefon;
            this->id = abonat.id;
            this->nume = abonat.nume;
            this->cnp = abonat.cnp;

            if(abonat.x != NULL)
            {
                Abonament *p;
                p = abonat.x;
                if(abonat.x->GetReducere())
                    this->x = new Abonament_Premium(abonat.x->GetNumeAbonament(), abonat.x->GetPret(), abonat.x->GetPerioada(), abonat.x->GetReducere());
                else
                    this->x = new Abonament(abonat.x->GetNumeAbonament(), abonat.x->GetPret(), abonat.x->GetPerioada());
                delete p;
                return *this;
            }
            if(dynamic_cast<Abonament_Premium*> (abonat.x))
                this->x = new Abonament_Premium(abonat.x->GetNumeAbonament(), abonat.x->GetPret(), abonat.x->GetPerioada(), abonat.x->GetReducere());
            else
                this->x = new Abonament(abonat.x->GetNumeAbonament(), abonat.x->GetPret(), abonat.x->GetPerioada());
            return *this;
        }
        Abonament* GetX() {return x;}
        virtual ~Abonat() {delete x;}
        friend ostream& operator<< (ostream& out, const Abonat&);
        string GetNrTelefon() {return nr_telefon;}
};


ostream& operator<< (ostream& out, const Abonat& abonat)
{
    out << abonat.id << ' ' << abonat.nume << ' ' << abonat.cnp << ' ' << abonat.nr_telefon << ' ' << abonat.x->GetNumeAbonament() << ' ' << abonat.x->GetPret() << ' ' << abonat.x->GetPerioada();
    if(abonat.x->GetReducere())
        out << ' ' << abonat.x->GetReducere();
    return out;
}

#endif // ABONAT_H_INCLUDED