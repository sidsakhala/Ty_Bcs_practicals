#include<stdio.h>
#include<stdlib.h>

void acceptAvail(int available[3]){
	int i=0;
	printf("enter 3 available");
	for(i=0; i<3; i++){
		scanf("%d",&available[i]);
	}
}



void displayNeed(int max[4][3],int alloc[4][3],int need[4][3]){
	printf("Need Matrix is\n");
	int i,j=0;
	for(i=0; i<4; i++){
		for(j=0;j<3;j++){		
		 need[i][j]= max[i][j]-alloc[i][j];
		 printf("%d\t",need[i][j]);
		}
		printf("\n");
	}	
}

void disAlMax(int alloc[4][3],int max[4][3]){
	int i,j=0;
	printf("Allocation Matrix\t\t\t Max Matrix\n");
	for(i=0; i<4; i++){
		for(j=0;j<3;j++){
			printf("%d\t",alloc[i][j]);
		}
		printf("\t\t");
			for(j=0;j<3;j++){
			printf("%d\t",max[i][j]);
		}
		printf("\n");
	}

}

void dispAvail(int available[3]){
	int i=0;
	for(i=0; i<3; i++){
		printf("%d\t",available[i]);
	}
}

void safety(int available[3],int alloc[4][3],int max[4][3],int need[4][3])
{
    int over=0,i,j,k,l=0,flag,pno;
    int safe[4];
    int work[3],finish[4];
    for(i=0;i<3;i++)
    {
      work[i]=available[i];
    }
    for(i=0;i<4;i++)
    {
      finish[i]=0;
    }
   while(!over)
   {
     for(i=0;i<4;i++)
    { 
     	if(finish[i]==0)
    	{   
     		flag=0;
     		pno=compare_need(i,need,work);
     		if(pno>-1)
     		{
 	   	  break;    
     		}
    	}	 
   }
    if(i==4)
    {
      printf("System is unsafe \n");
      exit(1);
    } 
    	if(i<4 && pno>=0)
    	{
      		for(k=0;k<3;k++)
      		{
		   work[k]+= alloc[pno][k];		   	        
      		}
      		
      		finish[pno]=1;
      		safe[l++]=pno;
      		if(l>=4)
      		{
      		  printf("\n Safe sequence is");
      		  for(l=0;l<4;l++)
      		  {
      		    printf("P%d\t",safe[l]);
      		  }
      		   over=1;
      		}
    	}
  }
}

int compare_need(int p,int need[4][3],int work[3])
{
 
  int i,j,flag=0;
  for(j=0;j<3;j++)
  {
   if(need[p][j]>work[j])
   {
     flag=1;
     break;
   }
   	if(flag==0)
   	{
     	return p;
   	}
   	return -1;
  }
}

void reso_req(int available[3],int alloc[4][3],int max[4][3],int need[4][3])
{
  int proc,i;
  int req[3];
  printf("Enter request process number");
  scanf("%d",&proc);
  printf("Enter %d  elements request matrix ",3);
  for(i=0;i<3;i++)
  {
    scanf("%d",&req[i]);
  }
  for(i=0;i<3;i++)
  {
  	if(req[i]>need[proc][i])
  	{
  	printf("Error process exceed max demand \n");
  	exit(1);
  	}
  }
 
    for(i=0;i<3;i++)
    {
    	if(req[i]>available[i])
    	{
    	  printf("Error process must wait \n");
  	  exit(1);
    	}
    }
     for(i=0;i<3;i++)
     {
       available[i]-=req[i];
       alloc[proc][i]+=req[i];
       need[proc][i]-=req[i];
     }
     printf("hello \n");
     safety(available,alloc,max,need);
}
void main(){
	int n=0;
	int available[3];
	int alloc[4][3]  = {{1,0,1},{1,1,2},{1,0,3},{2,0,0}};
	int max[4][3] = {{4,3,1},{2,1,4},{1,3,3},{5,4,1}};
	int need[4][3];
	int p,r,i,j;
	/*	printf("Enter your resources and process\n");
		scanf("%d%d",&r,&p);
		printf("Enter %d elements in allocation matrix \n",(p*r));
		for(i=0;i<p;i++)
		{
		  for(j=0;j<r;j++)
		  {
		    scanf("%d",&alloc[i][j]);
		  }
		}
		printf("Enter %d elements in max matrix \n",(p*r));
		for(i=0;i<p;i++)
		{
		  for(j=0;j<r;j++)
		  {
		    scanf("%d",&max[i][j]);
		  }
		}*/

	do{
		
		printf("1. Accept Available\n 2.Display Allocation and Max\n 3.Display Contents of need matrix\n 4.Display Available\n 5.Safety algo\n 6 . Resource Request\n 7 . exit\n");
		scanf("%d",&n);

		switch(n){
			case 1: acceptAvail(available);
				break; 
			case 2: disAlMax(alloc,max);
				break;
			case 3: displayNeed(max,alloc,need);
				break;
			case 4: dispAvail(available);
				break;
			case 5: safety(available,alloc,max,need);
				break;	
			case 6: reso_req(available,alloc,max,need);
				break;
			case 7: exit(0);
			default: printf("Wrong choice \n");
				
		}
	}while(1);
}

