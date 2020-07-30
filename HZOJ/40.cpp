/*************************************************************************
	> File Name: 40.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 23时11分58秒
 ************************************************************************/

#include<iostream>
using namespace std;

int a[510][1000] = {0};


int main() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    a[2][0] = 1, a[3][0] = 1, a[4][0] = 1;
    a[2][1] = 1, a[3][1] = 1, a[4][1] = 1;
    for(int i = 5; i <= n; ++i) {
        a[i][0] = a[i - 2][0];
        for(int k = 1; k <= a[i][0]; k++) {
            a[i][k] += a[i - 3][k] + a[i - 2][k];
        }
        for(int j = 1; j <= a[i][0]; j++) {
            if(a[i][j] < 10) continue;
            a[i][j + 1] += a[i][j] / 10;
            a[i][j] %= 10;
            a[i][0] += (j == a[i][0]);
        }
    }
    for(int i = a[n][0]; i >= 1; i--) {
        cout << a[n][i];
    }
    cout << endl;
    return 0;
}
