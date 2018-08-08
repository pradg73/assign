#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Mtg;
bool compare(const Mtg &r, const Mtg &l);

struct Mtg
{
    Mtg(int _start, int _end)
    : start(_start)
    , end(_end)
    {

    }
    int start;
    int end;

    bool operator< (const Mtg& l) const
    {
        return compare(*this, l);
    }
};

bool overlap(const Mtg& r, const Mtg& l)
{
    if (r.start <= l.start && r.end <= l.start)
        return false;
    if (r.start >= l.start && r.end >= l.start)
        return false;
    return true;
}
bool compare(const Mtg &r, const Mtg &l)
{
    if (overlap(r,l))
        return false;

    if (r.start != l.start)
        return r.start < l.start;

    return r.end < l.start;
}

typedef vector<Mtg> Mtgs;
typedef map<Mtg, Mtgs> Eq;
Eq eq;

int main(int argc, char*argv[])
{
    int n;
    cin >> n;
    //    vector<Mtg> mtgs;

    for (int i = 0; i < n; ++i)
    {
        int start, end;
        cin >> start >> end;
        Mtg meeting(start,end);
        vector<Mtg>& vm = eq[meeting];
        vm.push_back(meeting);
    }
    cout << n;
    for (const auto&kv: eq)
    {
        cout << "\noverlapping " << kv.second.size() << ":";
        for (const auto&m: kv.second)
            cout << m.start << "," << m.end << "|";

    }

    return 0;
}
