#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE* fpin, * fpout;
char filename[] = "std.txt";

typedef struct stu_record {
	long number;
	char name[20];
	char CourseName[20];
	long classnum;
	long CourseNum;
	int CourseScore;
	int TestScore;
	int FinalScore;
};

typedef struct stud_node
{
	stu_record record;
	 stud_node* next;
};
stud_node* newstu;
stud_node* create(FILE* fp) {
	stud_node* head, * tail, * p;
	int num;
	int size = sizeof(struct stud_node);
    num = 1;
	p = (struct stud_node*)malloc(size);
	tail = p;
      
	while (!feof(fp))
	{
		if (num == 1) {
			head = p;
		}
		//fscanf(fp, "%s", &p->record.name);
		//fscanf(fp, "%s", &p->record.CourseName);
		fscanf(fp, "%s %s %ld %ld %ld %d %d", &p->record.name, &p->record.CourseName, &p->record.number, &p->record.CourseNum, &p->record.classnum, &p->record.CourseScore, &p->record.TestScore);
		p->next = NULL;
		tail->next = p;
		tail = p;
		p = (struct stud_node*)malloc(size);
        num++;
	}
//	p->next = NULL;
	 tail->next = NULL;
	//tail = p;
	return head;
	printf("successful");
}
stud_node* read(char fname[20])
{

	if ((fpin=fopen(fname, "r"))!=NULL) {
		printf("open file failed");
		return NULL;
	}
	else {
		return 	create(fpin);
	}
}

stud_node* stu_search(stud_node* originchain , int op)
{

    long number;
	char name[20];
	char coursename[10];
	long classnum;
switch(op)
	{
	case 0:
		printf("输入想要查找的名字");
		gets(name) ;
		
		break;
			
	case 1:
		printf("输入想要查找的学号");
	    scanf("%ld",number);
		getchar();	
	    break;
	case 2:
		printf("输入课程名");
		gets(coursename);
	    break;
	case 3:
		printf("输入想要查找的班级");
		scanf("%ld",classnum);
		break;
		default :
		return NULL;
	}
   
    stud_node* head;
    stud_node* p; 
	int count=0;
	while(originchain!=NULL)
    {
    	if(strcmp(originchain->record.name,name)==0||strcmp(originchain->record.CourseName,coursename)==0||classnum==originchain->record.classnum||originchain->record.number==number)
	     {
	     	
			 if(count==0)
			 {
	     		p=originchain;
				head=p;
			}
			else
			{
			p->next=originchain;
			p=p->next;
			}
           	count++;	 
		 }
	    originchain=originchain->next;
	}
p->next=NULL;
return head;
}
int AddNew() {
	long number;
	char name[20];
	char CourseName[10];
	long classnum;
	long CourseNum;
	int CourseScore;
	int TestScore;
   getchar();
    printf("输入学生姓名");
    gets(name);
    printf("输入课程名称");
	gets(CourseName);
	printf("输入学号");
	scanf("%ld",&number);
	printf("课程序号\n");
	scanf("%ld",&CourseNum);
	printf("班级\n");
	scanf("%ld",&classnum);
	printf("现在请输入学生平时成绩\n");
	scanf("%d",&CourseScore);
	printf("现在请输入学生期末成绩\n");
	scanf("%d",&TestScore);
    printf("%s %s %ld %ld %ld %d %d\n",name,CourseName,number,CourseNum,classnum,CourseScore,TestScore);  
	
	fprintf(fpin,"%s %s %ld %ld %ld %d %d\n",name,CourseName,number,CourseNum,classnum,CourseScore,TestScore);
    return 0;
}

int main() {
	int op;
	
	printf("学生信息管理系统\n\n");
	printf("1,输入学生信息\n");
	printf("2，修改学生信息\n");
	printf("3，按姓名查询\n");
	printf("4,按学号查询\n");
	printf("5,按班级查询\n");
	printf("6，按课程名查询\n");
	printf("7，按总分高低排序\n");
	printf("8,单科成绩排名\n");
	printf("9，查询班级优秀律\n");
	printf("退出\n");
	scanf("%d", &op);
		//stud_node* modifychain=create(fpin);
	stud_node* searchchain=NULL;
	 stud_node * resultchain=NULL;

	switch(op)
	{
	case 1:
		fpin=fopen(filename, "a");
	    AddNew();
	    break;
	case 2:
		fpin=fopen(filename, "r");
	
		fclose(fpin);
		break;
	case 3:
		fpin=fopen(filename, "r");
		
	    break;
	case 4:
	     	fpin=fopen(filename, "r");
	        searchchain=create(fpin);
	        resultchain=stu_search(searchchain,1);
	        for(resultchain;resultchain->next!=NULL;resultchain=resultchain->next)
	        printf("%ld\n",resultchain->record.number);
	        break;
	defalult:
	    	return 0;	
	}

}
