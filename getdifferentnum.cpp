#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getDifferentNumber2( const vector<int>& arr )
{
  vector<int> c = arr;
  sort(c.begin(), c.end());
  int s = c[0];
  if (s != 0)
    return s-1;
  else
  {
    int s = 1;
    for (int i = 1; i < c.size(); ++i)
    {
      if (s != c[i])
        break;
      else s++;
    }
    return s;
  }
}

int getDifferentNumber(  vector<int>& arr )
{
    size_t N = arr.size();
    for (int i = 0; i < N; ++i)
    {
        int k = arr[i];

        if (k < N && arr[k] != k)
            swap(arr[i], arr[k]);
    }

    int s = 0;
    for (int i = 0; i < N; ++i)
    {
        if (s != arr[i])
            break;
        s++;
    }
    return s;
}

int main(int argc, char*argv[])
{
    vector<int> v = {0,5,9};
    cout << getDifferentNumber(v);
}
