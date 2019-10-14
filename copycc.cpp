#include<vector>
#include <iostream>

using namespace std;

struct Foo
{
    int i;
    Foo(): i(5) {}
};

int main()
{
    vector<Foo> v;
    Foo f;
    f.i = 6;

    v.emplace_back(f);

    cout << v.back().i << endl;
    return 0;
}
