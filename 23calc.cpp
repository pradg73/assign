#include <bits/stdc++.h>
using namespace std;

int min_steps(INT_MAX);
int t = 10;

unordered_set<int> seen;

void steps(int v, int step)
{
    if (seen.find(v) != seen.end())
    {
        min_steps = 0;
        return;
    }

    seen.insert(v);

    if (v == t){
        min_steps = std::min(min_steps,step);
        return;
    }

    if (v < t)
    {
        steps(v*2, step+1);
    }
     else
    {
        steps(v/3, step+1);
    }
}
int main(int argc, char* argv[])
{
    t = argc > 1 ? atoi(argv[1]) : 10;

    steps(1,0);
    cout << t << " " << min_steps << endl;
}
#if 0
def minNumOfOps(targetNum):
    ops = {1: 0}
    todo = [1]

    while not targetNum in ops:
        while len(todo) > 0:
            base = todo.pop()

            vals = [base * 2, base / 3]
            for val in vals:
                currOps = ops[base] + 1
                if not val in ops or currOps < ops[val]:
                    ops[val] = currOps

        todo = ops.keys()

    return ops[targetNum]
#endif
