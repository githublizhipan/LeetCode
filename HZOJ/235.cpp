/*************************************************************************
	> File Name: 235.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月14日 星期六 10时07分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, cnt, num[15];


void print() {
    for(int i = 0; i < cnt; i++) {
        if(i) cout << " ";
        cout << num[i];
    }
    cout << endl;
    return ;
}

void func(int m) { //**********
    for(int i = m; i <= n; i++) {
        num[cnt++] = i;
        print();
        func(i + 1);
        cnt--;
    }
    return ;
}


int main() {
    cin >> n;
    func(1);
    return 0;
}
