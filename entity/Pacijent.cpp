//
// Created by Marko on 31/05/2022.
//

#include "Pacijent.h"
#include "../exception/InvalidDatumException.h"
#include "../exception/InvalidBrojDanaException.h"
#include "../util/StringUtil.h"

const string &Pacijent::getLbo() const {
    return lbo;
}

void Pacijent::setLbo(const string &lbo) {
    Pacijent::lbo = lbo;
}

const string &Pacijent::getDijagnoza() const {
    return dijagnoza;
}

void Pacijent::setDijagnoza(const string &dijagnoza) {
    Pacijent::dijagnoza = dijagnoza;
}

const string &Pacijent::getDatumOvereKnjizice() const {
    return datumOvereKnjizice;
}

void Pacijent::setDatumOvereKnjizice(const string &datumOvereKnjizice) {
    if (this->isValidDate(datumOvereKnjizice)) {
        Pacijent::datumOvereKnjizice = datumOvereKnjizice;
    } else {
        InvalidDatumException invalidDatumException;
        throw invalidDatumException;
    }
}

/**
 * Funkcija koja racuna zaduzenje pacijenta na osnovu tarife za broj dana koji je bio u bolnici
 * @param brojDana
 * @param tarifa
 * @return
 */
string Pacijent::izracunaj(int brojDana, int tarifa, Valuta valuta) {
    double vrednostTarife;
    if (brojDana < 0) {
        InvalidBrojDanaException invalidBrojDanaException;
        throw invalidBrojDanaException;
    }
    switch (tarifa) {
        case 1:
            vrednostTarife = 20000;
            break;
        case 2:
            vrednostTarife = 25000;
            break;
        case 3:
            vrednostTarife = 30000;
            break;
        case 4:
            vrednostTarife = 35000;
            break;
        case 5:
            vrednostTarife = 40000;
            break;
        default:
            vrednostTarife = 0;
    }
    if (valuta == Valuta::EUR) {
        vrednostTarife = vrednostTarife / 120;
    } else if (valuta == Valuta::USD) {
        vrednostTarife = vrednostTarife / 110;
    }
    double zaduzenje = brojDana * vrednostTarife;
    return "Pacijent " + this->ime + " " + this->prezime +
           " je za " + to_string(brojDana) + " dana zadužen " + to_string(zaduzenje)
           + " " + StringUtil::getValutaValue(valuta);
}

void Pacijent::toString() {
    Osoba::toString();
    cout << ", LBO: " << this->lbo << ", "
         << "Datum overe knjižice: " << this->datumOvereKnjizice << ", "
         << "Dijagnoza: " << this->dijagnoza << endl;
}
