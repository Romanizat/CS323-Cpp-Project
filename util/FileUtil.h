//
// Created by Marko on 04/06/2022.
//

#ifndef CS323_PROJEKAT2_MARKOJOSIFOVIC4494_FILEUTIL_H
#define CS323_PROJEKAT2_MARKOJOSIFOVIC4494_FILEUTIL_H

#include <iostream>
#include "../entity/Pacijent.h"

using namespace std;

class FileUtil {
private:
    FileUtil();

public:
//    static string readFile(string fileName);
    static void writePacijentToFile(const string& filename, Pacijent &pacijent);
};


#endif //CS323_PROJEKAT2_MARKOJOSIFOVIC4494_FILEUTIL_H
