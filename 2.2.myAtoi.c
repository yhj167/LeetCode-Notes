/*
实现 atoi，将字符串转为整数。

在找到第一个非空字符之前，需要移除掉字符串中的空格字符。如果第一个非空字符是正号或负号，选取该符号，并将其与后面尽可能多的连续的数字组合起来，这部分字符即为整数的值。如果第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

字符串可以在形成整数的字符后面包括多余的字符，这些字符可以被忽略，它们对于函数没有影响。

当字符串中的第一个非空字符序列不是个有效的整数；或字符串为空；或字符串仅包含空白字符时，则不进行转换。

若函数不能执行有效的转换，返回 0。

说明：

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。如果数值超过可表示的范围，则返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 
*/

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int myAtoi(char* str) {
    int len = strlen(str);
    int flag=0;
    int start=-1;
    int end=0;
    int result=0;
    unsigned long long tmp=0;
    char* out;
    for(int i=0; i<len; i++){        
        if(flag==0){
            if(str[i]=='-'){
                flag = 2;
            }
            else if(str[i]=='+'){
                flag = 1;
            }
            else if((str[i]>='0')&&(str[i]<='9')){
                flag=1;
                start = i;
                end++;
            }
            else if(str[i]!=' ')return 0;
        }
        else{
            if((str[i]>='0')&&(str[i]<='9')){
                if(start<0)start = i;
                end++;
            }
            else break;
        }
    }
    if(end>0){
        out = (char*)malloc(end+1);
        memset(out,0,end+1);
        memcpy(out, &str[start], end);
        sscanf(out, "%ld", &tmp);
        if(flag==2){//-
            if(tmp > 2147483648)result = -2147483648;
            else result = tmp*(-1);
        }
        else if(flag==1){//+
            if(tmp > 2147483647)result = 2147483647;
            else result = tmp;
        }
    }
        printf("\n%d,%d,%d,%d,%s\n",len,start,end,tmp,out);
    return result;
}
int main(){
    int a = myAtoi(" 123123123123213");
    printf("%d\n",a);
    return 0;
}
