//
// Created by Marko on 06/06/2022.
//

#ifndef CS323_PROJEKAT2_MARKOJOSIFOVIC4494_INVALIDLBOEXCEPTION_H
#define CS323_PROJEKAT2_MARKOJOSIFOVIC4494_INVALIDLBOEXCEPTION_H

#include <exception>

using namespace std;

class InvalidLboException : exception {
public:
    const char *what() {
        return "LBO mora imati 11 cifara i ne sme sadržati karaktere koji nisu brojevi";
    }
};


#endif //CS323_PROJEKAT2_MARKOJOSIFOVIC4494_INVALIDLBOEXCEPTION_H
