/*************************************************************************
	> File Name: 469.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月11日 星期六 11时48分20秒
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;

int f(int x, char s[]) {
    int m = 0, p = 1;
    //cout << m << endl;
    int l = strlen(s);
    for(int i = l - 1; i >= 0; i--) {
        //cout << (n % 10) * p << endl;
        m += (s[i] - '0') * p;
        p *= x;
    }
    return m;
}

int main() {
    int x;
    char s[100];
    cin >> x >> s;
    cout << f(x, s) << endl;
    return 0;
}
