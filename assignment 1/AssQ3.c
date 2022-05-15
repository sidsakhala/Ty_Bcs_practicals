#include<stdio.h>
#include<stdlib.h>
#define MAX 4


void accept2dmatrix(int a[][MAX], int n, int m){
	int i,j=0;	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("Enter %d process %d resource\n",i,j);
			scanf("%d",&a[i][j]);
			
		}	
	
	}
}

void accept1darray(int a[MAX], int m){
	int i=0;	
	for(i=0; i<m; i++){
		printf("Enter instance of %d process",i);
		scanf("%d",&a[i]);
	}
}

void display2dmatrix(int a[][MAX], int n, int m){
	int i,j=0;	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%d\t",a[i][j]);
			
		}	printf("\n");
	
	}
}

void displayNeed(int need[][MAX], int max[][MAX],int alloc[][MAX], int n,int m){
	printf("Need Matrix is\n");
	int i,j=0;
	for(i=0; i<n; i++){
		for(j=0;j<m;j++){	
			need[i][j] = max[i][j]-alloc[i][j];	
			printf("%d\t",need[i][j]);
		}
		printf("\n");
	}
	
}

int compareNeed(int p, int m,int need[][MAX],int work[MAX] ){
	int i,j,flag=0;
	for(j=0;j<m; j++){
		if(need[p][j]>work[j]){
			flag =1;
			printf("fl");
			break;		
		}
	}
	if(flag==0){
		printf("hi");
		return p;	
	}
	return -1;
}

void safetyAlgo(int alloc[][MAX],int avail[MAX], int work[MAX],int need[][MAX], int Finish[10], int n,int m){
	printf("hi");
	int over=0,i,j,k,l=0,h;
	h=m;
	int flag,pno,safe[n],ne[n][m];
	for(i=0;i<n;i++){
		Finish[i] = 0;
		for(j=0;j<m;j++){ne[i][j] = need[i][j];} 
	}
	for(i=0;i<m;i++){
		work[i] = avail[i];
	}
	for(i=0;i<m;i++){
		printf("%d",work[i]);
	}
	while(!over){
		for(i=0;i<n;i++){
			if(Finish[i]==0){
				flag =0;
				pno = compareNeed(i,h,ne,work);
				printf("%d",pno);
				if(pno> -1)
				{
				printf("###################");
				break;
				}
			}
		}
		if(i==n){
			printf("System is unsafe");
			exit(1);		
		}
		if(i<n && pno>=0){
			printf("###################sfsdf");
			for(k=0; k<m; k++){
				work[k]+= alloc[pno][k];
			}
			Finish[pno] =1;
			safe[l++] = pno;
			if(l>=n){
				printf("Safe sequence is : \n");
				for(l=0;l<n;l++){
					printf("P %d",safe[l]);
					over =1;	
				}
			} 
		}
	}
}



void main(){
	int n,m;
	printf("Enter the number of resources and process\n");
	scanf("%d%d",&m,&n);
	int alloc[n][m], max[n][m];
	printf("Enter allocation matrix");
	accept2dmatrix(alloc,n,m);
	display2dmatrix(alloc,n,m);
	printf("Enter Maximum matrix");
	accept2dmatrix(max,n,m);
	display2dmatrix(max,n,m);
	int avail[m],work[m],Finish[n];
	accept1darray(avail,m);
	int need[n][m];
	displayNeed(need,max,alloc,n,m);
	safetyAlgo(alloc,avail,work,need,Finish,n,m);
}
