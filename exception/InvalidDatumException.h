//
// Created by Marko on 31/05/2022.
//

#ifndef CS323_PROJEKAT2_MARKOJOSIFOVIC4494_INVALIDDATUMEXCEPTION_H
#define CS323_PROJEKAT2_MARKOJOSIFOVIC4494_INVALIDDATUMEXCEPTION_H

#include <exception>

using namespace std;

class InvalidDatumException : public exception {
public:
    const char *what() {
        return "Unet datum nije validan, datum mora biti formata dd/MM/yyyy";
    }
};


#endif //CS323_PROJEKAT2_MARKOJOSIFOVIC4494_INVALIDDATUMEXCEPTION_H
