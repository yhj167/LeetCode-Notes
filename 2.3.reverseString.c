#include<string.h>
char* reverseString(char* s) {
    int i;
    int len = strlen(s);
    char temp;
    for(i=0;i<len/2;i++)    //i<len/2就可以了，奇数，不交换中间那个数
    {
        temp = s[i];
        s[i]=s[len-1-i];
        s[len-1-i]=temp;
    }
    return s;
}
/*
char* reverseString(char* s) {
    int len=0,j=0;
    char* tmp;
    
    if(s == NULL)return;
    len = strlen(s);
    if(len == 1)return s;
    tmp = (char*)malloc(len+1);
    memset(tmp, 0, len+1);
    for(int i=len-1; i>=0; i--){
        tmp[j] = s[i];
        j++;
    }
    return tmp;
}
*/
