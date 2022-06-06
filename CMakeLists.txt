cmake_minimum_required(VERSION 3.21)
project(CS323_Projekat2_MarkoJosifovic4494)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS323_Projekat2_MarkoJosifovic4494 main.cpp entity/Osoba.cpp entity/Osoba.h entity/Lekar.cpp entity/Lekar.h exception/InvalidGodStazaException.cpp exception/InvalidGodStazaException.h entity/Pacijent.cpp entity/Pacijent.h exception/InvalidDatumException.cpp exception/InvalidDatumException.h util/FileUtil.cpp util/FileUtil.h entity/enum/Valuta.cpp entity/enum/Valuta.h util/StringUtil.cpp util/StringUtil.h)
