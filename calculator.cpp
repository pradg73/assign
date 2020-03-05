#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){

    unordered_map<char,int> prio = {
        {'+', 0},
        {'*', 1}
    };

    auto less =
        [&](char l, char r){
            return prio[l] < prio[r];
        };

    auto isOp =
        [&](char c){
            return prio.find(c) != prio.end();
        };

    auto eval =
        [](int v1, int v2, char Op){
            cout << "eval " << v1 << ", " << v2 << ", " << Op << '\n';
            switch (Op){
              case '+':
                return v1+v2;
                break;
              case '*':
                return v1*v2;
                break;
              default:
                cout << "error no handled op " << Op << "\n";
                return 0;
            }
        };

    stack<int> val; stack<char> op;

    auto reduce =
        [&](){
            while(op.size()){
                char opr = op.top();
                op.pop();
                int v1 = val.top(); val.pop();
                int v2 = val.top(); val.pop();
                val.push(eval(v1,v2,opr));
            }
        };

    string exp = argc > 1 ? argv[1] : "2*1+5";

    for (char c : exp){
        if (!isOp(c)){
            val.push(c-'0');
        }else{
            if (op.size() == 0){
                op.push(c); continue;
            }
            char prevOp = op.top();
            if (less(c, prevOp)){ // e.g. + after *
                reduce();
            }
            op.push(c);
        }
    }
    reduce();
    cout << val.top() << '\n';
    return 0;
}
