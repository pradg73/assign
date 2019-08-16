//https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/monk-visits-coderland-4/
#include <bits/stdc++.h>
using namespace std;

struct Calc
{
    int N;
    vector<unsigned long long> c;
    vector<unsigned long long> l;

    unsigned long long minc()
    {
        unsigned long long mc(0);
        unsigned long long lsofar(0);
        for (int i = N-1; i >= 0; --i)
        {
            lsofar += l[i];
            if (i == 0 || c[i-1] > c[i]) // gas station before is more expensive
            {
                mc += c[i]*lsofar;
                lsofar = 0;
            }
        }
        return mc;
    }
};

int main(void)
{
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        Calc c;
        cin >> c.N;

        c.c.reserve(c.N); c.l.reserve(c.N);
        copy_n(istream_iterator<unsigned long long>(cin), c.N, back_inserter(c.c));
        copy_n(istream_iterator<unsigned long long>(cin), c.N, back_inserter(c.l));

        cout << c.minc() << "\n";
    }
    return 0;
}
