#include<stdio.h>

//program for deletion in an array

int del(int[],int,int);

void main()
{
	int a[100],len,pos,num,i;
	
	printf("Enter length for array:");
	scanf("%d",&len);
	
	printf("Enter element for array:");
	for(i=0;i<len;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("Enter position where delting : ");
	scanf("%d",&pos);
	
	--pos;
	
	del(a,len,pos);
}

int del(int a[],int len,int pos)
{
	int i;
	
	for(i=pos;i<len;i++)
	{
		a[i]=a[i+1];
	}
	
	len--;
	
	printf("New array:");
	
	for(i=0;i<len;i++)
	printf("\n%d",a[i]);
	
	return 0;
}
