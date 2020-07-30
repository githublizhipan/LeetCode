/*************************************************************************
	> File Name: 587.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月06日 星期三 18时10分11秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if ((a < b && b < c) || (c < a && a < b) || (b < c && c < a)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
