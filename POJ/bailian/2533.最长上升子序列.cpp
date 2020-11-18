/*************************************************************************
	> File Name: 2533.最长上升子序列.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Wed Nov 18 08:43:59 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAXN 1000010

int n, arr[MAXN], dp[MAXN], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (arr[j] >= arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
