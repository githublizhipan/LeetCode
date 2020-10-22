/*************************************************************************
	> File Name: 2808.校门外的树.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Wed Oct 21 11:00:23 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;

int l, m, a, b, arr[10005], ans;

int main() {
    cin >> l >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        for (int j = a; j <= b; j++) {
            arr[j] = 1;
        }
    }
    for (int i = 0; i <= l; i++) {
        if (!arr[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
