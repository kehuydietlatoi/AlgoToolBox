#include "stdio.h"
#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n){
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
int fibonacciLastDigits(int n){
    if (n <= 1) return n;
    int n0 = 0;
    int n1 = 1;
    int res;
    for (int i = 2; i <= n; i++) {
        res = n1 + n0;
        res = res%10;
        n0 = n1;
        n1 = res;
    }
    return res;
}
int gcd(int a, int b){
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    if (a > b) return gcd(a-b, b);
    return gcd(a, b-a);
}
size_t lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
// pisano sequence always starts with 0,1 then we can count pair 0,1
size_t pisano(int m){
    int prev =0,curr =1,res =0;
    for (size_t i = 0; i < m*m; i++) {
        int temp = curr;
        curr = (prev+curr)%m;
        prev = temp;
        if (prev == 0 and curr == 1) {
            res = i + 1;
        }
    }
    return res;
}
int fibonacciModulo(size_t n,int m){
    int period = pisano(m);
    n = n%period;
    long prev = 0;
    long curr = 1;
    if (n == 0) return 0;
    else if (n == 1) return 1;

    for(int i = 0; i < n - 1; i++)
    {
        long temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
    }
    return curr % m;

}
int fibonacciSumLastDigit(int n){
    if (n <= 1) return n;
    int n0 = 0;
    int n1 = 1;
    int res = n1 + n0;
    for (int i = 2; i <= n; i++) {
        int temp = (n1 + n0)%10;
        res = (res + temp)%10;
        n0 = n1;
        n1 = temp;
    }
    return res;
}
int fibonacciSumLastDigit2(int n,int m){
    return(fibonacciSumLastDigit(m) + 10 -fibonacciSumLastDigit(n-1))%10;
}
int squareFibo(int n){
    return fibonacciLastDigits(n)*(fibonacciLastDigits(n+1))%10;
}
int main() {
    cout << "n :" << endl;
    int n;
    cin >> n ;
    cout <<"result "<< squareFibo(n) << endl;
    return 0;
}
