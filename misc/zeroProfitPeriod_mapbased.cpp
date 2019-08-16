typedef std::vector<int>::iterator Iter;

int zsums(Iter b, Iter e)
{
    int sum(0); int count(0);
    for(Iter i = b; i != e; ++i)
    {
        sum += *i;
        if (sum == 0)
            count++;
    }
    return count;
}

typedef std::map<std::pair<Iter,Iter>,int > Cache;
Cache cache;

int maxp(Iter b, Iter e)
{
    Cache::const_iterator ci = cache.find(make_pair(b,e));
    if (ci != cache.end())
    {
        return ci->second;
    }

    int maxl = zsums(b,e);
    for(Iter i = b+1; i != e; ++i)
    {
        maxl = max(maxp(b,i) + maxp(i,e), maxl);
    }
    cache[make_pair(b,e)] = maxl;
    return maxl;
}

int zeroProfitPeriods(std::vector<int> t) {
    return maxp(t.begin(),t.end());
}
