/*************************************************************************
	> File Name: 171.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月03日 星期一 12时04分19秒
 ************************************************************************/
#include <cstring>
#include<iostream>
using namespace std;

string num, num1, num2, num3;

int f1() {
    if(num[0] != '1') return 0;
    for(int i = 1; i < num.size(); i++) {
        if(num[i] != '0') return 0;
    }
    return 1;
}

int f2() {
    for(int i = 0, j = num.size() - 1; i <= j; i++, j--) {
        if(num[i] != num[j]) return 0;
    }
    return 1;
}

void get_num1() { 
    for(int i = 0, j = num.size() - 1; i < j; i++, j--) {
        num1[j] = num1[i];
    }
    return ;
}

void get_num2() {
    int t = (num2.size() + 1) / 2 - 1;
    num2[t] -= 1;
    for(int i = t; i >= 0; i--) {
        if(num2[i] < '0') {
            num2[i - 1] -= 1;
            num2[i] += 10;
        }
    }
    for(int i = 0, j = num2.size() - 1; i < j; i++, j--) {
        num2[j] = num2[i];
    }
    return ;
}


void get_num3() {
    int t = (num3.size() + 1) / 2 - 1;
    num3[t] += 1;
    for(int i = t; i >= 0; i--) {
        if(num3[i] > '9') {
            num3[i - 1] += 1;
            num3[i] -= 10; // 。。。。。。。。
        }
    }
    for(int i = 0, j = num3.size() - 1; i < j; i++, j--) {
        num3[j] = num3[i];
    }
    return ;
}

void calc(string str1, string str2) {
    string s1 = num, s2 = num;
    for(int i = 0; i < s1.size(); ++i) {
        s1[i] = '0';
        s2[i] = '0';
    }
    //s1 = str1 - num;
    for(int i = 0; i < num.size(); i++) {
        s1[i] = str1[i] - num[i] + '0';
    }
    for(int i = s1.size() - 1; i >= 0; i--) {
        if(s1[i] < '0') {
            s1[i - 1] -= 1;
            s1[i] += 10;
        }
    }
    //s2 = num - str2;
    for(int i = 0; i < num.size(); i++) {
        s2[i] = num[i] - str2[i] + '0';
    }
    for(int i = s2.size() - 1; i >= 0; i--) {
        if(s2[i] < '0') {
            s2[i - 1] -= 1;
            s2[i] += 10;
        }
    }

    if(s1 > s2) {
        cout << str2 << endl;
    } else cout << str1 << endl;
    return ;
}



int main(){
    cin >> num;
    if(f1()) {
        for(int i = 0; i < num.size() - 1; i++) {
            cout << '9';
        }
        cout << endl;
    } else if(f2()) {
        cout << num << endl;
    } else {
        num1 = num, num2 = num, num3 = num;
        get_num1(); //得到num1
        if(num1 > num) {
            get_num2();
            calc(num1, num2);
        } else {
            get_num3();
            calc(num3, num1);
        }
    }
    return 0;
}
