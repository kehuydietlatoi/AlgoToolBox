#include "stdio.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int solve() {
    int x,y;
    int res = 0;
    cin >> x >> y;
    string s;
    getline(cin,s);
    int len = s.size();
    if (len <= 1) return 0;
    auto prev = s[0];
    for (auto i = 1; i < len; i++) {
        if(s[i] == 'C'){
            if(prev == 'J'){
                res += y;
            }
            prev = 'C';
        }
        else if(s[i] == 'J'){
            if(prev == 'C'){
                res += x;
            }
            prev = 'J';
        }
        else{
            //nothin
        }
    }
    return res;
}



int main() {
    int n;
    std::cin >> n;
    std::vector<int> v;
    //v.push_back(1);v.push_back(2);v.push_back(4);v.push_back(5);v.push_back(7);
    for (int i = 1; i <= n; i++) {
        std::cout << "Case #"<<i<<": "<< solve() << '\n';
    }
    return 0;
}
