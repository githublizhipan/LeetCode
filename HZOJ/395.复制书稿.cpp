/*************************************************************************
	> File Name: 395.复制书稿.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sun Sep 20 11:46:31 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;

int m, k, book[510], l, r, ans[510][2];

int check(int mid) {
    int sum = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        if (sum + book[i] < mid) {
            sum += book[i];
        } else if (sum + book[i] == mid) {
            sum = 0;
            cnt++;
        } else {
            sum = book[i];
            cnt++;
        }
    }
    if (sum != 0) cnt++;
    return cnt;
}

int main() {
    cin >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> book[i];
        r += book[i];
    }
    while (l != r) {
        int mid = (l + r) / 2;
        if (check(mid) <= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    ans[k][1] = m;
    int now = book[m - 1], j = k;
    for (int i = m - 2; i >= 0; i--) {
        if (now + book[i] > l) {
            ans[j][0] = i + 2;
            j--;
            now = book[i];
            ans[j][1] = i + 1;
        } else if (now + book[i] == l) {
            ans[j][0] = i + 1;
            j--;
            i--;
            now = book[i];
            ans[j][1] = i + 1;
        } else {
            now += book[i];
        }
    }
    ans[1][0] = 1;
    for (int i = 1; i <= k; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}
