/*************************************************************************
	> File Name: 594.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月07日 星期五 21时30分58秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX 100005
int a[10000][10000] = {0};

int main() {
    long long n, m, l, r, ans = 0;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> l >> r;
        for(int j = l + 1; j <= r; j++) {
            a[j - 1][j] = 1;
            a[j][j] = 1;
        }
        a[r][r] = 0;
    }
    for(int i = 1; i < n; i++) {
        if(a[i][i] == 0) ans++;
        if(a[i][i + 1] == 0) ans++;
    }
    if(a[n][n] == 0) ans++;
    printf("%d\n", ans);
    return 0;
}
