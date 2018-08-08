#include <queue>
#include <iostream>
#include<cassert>
#include <vector>
#include <algorithm>

using namespace std;

/**
https://momath.org/home/varsity-math/varsity-math-week-121/
Novak, Roger, and Rafa play an exhibition in which two play a set and the winner stays on court to play the waiting player. At the end of the event, Rafa has played 15 sets, Roger has played 14 sets, and Novak has played 9 sets.

What pair played in set number 13?
 **/

struct S
{
    bool a;
    bool b;
    bool c;
    int ap;
    int bp;
    int cp;
    S* p; //parent
};

ostream& operator << (ostream& ostr, const S& s)
{
    ostr << s.a << ", " << s.b << ", " << s.c << ", "
         << s.ap << ", " << s.bp << ", " << s.cp << "\n";
}

int main(int argc, char*argv[])
{
    queue<S*> v;
    v.push(new S{1,1,0,15,14,9,0});
    v.push(new S{1,0,1,15,14,9,0});
    v.push(new S{0,1,1,15,14,9,0});

    while(1)
    {
        S* k = v.front();
        v.pop();

        /*
        */

        if (k->ap == 0 && k->bp == 0 && k->cp == 0)
        {
            cout << "found\n";

            int c = 0;
            for (S* i = k; i != nullptr; i =  i->p)
            {
                cout << c << ":" << *i;
                if (c++ == 13)
                    cout << "*";
            }

            break;
        }
        if (k->ap <  0 || k-> bp < 0 || k->cp < 0)
            continue;

        if (k->a == true and k->b == true)
        {
            // c lost previously against a
            v.push(new S{1,0,1,k->ap-1, k->bp-1, k->cp, k});
            // c lost previously against b
            v.push(new S{0,1,1,k->ap-1, k->bp-1, k->cp, k});
        }
        else if (k->c == true and k->b == true)
        {
            // a lost previously against c
            v.push(new S{1,0,1,k->ap, k->bp-1, k->cp-1, k});

            // a lost previously against b
            v.push(new S{1,1,0,k->ap, k->bp-1, k->cp-1, k});
        }
        else if (k->c == true and k->a == true)
        {
            // b lost previously against c
            v.push(new S{0,1,1,k->ap-1, k->bp, k->cp-1,k});

            // b lost previously against a
            v.push(new S{1,1,0,k->ap-1, k->bp, k->cp-1, k});

        }
        else assert("error " && false);
    }
}
