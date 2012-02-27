/* This code contains the O(n) solution for finding the max sum in any subarray */

#include <stdio.h>
#include <stdlib.h>
#define maxmac(a,b) ((a>b)?(a):(b))
int max_sub(int *a,int len)
{
	int i;
	int maxsofar=0,maxendinghere=0;
	for(i=0;i<len;i++){
		printf("Iter[%d]:",i);
		maxendinghere+=a[i];
		printf("me:%d",maxendinghere);
		maxendinghere=maxmac(maxendinghere,0);
		printf(" menew:%d",maxendinghere);
		maxsofar=maxmac(maxsofar,maxendinghere);
		printf(" msf:%d\n",maxsofar);
		}
	return maxsofar;
}

int main()
{
	int a[10]={1,4,-3,-2,10,-11,6,7,2,2};
	int i;
	printf("\n");
	for(i=0;i<10;i++){
		printf("%d  ",a[i]);
		}
	printf("\n");
	printf("\nmax sub:%d\n",max_sub(a,10));
	return 0;
}
