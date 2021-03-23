#include "stdio.h"
#include <iostream>
#include <vector>
using namespace std;
void maxPairWise(){ //slow one
    cout << "MaxPairWise , insert n and numbers" << endl;
    int n;
    cin >> n;
    vector<int> vectorNumber;
    for (int i = 0; i < n; i++){
        int j;
        cin >> j;
        vectorNumber.push_back(j);
    }
    int res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            else{
                res = (vectorNumber[i]*vectorNumber[j] > res) ? vectorNumber[i]*vectorNumber[j] : res;
            }
        }
    }
    cout << "result : " << res << endl;
}
void maxPairWiseFast(){ //fast one
    cout << "MaxPairWiseFast , insert n and numbers" << endl;
    int n;
    cin >> n;
    int max1 = 0,max2 =0;
    for (int i = 0; i < n; i++){
        int j;
        cin >> j;
        if (j > max1){
            max2 = max1;
            max1 = j;
        }
        else if(j > max2){
            max2 = j;
        }
    }
    cout << "result : " << max1*max2<< endl;
}


int main(){
    maxPairWise();
    return 0;
}
