#include<stdio.h>
int main()
{
	int rq[100],i,j,n,THM=0,initial,size,move;
	printf("Enter number of Request: ");
	scanf("%d",&n);
	printf("Enter The Request Sequence: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rq[i]);
	}
	printf("Enter initial Head Position: ");
	scanf("%d",&initial);
	printf("Enter Total Disk (cylenders) Size: ");
	scanf("%d",&size);
	
	printf("Enter the Direction of Head Movement (Right=1 & Left=0:) ");
	scanf("%d",&move);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(rq[j]>rq[j+1])
			{
				int temp;
				temp=rq[j];
				rq[j]=rq[j+1];
				rq[j+1]=temp;
			}
		}
	}
	
	int index;
	for(i=0;i<n;i++)
	{
		if(initial < rq[i])
		{
			index=i;
			break;
		}
	}
	
	if(move==1)
	{
		for(i=index;i<n;i++)
		{
			THM=THM + abs(rq[i]-initial);
			initial=rq[i];
		}
		
		THM=THM + abs(size - rq[i-1]-1);
		initial= size-1;
		
		for(i=index-1;i>=0;i--)
		{
			THM=THM + abs(rq[i]-initial);
			initial=rq[i];
		}
	}
			
	else
	{
		for(i=index-1;i>=0;i--)
		{
			THM=THM + abs(rq[i]-initial);
			initial=rq[i];
		}
		THM=THM + abs(size - rq[i-1]-0);
		initial=0;
		
		for(i=index;i<n;i++)
		{
			THM=THM + abs(rq[i]-initial);
			initial=rq[i];
		}
	}
	
	printf("Total Head Movement: %d",THM);
	return 0;
	
}
			
	
	 	
