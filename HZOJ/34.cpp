/*************************************************************************
	> File Name: 34.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 14时37分38秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main() {
    int y;
    cin >> y;
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0) cout << 'L' << endl;
    else cout << 'N' << endl;
    
    return 0;
}
