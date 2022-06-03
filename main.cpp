#include <iostream>
#include "entity/Osoba.h"
#include "entity/Lekar.h"
#include "entity/Pacijent.h"
#include "exception/InvalidDatumException.h"
#include "exception/InvalidGodStazaException.h"
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

void toUppercase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
}

int main() {
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


    cout << "Da li želite da unesete novog lekara? (DA/NE)" << endl;
    string answer;
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
//    toUppercase(answer);
    cout << answer << endl;
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
        cout << "Unesite broj godina staža:" << endl;
        cin >> answer;
        int godineStaza;
        try {
            godineStaza = stoi(answer);
            l->setGodineStaza(godineStaza);
        } catch (invalid_argument ex) {
            cout << "Uneta vrednost nije broj! " << ex.what() << endl;
        } catch (InvalidGodStazaException ex) {
            cout << ex.what() << endl;
        }

        l->toString();
//        FileUtil.upisiLekareFajl(l);
        cout << "Lekar upisan!" << endl;
//
//    } else if (line.equalsIgnoreCase("NE")) {
//        System.out.println("Hvala na odgovoru!");
//    }
//
//    System.out.println("Da li želite da unesete novog pacijenta? (DA/NE)");
//    line = ulaz.nextLine();
//    if (line.equalsIgnoreCase("DA")) {
//
//        Pacijent p = new Pacijent();
//        System.out.println("Unesite ime pacijenta:");
//        p.setIme(ulaz.nextLine());
//        System.out.println("Unesite prezime pacijenta:");
//        p.setPrezime(ulaz.nextLine());
//        System.out.println("Unesite pol pacijenta, 'M','F' ili 'DRUGO':");
//        p.setPol(Pol.valueOf(ulaz.nextLine().toUpperCase()));
//        System.out.println("Unesite LBO:");
//        p.setLbo(ulaz.nextLine());
//        Karton k = new Karton();
//        System.out.println("Unesite anamnezu, za obustavu unesite karakter '0'");
//        List <String> anamneza = new ArrayList<>();
//        String linija = null;
//        do {
//            linija = ulaz.nextLine();
//            if (!linija.equals("0")) {
//                anamneza.add(linija);
//            }
//        } while (!linija.equals("0"));
//        k.setAnamneza(anamneza);
//        System.out.println("Unesite alergije, za obustavu unesite karakter '0'");
//        List <String> alergije = new ArrayList<>();
//        do {
//            linija = ulaz.nextLine();
//            if (!linija.equals("0")) {
//                alergije.add(linija);
//            }
//        } while (!linija.equals("0"));
//        k.setAlergije(alergije);
//        System.out.println("Unesite datum overe knjižice, formata 'DD-MM-GGGG'");
//
//        boolean tester = true;
//        while (tester) {
//            String datum = ulaz.nextLine();
//            try {
//                k.setDatumOvereKnjizice(datum);
//                tester = false;
//            } catch (NevalidanFormatDatumaException ex) {
//                System.out.println(ex.getMessage());
//            } catch (NevalidanDatumException ex) {
//                System.out.println(ex.getMessage());
//            }
//        }
//        System.out.println(
//                "Unesite vakcine koje je primio pacijent:\n {BCG, HB, HBig, DTP, OPV, Hib, MMR}\n Za obustavu unesite karakter '0'");
//        List <String> vakcine = new ArrayList<>();
//        do {
//            linija = ulaz.nextLine();
//            if (!linija.equals("0")) {
//                vakcine.add(linija);
//            }
//        } while (!linija.equals("0"));
//        k.setVakcine(vakcine);
//        p.setKarton(k);
//
//        FileUtil.upisiPacijenteFajl(p);
//        System.out.println("Pacijent upisan!");
//
//    } else if (line.equalsIgnoreCase("NE")) {
//        System.out.println("Hvala na odgovoru!");
//    }

        cout << "Hvala Vam!" << endl;
        return 0;
    }
}