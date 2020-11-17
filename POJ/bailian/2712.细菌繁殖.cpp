/*************************************************************************
	> File Name: 2712.细菌繁殖.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Thu Oct 22 15:09:06 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int t, month1, day1, month2, day2;
long long num, sumday, ans;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    cin >> t;
    while (t--) {
        cin >> month1 >> day1 >> num >> month2 >> day2;
        sumday = 0;
        if (month1 == month2) {  //在同一个月
            sumday = day2 - day1;
        } else {
            sumday += (month[month1] - day1);
            for (int i = month1 + 1; i < month2; i++) {
                sumday += month[i];
            }
            sumday += day2;
        }
        ans = num * pow(2, sumday);
        cout << ans << endl;
    }
    return 0;
}
