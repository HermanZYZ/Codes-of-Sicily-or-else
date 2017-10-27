
#include<stdio.h> 

#include<stdlib.h> 

#include<string.h> 

int main(){ 

char a[10000];//定义一个字符型数组，最多可以容纳10000位，可修改  

memset(a,'\0',10000*sizeof(char));//对数组初始化  

int n,temp=0; 

scanf("%d",&n); 

itoa(n,a,2);//改变成2进制，n是要转化的整数，a是转化后保存的字符串，2代表2进制，范围2-36进制  

for(n=0;n<strlen(a);n++){ 

    if(a[n]=='1') 

    temp++; 

} 

printf("%d\n",temp); 

return 0; 

}
