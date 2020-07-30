/*************************************************************************
	> File Name: 519.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月20日 星期三 20时46分16秒
 ************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;
long long a, b, ans;

int main() {
    cin >> a >> b;
    for (int i = 0; i <= 9; i++) { //枚举一堆数
        for (int j = 0; j <= 9; j++) { //枚举那一个数
            if (i == j) continue;
            for (int k = 3; k <= 17; k++) { //枚举数的总长度
                for (int l = 1; l <= k; l++) { //枚举那一个数的位置
                    if (j == 0 && l == 1) continue;
                    if (i == 0 && l != 1) break;
                    long long t = 0;
                    for (int m = 1; m <= k; m++) { //求出这个数
                        if (m != l) {
                            t = t * 10 + i;
                        } else {
                            t = t *10 + j;
                        }
                    }
                    if (t >= a && t <= b) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
