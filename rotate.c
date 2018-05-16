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

/*
void rotate1(int* nums, int numsSize, int k) {
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

int rotate(int* nums, int numsSize, int k) {
    int i,j,tmpnum;
    if(k<0)
        return -1;
    if(k>=numsSize)
        k%=numsSize;
    for(i=0; i<k; i++){
        tmpnum = nums[numsSize-1];
        for(j=numsSize-1; j>0; j--){
            nums[j] = nums[j-1];
        }
        nums[0] = tmpnum;
    }
    return 1;
}
*/
