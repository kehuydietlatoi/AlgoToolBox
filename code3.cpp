#include "stdio.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
void solve() {
    int N,C;
    std::vector<int> v;
    cin >> N >> C;
    if (C < N-1) {
        std::cout << " IMPOSSIBLE" << '\n';
        return;
    }
    for(int i = 1; i <= N;i++){
        v.push_back(i);
    }
    C = C - N + 1;
    for (auto i = N-1; i >=0; i--) {
        int minCost = min(C,N-1-i);
        C -= minCost;
        reverse(v.begin()+i,v.begin()+i+minCost+1);
    }
    if(C != 0){
        std::cout << " IMPOSSIBLE" << '\n'; return;
    }
    for (auto it = v.begin();it!=v.end();++it) {
        std::cout << " "<<*it;
    }
    std::cout << '\n';
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cout << "Case #"<<i<<":";
        solve();
    }
    return 0;
}
