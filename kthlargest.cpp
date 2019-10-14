#include <bits/stdc++.h>
using namespace std;

#if 0
<<<<<<< HEAD
int main(int argc, char*argv[])
{
    istringstream in (argv[1]);
    vector<int> v;
    while(!in.eof())
    {
        int i;
        in >> i;
        v.emplace_back(i);
    }

    for (int i : v)
    {
        cout << i << " ";
    }
=======
#endif

ostream& operator<<( ostream &oss, const vector<int> &v)
{
    for (int k: v) oss << k << ',';
    return oss;
}

class Solution {
public:
    int* a;

    void swap(int i, int j)
    {
        int tmp = *(a+i);
        *(a+i) = *(a+j);
        *(a+j) = tmp;
    }

    int part(int s, int N)
    {
        cout << "part l " << s << ", N " << N << endl;
        int piv = a[s];
        int i = s+1;

        for (int j = s+1; j < N; ++j)
        {
            if (a[j] < piv)
            {
                swap(i,j);
                i++;
            }
        }
        swap(i-1,s);
        return i-1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        a = nums.data();
        int N = nums.size();
        int l = 0;
        int p = part(l,N);
        int t = N-k;
        cout << "finding index " << t << endl;
        while (p != t)
        {
            cout << "p " << p << " v " << nums << endl;
           if (p < t)
           {
               l = p+1;
               p = part(l, N);
           }
           else
           {
               N = p-1;
               p = part(l,N);
           }
        }
        return nums[p];
    }


};

int main(int argc, char*argv[])
{
    vector<int> v = {3,8,2,5,1,4,7,6};
    Solution s;
    int k = atoi(argv[1]);
    int a = s.findKthLargest(v, k);
    cout << "kth " << k << " is " << a << endl;

    return 0;
}
