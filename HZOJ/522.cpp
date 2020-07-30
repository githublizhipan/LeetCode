/*************************************************************************
	> File Name: 522.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 10时13分50秒
 ************************************************************************/
#include <cmath>
#include<iostream>
using namespace std;
int main() {
    long long n, x, sum = 0, a;
    cin >> n >> x >> a;
    sum = a;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        sum += a * pow(x, i);
    }
    cout << sum << endl;
    return 0;
}
