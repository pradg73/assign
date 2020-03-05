#include <bits/stdc++.h>
using namespace std;

int main(void){

    vector<int> a = {5,6,-7,8,3,4,0,1,12};
    int N = a.size();
    int k = a[0];
    // put a[0] in its correct pos
    int i = 1;
    for (int j =1; j < N; ++j){
        if (a[j] < k){
            swap(a[i],a[j]);
            ++i;
        }
    }
    swap(a[i-1],a[0]);

    cout << i-1 << '\n';

    for (int m : a){
        cout << m << ' '; 
    }
    cout << '\n';
    return 0;
}
