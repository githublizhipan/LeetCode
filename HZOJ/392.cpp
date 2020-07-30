/*************************************************************************
	> File Name: 392.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月22日 星期三 16时41分12秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int m, n, num[100005], maxn;
int func() {
    int l = 1, r = maxn;
    while(l != r) {
        int mid = (l + r + 1) / 2;
        int now = 0, cnt = 1;
        for(int i = 1; i < m; i++) {
            if(num[i] - num[now] >= mid) {
                cnt++;
                now = i;
            }
        }
        if(cnt >= n) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}


int main() {
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        cin >> num[i];
    }
    sort(num, num + m);
    maxn = num[m - 1] - num[0];
    cout << func() << endl;
    return 0;
}
