/*************************************************************************
	> File Name: 245.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 10时23分43秒
 ************************************************************************/
#include <algorithm>
#include<iostream>
#include <cmath>
using namespace std;

int n, a[100005];
int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    int index, ans = 0;
    if(n % 2) {
        index = a[n / 2 + 1];
    } else index = (a[n / 2] + a[n / 2 + 1]) / 2;
    
    for(int i = 1; i <= n; i++) {
        ans += abs(index - a[i]);
    }
    cout << ans << endl;

    return 0;
}
