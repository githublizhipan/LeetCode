/*************************************************************************
	> File Name: 578.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月03日 星期一 16时28分15秒
 ************************************************************************/
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int m, n;

struct student {
    int num;
    set<int> p;
};

student stu[200];



void test() {
    int sum, index[200];
    cin >> sum; //参赛学生数

    //输入编号
    for(int i = 1; i <= sum; i++) {
        cin >> index[i];
    }


    int f = 1;
    //遍历总题目
    for(int i = 1; i <= m; i++) {
        int flag = 1;
        
        //在这些参赛的每位学生中找第i题
        for(int j = 1; j <= sum; j++) {
            if(stu[index[j]].p.count(i) == 0) {
                flag = 0;
                break;
            } else continue;
        } 

        if(flag) {
            if(f) {
                cout << i;
                f = 0;
            } else cout << " " << i; 
        }
    }
    cout << endl;
    return ;
}


void competition() {
    int sum, index[200];
    cin >> sum;
    for(int i = 1; i <= sum; i++) {
        cin >> index[i];
    }
    int f = 1;
    for(int i = 1; i <= m; i++) {
        int flag = 1;
        for(int j = 1; j <= sum; j++) {
            if(stu[index[j]].p.count(i) != 0) {
                flag = 0;
                break;
            } else continue;
        }
        if(flag) {
            if(f) {
                cout << i;
                f = 0;
            } else cout << " " << i;
        }
    }
    cout << endl;
    return ;
}




int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        cin >> stu[i].num;
        for(int j = 1; j <= stu[i].num; j++) {
            int problem;
            cin >> problem;
            stu[i].p.insert(problem);
        }
    }
    
/*
    for(int i = 1; i <= n; i++) {
        for(set <int>::iterator it = stu[i].p.begin(); it != stu[i].p.end(); it++) {
            cout << *it << " ";
        }
        
        cout << endl;
    }
*/


    int k, type;
    cin >> k;

    for(int i = 1; i <= k; i++) {
        cin >> type;
        if(type == 1) {
            test();
        } else {
            competition();
        }
    }

    return 0;
}
