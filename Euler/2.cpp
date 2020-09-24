/*************************************************************************
	> File Name: 2.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Wed Sep 23 16:39:49 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;


int main() {
    int a[3] = {0, 1, 2}, sum = 0;
    for (int i = 3; a[(i - 1) % 3] + a[(i - 2) % 3] <= 4000000; ++i) {
        a[i % 3] = a[(i - 1) % 3] + a[(i - 2) % 3];
        if (a[i % 3] & 1) sum += a[i % 3];
    }
    cout << sum << endl;
    return 0;
}
