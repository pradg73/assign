// https://leetcode.com/explore/interview/card/facebook/53/recursion-3/267/
#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<char>> Ph = {
  {'1',{}},
  {'2', {'a','b','c'}},
  {'3', {'d','e','f'}}
};

class Solution {
  
      void lc(string& digits, long unsigned int i, string sofar, vector<string> & r) {
        
        if (i == digits.size()){
          r.push_back(sofar);
          return;
        }
        
        char d = digits[i];
        
        for (char c : Ph[d]){
          string s = sofar + c;
          lc(digits,i+1,s,r);            
        }
      }
  
public:
    vector<string> letterCombinations(string digits) {
        
      vector<string> r;
      lc(digits,0,"",r);
      return r;
    }
};

// To execute C++, please define "int main()"
int main() {

  Solution sol;
  
  for (auto s: sol.letterCombinations("23")){
    cout << s << ",";
  }
  
  return 0;
}
