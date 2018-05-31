#include <bits/stdc++.h>
using namespace std;

void print(auto& v)
{

    for (auto vi : v)
    {
        for (auto i: vi)
            cout << i << " ";
        cout << "\n";
    }

}
struct Visitor
{
    std::vector<std::vector<int>>& cons;
    size_t N;

    Visitor(std::vector<std::vector<int>> &_connections):
    cons(_connections), N(cons.size()){ print(cons);}

    std::queue<int> q;
    std::set<int> visited;
    int visit (int _i, int j) // if cannot reach i to j, return 1 else 0
    {
        cout << "visit " << _i << "," << j << "\n";
        visited.clear();
        queue<int> empty;
        q.swap(empty);

        q.push(_i);

        while(!q.empty())
        {
            int i = q.front(); q.pop();
            visited.insert(i);
            cout << "visiting " << i << endl;
            for (int k = 0; k < N; ++k)
            {
                cout << "check " << i << "," << k << " " << cons[i][k] <<"\n";
                //           cout << "size " << cons->size() << endl;
                // cout << "size i" << (*cons)[i].size() << endl;

                if (cons[i][k] == 0) continue;

                if (k == j) return 0;

                if (visited.find(k) == visited.end())
                {
                    cout << "pushing " << k << endl;
                    q.push(k);
                }
            }
        }
        return 1;
    }
};

int singlePointOfFailure(std::vector<std::vector<int>> &connections) {

    size_t N = connections.size();
    Visitor v(connections);
    int f(0);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (i >= j) continue;
            if (connections[i][j] == 0)
                continue;

            connections[i][j] = 0;
            f += v.visit(i,j);
            cout << "f " << f << endl;
            connections[i][j] = 1;
        }
    return f;
}

int main(void)
{
    std::vector<std::vector<int>> v =
        {{0, 1, 1, 1, 1}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 0}};
    //print (v);

    std::vector<std::vector<int>> v1 ={{0,1},{1,0}};

     std::vector<std::vector<int>> v2 = {{0,1,1},
                                         {1,0,1},
                                         {1,1,0}};

     std::vector<std::vector<int>> v3 =
         {{0,1,1,0,0,0,0},
          {1,0,1,0,0,0,0},
          {1,1,0,0,0,0,1},
          {0,0,0,0,1,1,1},
          {0,0,0,1,0,1,0},
          {0,0,0,1,1,0,0},
          {0,0,1,1,0,0,0}};

    int f = singlePointOfFailure(v3);
    cout << f << endl;
}
