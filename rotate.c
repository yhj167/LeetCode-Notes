/*数组：翻转数组
* 思路3：例如k为3，numsSizew为7，则i为4,5,6的元素翻转后分别变为i为(4+3)%7,(5+3)%7,(6+3)%7的元素
*/
void rotate(int* nums, int numsSize, int k) {
    int i,j;
    int tmpnum[numsSize];
    if(k<=0)
        return;
    if(k>=numsSize)
        k= k % numsSize;
    for(i=0; i<numsSize; i++){
        tmpnum[(i+k)%numsSize] = nums[i];
    }
    memcpy(nums, tmpnum, numsSize*sizeof(int));
}

/*数组：翻转数组
* 思路2：直接向右移动k位，需一个临时变量数组，只需循环一次
*/
void rotate(int* nums, int numsSize, int k) {
    int i,j;
    int tmpnum[numsSize];
    if(k<=0)
        return;
    if(k>=numsSize)
        k= k % numsSize;
    for(i=0; i<k; i++){
        tmpnum[i] = nums[numsSize-k+i];
    }
    for(j=numsSize-1; j>=k; j--){
        nums[j] = nums[j-k];
    }
    for(i=0; i<k; i++){
        nums[i] = tmpnum[i];
    }
}

/*数组：翻转数组
* 思路1：每次向右移动1位，只需一个临时变量，循环K次
*/
int rotate(int* nums, int numsSize, int k) {
    int i,j,tmpnum;
    if(k<0)
        return -1;
    if(k>=numsSize)
        k %= numsSize;
    for(i=0; i<k; i++){
        tmpnum = nums[numsSize-1];
        for(j=numsSize-1; j>0; j--){
            nums[j] = nums[j-1];
        }
        nums[0] = tmpnum;
    }
    return 1;
}
