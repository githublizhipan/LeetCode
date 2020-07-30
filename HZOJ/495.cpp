/*************************************************************************
	> File Name: 495.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月28日 星期二 22时42分16秒
 ************************************************************************/

#include<iostream>
using namespace std;
int sum, sum1, w[105], dp[45005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    sum1 = sum / 2;
    for (int i = 1; i <= n; i++) {
        for (int j = sum1; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        }
    }
    cout << dp[sum1] << " " << sum - dp[sum1] << endl;
    return 0;
}
