//
// Created by Marko on 29/05/2022.
//

#include "Osoba.h"

const string &Osoba::getIme() const {
    return ime;
}

void Osoba::setIme(const string &ime) {
    Osoba::ime = ime;
}

const string &Osoba::getPrezime() const {
    return prezime;
}

void Osoba::setPrezime(const string &prezime) {
    Osoba::prezime = prezime;
}

void Osoba::toString() {
    cout << this->ime + " " + this->prezime;
}
