//
// Created by Marko on 06/06/2022.
//

#ifndef CS323_PROJEKAT2_MARKOJOSIFOVIC4494_STRINGUTIL_H
#define CS323_PROJEKAT2_MARKOJOSIFOVIC4494_STRINGUTIL_H

#include <iostream>
#include "../entity/enum/Valuta.h"

using namespace std;

class StringUtil {
private:
    StringUtil();

public:
    static string getValutaValue(Valuta valuta);

    static Valuta ValutaValueOf(const string& valuta);
};


#endif //CS323_PROJEKAT2_MARKOJOSIFOVIC4494_STRINGUTIL_H
