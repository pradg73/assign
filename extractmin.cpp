//extract min
#include <bits/stdc++.h>
using namespace std;

struct MinS{

    stack<int> orders;
    multiset<int> minmap, delmap;

    void addOrder(int i){
        orders.push(i);
        minmap.insert(i);
    }

    int executeOrder(){
        int i = orders.top();
        orders.pop();
        delmap.insert(i);
        return i;

    }

    int extractMin(){

        while(1){
        auto itm = minmap.begin();

        auto itd = delmap.find(*itm);

        if (itd != delmap.end()){
            minmap.erase(itm); delmap.erase(itd);
        }else{
            return *itm;
        }
        }
    }

};

int  main(){

    MinS s;
    /*
    addOrder(13), addOrder(11), addOrder(9), addOrder(20)
extractMin() -> 9

executeOrder() -> 20
extractMin() -> 9

executeOrder() -> 9
extractMin() -> 11

addOrder(11)
extractMin() -> 11

executeOrder() -> 11
extractMin() -> 11

executeOrder() -> 11
extractMin() -> 13

executeOrder() -> 13*/

    s.addOrder(13);
    s.addOrder(11);
    s.addOrder(9);
    s.addOrder(20);

    cout << s.extractMin() <<  '\n';// -> 9

    cout << s.executeOrder() << '\n'; //-> 20
    cout << s.extractMin() << '\n'; // -> 9

    cout << s.executeOrder() << '\n'; // -> 9
    cout << s.extractMin() << '\n'; //-> 11

    s.addOrder(11);
    cout << s.extractMin() << '\n'; // -> 11

    cout << s.executeOrder() << '\n'; //-> 11
    cout << s.extractMin() << '\n'; //-> 11

    cout << s.executeOrder() << '\n'; //-> 11
    cout << s.extractMin() << '\n'; //-> 13

    cout << s.executeOrder() << '\n'; //-> 13
    return 0;
}
