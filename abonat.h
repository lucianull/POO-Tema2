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
                this->x = new Abonament(nume_abonament, pret, perioada);
            else
                this->x = new Abonament_Premium(nume_abonament, pret, perioada, reducere);
        }
        Abonat(const Abonat& abonat)
        {
            this->id = abonat.id;
            this->nume = abonat.nume;
            this->cnp = abonat.cnp;
            this->nr_telefon = abonat.nr_telefon;
            Abonament_Premium* pointer = dynamic_cast <Abonament_Premium* > (abonat.x);
            if(pointer)
                this->x = new Abonament_Premium(*pointer);
            else
                this->x = new Abonament(*pointer);
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
                Abonament_Premium* pointer = dynamic_cast <Abonament_Premium* > (abonat.x);
                if(pointer and pointer->GetReducere())
                    this->x = new Abonament_Premium(abonat.x->GetNumeAbonament(), abonat.x->GetPret(), abonat.x->GetPerioada(), pointer->GetReducere());
                else
                    this->x = new Abonament(abonat.x->GetNumeAbonament(), abonat.x->GetPret(), abonat.x->GetPerioada());
                delete p;
                return *this;
            }
            Abonament_Premium* pointer = dynamic_cast <Abonament_Premium* > (abonat.x);
            if(pointer)
                this->x = new Abonament_Premium(abonat.x->GetNumeAbonament(), abonat.x->GetPret(), abonat.x->GetPerioada(), pointer->GetReducere());
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
    Abonament_Premium* pointer = dynamic_cast <Abonament_Premium* > (abonat.x);
    out << abonat.id << ' ' << abonat.nume << ' ' << abonat.cnp << ' ' << abonat.nr_telefon << ' ' << abonat.x->GetNumeAbonament() << ' ' << abonat.x->GetPret() << ' ' << abonat.x->GetPerioada();
    if(pointer and pointer->GetReducere())
        out << ' ' << pointer->GetReducere();
    return out;
}

#endif // ABONAT_H_INCLUDED