/*************************************************************************
	> File Name: 35.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 13时40分08秒
 ************************************************************************/
int searchInsert(int* nums, int numsSize, int target){
    int l = 0, r = numsSize;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
