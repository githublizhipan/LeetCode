/*************************************************************************
	> File Name: 565.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月11日 星期六 12时35分24秒
 ************************************************************************/
#include<iostream>
#include <cstdio> 
using namespace std;
int main() {
    int n, m;
    cin >> n;
    int a2 = n, a4 = n;
    a2 <<= 16;
    a4 >>= 16;

    //cout << a2 << endl << a4 << endl;

    m = a2|a4;
    cout << m << endl;

    return 0;
}
