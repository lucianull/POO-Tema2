

#ifndef POO_TEMA_LABORATOR_2_ABONAMENT_PREMIUM_H
#define POO_TEMA_LABORATOR_2_ABONAMENT_PREMIUM_H

#include <abonament.h>
#include <string>

using namespace std;


class Abonament_Premium : public Abonament {
    private:
        int reducere;
    public:
        Abonament_Premium(): Abonament(), reducere(0) {}
        Abonament_Premium(string name, float price, int period, int discount): Abonament(name, price, period), reducere(discount) {}
        Abonament_Premium(const Abonament_Premium & abonament): reducere(abonament.reducere), Abonament(abonament.nume_abonament, abonament.pret, abonament.perioada) {}
        void SetReducere(int reducere) { this->reducere = reducere; }
        int GetReducere() { return reducere; }
        Abonament_Premium& operator= (const Abonament_Premium& abonament)
        {
            this->nume_abonament = abonament.nume_abonament;
            this->pret = abonament.pret;
            this->perioada = abonament.perioada;
            this->reducere = abonament.reducere;
            return *this;
        }
        friend istream& operator>> (istream&, Abonament_Premium&);
        friend ostream& operator<<(ostream&, const Abonament_Premium&);
};

istream& operator>>(istream& in, Abonament_Premium& abonament)
{
    in >> abonament.nume_abonament >> abonament.pret >> abonament.perioada >> abonament.reducere;
    return in;
}

ostream& operator<< (ostream& out, const Abonament_Premium& abonament)
{
    out << abonament.nume_abonament << ' ' << abonament.pret << ' ' << abonament.perioada << ' ' << abonament.reducere;
    return out;
}

#endif