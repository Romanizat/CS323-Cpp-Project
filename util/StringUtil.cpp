//
// Created by Marko on 06/06/2022.
//

#include "StringUtil.h"
#include "../exception/UnsupportedValutaException.h"

StringUtil::StringUtil() = default;

string StringUtil::getValutaValue(Valuta valuta) {
    switch (valuta) {
        case Valuta::EUR:
            return "EUR";
        case Valuta::RSD:
            return "RSD";
        case Valuta::USD:
            return "USD";
        default:
            return "";
    }
}

Valuta StringUtil::ValutaValueOf(const string& valuta) {
    if (valuta == "EUR") {
        return Valuta::EUR;
    } else if (valuta == "RSD") {
        return Valuta::RSD;
    } else if (valuta == "USD") {
        return Valuta::USD;
    } else {
        UnsupportedValutaException unSupportedValutaException;
        throw unSupportedValutaException;
    }
}
