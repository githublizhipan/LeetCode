/*************************************************************************
	> File Name: 38.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月21日 星期二 19时34分33秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;
#define MAX 1005
int main() {
    int a[3][1005] = {0};
    a[0][0] = 1, a[0][1] = 1;
    a[1][0] = 1, a[1][1] = 1;
    int n, i = 1;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= a[(i - 1) % 3][0]; ++j) {
            a[i % 3][j] = a[(i - 1) % 3][j] + a[(i - 2) % 3][j];
        }

        a[i % 3][0] = a[(i - 1) % 3][0];

        for(int k = 1; k <= a[i % 3][0]; k++) {
            if(a[i % 3][k] < 10) continue;
            a[i % 3][k + 1] += a[i % 3][k] / 10;
            a[i % 3][k] %= 10;
            a[i % 3][0] += (k == a[i % 3][0]);
        }
    }
    n %= 3;
    for(int i = a[n][0]; i >= 1; i--) {
        cout << a[n][i];
    }
    cout << endl;
    return 0;
}

/*
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int fib[3][1005] = {0};
    fib[0][0] = fib[0][1] = 1;
    fib[1][0] = fib[1][1] = 1;
    int n = 1, m;
    cin >> m;
    while(n <= m) {
        n++;
        for(int i = 1; i <= fib[(n - 1) % 3][0]; ++i) {
            fib[n % 3][i] = fib[(n - 1) % 3][i] + fib[(n - 2) % 3][i];
        }
        fib[n % 3][0] = fib[(n - 1) % 3][0];
        for(int i = 1; i <= fib[n % 3][0]; i++) {
            if(fib[n % 3][i] < 10) continue;
            fib[n % 3][i + 1] += fib[n % 3][i] / 10;
            fib[n % 3][i] %= 10;
            fib[n % 3][0] += (i == fib[n % 3][0]);
        }
    }
    int t = m % 3;
    for(int i = fib[t][0]; i >= 1; i--) {
        cout << fib[t][i];
    }
    cout << endl;
    return 0;
}
*/
