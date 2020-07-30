/*************************************************************************
	> File Name: 520.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 10时28分11秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main() {
    int a, k, n, temp1, temp2;
    cin >> a;
    for(int i = a + 1; ; i++) {
        temp1 = a * (a - 1) / 2;
        temp2 = (a + 1 + i) * (i - a) / 2;
        if(temp1 == temp2) {
            cout << a << " " << i << endl;
            return 0;
        } else for(int j = a + 1; j < i; j++) {
            temp1 += (j - 1);
            temp2 -= j;
            if(temp1 == temp2) {
                cout << j << " " << i << endl;
                return 0;
            }
        }
    }
    return 0;
}
