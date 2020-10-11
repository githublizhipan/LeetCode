/*************************************************************************
	> File Name: 77.大整数乘方.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sun Oct 11 11:55:53 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, ans[1000000] = {1, 1};

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= ans[0]; j++) {
            ans[j] *= m;
        }
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (j == ans[0]);
        }
    }
    for (int i = ans[0]; i > 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
