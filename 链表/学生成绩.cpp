#include<stdio.h>
#include<string.h>

typedef struct Book{
	char name[20];
    long number;
	float course1;
    float course2;
	float course3;
	float fianlscore;
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
			if(NewBookList[max].fianlscore<NewBookList[j].fianlscore){
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
 FILE *fp=fopen("P356.txt","w"); 
	int n=0;
	while(n<5){
		printf("please enter the Student name\n");
	    gets(NewBookList[n].name);
	  // printf("%s\n",NewBookList[n].name);
	    if(strcmp(NewBookList[n].name,"none")==0)
		{
			break;
		}
		
		printf("please enter%s's number\n",NewBookList[n].name);
		
		scanf("%l",&NewBookList[n].number);
		printf("please enter%s's course2 score\n",NewBookList[n].name);
		scanf("%f",&NewBookList[n].course2);
		printf("please enter%s's course3 score\n",NewBookList[n].name);
		scanf("%f",&NewBookList[n].course3);
		getchar();
	n++;
	NewBookList[n].fianlscore=(NewBookList[n].course1+NewBookList[n].course2+NewBookList[n].course3)/3;
	}
sort();
for(int i=0;i<n;i++)
fprintf(fp,"%s的课程1成绩%.2f，课程2成绩%.2f，课程3成绩%.2f，为总品均分是%.2f\n",NewBookList[i].name,NewBookList[i].course1,NewBookList[i].course2,NewBookList[i].course3,NewBookList[i].fianlscore);
} 
