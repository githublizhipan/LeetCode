/*************************************************************************
	> File Name: 475.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月16日 星期六 11时41分35秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
char n[2000], m[2000], temp[20000];
int ans[2000] = {1};
int bigger(char *a, char *b) {
    int la = strlen(a), lb = strlen(b);
    if (la > lb) return 1;
    if (la < lb) return 0;
    if (la == lb) {
        int i = 0, j = 0;
        for ( ; i < la && j < lb; ) {
            if (a[i] > b[j]) return 1;
            if (a[i] < b[j]) return 0;
            if (a[i] == b[j]) {
                i++;
                j++;
            }
        }
        if (i == la && j == lb) return 1;
    }
    return 0;
}

void add(int *ans) {
    ans[ans[0]] += 1;
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] >= 10) {
            ans[i] -= 10;
            ans[i + 1] += 1;
            ans[0] += (i == ans[0]);
        }
    }
}

int main() {
    cin >> n >> m;
    int lm = strlen(m);
    for (int i = 0; i < lm; i++) {
        temp[strlen(temp)] = m[i];
        temp[strlen(temp)] = '\0';
        cout << temp << endl;
        while (bigger(temp, n)) {
            for (int i = strlen(temp) - 1, j = strlen(n) - 1; i >= 0; i--, j--) {
                int c = temp[i] - n[i];
                if (c < 0) temp[i] = '0' - c;
                else temp[i] = c + '0';
            }
            for (int i = strlen(temp) - 1; i > 0; i--) {
                if (temp[i] >= '0') continue;
                temp[i] += 10;
                temp[i - 1] -= 1;
            }
            int k = 0, ltemp = strlen(temp);
            while (temp[k] == '0') k++;
            for (int i = k; i < ltemp; i++) {
                temp[i - k] = temp[i];
            }
            temp[ltemp - k] = '\0';
            add(ans);
        }
    }
    cout << ans[0] << endl;
    for (int i = ans[0]; i >= 1; i--) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
