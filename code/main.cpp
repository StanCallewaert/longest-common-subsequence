#include "lcs.h"

#include <iostream>
#include <string>

using std::cout;
using std::string;

int main(int argc, char** argv) {
    string a = "louis";
    string b = "aloysius";
    
    cout << Lcs::longest_common_subsequence(a, b);
    
    return 0;
}

