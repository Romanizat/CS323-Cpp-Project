//
// Created by Marko on 29/05/2022.
//

#ifndef CS323_PROJEKAT2_MARKOJOSIFOVIC4494_LEKAR_H
#define CS323_PROJEKAT2_MARKOJOSIFOVIC4494_LEKAR_H


#include "Osoba.h"

class Lekar : public Osoba {
private:
    string zvanje;
    int godineStaza;
public:
    int getGodineStaza() const;

    void setGodineStaza(int godineStaza);

    const string &getZvanje() const;

    void setZvanje(const string &zvanje);

    string izracunaj(int brojDana, int tarifa, Valuta valuta) override;

    void toString() override;

    bool operator<(const Lekar &rhs) const;

    bool operator>(const Lekar &rhs) const;

    bool operator<=(const Lekar &rhs) const;

    bool operator>=(const Lekar &rhs) const;
};


#endif //CS323_PROJEKAT2_MARKOJOSIFOVIC4494_LEKAR_H
