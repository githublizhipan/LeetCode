/*************************************************************************
	> File Name: 585.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月02日 星期日 20时04分13秒
 ************************************************************************/
#include <algorithm>
#include<iostream>
using namespace std;
struct stu {
    int score, grade, ans;
};

bool cmp(stu a, stu b) {
    if(a.score < b.score) return 0;
    else if(a.score > b.score) return 1;
    else return a.grade < b.grade;
}

int main() {
    int n;
    stu s[250];
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> s[i].score >> s[i].grade;
        s[i].ans = 0;
    }
    sort(s, s + n, cmp);
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(s[j].grade >= s[i].grade) continue;
            s[i].ans++;
        }
        cout << s[i].ans << endl;
    }
    return 0;
}
