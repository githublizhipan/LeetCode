/*************************************************************************
	> File Name: 1001.A+BFormat.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Oct 17 19:02:52 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;

int a, b, num[10];

int main() {
    cin >> a >> b;
    a += b;
    if (a < 0) {
        a *= -1;
        cout << "-";
    }
    while (a >= 1000) {
        num[++num[0]] = a % 1000;
        a /= 1000;
    }
    num[++num[0]] = a;
    cout << num[num[0]];
    for (int i = num[0] - 1; i >= 1; i--) {
        cout << ",";
        if (num[i] < 10) cout << "00" << num[i];
        else if (num[i] < 100) cout << "0" << num[i];
        else cout << num[i];
    }
    cout << endl;
    return 0;
}
