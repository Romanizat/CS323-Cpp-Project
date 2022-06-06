#include <iostream>
#include "entity/Lekar.h"
#include "entity/Pacijent.h"
#include "exception/InvalidDatumException.h"
#include "exception/InvalidGodStazaException.h"
#include "util/FileUtil.h"
#include "util/StringUtil.h"
#include "exception/InvalidBrojDanaException.h"
#include "exception/UnsupportedValutaException.h"
#include "exception/InvalidLboException.h"
#include <algorithm>
#include <string>

using namespace std;

int main() {
    bool flag = true;
    int brojDana;
    int tarifa;
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
            } catch (invalid_argument &ex) {
                cout << "Uneta vrednost nije broj! Izuzetak: " << ex.what() << endl;
            } catch (InvalidGodStazaException &ex) {
                cout << ex.what() << endl;
            }
        }

        FileUtil::writeLekarToFile(*l);
        cout << "Lekar upisan!" << endl;

        cout << "Da li želite da izračunate zaradu ovog lekara? (DA/NE)" << endl;
        cin >> answer;
        transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
        if (answer == "DA") {
            flag = true;
            while (flag) {
                cout << "Unesite broj dana za koje želite da izračunate zaradu:" << endl;
                cin >> brojDana;
                cout << "Unesite tarifu za koju želite da izračunate zaradu (1-5):" << endl;
                cin >> tarifa;
                cout << "Koja valuta? (RSD/EUR/USD)" << endl;
                cin >> answer;
                transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
                try {
                    cout << l->izracunaj(brojDana, tarifa, StringUtil::ValutaValueOf(answer)) << endl;
                    flag = false;
                } catch (InvalidBrojDanaException &ex) {
                    cout << ex.what() << endl;
                } catch (UnsupportedValutaException &ex) {
                    cout << ex.what() << endl;
                }
            }
        } else if (answer == "NE") {
            cout << "Hvala na odgovoru!" << endl;
        }

    } else if (answer == "NE") {
        cout << "Hvala na odgovoru!" << endl;
    }

    cout << "Da li želite da vidite sve upisane lekare? (DA/NE)" << endl;
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
    if (answer == "DA") {
        auto lekari = FileUtil::readLekariFromFile();
        auto lekarIterator = lekari.begin();
        while (lekarIterator != lekari.end()) {
            lekarIterator->toString();
            lekarIterator++;
        }
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
        flag = true;
        while (flag) {
            cout << "Unesite LBO pacijenta:" << endl;
            cin >> answer;
            try {
                p->setLbo(answer);
                flag = false;
            } catch (InvalidLboException &ex) {
                cout << ex.what() << endl;
            }
        }
        flag = true;
        while (flag) {
            cout << "Unesite datum overe knjižice pacijenta:" << endl;
            cin >> answer;
            flag = true;
            try {
                p->setDatumOvereKnjizice(answer);
                flag = false;
            } catch (InvalidDatumException &ex) {
                cout << ex.what() << endl;
            }
        }
        cout << "Unesite dijagnozu pacijenta:" << endl;
        getline(cin, answer);
        getline(cin, answer);
        p->setDijagnoza(answer);
        FileUtil::writePacijentToFile(*p);
        cout << "Pacijent upisan!" << endl;

        cout << "Da li želite da izračunate zaduženje ovog pacijenta? (DA/NE)" << endl;
        cin >> answer;
        transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
        if (answer == "DA") {
            flag = true;
            while (flag) {
                cout << "Unesite broj dana za koje želite da izračunate zaduženje:" << endl;
                cin >> brojDana;
                cout << "Unesite tarifu za koju želite da izračunate zaduženje (1-5):" << endl;
                cin >> tarifa;
                cout << "Koja valuta? (RSD/EUR/USD)" << endl;
                cin >> answer;
                transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
                try {
                    cout << p->izracunaj(brojDana, tarifa, StringUtil::ValutaValueOf(answer)) << endl;
                    flag = false;
                } catch (InvalidBrojDanaException &ex) {
                    cout << ex.what() << endl;
                } catch (UnsupportedValutaException &ex) {
                    cout << ex.what() << endl;
                }
            }
        } else if (answer == "NE") {
            cout << "Hvala na odgovoru!" << endl;
        }
    } else if (answer == "NE") {
        cout << "Hvala na odgovoru!" << endl;
    }
    cout << "Da li želite da vidite sve upisane pacijente? (DA/NE)" << endl;
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
    if (answer == "DA") {
        auto pacijenti = FileUtil::readPacijentiFromFile();
//        list<Pacijent>::iterator pacijentIterator = pacijenti.begin();
        auto pacijentIterator = pacijenti.begin();
        while (pacijentIterator != pacijenti.end()) {
            pacijentIterator->toString();
            pacijentIterator++;
        }
    } else if (answer == "NE") {
        cout << "Hvala na odgovoru!" << endl;
    }


    cout << "Hvala Vam!" << endl;
    return 0;
}