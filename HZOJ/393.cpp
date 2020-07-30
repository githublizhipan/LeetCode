/*************************************************************************
	> File Name: 393.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 08时46分34秒
 ************************************************************************/
#include <cstdio>
#include<iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k;
double l[100010];

int is_valu(double mid) {
    int num = 0;
    for(int i = 1; i <= n; i++) {
        num += floor(l[i] / mid);
    }
//cout << num << endl;
    return num >= k;
}


int main() {
    cin >> n >> k;
    double head = 0, tail = 0, mid;
    for(int i = 1; i <= n; i++) {
        cin >> l[i];
        //tail += l[i];
        tail = max(tail, l[i]);
    }

    for(int i = 1; i <= 200; i++) {
        mid = (head + tail) / 2;
        if(is_valu(mid)) {
            head  = mid;
        } else tail = mid;
    }
    printf("%.2lf\n", floor(head * 100) / 100);
    return 0;
}
