#include<stdio.h>
int main()
{
	int num[100],i,size,flag=0,n;
	printf("Enter the size : ");
	scanf("%d",&size);
	printf("Enter the numbers : \n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&num[i]);
    }
    printf("Enter the number : ");
    scanf("%d",&n);
    for(i=0;i<size;i++)
    {
    	if(n==num[i])
    	{
    		flag++;
    		break;
		}
	}
	if(flag==0)
	{
	  printf("%d is not present",n);
	}
	else
	{
		printf("%d is present at index %d",n,i);
	}

    return 0;
}