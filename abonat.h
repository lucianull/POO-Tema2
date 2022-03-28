

#ifndef POO_TEMA_LABORATOR_2_ABONAT_H
#define POO_TEMA_LABORATOR_2_ABONAT_H

#include <persoana.h>
#include <abonament_premium.h>
#include <string>


using namespace std;

class Abonat : public Persoana {
    string nr_telefon;
    Abonament* x;
    public:
        Abonat()
        {
            nr_telefon = "";
            x = NULL;
            Persoana();
        }
        Abonat(int id, string nume, string cnp, string nr_telefon, string nume_abonament, float pret, int perioada, int reducere=0)
        {
            this->id = id;
            this->nume = nume;
            this->cnp = cnp;
            this->nr_telefon = nr_telefon;
            if(reducere == 0)
            {
                x = new Abonament;
                x->SetNumeAbonament(nume_abonament);
                x->SetPret(pret);
                x->SetPerioada(perioada);
            }
            else
            {
                x = new Abonament_Premium;
                x->SetNumeAbonament(nume_abonament);
                x->SetPret(pret);
                x->SetPerioada(perioada);
                x->SetReducere(reducere);
            }

        }
};


#endif