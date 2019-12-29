//https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
#include <bits/stdc++.h>

using namespace std;


bool checksame(string& a, string& b){
    int N = a.size();
    for (int i = 0; i < N; ++i){
        if (b[i] == '-') continue;
        if (tolower(a[i]) != tolower(b[i])) return false;
    }
    return true;
}

bool check(string& a, string& b) {
    int N = a.size() - b.size();

    string spaces;
    {
        ostringstream ss;
        for (int i =0; i < N; ++i)
            ss << '-';
        spaces = ss.str();
    }
    for (int i = 0; i < b.size(); ++i){
        string bx = b.substr(0,i) + spaces + b.substr(i,b.size()-i);
        cerr << bx << '\n';
        //assert(a.size() == bx.size());
        //cout << a.size() << "," << bx.size() << '\n';
        if (checksame(a,bx)) return true;
    }
    return false;
}

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    if (a.size() > b.size()){
        return check(a,b) ? "YES" : "NO";
    }else{
        return check(b,a) ? "YES" : "NO";
    }

}
