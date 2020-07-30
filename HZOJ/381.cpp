/*************************************************************************
	> File Name: 381.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月06日 星期四 17时52分35秒
 ************************************************************************/
#include <cstring>
#include<iostream>
using namespace std;

struct student {
    char name[25];
    int score1, score2, num, price;
    char p1, p2;
};


int main() {
    student stu[150];
    int n, maxsum = 0, sum = 0;
    char maxname[25];
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> stu[i].name >> stu[i].score1 >> stu[i].score2 >> stu[i].p1 >> stu[i].p2 >> stu[i].num;
        stu[i].price = 0;
        if(stu[i].score1 > 80) {
            if(stu[i].num >= 1) stu[i].price += 8000;
            if(stu[i].score1 > 85) {
                if(stu[i].score2 > 80) stu[i].price += 4000;
                if(stu[i].p2 == 'Y') stu[i].price += 1000;
                if(stu[i].score1 > 90) stu[i].price += 2000;
            }

        }
        if(stu[i].p1 == 'Y' && stu[i].score2 > 80) stu[i].price += 850;
        if(stu[i].price > maxsum) {
            maxsum = stu[i].price;
            strcpy(maxname, stu[i].name);
        }
        sum += stu[i].price;
    }
    cout << maxname << endl << maxsum << endl << sum << endl;

    return 0;
}
