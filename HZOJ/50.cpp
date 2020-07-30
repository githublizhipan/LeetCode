/*************************************************************************
	> File Name: 50.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月12日 星期二 18时54分30秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 32
#define MAX_M 10000
int dp[MAX_N + 5][MAX_M + 5];
int f[MAX_N + 5][MAX_M + 5];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1) {
                dp[i][j] = j;
                f[i][j] = 1;
                continue;
            }
            dp[i][j] = j;
            f[i][j] = 1;
            for (int k = 1; k <= j; k++) {
                int val = 1 + max(dp[i - 1][k - 1], dp[i][j - k]);
                if (val < dp[i][j]) {
                    f[i][j] = k;
                    dp[i][j] = val;
                }
            }
        }
    }
    cout << dp[n][m] << endl;
    int p = f[n][m], sum = 0;
    while (sum < m) {
        cout << sum + f[n][m - sum] << " ";
        sum += f[n][m - sum];
    }
    cout << f[n][m] << endl;
    return 0;
}
