#include<stdio.h>
#include<string>
#include<stdlib.h>
FILE* fpin, * fpout;
char filename[] = "std.txt";

typedef struct stu_record {
	long number;
	char name[10];
	char CourseName[10];
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
	head = tail = NULL;

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
		fscanf(fp, "%s %s %l %l %l %d %d", &p->record.name, &p->record.CourseName, &p->record.number, &p->record.CourseNum, &p->record.classnum, &p->record.CourseScore, &p->record.TestScore);
		p->next = NULL;
		tail->next = p;
		tail = p;
		p = (struct stud_node*)malloc(size);

		num++;
	}
	p->next = NULL;
	tail->next = head;
	tail = p;
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
int AddNew() {
	long number;
	char name[10];
	char CourseName[10];
	long classnum;
	long CourseNum;
	int CourseScore;
	int TestScore;
   getchar();
    printf("����ѧ������");
    gets(name);
    printf("����γ�����");
	gets(CourseName);
	printf("����ѧ��");
	scanf("%ld",&number);
	printf("�γ����\n");
	scanf("%ld",&CourseNum);
	printf("�༶\n");
	scanf("%ld",&classnum);
	printf("����������ѧ��ƽʱ�ɼ�\n");
	scanf("%d",&CourseScore);
	printf("����������ѧ����ĩ�ɼ�\n");
	scanf("%d",&TestScore);
    printf("%s %s %ld %ld %ld %d %d\n",name,CourseName,number,CourseNum,classnum,CourseScore,TestScore);  
	
	fprintf(fpin,"%s %s %ld %ld %ld %d %d\n",name,CourseName,number,CourseNum,classnum,CourseScore,TestScore);
    return 0;
}
int main() {
	int op;
	
	printf("ѧ����Ϣ����ϵͳ\n\n");
	printf("1,����ѧ����Ϣ\n");
	printf("2���޸�ѧ����Ϣ\n");
	printf("3����������ѯ\n");
	printf("4,��ѧ�Ų�ѯ\n");
	printf("5,���༶��ѯ\n");
	printf("6�����γ�����ѯ\n");
	printf("7�����ָܷߵ�����\n");
	printf("8,���Ƴɼ�����\n");
	printf("9����ѯ�༶������\n");
	printf("�˳�\n");
	scanf("%d", &op);
	
	switch(op)
	{
	case 1:
		fpin=fopen(filename, "a");
	    AddNew();
	    break;
	defalult:
	    	return 0;	
	}

}
