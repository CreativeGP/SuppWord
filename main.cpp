/* ========================================================================
   $File: main.cpp $
   $Date: Feb 02 2019 $
   $Revision: $
   $Creator: Creative GP $
   $Notice: (C) Copyright 2019 by Creative GP. All Rights Reserved. $
   ======================================================================== */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <codecvt>
#include <locale>
using namespace std;

typedef unsigned int uint;

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

vector<vector<string>> dic;


void load_dictionary() {
    for (int i = 0; i <= 9; i++) {
        ifstream ifs("h"+to_string(i));
        if (!ifs) continue;
    
        stringstream ss;
        ss << ifs.rdbuf();
        ifs.close();

        dic.push_back(split(ss.str(), '\n'));
    }
}

void check_low_level(int target) {
    
}

int main(int argc, char** argv) {
    if (argc != 2) return -1;

    const int target = atoi(argv[1]);

    load_dictionary();

    

    return 0;
}
