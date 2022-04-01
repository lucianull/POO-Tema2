#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include "abonat.h"
#include <vector>

using namespace std;

class Clienti {
    private:
        vector < Abonat* > clienti;
    public:
        Clienti(): clienti(){}
        Clienti(const Clienti& v)
        {
            Abonat* a;
            for(Abonat* it : v.clienti)
            {
                a = new Abonat(it->GetId(), it->GetNume(), it->GetCnp(), it->GetNrTelefon(), it->GetX()->GetNumeAbonament(), it->GetX()->GetPret(), it->GetX()->GetPerioada(), it->GetX()->GetReducere());
                this->clienti.push_back(a);
            }
        }
        ~Clienti()
        {
            int size = clienti.size();
            Abonat *pointer;
            while(!clienti.empty()) 
            { 
                pointer = clienti[size - 1];
                clienti.pop_back();
                size --;
                delete pointer;
            }
        }
        void addClient(int id, string nume, string cnp, string nr_telefon, string nume_abonament, float pret, int perioada, int reducere=0)
        {
            Abonat *ClientNou = new Abonat(id, nume, cnp, nr_telefon, nume_abonament, pret, perioada, reducere);
            clienti.push_back(ClientNou);
        }
        void popClient(int indexClient)
        {
            Abonat *Client = clienti[indexClient - 1];
            std :: vector < Abonat* > :: iterator it = clienti.begin() + indexClient - 1;
            if(Client->GetX()->GetReducere())
            clienti.erase(it);
            delete Client;
        }
        void ShowClient(int indexClient)
        {
            cout <<clienti[indexClient - 1]->GetId() << ' ' << clienti[indexClient - 1]->GetNume() << ' ' << clienti[indexClient - 1]->GetCnp();
        }
        void ShowClientSubs(int indexClient)
        {
            cout << clienti[indexClient - 1]->GetX()->GetNumeAbonament() << ' ' << clienti[indexClient - 1]->GetX()->GetPret() << ' ' << clienti[indexClient - 1]->GetX()->GetPerioada();
            if(dynamic_cast<Abonament_Premium*> (clienti[indexClient - 1]->GetX()))
                cout << ' ' << clienti[indexClient - 1]->GetX()->GetReducere();
        }
        // int GetNrAbonatiPremium()
        // {
        //     int nrAbonatiPremium = 0;
        //     for(Abonat* it : clienti)
        //         if(dynamic_cast<Abonament_Premium*> (it->GetX()))
        //             nrAbonatiPremium ++;
        //     return nrAbonatiPremium;
        // }
        int GetNrAbonatiPremium()
        {
            return Abonament_Premium::GetNrAbonatiPremium();
        }
        Clienti& operator= (const Clienti& clienti)
        {
            Abonat* a;
            while(!this->clienti.empty())
            {
                a = this->clienti[this->clienti.size() - 1];
                this->clienti.pop_back();
                delete a;
            }
                
            for(Abonat* it : clienti.clienti)
            {
                a = new Abonat(it->GetId(), it->GetNume(), it->GetCnp(), it->GetNrTelefon(), it->GetX()->GetNumeAbonament(), it->GetX()->GetPret(), it->GetX()->GetPerioada(), it->GetX()->GetReducere());
                this->clienti.push_back(it);
            }
            return *this;
        }
        float Suma()
        {
            float suma = 0;
            for(Abonat* it : clienti)
                suma += it->GetX()->BaniPlatiti();
            return suma;
        }
};


#endif // CLIENT_H_INCLUDED
