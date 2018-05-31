// https://codefights.com/challenge/EExivsGzRjHjcjA8y

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

int maxp(Iter b, Iter e)
{
    int maxl = zsums(b,e);
    for(Iter i = b; i != e; ++i)
    {
        maxl = max(maxp(b,i) + maxp(i,e), maxl);
    }
}

int zeroProfitPeriods(std::vector<int> t) {
    return maxp(t.begin(),t.end());
}
