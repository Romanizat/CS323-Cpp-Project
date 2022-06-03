//
// Created by Marko on 31/05/2022.
//

#include "Pacijent.h"
#include "../exception/InvalidDatumException.h"

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
string Pacijent::izracunaj(int brojDana, int tarifa) {
    double vrednostTarife;
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
    double zaduzenje = brojDana * vrednostTarife;
    return "Pacijent " + this->ime + " " + this->prezime +
           "je za " + to_string(brojDana) + " dana zadužen " + to_string(zaduzenje);
}
