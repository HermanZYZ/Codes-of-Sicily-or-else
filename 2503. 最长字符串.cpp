#include <stdio.h>
#include <math.h>
int countA, countB, maxA, maxB, ans; 
int pieceA, pieceB; 

int min(const int a,const int b)
{
	return a>b?b:a;
}
 
int main(int argc, char *argv[]) 
{ 
	while ( scanf("%d%d%d%d", &countA, &countB, &maxA, &maxB)!=EOF ) 
	{ 
		int rest; 
		if ( maxA == 0 ) 
			ans=maxB > countB ? countB : maxB; 
		else if ( maxB == 0 ) 
			ans=maxA > countA ? countA : maxA; 
		else if ( countA > countB ) 
		{ 
			rest = countA - countB -1; 
			ans=countB*2+1 + min( rest, (countB+1)*(maxA-1) ); 
		}
		else if ( countA < countB ) 
		{ 
			rest = countB - countA -1; 
			ans=countA*2+1 + min( rest, (countA+1)*(maxB-1) ); 
		} 
		else
			ans=countA*2;
		printf("%d\n", ans); 
	} 
	return 0; 
} 
