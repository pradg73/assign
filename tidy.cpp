#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

bool isTidy(unsigned long long n)
{
    unsigned long long p = n%10;
    n = n/10;

    if (n == 0) return true;

    while(n)
    {
        unsigned long long k = n%10;
        if (k > p) return false;
        n = n/10;
    }

    return true;
}

template <typename T>
void printlimits(const char* name)
{
    cout << name << " " << numeric_limits<T>::max() << " " << numeric_limits<T>::min() << endl;
}

int main(int argc, char* argv[])
{
    printlimits<int>("int");
    printlimits<unsigned long long>("unsigned long long");
    printlimits<long>("long");
    printlimits<double>("double");
    printlimits<float>("float");

    unsigned long long n = atoi(argv[1]);

    while (n)
    {
        if (isTidy(n)) break;
        n = n-1;
    }

    cout << n << endl;
}
