
#include<stdio.h> 

#include<stdlib.h> 

#include<string.h> 

int main(){ 

char a[10000];//����һ���ַ������飬����������10000λ�����޸�  

memset(a,'\0',10000*sizeof(char));//�������ʼ��  

int n,temp=0; 

scanf("%d",&n); 

itoa(n,a,2);//�ı��2���ƣ�n��Ҫת����������a��ת���󱣴���ַ�����2����2���ƣ���Χ2-36����  

for(n=0;n<strlen(a);n++){ 

    if(a[n]=='1') 

    temp++; 

} 

printf("%d\n",temp); 

return 0; 

}
