//
// Created by Marko on 29/05/2022.
//

#ifndef CS323_PROJEKAT2_MARKOJOSIFOVIC4494_OSOBA_H
#define CS323_PROJEKAT2_MARKOJOSIFOVIC4494_OSOBA_H

#include <iostream>

using namespace std;

class Osoba {
protected:
    string ime;
    string prezime;
public:
    const string &getIme() const;

    void setIme(const string &ime);

    const string &getPrezime() const;

    void setPrezime(const string &prezime);

//    virtual int uporedi(Osoba *o)=0;

    virtual string izracunaj(int brojDana, int tarifa) = 0;

    virtual void toString();
};


#endif //CS323_PROJEKAT2_MARKOJOSIFOVIC4494_OSOBA_H
