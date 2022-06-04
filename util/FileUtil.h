//
// Created by Marko on 04/06/2022.
//

#ifndef CS323_PROJEKAT2_MARKOJOSIFOVIC4494_FILEUTIL_H
#define CS323_PROJEKAT2_MARKOJOSIFOVIC4494_FILEUTIL_H

#include <iostream>
#include <list>
#include "../entity/Pacijent.h"

using namespace std;

class FileUtil {
private:
    FileUtil();

public:
    static void writePacijentToFile(const string &filename, Pacijent &pacijent);

    static list<Pacijent> readPacijentiFromFile(const string &filename);
};


#endif //CS323_PROJEKAT2_MARKOJOSIFOVIC4494_FILEUTIL_H
