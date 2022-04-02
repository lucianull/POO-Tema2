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
                a = new Abonat(*it);
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
        void addClient(int id, string nume, string cnp, string nr_telefon, string nume_abonament, float pret, int perioada, float reducere=0)
        {
            Abonat *ClientNou = new Abonat(id, nume, cnp, nr_telefon, nume_abonament, pret, perioada, reducere);
            clienti.push_back(ClientNou);
        }
        void popClient(int indexClient)
        {
            Abonat *Client = clienti[indexClient - 1];
            std :: vector < Abonat* > :: iterator it = clienti.begin() + indexClient - 1;
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
            Abonament_Premium* pointer = dynamic_cast <Abonament_Premium* > (clienti[indexClient - 1]->GetX());
            if(pointer)
                cout << ' ' << pointer->GetReducere();
        }
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
                a = new Abonat(*it);
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
        int size() {return clienti.size();}
};
#endif // CLIENT_H_INCLUDED
