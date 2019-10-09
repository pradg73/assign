#include <bits/stdc++.h>
using namespace std;

class Solution {
    size_t Rows;
    size_t Cols;
    vector<vector<char>>* board;
    vector<vector<bool>> inuse;
    bool found {false};
    size_t N;
    string word;
    size_t W;
public:
    void check(size_t r, size_t c, size_t i)
    {
        cout << r << ' '
            << c << ' ' << i
            << ' ' << Rows
            << ' ' << Cols
            << ' ' << W
            << endl;
        if (found == true) return;

        inuse[r][c] = true;

        if ((*board)[r][c] == word[i]) // found the char
        {
            if (i == W-1)
            {
                found = true;
                return;
            }

            if (i+1 == W) return;

            if (c+1 < Cols)
            {
                if (inuse[r][c+1] == false)
                check(r,c+1,i+1);
            }
            if (c > 0)
            {
                if (inuse[r][c-1] == false)
                check(r,c-1,i+1);
            }

            if (r > 0)
            {
                if(inuse[r-1][c] == false)
                check(r-1,c,i+1);
            }
            if (r+1 < Rows)
            {
                if(inuse[r+1][c] == false)
                check(r+1,c,i+1);
            }

        }
        inuse[r][c] = false;

    }
    bool exist(vector<vector<char>>& _board, string _word) {
        word = _word;
        W = word.size();

        board = &_board;
       Rows =  _board.size();
       Cols = _board[0].size();

        N = Rows*Cols;

        vector<bool> brow; brow.resize(Cols);
        inuse.resize(Rows);
        for (auto & r:inuse) r = brow;

        cout << inuse.size() << ' ' << inuse[0].size() << endl;
        check(0,0,0);
        return found;
    }
};

int main(void)
{
    vector<vector<char>> b =
        {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

    Solution s;
    cout << s.exist(b,"ABCCED")<< endl;
    return 0;
}
