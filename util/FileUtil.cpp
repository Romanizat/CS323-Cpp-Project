//
// Created by Marko on 04/06/2022.
//

#include "FileUtil.h"
#include "../exception/InvalidDatumException.h"
#include "../exception/InvalidGodStazaException.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

const static string pacijentiFilename = "pacijenti.txt";
const static string lekariFilename = "lekari.txt";

void FileUtil::writePacijentToFile(Pacijent &pacijent) {
    ofstream file;
    file.open(pacijentiFilename, ios::app);
    file << pacijent.getIme()
         << "~" << pacijent.getPrezime()
         << "~" << pacijent.getLbo()
         << "~" << pacijent.getDijagnoza()
         << "~" << pacijent.getDatumOvereKnjizice() << endl;
    file.close();
}

list<Pacijent> FileUtil::readPacijentiFromFile() {
    list<Pacijent> pacijenti;
    ifstream file;
    file.open(pacijentiFilename);
    string line;
    while (getline(file, line)) {
        string ime, prezime, lbo, dijagnoza, datumOvereKnjizice;
        stringstream ss(line);
        getline(ss, ime, '~');
        getline(ss, prezime, '~');
        getline(ss, lbo, '~');
        getline(ss, dijagnoza, '~');
        getline(ss, datumOvereKnjizice, '~');
        auto *p = new Pacijent();
        p->setIme(ime);
        p->setPrezime(prezime);
        p->setLbo(lbo);
        p->setDijagnoza(dijagnoza);
        try {
            p->setDatumOvereKnjizice(datumOvereKnjizice);
        } catch (InvalidDatumException &ex) {
            cout << ex.what() << endl;
        }
        pacijenti.push_back(*p);
    }
    return pacijenti;
}

list<Lekar> FileUtil::readLekariFromFile() {
    list<Lekar> lekari;
    ifstream file;
    file.open(lekariFilename);
    string line;
    while (getline(file, line)) {
        string ime, prezime, zvanje, godineStazaStr;
        int godineStaza;
        stringstream ss(line);
        getline(ss, ime, '~');
        getline(ss, prezime, '~');
        getline(ss, zvanje, '~');
        getline(ss, godineStazaStr, '~');
        auto *l = new Lekar();
        l->setIme(ime);
        l->setPrezime(prezime);
        try {
            godineStaza = stoi(godineStazaStr);
            l->setGodineStaza(godineStaza);
        } catch (invalid_argument &ex) {
            cout << "Uneta vrednost nije broj! Izuzetak: " << ex.what() << endl;
        } catch (InvalidGodStazaException &ex) {
            cout << ex.what() << endl;
        }
        l->setZvanje(zvanje);
        lekari.push_back(*l);
    }
    return lekari;
}

void FileUtil::writeLekarToFile(Lekar &lekar) {
    ofstream file;
    file.open(lekariFilename, ios::app);
    file << lekar.getIme()
         << "~" << lekar.getPrezime()
         << "~" << lekar.getZvanje()
         << "~" << lekar.getGodineStaza() << endl;
    file.close();
}


FileUtil::FileUtil() = default;
