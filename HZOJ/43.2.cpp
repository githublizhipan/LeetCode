/*************************************************************************
	> File Name: 43.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月29日 星期三 20时13分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[1005][1005], ans[1005][1005], t;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = max(ans[i - 1][j - 1], ans[i - 1][j]) + num[i][j];
            t = max(ans[i][j], t);
        }
    }
    cout << t << endl;
    return 0;
}
