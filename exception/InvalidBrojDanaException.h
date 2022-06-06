//
// Created by Marko on 06/06/2022.
//

#ifndef CS323_PROJEKAT2_MARKOJOSIFOVIC4494_INVALIDBROJDANAEXCEPTION_H
#define CS323_PROJEKAT2_MARKOJOSIFOVIC4494_INVALIDBROJDANAEXCEPTION_H

#include <exception>

using namespace std;

class InvalidBrojDanaException : public exception {
public:
    const char *what() {
        return "Broj dana ne sme biti negativan";
    }
};


#endif //CS323_PROJEKAT2_MARKOJOSIFOVIC4494_INVALIDBROJDANAEXCEPTION_H
