//
// Created by Marko on 04/06/2022.
//

#ifndef CS323_PROJEKAT2_MARKOJOSIFOVIC4494_FILEUTIL_H
#define CS323_PROJEKAT2_MARKOJOSIFOVIC4494_FILEUTIL_H

#include <iostream>
#include <list>
#include "../entity/Pacijent.h"
#include "../entity/Lekar.h"

using namespace std;

class FileUtil {
private:
    FileUtil();

public:
    static void writePacijentToFile(Pacijent &pacijent);

    static list<Pacijent> readPacijentiFromFile();

    static list<Lekar> readLekariFromFile();

    static void writeLekarToFile(Lekar &lekar);
};


#endif //CS323_PROJEKAT2_MARKOJOSIFOVIC4494_FILEUTIL_H
