/*************************************************************************
	> File Name: 587.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 13时24分44秒
 ************************************************************************/
#include <string>
#include<iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, a, b, c;
    cin >> N >> a >> b >> c;
    
    int arr[3];
    
    int min_num, max_num, mid_num;
    
    min_num = min(a, b);
    min_num = min(min_num, c);

    max_num = max(a, b);
    max_num = max(max_num, c);

    mid_num = a + b + c - min_num - max_num;


    arr[0] = min_num, arr[1] = mid_num; arr[2] = max_num;


    int x, y, z;
    if(a == arr[0]) {
        x = 1;
        if(b == arr[1]) {
            y = 2;
            z = 3;
        } else {
            y = 3;
            z = 2;
        }
    } else if(a == arr[1]) {
        x = 2;
        if(b == arr[0]) {
            y = 1;
            z = 3;
        } else {
            y = 3;
            z = 1;
        }
    } else {
        x = 3;
        if(b == arr[0]) {
            y = 1;
            z = 2;
        } else {
            y = 2;
            z = 1;
        }
    }
    if((x == 1 && y == 2 && z == 3) || (x == 2 && y == 3 && z == 1) || (x == 3 && y == 1 && z == 2)) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}
