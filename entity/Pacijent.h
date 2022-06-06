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

    bool isValidDate(string datumOvereKnjizice) {
        return regex_match(datumOvereKnjizice,
                           regex("(^(((0[1-9]|1[0-9]|2[0-8])[\\/](0[1-9]|1[012]))|((29|30|31)[\\/](0[13578]|1[02]))|((29|30)[\\/](0[4,6,9]|11)))[\\/](19|[2-9][0-9])\\d\\d$)|(^29[\\/]02[\\/](19|[2-9][0-9])(00|04|08|12|16|20|24|28|32|36|40|44|48|52|56|60|64|68|72|76|80|84|88|92|96)$)"));
    }

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
