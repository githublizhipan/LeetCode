/*************************************************************************
	> File Name: 2733.判断闰年.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Wed Oct 21 10:54:10 2020
	> Source: 
 ************************************************************************/

#include <iostream>
using namespace std;

int y;

int main() {
    cin >> y;
    if ((y % 4 == 0 && y % 100) || (y % 400 == 0)) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }
    return 0;
}
