//
// Created by Marko on 29/05/2022.
//

#ifndef CS323_PROJEKAT2_MARKOJOSIFOVIC4494_INVALIDGODSTAZAEXCEPTION_H
#define CS323_PROJEKAT2_MARKOJOSIFOVIC4494_INVALIDGODSTAZAEXCEPTION_H

#include <exception>

using namespace std;

class InvalidGodStazaException : public exception {
public:
    const char *what() {
        return "Godine staza ne smeju biti negativne";
    }
};


#endif //CS323_PROJEKAT2_MARKOJOSIFOVIC4494_INVALIDGODSTAZAEXCEPTION_H
