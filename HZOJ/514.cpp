/*************************************************************************
	> File Name: 514.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月05日 星期三 20时03分08秒
 ************************************************************************/

#include<iostream>
using namespace std;


int n, cnt = 0;
int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int num(int n) {
    if(n == 0) return 6;
    int t = 0;
    while(n) {
        t += arr[n % 10];
        n /= 10;
    }
    return t;
}


int main() {

    int n, cnt = 0;
    int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    cin >> n;
    n -= 4;
    for(int i = 0; i <= 1000; i++) {
        for(int j = 0; j <= 1000; j++) {
            int k = i + j;
            int temp;
            if(num(k) > n) continue;
            temp = num(i) + num(j) + num(k);
            if(temp != n) continue;
            
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
