/*************************************************************************
	> File Name: 57.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月03日 星期一 10时04分57秒
 ************************************************************************/
#include<cmath>
#include<iostream>
using namespace std;
#define MAX 1000005
int f(int n) {
    int t, i, sum = 0;
    for(i = 1; ; i++) {   //判断n在几位数的拼接范围内
        int temp = 9 * i * pow(10, i - 1); 
        if(sum + temp > n) {
            n -= sum;
            t = i;
            break;
        } else {
            sum += temp;
        }
    }
    t = n / i;
    t = t + pow(10, i - 1);
    int t1 = n % i, cnt = 0, t2;
    if(t1 == 0) {
        t2 = (t - 1) % 10;
    } else {
        while(i - cnt >= t1) {
            t2 = t % 10;
            t /= 10;
            cnt++;
        }
    }
    return t2;
}
int main() {
    int x, y, z, ans = 1;
    cin >> x >> y >> z;

    if(f(x) == 0 || f(y) == 0 || f(z) == 0) {
        cout << 0 << endl;
        return 0;
    }
    ans = f(x) * f(y) * f(z);
    cout << ans << endl;
    return 0;
}
