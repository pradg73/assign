#include <bits/stdc++.h>
using namespace std;
// Q compute the longest valid word. given dict
//g++ -g -O0 -std=c++17 scrabble.cpp
struct Node
{
    typedef shared_ptr<Node> Ptr;
    char c {'\0'};
    bool term {false};
    unordered_map<char, Ptr> childs;
};

void initTrie(Node::Ptr &r, const vector<string>& dict)
{
    for (const string& w : dict)
    {
        Node::Ptr i = r;
        for (const char c: w)
        {
            Node::Ptr& p = i->childs[c];

            if (!p)
                p = Node::Ptr (new Node{c});
            i = p;
        }
        i->term = true;
    }
}

struct Find
{
    unordered_map<char, bool> h;
    string ans;
    string find(const Node::Ptr&n, const string& in)
    {
        for (const char c : in) h[c] = false;

        for (const auto& k : n->childs)
        {
            vector<char> path;
            dfs(k.second, path);
        }

        return ans;
    }

    void dfs(const Node::Ptr&n, vector<char> path)
    {
        auto it = h.find(n->c);
        if (it != h.end())
        {
            if (it->second == false)
            {
                path.push_back(n->c);

                if (n->term == true)
                {
                    string s{path.begin(), path.end()};
                    if (s.size() > ans.size())
                    {
                        ans = s;
                    }
                }
                it->second = true;
                for (const auto& k : n->childs)
                {
                    dfs(k.second, path);
                }
                it->second = false;
            }
        }
    }

};

int main(int argc, char** argv)
{
    const vector<string> dict = {
      "bear", "are", "ear", "care", "cares", "a", "zesbqrvac"
    };

    Node::Ptr root = Node::Ptr (new Node);
    initTrie(root, dict);

    Find f;
    if (argc > 1)
        cout << f.find(root, argv[1]) << endl;
}
