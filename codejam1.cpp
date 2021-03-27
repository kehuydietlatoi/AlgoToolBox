#include "stdio.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isTrue(int c,std::vector<int> v ) {
    int n = v.size(),res=0;
    for (int i = 0; i < n-1; i++) {
        int iteMin = i;
        for (int j = i+1; j < n; j++) {
            if (*(std::next(v.begin(), j)) <= *(std::next(v.begin(), iteMin))){
                iteMin = j;
            }
        }
        res += (iteMin-i+1);
        std::vector<int>::iterator it = std::next(v.begin(), iteMin+1);
        std::vector<int>::iterator it1 = std::next(v.begin(), i);
        std::reverse(it1,it);

    }
    return (res == c);
}

void solve() {
    int N,C;
    int res = 0;
    cin >> N >> C;
    int myints[N];
    if (C < N-1) {
        std::cout << " IMPOSSIBLE" << '\n';
        return;
    }
    for(int i = 1; i <= N;i++){
        myints[i-1]=i;
    }
    do {
        std::vector<int> v;
        for(int i = 1; i <= N;i++){
            v.push_back(myints[i-1]);
    
        }
        if (isTrue(C,v)) {
            for(int i = 1; i <= N;i++){
                std::cout << " "<<v[i-1];
            }
            cout    << '\n';return;
        }
    } while(std::next_permutation(myints,myints+N));
    std::cout << " IMPOSSIBLE" << '\n';
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
