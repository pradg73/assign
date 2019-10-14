#include <bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[])
{
    istringstream in (argv[1]);
    vector<int> v;
    while(!in.eof())
    {
        int i;
        in >> i;
        v.emplace_back(i);
    }

    for (int i : v)
    {
        cout << i << " ";
    }
}
