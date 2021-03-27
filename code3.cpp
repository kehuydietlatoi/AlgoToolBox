#include "stdio.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
void solve() {
    int N,C;
    int res = 0;
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
    int MAX = N;
    for (auto i = 0; i < N-1; i++) {
        if(C >= N-1 -i){ //too big
            std::vector<int>::iterator itBig = find (v.begin(), v.end(), MAX);
            std::vector<int>::iterator itSmall = find (v.begin(), v.end(), i+1);
            for (auto it = v.begin(); it != v.end(); ++it) {
                if (*it == *itSmall) {
                    std::reverse(itSmall,itBig+1);break;
                }
                if (*it == *itBig) {
                    std::reverse(itBig,itSmall+1);break;
                }
            }
            C = C - (N-1-i);
        }
        else if (C < N -1-i){
            std::vector<int>::iterator itBig = find (v.begin(), v.end(), MAX);
            std::vector<int>::iterator itSmall = find (v.begin(), v.end(), MAX-C);
            for (auto it = v.begin(); it != v.end(); ++it) {
                if (*it == *itSmall) {
                    std::reverse(itSmall,itBig+1);break;
                }
                if (*it == *itBig) {
                    std::reverse(itBig,itSmall+1);break;
                }
            }
            C = 0;break;
        }
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
