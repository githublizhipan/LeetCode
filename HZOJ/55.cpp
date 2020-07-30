/*************************************************************************
	> File Name: 55.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月03日 星期一 09时08分09秒
 ************************************************************************/

#include<iostream>
using namespace std;

int years[3000];
int sum[3000] = {0}; //当前年的1.1距离1900.1.1的天数
int sixday[3000] = {0};
int main() {
    int year;
    int y1, m1, d1, y2, m2, d2, ans = 0;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    
    for(int i = 1900; i <= 2020; i++) {
        if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            years[i] = 366;
            sixday[i] = 158;//本年的六月六日是第几天
        } else {
            years[i] = 365;
            sixday[i] = 157;
        }
        sum[i] = sum[i - 1] + years[i];
        int temp = sum[i - 1] + sixday[i];
        //cout << temp << endl;
        if(i > y2 || i < y1) continue;
        if(i == y1 && (m1 > 6 || (m1 == 6 && d1 > 6))) continue;
        if(i == y2 && (m2 < 6 || (m1 == 6 && d1 < 6))) continue;
        if(temp % 7 == 6) {
            ans++;
            //cout << i << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
