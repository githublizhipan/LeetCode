/*************************************************************************
	> File Name: 69.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月13日 星期一 18时02分08秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main() {
    int y, m, d;
    int month[13] = {0, 
        31, 28, 31,
        30, 31, 30,
        31, 31, 30,
        31, 30, 31
    };
    cin >> y >> m >> d;
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        month[2] = 29;
        if(m < 1 || m > 12 || d > month[m] || d < 1) {
            cout << "No" << endl;
            return 0;
        }
    } else {
        month[2] = 28;
        if(m < 1 || m > 12 || d > month[m] || d < 1) {
            cout << "No" << endl;
            return 0;
        }    
    }
    cout << "Yes" << endl;
    return 0;
}
