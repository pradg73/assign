#include <iostream>
#include <cstdlib>
using namespace std;

bool isTidy(unsigned n)
{
    unsigned p = n%10;
    n = n/10;

    if (n == 0) return true;

    while(n)
    {
        unsigned k = n%10;
        if (k > p) return false;
        n = n/10;
    }

    return true;
}

int main(int argc, char* argv[])
{
    unsigned n = atoi(argv[1]);

    while (n)
    {
        if (isTidy(n)) break;
        n = n-1;
    }

    cout << n << endl;
}
