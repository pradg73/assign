#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    vector<int> v = {4,5,1,2,3};
    
    int i = 0, n = v.size()-1;
    int j = n;

    int m = -1;
    while (i <= j){
        m = i+ (j-i)/2;
        cout << i << ", " << j << ", " << m <<'\n';
        if (v[m] < v[m-1] && v[m] < v[m+1]){
            cout << "found m " << m << "\n";
            break;
        }

        if (v[0] > v[n]){
            i = m+1;
        }else{
            j = m-1;
        }
    }
    cout << v[m] << "\n";
    return 0;
}
/**
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. Find the minimum element in O(log N) time. You may assume the array does not contain duplicates.

For example, given [5, 7, 10, 3, 4], return 3.
*/
