/*************************************************************************
	> File Name: 343.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月30日 星期四 22时12分17秒
 ************************************************************************/

#include<iostream>
using namespace std;
int n, a[3005], b[3005];
int dp[3005][3005];


int main() {
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int j = 1; j <= n; j++) {
        cin >> b[j];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if(a[i] - b[j]) continue;
            dp[i][j] = max(1, dp[i][j]); //.. 
            for (int k = 1; k < i; k++) {
                if (a[k] >= a[i]) continue;
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + 1);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
