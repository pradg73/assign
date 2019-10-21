#include <bits/stdc++.h>
using namespace std;

ostream& operator<<(ostream& ostr, const vector<char>& v)
{
    ostr << '|';
    for (char c: v) ostr << (c == 0 ? ' ' : c);
    ostr << '|';
    return ostr;
}
int main(int argc, char*argv[])
{
    const char* argv1 = argc > 2 ? argv[1] : "kitten";
    const char* argv2 = argc > 2 ? argv[2] : "sitting";

    string s1(argv1), s2(argv2);

    int N = max(s1.size(), s2.size());

    vector<char> v1(N*3);
    vector<char> v2(N*3);

    auto diff = [=](const vector<char> &l, const vector<char> &r)->int
                {
                    cout << l << endl << r << endl << endl;
                    int c(0);
                    for (int i = 0; i < 3*N; ++i)
                    {
                        c += int(l[i] != r[i]);
                    }
                    return c;
                };

    copy(s1.begin(),s1.end(),v1.begin()+N);

    copy(s2.begin(),s2.end(),v2.begin()+N);
    diff(v1,v2);
    int mindiff(INT_MAX);
    if(1) for (int i = 0; i < 2*N; ++i)
    {
        v2.assign(3*N,0);
        auto iv2 = v2.begin()+i;
        copy(s2.begin(),s2.end(),iv2);
        mindiff = min(mindiff,diff(v1,v2));
    }

    cout << s1 << " | " << s2 << ": " << mindiff << endl;
    return 0;
}
