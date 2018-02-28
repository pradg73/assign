#include <iostream>
#include <string>

using namespace std;

bool check(const string& l)
{
    for (char c: l)
    {
        if (c == '-') return false;
    }

    return true;
}

int numf (const string& s, int b, int e)
{

}

int main ()
{
    string s = "---+-++-";
    int l = 3;

    int N = s.length();


}
