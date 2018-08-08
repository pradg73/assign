//https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/monk-visits-coderland-4/
#include <bits/stdc++.h>
using namespace std;

struct Calc
{
    int N;
    vector<int> c;
    vector<int> l;

    // step i, Petrol with me, Total petrol required
    int minc(int i, int P, int T)
    {
        cout << i << " " << P << " " << T << "\n";
        if (i == N) return 0;

        int r = max(0, l[i] - P); // min required

        int mi(INT_MAX);
        for (int b = r; b <= T; ++b)
        {
            int cost = b*c[i] + minc(i+1, P+b-l[i], T-b);
            mi = min(mi, cost);
        }
        return mi;
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
        copy_n(istream_iterator<int>(cin), c.N, back_inserter(c.c));
        copy_n(istream_iterator<int>(cin), c.N, back_inserter(c.l));

        t = 0;
        for (int l: c.l)
            t += l;

        cout << c.minc(0, 0,t) << "\n";
    }
    return 0;
}
