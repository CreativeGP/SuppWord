/* ========================================================================
   $File: divide.cpp $
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
#include <algorithm>
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

int main() {
    ifstream ifs("buta.dic");

    if (!ifs) return -1;
    
    stringstream ss;
    ss << ifs.rdbuf();
    ifs.close();

    string dic_str(ss.str());

    vector<string> dic = split(dic_str, '\n');

    wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
    int counter = 2;
    bool exit = true;
    for (int counter = 2; ; ++counter) {
        const string filename("h"+to_string(counter));
        vector<string> pack;
        exit = true;
        ofstream ofs(filename);

        for (auto e : dic) {
            if (conv.from_bytes(e).size() == counter) {
                if (e.find("ん") != std::string::npos ||
                    e.find("ー") != std::string::npos) {
                    continue;
                }
                pack.push_back(e);
                exit = false;
            }
        }

        sort(pack.begin(), pack.end());

        for (auto e : pack) ofs << e << endl;

        ofs.close();
        if (exit) break;
    }

    return 0;
}
