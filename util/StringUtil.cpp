//
// Created by Marko on 06/06/2022.
//

#include "StringUtil.h"

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
