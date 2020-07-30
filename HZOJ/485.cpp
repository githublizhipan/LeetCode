/*************************************************************************
	> File Name: 485.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月08日 星期六 16时11分00秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main() {
    int n, a[10005], sum = 0, ans = 0;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int t = sum / n;
    for(int i = 1; i <= n; i++) {
        a[i] -= t;
    }

    for(int i = 1; i < n; i++) {
        if(a[i] == 0) continue;
        a[i + 1] += a[i];
        ans++;
        /*
        if(a[i] < 0) {
            a[i + 1] += a[i];
            ans++;
        } else if(a[i] > 0) {
            a[i + 1] += a[i];
            an++;
        }
        */
    }
    cout << ans << endl;
    return 0;
}
