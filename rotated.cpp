#include <iostream>
#include <vector>
#include <algorithm>
//#include <random>
#include<cstdlib>
#include <ctime>
#include <chrono>
#include <random>
#include<cassert>


using namespace std;

int bs(vector<int> &v, int t)
{
    size_t N(v.size());
    size_t l(0), r(N-1);

    while (l <= r)
    {
        size_t m = l +((r-l)/2);

        cout << "l " << l << " r " << r << " m " << m << endl;
        assert(l >= 0);
        assert(r < N);
        assert( 0 <= m && m < N);

        if (v[m] == t) return m;

        if (v[m] < t )
            l = m+1;
        else
            r = m-1;
    }
    return -1;
}

int pivot(vector<int> &v)
{
    size_t N(v.size());
    size_t l(0), r(N-1);

    if (v[l] < v[r] || N == 1) // no rotation
        return -1;

    while (l <= r)
    {
        size_t m = l +((r-l)/2);

        cout << "l " << l << " r " << r << " m " << m << endl;
        assert(l >= 0);
        assert(r < N);
        assert( 0 <= m && m < N);

        if (v[m] > v[m+1]) return m;

        if (v[m] > v[0] )
            l = m+1;
        else
            r = m-1;
    }
    return -1;
}

int main(int argc, char*argv[])
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::mt19937 generator (seed);  // mt19937 is a standard mersenne_twister_engine
    //std::cout << "Random value: " << generator() << std::endl;


    vector<int> v;
    int n = 50;

    if (argc > 1)
        n = atoi(argv[1]);

    for (int i = 0; i < n;++i)
        v.push_back(generator());
    //    srand(time(NULL));

    for (const int i: v)
        cout << i << ' ';
    sort(v.begin(),v.end());

    cout << "\nsorted";
    int j = 0;
    for (const int i: v)
        cout << i << "[" << j++ << "]" << ' ';
    cout << endl;

    int t = v[generator()%n];
    if (argc > 2)
    {
        cout << "enter the number to find: ";
        cin >> t;
    }

    size_t i = bs(v,t);
    if (i == -1)
        cout << "not found\n";
    else
    {
        cout << t << " is at " << i << endl;
        cout << "check " << v[i] << endl;
        cout << "log2 " << log2(n) << endl;
    }

    cout << t << " via std bs" << binary_search(v.begin(), v.end(), t);

    int r = generator()%(n-1);
    cout << "rotation by " << r << "\n";
    std::rotate(v.begin(), v.begin() + r, v.end());
    j = 0;
    for (const int i: v)
        cout << i << "[" << j++ << "]" << ' ';
    cout << endl;

    int p = pivot(v);
    cout << "pivot at " << p << endl;

    bool b;
    if (t < v[0])
        b = binary_search(v.begin()+p, v.end(), t);
    else
        b = binary_search(v.begin(), v.begin()+p, t);

    cout << "search result " << b << endl;
}
