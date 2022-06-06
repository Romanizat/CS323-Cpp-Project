//
// Created by Marko on 06/06/2022.
//

#include <regex>
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

bool StringUtil::isValidDate(const string& datumOvereKnjizice) {
    return regex_match(datumOvereKnjizice,
                       regex("(^(((0[1-9]|1[0-9]|2[0-8])[\\/](0[1-9]|1[012]))|((29|30|31)[\\/](0[13578]|1[02]))|((29|30)[\\/](0[4,6,9]|11)))[\\/](19|[2-9][0-9])\\d\\d$)|(^29[\\/]02[\\/](19|[2-9][0-9])(00|04|08|12|16|20|24|28|32|36|40|44|48|52|56|60|64|68|72|76|80|84|88|92|96)$)"));
}
