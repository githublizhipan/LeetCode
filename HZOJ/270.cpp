/*************************************************************************
	> File Name: 270.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月30日 星期四 09时01分12秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int n, m, arr[300005], head, ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int j = m; j >= 1; j--) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (i < j) {
                sum += arr[i];
                continue;
            } else {
                sum += arr[i];
                sum -= arr[i - j];
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
