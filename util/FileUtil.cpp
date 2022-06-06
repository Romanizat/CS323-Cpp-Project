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

FileUtil::FileUtil() = default;
