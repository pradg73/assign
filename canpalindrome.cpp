#include <iostream>
#include <bits/stdc++.h>

using namespace std;

using iter = string::iterator;
int maxd(0);

bool canpal(iter i, iter j, int d){
  string si{i,next(j)};
  //cout << "got s " << si << ' ' << d << '\n';

  if (d > maxd) return false;
  iter is(i), js(j);
  while(i < j){
    if (*i != *j) return canpal(i+1,j,d+1) || canpal(i,j-1,d+1);
    ++i;--j;
  }
  string s{is,next(js)};
  cout << "true  " << s << '\n';
  return true;
}

// To execute C++, please define "int main()"
int main() {

  string s("waterrfetawx");
  maxd = 2;
  bool b = canpal(s.begin(),prev(s.end()),0);
  cout << "ret " << b << endl;
  return 0;
}
