/*************************************************************************
	> File Name: 507.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 21时58分45秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct node {
    int y, c;
};
node p[50005];
int cmp(node a, node b) {
    if (a.y + a.c == b.y + b.c) return a.y < b.y;
    return a.y + a.c < b.y + b.c;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].y >> p[i].c;
    }
    sort(p, p + n, cmp);
    
    int d, ans = -999999999, sum = 0;
    for (int i = 0; i < n; i++) {
        d = sum - p[i].c;
        sum += p[i].y;
        ans = max(ans, d);
    }
    cout << ans << endl;
    return 0;
}
