//
// Created by Marko on 31/05/2022.
//

#ifndef CS323_PROJEKAT2_MARKOJOSIFOVIC4494_PACIJENT_H
#define CS323_PROJEKAT2_MARKOJOSIFOVIC4494_PACIJENT_H


#include <regex>
#include "Osoba.h"

using namespace std;

class Pacijent : public Osoba {
private:
    string lbo;
    string dijagnoza;
    string datumOvereKnjizice;

public:
    const string &getLbo() const;

    void setLbo(const string &lbo);

    const string &getDijagnoza() const;

    void setDijagnoza(const string &dijagnoza);

    const string &getDatumOvereKnjizice() const;

    void setDatumOvereKnjizice(const string &datumOvereKnjizice);

    string izracunaj(int brojDana, int tarifa, Valuta valuta) override;

    void toString() override;
};


#endif //CS323_PROJEKAT2_MARKOJOSIFOVIC4494_PACIJENT_H
