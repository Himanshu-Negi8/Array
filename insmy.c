#include<stdio.h>

//program for inserting a value in an array

int insert(int[],int,int,int);

void main()
{
	int a[100],len,pos,i,num;
	
	printf("Enter the length of array:");
	scanf("%d",&len);
	printf("Enter the numbers for array:");
	for(i=0;i<len;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("\nEnter the position where you wnt insert:");
    scanf("%d",&pos);
	
	printf("\nEnter the number you wwant insert:");
	scanf("%d",&num);
	
	--pos ;
	
	insert(a,len,pos,num);
		
}

int insert(int a[],int len,int pos,int num)
{
	int i;
	
	for(i=len-1;i>=pos;i--)
	{
		a[i+1]=a[i];
	}
	a[pos]=num;
	len++;
	printf("New array:");
	for(i=0;i<len;i++)
	{
		printf("\n%d",a[i]);
	}
	return 0;
}
