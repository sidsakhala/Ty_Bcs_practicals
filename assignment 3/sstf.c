#include<stdio.h>
int main()
{
	int rq[100],i,n,THM=0,initial,cnt=0;
	
	printf("Enter number of Request: ");
	scanf("%d",&n);
	printf("Enter The Request Sequence: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rq[i]);
	}
	+printf("Enter initial Head Position: ");
	scanf("%d",&initial);
	
	while(cnt!=n)
	{
		int min=1000,d,index;
		for(i=0;i<n;i++)
		{
			d=abs(rq[i]-initial);
			if(min>d)
			{
				min=d;
				index=i;
			}
		}
		THM = THM + min;
		initial = rq[index];
		rq[index]=1000;
		cnt++;
	}
	
	printf("Total Head Count is %d",THM);
	return 0;
}
