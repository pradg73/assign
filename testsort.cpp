#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> v = {3, -1, 5, 0,9, 3, 7,0,3, -5};

    sort(v.begin(),v.end(), [](const int&l, const int& r){
                                if (l == 0) return false;
                                if (r ==0) return true;

                                return l < r;
                            });
    for (int i : v)
    {
        cout << i << ',';
    }
}
