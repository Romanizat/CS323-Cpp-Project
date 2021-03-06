//
// Created by Marko on 29/05/2022.
//

#include "Lekar.h"
#include "../exception/InvalidGodStazaException.h"
#include "../util/StringUtil.h"
#include "../exception/InvalidBrojDanaException.h"

int Lekar::getGodineStaza() const {
    return godineStaza;
}

void Lekar::setGodineStaza(int godineStaza) {
    if (godineStaza >= 0) {
        Lekar::godineStaza = godineStaza;
    } else {
        InvalidGodStazaException invalidGodStazaException;
        throw invalidGodStazaException;
    }
}

const string &Lekar::getZvanje() const {
    return zvanje;
}

void Lekar::setZvanje(const string &zvanje) {
    Lekar::zvanje = zvanje;
}

void Lekar::toString() {
    cout << this->zvanje << " ";
    Osoba::toString();
    cout << ", " << this->godineStaza << " godine/a staza" << endl;

}

/**
 * Funkcija koja izracunava zaradu lekara na osnovu njegove tarife za prosledjeni broj dana
 * @param brojDana
 * @param tarifa
 * @return
 */
string Lekar::izracunaj(int brojDana, int tarifa, Valuta valuta) {
    double vrednostTarife;
    if(brojDana < 0) {
        InvalidBrojDanaException invalidBrojDanaException;
        throw invalidBrojDanaException;
    }
    switch (tarifa) {
        case 1:
            vrednostTarife = 3000;
            break;
        case 2:
            vrednostTarife = 3500;
            break;
        case 3:
            vrednostTarife = 4000;
            break;
        case 4:
            vrednostTarife = 4500;
            break;
        case 5:
            vrednostTarife = 5000;
            break;
        default:
            vrednostTarife = 0;
    }
    if (valuta == Valuta::EUR) {
        vrednostTarife = vrednostTarife / 120;
    } else if (valuta == Valuta::USD) {
        vrednostTarife = vrednostTarife / 110;
    }
    double zarada = brojDana * vrednostTarife;
    return "Lekar " + this->ime + " " + this->prezime +
           " je za " + to_string(brojDana) + " dana zaradio " + to_string(zarada)
           + " " + StringUtil::getValutaValue(valuta);
}

bool Lekar::operator<(const Lekar &rhs) const {
    return godineStaza < rhs.godineStaza;
}

bool Lekar::operator>(const Lekar &rhs) const {
    return rhs < *this;
}

bool Lekar::operator<=(const Lekar &rhs) const {
    return !(rhs < *this);
}

bool Lekar::operator>=(const Lekar &rhs) const {
    return !(*this < rhs);
}

