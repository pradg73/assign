//https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    std::unordered_set<char> as, bs;
    int aN = a.size();
    int bN = b.size();
    int ai(0),bi(0);

    bool ret(true);
    while (ai < aN && bi < bN){

        for (char ca = a[ai];
         ai < aN && islower(ca); as.insert(ca), ++ai); 
        
        for (char cb = b[bi];
         bi < bN && islower(cb); bs.insert(cb), ++bi); 

        if (ai == aN || bi == bN) break;

        char ca = a[ai];
        char cb = b[bi];

        if (tolower(ca) == tolower(cb)) {
            as.clear(); bs.clear();
            continue;
        }

        if (bs.find(tolower(ca)) == bs.end()){
            ret = false;
            break;
        }
        if (as.find(tolower(cb)) == as.end()){
            ret = false;
            break;
        }
        as.clear(); bs.clear();
    }
    for (;ai < aN && islower(ai);++ai);
    for (;bi < bN && islower(bi);++bi);

    if (ai < aN || bi < bN) ret = false;

    return ret ? "YES" : "NO";
}
//-------
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
