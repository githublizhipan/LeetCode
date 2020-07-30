/*************************************************************************
	> File Name: 515.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月04日 星期二 14时08分06秒
 ************************************************************************/
///////////////////////////////////////////////////////////不对**********************************************/////////////////////



#include<iostream>
using namespace std;


int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int a, b, l, a1, b1;
    cin >> a >> b >> l;
    
    int temp = gcd(a, b);

    cout << temp << endl;

    a1 = a / temp, b1 = b / temp;

cout << a1 << " " << b1 << endl;

    while(a1 > l || b1 > l) {
        //if(a1 == 1 || b1 == 1) break;
        a1 += 1;
        b1 += 1;
        int t = gcd(a1, b1);
        a1 /= t;
        b1 /= t;
    }

    while(a1 * 1.0 / b1  < a * 1.0 / b) {
        //if(a1 == 1 || b1 == 1) break;
        a1 += 1;
        b1 += 1;
        int t = gcd(a1, b1);
        a1 /= t;
        b1 /= t;
    }


/*
    while(a1 > l || b1 > l) {
        if(a1 > 1) a1 /= temp;
        if(b1 > 1) b1 /= temp;
    }
*/
    double m = a * 1.0 / b, n = a1 * 1.0 / b1;

    /*
    while(a1 && b1 && n < m) {
        a1 /= temp;
        b1 /= temp;
        m = a * 1.0 / b;
        n = a1 * 1.0 / b1;
    }
    */

    cout << a1 << " " << b1 << endl;
    return 0;
}
