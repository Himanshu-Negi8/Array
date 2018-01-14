#include<stdio.h>
#include<string.h>
main()
{
	char a[50];
	int var=0,i,len,k;
	printf("Enter any string : ");
	gets(a);
	len = strlen(a);
	int freq[len],j;
	for(i=0;i<len;i++)
	{
		freq[i]=0;
	}
	
	for(i=0;i<len;i++)
	{
		var =0;
		for(j=i+1;j<len;j++)
		{
			if(a[i]==a[j])
			{
				++var;
				freq[i]=var;
			}
		}
	}
	k=max_freq(freq,len);
	printf("Repeated index is %d",k);
	printf("\nRepeated character is = %c",a[k]);
	
}

int max_freq(int freq[], int len)
{
	int i,max,index;
	max = freq[0];
	for(i=0;i<len;i++)
	{
		if(max<freq[i])
		{
			max = freq[i];
			index = i;
		}
	}
	return index;
}



