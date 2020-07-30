/*************************************************************************
	> File Name: 561.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月29日 星期三 19时23分12秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
int e, f, r, n, w[505], v[505], ans[10005];
int main() {
    memset(ans, 0x3f, sizeof(ans));
    ans[0] = 0;
    cin >> e >> f >> n;
    f -= e;
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= f; j++) {
            ans[j] = min(ans[j], ans[j - w[i]] + v[i]);
        }
    }
    if (ans[f] == 0x3F3F3F3F) {
        cout << "This is impossible." << endl;
    } else {
        cout << "The minimum amount of money in the piggy-bank is " << ans[f] << ".\n";
    }
    return 0;
}
