//
// Created by Marko on 04/06/2022.
//

#include "FileUtil.h"
#include <fstream>

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
        p->setDatumOvereKnjizice(datumOvereKnjizice);
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
        string ime, prezime, zvanje;
        int godineStaza;
        stringstream ss(line);
        getline(ss, ime, '~');
        getline(ss, prezime, '~');
        getline(ss, zvanje, '~');
        ss >> godineStaza;
        auto *l = new Lekar();
        l->setIme(ime);
        l->setPrezime(prezime);
        l->setGodineStaza(godineStaza);
        l->setZvanje(zvanje);
        lekari.push_back(*l);
    }
    return lekari;
}

void FileUtil::writeLekarToFile(Lekar &lekar) {
    cout << "ovde" << endl;
    ofstream file;
    file.open(lekariFilename, ios::app);
    file << lekar.getIme()
         << "~" << lekar.getPrezime()
         << "~" << lekar.getZvanje()
         << "~" << lekar.getGodineStaza() << endl;
    file.close();
}


FileUtil::FileUtil() = default;
