#include <bits/stdc++.h>
using namespace std;

char* fix(char* s);

int main(int argc, char* argv[])
{
    char* str(0);
    if (argc > 0)
        str = argv[1];

    cout << str << endl;

    cout << fix(str) << endl;
    return 0;
}

size_t find_first_space(char* s, size_t N, size_t i)
{
    while (i < N && s[i] != ' ') ++i;
    return i;
}

size_t find_first_nospace(char* s, size_t N, size_t i)
{
    while (i < N && s[i] == ' ') ++i;
    return i;
}

void move(char* &s, size_t& N, size_t i, size_t j)
{
    size_t n = j-i;
    size_t d = n;
    while(i+n < N)
    {
        s[i] = s[j];
        i++; j++;
    }
    N -= d;
    s[N] = '\0';
}

char* fix(char* s)
{
    size_t N = strlen(s);

    for (size_t i(0); i < N;)
    {
        size_t j = find_first_space(s,N,i);
        if (j < N)
        {
            size_t k = find_first_nospace(s,N,j);
            if ( k < N)
            {
                move(s,N,j+1,k);
                i = j+1;
            }
            else{
                break;
            }
        }
        else
        {
            break;
        }
    }
    return s;
}
