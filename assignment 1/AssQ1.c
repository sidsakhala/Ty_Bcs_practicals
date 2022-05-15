#include<stdio.h>
void main(){
	int n=0;
	int available[3];
	int alloc[5][3]  = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
	int max[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
	do{
		printf("Enter your choice\n");
		
		printf("1. Accept Available\n 2.Display Allocation and Max\n 3.Display Contents of need matrix\n 4.Display Available\n 5.Exit\n");
		scanf("%d",&n);

		switch(n){
			case 1: acceptAvail(available);
				break; 
			case 2: disAlMax(alloc,max);
				break;
			case 3: displayNeed(max,alloc);
				break;
			case 4: dispAvail(available);
				break;
			case 5: break;
		}
	}while(n!=5);
}


void acceptAvail(int available[3]){
	int i=0;
	for(i=0; i<3; i++){
		scanf("%d",&available[i]);
	}
}


void displayNeed(int max[5][3],int alloc[5][3]){
	printf("Need Matrix is\n");
	int i,j=0;
	for(i=0; i<5; i++){
		for(j=0;j<3;j++){		
			printf("%d\t",max[i][j]-alloc[i][j]);
		}
		printf("\n");
	}
	
}


void disAlMax(int alloc[5][3],int max[5][3]){
	int i,j=0;
	printf("Allocation Matrix\t\t\t Max Matrix\n");
	for(i=0; i<5; i++){
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
