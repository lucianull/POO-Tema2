#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include "abonat.h"
#include <vector>

using namespace std;

class Clienti {
    private:
        vector < Abonat* > clienti;
        int nrAbonatiPremium, size;
        float SumaBani;
    public:
        Clienti(): clienti(), nrAbonatiPremium(0), SumaBani(0), size(0) {}
        Clienti(const Clienti& v)
        {
            Abonat* a;
            for(Abonat* it : v.clienti)
            {
                a = new Abonat(it->GetId(), it->GetNume(), it->GetCnp(), it->GetNrTelefon(), it->GetX()->GetNumeAbonament(), it->GetX()->GetPret(), it->GetX()->GetPerioada(), it->GetX()->GetReducere());
                this->clienti.push_back(a);
            }
            this->nrAbonatiPremium = v.nrAbonatiPremium;
            this->size = v.size;
            this->SumaBani = v.SumaBani;
        }
        ~Clienti()
        {
            while(!clienti.empty())
                clienti.pop_back();
        }
        void addClient(int id, string nume, string cnp, string nr_telefon, string nume_abonament, float pret, int perioada, int reducere=0)
        {
            Abonat *ClientNou = new Abonat(id, nume, cnp, nr_telefon, nume_abonament, pret, perioada, reducere);
            clienti.push_back(ClientNou);
            nrAbonatiPremium += (reducere!=0);
            SumaBani += perioada * (pret - reducere);
            size++;
        }
        void popClient(int indexClient)
        {
            Abonat *Client = clienti[indexClient - 1];
            std :: vector < Abonat* > :: iterator it = clienti.begin() + indexClient - 1;
            SumaBani -= Client->GetX()->GetPerioada() * (Client->GetX()->GetPret() + Client->GetX()->GetReducere());
            if(Client->GetX()->GetReducere())
                nrAbonatiPremium -=1;
            clienti.erase(it);
            delete Client;
        }
        float Suma() {return SumaBani;}
        int GetNrAbonatiPremium() {return nrAbonatiPremium;}
        Clienti& operator= (const Clienti& clienti)
        {
            Abonat* a;
            while(!this->clienti.empty())
                this->clienti.pop_back();
            for(Abonat* it : clienti.clienti)
            {
                a = new Abonat(it->GetId(), it->GetNume(), it->GetCnp(), it->GetNrTelefon(), it->GetX()->GetNumeAbonament(), it->GetX()->GetPret(), it->GetX()->GetPerioada(), it->GetX()->GetReducere());
                this->clienti.push_back(it);
            }
            this->nrAbonatiPremium = clienti.nrAbonatiPremium;
            this->SumaBani = clienti.SumaBani;
            this->size = clienti.size;
            return *this;
        }

};


#endif // CLIENT_H_INCLUDED