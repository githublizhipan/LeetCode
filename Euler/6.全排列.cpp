/*************************************************************************
	> File Name: 6.全排列.cpp
	> Author: lzp
	> Mail: 
	> Created Time: Sat Oct  3 18:58:39 2020
	> Source: 
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[3] = {3, 1, 2};
void output() {
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int main() {
    sort(arr, arr + 3);
    reverse(arr, arr + 3);
    cout << "prev_permutation:" << endl;
    do {
        output();
    } while (prev_permutation(arr, arr + 3));
    
    sort(arr, arr + 3);
    output();
    cout << "next_permutation:" << endl;
    do {
        output();
    } while (next_permutation(arr, arr + 3));
    cout << "--------" << endl;
    output();
    cout << prev_permutation(arr, arr + 3) << endl;
    output();
    cout << prev_permutation(arr, arr + 3) << endl;
    return 0;
}
