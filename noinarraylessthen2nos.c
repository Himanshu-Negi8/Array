#include<stdio.h>
//program for finding the number which are atleast less then two numbers

main()
{
	int a[5],i;
	printf("Enter elements for array : ");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	
	findthenumber(a,5);
}

void findthenumber(int a[],int n)
{
	
	int i,j,count =0;
	
	for(i=0;i<n;i++)
	{ count =0;
		for(j=i;j<n;j++)
		{
			
			if(a[i]<a[j])
			count++;
	
		}
				if(count>=2)
		{
			printf("|%d|-",a[i]);	
		}
	
	}
}
