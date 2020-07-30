/*************************************************************************
	> File Name: 41.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月28日 星期二 23时41分30秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 1000


BigInt f[MAX_N + 5];

int main() {
    int n, k;
    cin >> n >> k;
    f[1] = k;
    f[2] = k * (k - 1);
    f[3] = k * (k - 1) * (k - 2);
    for (int i = 4; i <= n; i++) {
        f[i] = f[i - 1] * (k - 2) + f[i - 2] * (k - 1);
    }
    
    cout << f[n] << endl;

    return 0;
}
