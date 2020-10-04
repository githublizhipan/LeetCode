/*************************************************************************
	> File Name: 5.gcd.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Fri Oct  2 10:51:24 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "最大公约数：" << gcd(a, b) << endl;
    cout << "最小公倍数：" << a * b / gcd(a, b) << endl;
    return 0;
}
