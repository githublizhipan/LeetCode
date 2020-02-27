/*************************************************************************
	> File Name: 287.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 22时40分19秒
 ************************************************************************/
int findDuplicate(int* nums, int numsSize){
    int p = nums[0], q = nums[0];
    do {
        p = nums[p];
        q = nums[nums[q]];
    } while(p != q);
    q = nums[0];
    while(p != q) {
        p = nums[p];
        q = nums[q];
    }
    return p;
}
