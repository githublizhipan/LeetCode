/*************************************************************************
	> File Name: 537.门票问题.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Fri Sep 18 07:56:27 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int l, c, cnt, num;
char arr[26000], ans[26000];

void output() {
    for (int i = 0; i < cnt; i++) {
        cout << ans[i];
    }
    cout << endl;
    return ;
}

void func(int s, int left) {
    if (num == 25000) return ;
    if (left == 0) {
        int vcnt = 0, ccnt = 0;
        for (int i = 0; i < cnt; i++) {
            if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') {
                vcnt++;
            } else ccnt++;
        }
        if (vcnt >= 1 && ccnt >= 2) {
            output();
            num++;
            if (num == 25000) return ;
        } 
    }
    for (int i = s; i < c; i++) {
        ans[cnt++] = arr[i];
        func(i + 1, left - 1);
        cnt--;
    }
    return ;
}



int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + c);
    func(0, l);
    return 0;
}
