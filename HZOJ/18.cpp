/*************************************************************************
	> File Name: 18.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 19时34分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, a = 1, b = 1, ans = 0;

void f(int a, int b) {
    if(a == n || b == n) return ;
    int t1 = n - a, t2 = n - b;
    if(t1 > t2) {
        f(a, b + a);
        ans++;
    } else {
        f(a + b, b);
        ans++;
    }
    return ;
}

int main() {
    f(a, b);
    cout << ans << endl;
    return 0;
}
