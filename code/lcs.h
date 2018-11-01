#ifndef LCS_H
#define LCS_H

#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::max;

class Lcs {
    public:
        static string longest_common_subsequence(string& a, string& b);
};

string Lcs::longest_common_subsequence(string& a, string& b) {
    // Declare 2D vector with sizes of strings+1 because
    // a starting border of zeros is necessary to be able to write clean code
    vector<vector<int>> lcs(a.length()+1, vector<int>(b.length()+1));
    
    // Initialize vertical zero border
    for (int i=0; i<=a.length(); i++) {
        lcs[i][0] = 0;
    }
    
    // Initialize horizontal zero border
    for (int j=1; j<=b.length(); j++) {
        lcs[0][j] = 0;
    }
    
    // If equal character add one to lcs[i-1][j-1]
    // If not equal character pick the max of the value on top or left
    // These for loops calculate the length of the Longest Common Subsequence
    for (int i=1; i<=a.length(); i++) {
        for (int j=1; j<=b.length(); j++) {
            if (a[i-1] == b[j-1]) {
                lcs[i][j] = lcs[i-1][j-1]+1;
            } else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    
    string lcs_str = "";
    int i = a.length();
    int j = b.length();
    
    // By backpropagating from the end of the 2D vector, 
    // the Longest Common Subsequence can be found
    while (i != 0 && j != 0) {
        if (lcs[i][j] == lcs[i][j-1]) {
            j--;
        } else {
            if (lcs[i][j] == lcs[i-1][j]) {
                i--;
            } else {
                lcs_str = a[i-1] + lcs_str;
                i--; j--;
            }
        }
    }
    
    return lcs_str;
}

#endif