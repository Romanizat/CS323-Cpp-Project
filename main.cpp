#include <iostream>
#include "entity/Osoba.h"
#include "entity/Lekar.h"
#include "entity/Pacijent.h"
#include "exception/InvalidDatumException.h"
#include "exception/InvalidGodStazaException.h"
#include "util/FileUtil.h"
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

void toUppercase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
}

int main() {
    const string pacijentiFilename = "pacijenti.txt";
    const string lekariFilename = "lekari.txt";
////    Osoba *osoba = new Pacijent();
////    auto& p = dynamic_cast<Pacijent&>(*osoba);
//    auto *p = new Pacijent();
//    p->setIme("Pera");
//    p->setPrezime("Peric");
//    p->setLbo("012346578");
//    try {
//        p->setDatumOvereKnjizice("dsada");
//    } catch (InvalidDatumException ex) {
//        cout << ex.what() << endl;
//    }

    bool flag = true;
    cout << "Da li želite da unesete novog lekara? (DA/NE)" << endl;
    string answer;
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
    if (answer == "DA") {
        auto *l = new Lekar();
        cout << "Unesite ime za Lekara:" << endl;
        cin >> answer;
        l->setIme(answer);
        cout << "Unesite prezime za Lekara:" << endl;
        cin >> answer;
        l->setPrezime(answer);
        cout << "Unesite zvanje lekara:" << endl;
        getline(cin, answer);
        getline(cin, answer);
        l->setZvanje(answer);
        while (flag) {
            cout << "Unesite broj godina staža:" << endl;
            cin >> answer;
            int godineStaza;
            try {
                godineStaza = stoi(answer);
                l->setGodineStaza(godineStaza);
                flag = false;
            } catch (invalid_argument ex) {
                cout << "Uneta vrednost nije broj! Izuzetak: " << ex.what() << endl;
            } catch (InvalidGodStazaException ex) {
                cout << ex.what() << endl;
            }
        }

        l->toString();
//        TODO:
//        FileUtil.upisiLekareFajl(l);
        cout << "Lekar upisan!" << endl;

    } else if (answer == "NE") {
        cout << "Hvala na odgovoru!" << endl;
    }

    cout << "Da li želite da unesete novog pacijenta? (DA/NE)" << endl;
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
    if (answer == "DA") {
        auto *p = new Pacijent();
        cout << "Unesite ime pacijenta:" << endl;
        cin >> answer;
        p->setIme(answer);
        cout << "Unesite prezime pacijenta:" << endl;
        cin >> answer;
        p->setPrezime(answer);
        cout << "Unesite LBO pacijenta:" << endl;
        cin >> answer;
        p->setLbo(answer);
        while (flag) {
            cout << "Unesite datum overe knjižice pacijenta:" << endl;
            cin >> answer;
            flag = true;
            try {
                p->setDatumOvereKnjizice(answer);
                flag = false;
            } catch (InvalidDatumException ex) {
                cout << ex.what() << endl;
            }
        }
        cout << "Unesite dijagnozu pacijenta:" << endl;
        getline(cin, answer);
        getline(cin, answer);
        p->setDijagnoza(answer);
        FileUtil::writePacijentToFile(pacijentiFilename, *p);
        cout << "Pacijent upisan!" << endl;
        p->toString();
    } else if (answer == "NE") {
        cout << "Hvala na odgovoru!" << endl;
    }
    cout << "Da li želite da vidite sve upisane pacijente? (DA/NE)" << endl;
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
    if (answer == "DA") {
        auto pacijenti = FileUtil::readPacijentiFromFile(pacijentiFilename);
//        TODO:
// iterate through pacijenti and print them using std::iterator
        for (auto p : pacijenti) {
            p.toString();
        }
    } else if (answer == "NE") {
        cout << "Hvala na odgovoru!" << endl;
    }


    cout << "Hvala Vam!" << endl;
    return 0;
}