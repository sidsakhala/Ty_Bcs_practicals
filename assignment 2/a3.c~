#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50
int n, bit[MAX];

typedef struct dir{
	char fname[20];
	int size;
	int items[MAX];
	int cnt;
	struct dir *next;
}node;
node *first, *last;

void display(){
	int i;
	printf("Bit vector: \n");
	for(i = 0; i < n; i++){
		printf("%d\n", bit[i]);
	}
}

void create(){
	node *p;
	char name[20];
	int nob, i, j;
	int st = -1;
	printf("Enter filename: ");
	scanf("%s", &name);
	printf("Enter no. of blocks for the file: ");
	scanf("%d", &nob);
	if(nob > n){
		printf("Failed to create file!\n");
		return;
	}
	p = (node *)malloc(sizeof(node));
	strcpy(p->fname, name);
	p->size = nob;
	p->cnt = 0;
	p->next = NULL;
	for(i = 0; i <= n; i++){
		if(p->cnt == nob){
			if(first == NULL){
				first = p;
				last = first;
			}
			else{
				last->next = p;
			}
			printf("File %s created successfully!\n", p->fname);
			return;
		}
		if(bit[i] == 0){
			p->items[p->cnt] = i;
			p->cnt += 1;
			bit[i] = 1;
		}
	}
	printf("Failed to create file!\n");
}

void delete(){
	char name[20];
	int j, k;
	node *p, *q;
	printf("Enter filename to delete: ");
	scanf("%s", &name);
	p = q = first;
	while(p != NULL){
		if(strcmp(p->fname, name) == 0){
			if(p == first){
				first = p->next;
			}
			else if(p == last){	
				last = q;
				last->next = NULL;
			}
			else{
				q->next = p->next;
			}
			for(j = 0; j < n; j++){
				for(k = 0; k < p->cnt; k++){
					if(p->items[k] == j){
						bit[j] = 0;
					}
				}
			}
			printf("File %s has been deleted!\n", p->fname);
			free(p);
			return;
		}
		else{
			q = p;
			p = p->next;
		}
	}
}

void show_dir(){
	node *p;
	int i;
	p = first;
	if(p == NULL){
		printf("No files in the directory\n");
		return;
	}
	printf("File\tSize\tBlock indexes\n");
	while(p != NULL){
		printf("%s\t%d\t", p->fname, p->size);
		for(i = 0; i < p->cnt; i++){
			printf("%d ", p->items[i]);
		}
		printf("\n");
		p = p->next;
	}
}

int main(){
	int ch, i;
	printf("Enter total no. of disk blocks available: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		bit[i] = 0;
	}
	do{
		printf("Enter choice:\n");
		printf("1. Show bit vector\n");
		printf("2. Create new file\n");
		printf("3. Show directory\n");
		printf("4. Delete a file\n");
		printf("5. Exit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				display();
				break;
			case 2:
				create();
				break;
			case 3:
				show_dir();
				break;
			case 4:
				delete();
				break;
				
		}
	}while(ch != 5);
}
