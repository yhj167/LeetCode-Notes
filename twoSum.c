/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 思路：从nums中选出不重复的2个数，相加判断
**/ 
#include<stdio.h>
/*
int* twoSum(int* nums, int numsSize, int target) {
    int index1=0;
    int* out;
    out = malloc(2*sizeof(int));
    if(numsSize<2)
        return 0;
    for(int i=index1; i<numsSize-1; i++)
    {
        for(int j=index1+1; j<numsSize; j++)
        {
            if(nums[i] + nums[j] == target){
                out[0] = i;
                out[1] = j;
                printf("out: %d,%d\n",out[0],out[1]);
                return out;
            }
        }
        index1++;
    }
    printf("not find\n");
    return 0;
}
*/
int* twoSum(int* nums, int numsSize, int target) {
    int* out;
    out = (int*)malloc(2*sizeof(int));
    if(numsSize<2)
        return 0;
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] <= target || target < 0){
            for(int j=0; j<numsSize; j++)
            {
                if(i != j){
                    if(nums[i] + nums[j] == target){
                        out[0] = i>j?j:i;
                        out[1] = j>i?j:i;
                        printf("out: %d,%d\n",out[0],out[1]);
                        return out;
                    }
                }
            }
        }
    }
    return 0;
}
int main(){
    int a[5] = {2,3,3,-7,-5};
    int b = 6;
    twoSum(a,5,b);
    return 0;
}

