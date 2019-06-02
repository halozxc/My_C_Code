#include<stdio.h>
#include<string.h>

typedef struct Book{
	char name[20];
    float price;
};
Book NewBookList[10];
int n=0;
void sort()
{
	
	int max;
	for(int i=0;i<n;i++)
	{
	max=i;
		for(int j=i+1;j<n-1;j++)
		{
			if(NewBookList[max].price<NewBookList[j].price){
				max=j;
			}
		}
	if(max!=i){
		Book swap=NewBookList[i];
		NewBookList[i]=NewBookList[max];
		NewBookList[max]=swap;
	}
    }
}
int main(){
 
	int n=0;
	while(n<10){
		printf("please enter the book name\n");
	    gets(NewBookList[n].name);
	  // printf("%s\n",NewBookList[n].name);
	    if(strcmp(NewBookList[n].name,"none")==0)
		{
			break;
		}
		printf("please enter the book price\n");
		scanf("%f",&NewBookList[n].price);
		
		getchar();
	n++;
	}
sort();
for(int i=0;i<n;i++)
printf("%s的价格是%.2f\n",NewBookList[i].name,NewBookList[i].price);
fclose(fp); 
} 
