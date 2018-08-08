#include <iostream>
#include <string>

using namespace std;

bool check(const string& l, int b = 0, int e = l.length())
{
    for (char c: l)
    {
        if (c == '-') return false;
    }

    return true;
}

int numf (const string& s, int f, int b, int e)
{
    if(check(s)) return 0;

    int min
    for (int i = b; i+f < e; ++i)
    {
        if(check(s,i,i+f)) // (i, i+f]
        {
            return numf(s,i+f,e);
        }
        else
        {
            // flip i,i+f
        }
    }
}

int main ()
{
    string s = "---+-++-";
    int f = 3;

    int N = s.length();

    cout << numf (s, f, 0, N) << endl;
}
