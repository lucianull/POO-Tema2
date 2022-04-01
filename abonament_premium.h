#ifndef ABONAMENT_PREMIUM_H_INCLUDED
#define ABONAMENT_PREMIUM_H_INCLUDED

#include "abonament.h"

using namespace std;

class Abonament_Premium : public Abonament {
    protected:
        static int NrAbonatiPremium;
        int reducere;
    public:
        Abonament_Premium(): Abonament(), reducere(0) {NrAbonatiPremium ++;}
        Abonament_Premium(string name, float price, int period, int discount): Abonament(name, price, period), reducere(discount) {NrAbonatiPremium ++;}
        Abonament_Premium(Abonament_Premium& abonament)
        {
            this->nume_abonament = abonament.nume_abonament;
            this->pret = abonament.pret;
            this->perioada = abonament.perioada;
            this->reducere = abonament.reducere;
            NrAbonatiPremium ++;
        }
        ~Abonament_Premium() {}
        friend istream& operator>> (istream&, Abonament_Premium&);
        friend ostream& operator<< (ostream&, const Abonament_Premium&);
        Abonament_Premium& operator= (const Abonament_Premium& abonament)
        {
            this->nume_abonament = abonament.nume_abonament;
            this->pret = abonament.pret;
            this->perioada = abonament.perioada;
            this->reducere = abonament.reducere;
            return *this;
        }
        void SetReducere(int discount) {reducere = discount;}
        int GetReducere() {return reducere;}
        float BaniPlatiti() {return (pret - reducere) * perioada;}
        static int GetNrAbonatiPremium() {return NrAbonatiPremium;}
};

istream& operator>> (istream& in, Abonament_Premium& abonament)
{
    in >> abonament.nume_abonament >> abonament.pret >> abonament.perioada >> abonament.reducere;
    return in;
}

ostream& operator<< (ostream& out, const Abonament_Premium& abonament)
{
    out << abonament.nume_abonament << ' ' << abonament.pret << ' ' << abonament.perioada << ' ' << abonament.reducere;
    return out;
}

int Abonament_Premium::NrAbonatiPremium = 0;

#endif // ABONAMENT_PREMIUM_H_INCLUDED