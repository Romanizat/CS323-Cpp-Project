//
// Created by Marko on 04/06/2022.
//

#include "FileUtil.h"
#include <fstream>

using namespace std;

void FileUtil::writePacijentToFile(const string filename, Pacijent &pacijent) {
    ofstream file;
    file.open(filename, ios::app);
    file << pacijent.getLbo() << "~" << pacijent.getDijagnoza() << "~" << pacijent.getDatumOvereKnjizice() << endl;
    file.close();
}

FileUtil::FileUtil() = default;
