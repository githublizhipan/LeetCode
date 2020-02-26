/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 12时34分18秒
 ************************************************************************/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *ind = (int *)malloc(sizeof(int) * 2);
    for(int i = 0; i < numsSize - 1; i++) {
        int t = target - nums[i];
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[j] != t) continue;
            ind[0] = i;
            ind[1] = j;
        }
    }
    *returnSize = 2;
    return ind;
}
