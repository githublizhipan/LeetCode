/*************************************************************************
	> File Name: 212.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月24日 星期二 20时49分26秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
#include <cstring>
using namespace std;


struct stu {
    char name[10];
} arr[10];

int cmp(struct stu a, struct stu b) {
    int t = strcmp(a.name, b.name);
    return t < 0;
}

int main() {
    for(int i = 0; i < 10; ++i) {
        cin >> arr[i].name;
    }
    sort(arr, arr + 10, cmp);
    for(int i = 0; i < 10; ++i) {
        cout << arr[i].name << endl;
    }
    return 0;
}
