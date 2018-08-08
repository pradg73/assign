#include <queue>
#include <iostream>
#include<cassert>

using namespace std;

struct S
{
    int a;
    int b;
    int c;
    S* p; //parent
};

int main(int argc, char*argv[])
{
    queue<S*> v;
    v.push(new S{15,14,9,0});

    while(1)
    {
        S* k = v.front();

        cout << k->a << ", " << k->b << ", " << k->c <<  "\n";
        v.pop();

        if (k->a == 0 && k->b == 0 && k->c == 0)
        {
            cout << "found\n";
            break;
        }

        if (k->a < 0 || k->b < 0 || k->c < 0)
            continue;

        v.push(new S{k->a-1,k->b-1,k->c,k}); // a, b played
        v.push(new S{k->a,k->b-1,k->c-1,k}); // b, c played
        v.push(new S{k->a-1,k->b,k->c-1,k}); // a, c played
    }
}
