#include <iostream>
using namespace std;

int main(void)
{
    int N = 5;

    for (int g = 1; g <= N; ++g)
    {
        cout << "--\n";
        for (int j = 1; j <= N; j += g)
        {
            for (int k = j; k < j+g; ++k)
            {
                cout << k << ' ';
            }
            cout << '\n';
        }

    }
    return 0;
}
