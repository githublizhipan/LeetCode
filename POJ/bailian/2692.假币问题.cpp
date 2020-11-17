/*************************************************************************
	> File Name: 2692.假币问题.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Tue Oct 27 21:26:56 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int n;
char l[5][10], r[5][10], result[5][10], flag[15];

int is_val() {
    for (int i = 0; i < 3; i++) {
        int temp1 = 0, temp2 = 0;
        for (int j = 0; l[i][j] != 0 && j < 6; j++) {
            temp1 += flag[l[i][j] - 'A'];
            temp2 += flag[r[i][j] - 'A'];
        }
        if (temp1 > temp2 && result[i][0] != 'u') return 0;
        else if (temp1 < temp2 && result[i][0] != 'd') return 0;
        else if (temp1 == temp2 && result[i][0] != 'e') return 0;
    }
    return 1;
}

int main() {
    cin >> n;
    while (n--) {
        int i;
        for (i = 0; i < 3; i++) {
            cin >> l[i] >> r[i] >> result[i];
        }
        memset(flag, 0, sizeof(flag));
        for (i = 0; i < 12; i++) {
            flag[i] = 1; //重
            if (is_val()) break;
            flag[i] = -1; //轻
            if (is_val()) break;
            flag[i] = 0;
        }
        if (flag[i] < 0) cout << char('A' + i) << " is the counterfeit coin and it is light." << endl;
        else cout << char('A' + i) << " is the counterfeit coin and it is heavy." << endl;
    }
    return 0;
}
