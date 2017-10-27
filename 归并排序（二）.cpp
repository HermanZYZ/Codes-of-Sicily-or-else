 1 #include<iostream>
 2 #include<malloc.h>
 3 using namespace std;
 4 
 5 #define   MAXSIZE  10
 6 
 7 void  PrintArr(int ar[],int n)
 8 {
 9     for(int i = 0; i < n; ++i)
10         cout<<ar[i]<<" ";
11     cout<<endl;
12 }
13 
14 static void merge(int ar[], int low, int mid, int high)  
15 {  
16     int i, k = 0;  
17     //����ռ䣬ʹ���СΪ�����Ѿ���������֮�ͣ��ÿռ�������źϲ��������   
18     int *temp = (int *)malloc((high - low + 1)*sizeof(int));   
19     int begin1 = low;  
20     int end1 = mid;
21 
22     int begin2 = mid + 1;  
23     int end2 = high;   
24 
25     //�Ƚ�����Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ��   
26     for (k = 0; begin1 <= end1 && begin2 <= end2;)    
27     {  
28         if(ar[begin1] < ar[begin2])  
29             temp[k++] = ar[begin1++];  
30         else  
31             temp[k++] = ar[begin2++];    
32     }   
33 
34     while(begin1 <= end1)  //����һ��������ʣ�ֱ࣬�ӿ�������ճ���ϲ�����β   
35         temp[k++] = ar[begin1++];  
36     while(begin2 <= end2)  //���ڶ���������ʣ�ֱ࣬�ӿ�������ճ���ϲ�����β   
37         temp[k++] = ar[begin2++];  
38 
39     for (i = 0;i < k; i++)   //������õ����п�����������  
40     {
41         ar[low+i] = temp[i]; 
42     }
43            
44     free(temp);  
45 }  
46 void merge_sort(int ar[],int begin,int end)  
47 {  
48     int mid = 0;  
49     if(begin < end)  
50     {  
51         mid = (begin + end) / 2;
52         merge_sort(ar, begin, mid); 
53         merge_sort(ar, mid + 1, end);
54         merge(ar, begin, mid, end);  
55     }  
56 }  
57 
58 void  main()
59 {
60     int  ar[] = {12, 14, 54, 5, 6, 3, 9, 8, 47, 89};
61     merge_sort(ar, 0, MAXSIZE-1);
62     PrintArr(ar, MAXSIZE);
63 }
64 
65 /*
66 *3 5 6 8 9 12 14 47 54 89
67  */

