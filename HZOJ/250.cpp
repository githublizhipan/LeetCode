/*************************************************************************
	> File Name: 250.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 20时11分11秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000000
long long a[MAX_N + 5];
long long s[MAX_N + 5];
long long g[MAX_N + 5];

long long n, c, sum, ans;

int main() {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        sum += a[i];
    }
    c = sum / n; //糖果平均数
    for (long long i = 1; i <= n; i++) {
        g[i] = s[i] - i * c;
    }
    sort(g + 1, g + 1 + n);
    c = g[n / 2];
    for (long long i = 1; i <= n; i++) {
        ans += abs(g[i] - c);
    }
    cout << ans << endl;
    return 0;
}
