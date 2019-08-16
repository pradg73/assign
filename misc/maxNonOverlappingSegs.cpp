#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#if 0
struct Line
{
    Line(int _s, int _e): s(_s), e(_e){}
    int s;
    int e;
};

struct customLess{
    bool operator()(const Line& l1, const Line& l2) const
    {
        return l1.s < l2.s;
    }
} ;

int solution(vector<int> &A, vector<int> &B)
{
    size_t N = A.size();
    vector<Line> byEnd;
    byEnd.reserve(N);
    for (size_t i = 0; i < A.size(); ++i)
    {
        byEnd.emplace_back(Line(A[i],B[i]));
    }

    vector<Line> byStart = byEnd;

    std::sort(byStart.begin(), byStart.end(), customLess());

    cout << "by end \n";
    for (auto s : byEnd)
    {
        cout << s.s << "," << s.e << "\n";
    }

    cout << "by start \n";
    for (auto s : byStart)
    {
        cout << s.s << "," << s.e << "\n";
    }
}
#endif

int solution(vector<int> &A, vector<int> &B)
{
    size_t N = A.size();
    vector<bool> isValid(N);
    std::fill(isValid.begin(), isValid.end(), true);

    int d = 0;

    for(int i = 0; i < N; ++i)
    {
        if (isValid[i])
        {
            d++;
            for (int j = i+1; j < N; ++j)
            {
                if (A[j] <= B[i]) // jth start time is before ith end time
                {
                    isValid[j] = false;
                }
            }
        }
    }

    for (bool b: isValid)
        cout << b << " ";
    cout << '\n';


    return d;
}

int main(int argc, char* argv[])
{
    vector<int> A = {1,3,7,9,9};
    vector<int> B = {5,6,8,9,10};
    cout << solution(A,B) << "\n";

    return 0;
}
