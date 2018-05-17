/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
案例:
s = "leetcode"
返回 0.
s = "loveleetcode",
返回 2.
注意事项：您可以假定该字符串只包含小写字母。
*/

#incldue<string.h>
int firstUniqChar(char* s) {
    int i,j;
    int len = strlen(s);
    if(len==0)return -1;
    if(len==1)return 0;
    for(i=0; i<len; i++){
        for(j=len-1; j>=0; j--){
            if(i!=j){
                if(s[i]==s[j]){
                    break;
                }
            }
        }
        if(j < 0)
            return i;
    }
    return -1;
}
