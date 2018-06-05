// https://codefights.com/challenge/EExivsGzRjHjcjA8y
#include <bits/stdc++.h>
using namespace std;

typedef std::vector<int>::iterator Iter;

int zsums(size_t b, size_t e, std::vector<int>& t)
{
    int sum(0); int count(0);
    for(size_t i = b; i != e; ++i)
    {
        sum += t[i];
        if (sum == 0)
            count++;
    }
    return count;
}

typedef std::unordered_map<size_t,int> EndCache;
typedef std::unordered_map<size_t,EndCache> Cache;
typedef std::vector<bool> IsIn;

Cache cache;
IsIn isInB, isInE;

int maxp(size_t b, size_t e, std::vector<int>& t)
{
    Cache::iterator ci = cache.find(b);
    if (ci != cache.end())
    {
        EndCache::iterator cj = ci->second.find(e);
        if (cj != ci->second.end())
        {
            return cj->second;
        }
    }
    //if(isInB[b] && isInE[e])
    //    return cache[b][e];

    int maxl = zsums(b,e, t);
    for(size_t i = b+1; i != e; ++i)
    {
        maxl = max(maxp(b,i,t) + maxp(i,e,t), maxl);
    }
    cache[b][e] = maxl;
    //    isInB[b] = isInE[e] = true;
    return maxl;
}

int zeroProfitPeriods(std::vector<int> t) {
    return maxp(0,t.size(),t);
}

int main(void)
{
    isInB.resize(pow(10,5),false);
    isInE.resize(pow(10,5),false);

    std::vector<int> t = //{1, 1, 2, -3, 0, 1000, 6, -6, 1, 1, 1, -3, 2};
         {1, 1, -2, -2, -2, 1, 1, 1, -2, 1, -2, 1, 1, 1, -2, 1, 1, 1, 1, 1, 1, -2, -2, 1, 1, 1, -2, 1, 1, -2};
    cout << zeroProfitPeriods(t) << endl;
    return 0;
}
