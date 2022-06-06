//
// Created by Marko on 06/06/2022.
//

#ifndef CS323_PROJEKAT2_MARKOJOSIFOVIC4494_UNSUPPORTEDVALUTAEXCEPTION_H
#define CS323_PROJEKAT2_MARKOJOSIFOVIC4494_UNSUPPORTEDVALUTAEXCEPTION_H

#include <exception>

using namespace std;

class UnsupportedValutaException : public exception {
public:
    const char *what() {
        return "Uneta valuta nije podržana";
    }
};


#endif //CS323_PROJEKAT2_MARKOJOSIFOVIC4494_UNSUPPORTEDVALUTAEXCEPTION_H
