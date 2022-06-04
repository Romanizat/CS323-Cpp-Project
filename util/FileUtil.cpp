//
// Created by Marko on 04/06/2022.
//

#include "FileUtil.h"
#include <fstream>

using namespace std;

void FileUtil::writePacijentToFile(const string &filename, Pacijent &pacijent) {
    ofstream file;
    file.open(filename, ios::app);
    file << pacijent.getIme()
         << "~" << pacijent.getPrezime()
         << "~" << pacijent.getLbo()
         << "~" << pacijent.getDijagnoza()
         << "~" << pacijent.getDatumOvereKnjizice() << endl;
    file.close();
}

list<Pacijent> FileUtil::readPacijentiFromFile(const string &filename) {
    list<Pacijent> pacijenti;
    ifstream file;
    file.open(filename);
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

FileUtil::FileUtil() = default;
