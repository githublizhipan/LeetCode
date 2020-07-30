/*************************************************************************
	> File Name: 513.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月03日 星期一 22时49分00秒
 ************************************************************************/

#include<iostream>
using namespace std;

int m, t, ans = 0;
int is_val(int n) {
    while(n) {
        if(n % 10 == t) return 1;
        n /= 10;
    }
    return 0;
}

int main() {
    cin >> m >> t;
    for(int i = 1; i <= m; ++i) {
        if(is_val(i)) continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
