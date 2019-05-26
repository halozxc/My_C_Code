#include<stdio.h>
#include<string>
#include<stdlib.h>
typedef struct record {
	float number;
	char name[10];
	char CourseName[10];
	int CourseNum;
	int CourseScore;
	int TestScore;
	int FinalScore;
};
int main()
{
  
 
	record Stu[100];
	int max = 0;
	int maxnum, minnum;
	int min = 100;
	int n=0;
	int Foption;
	FILE* S_data,*S_T_data;
	char aline[15];
	printf("读取文件请摁1,手动输入请摁2，退出请按0");
	  scanf("%d",&Foption);
	int count=0;
	S_T_data=fopen("T_data.txt","w");
	S_data=fopen("data.txt", "r");
	while(Foption!=0) 
	{
	
	if (Foption == 2)
	{
		printf("现在请输入学生信息,键入0来结束");
		bool con = true;
		
		while (con)
		{
			printf ("现在请输入学生%d学号\n",count+1);
			scanf("%d",&Stu[count].number);
			printf ("现在请输入学生%d姓名\n" ,count+1);
			getchar();
			gets(Stu[count].name);
		     printf ("课程名\n" );
			gets(Stu[count].CourseName);
			printf("课程序号\n");
			scanf("%d",&Stu[count].CourseNum);
			printf ("现在请输入学生%d平时成绩\n",count+1);
			scanf("%d",&Stu[count].CourseScore);
			printf("现在请输入学生%d期末成绩\n",count+1);
			scanf("%d",&Stu[count].TestScore);
		    Stu[count].FinalScore = Stu[count].CourseScore * 0.2 + Stu[count].TestScore * 0.8;
			fprintf(S_T_data,"学生%d的总分：%d\n",count+1,Stu[count].FinalScore);
			if (Stu[count].FinalScore > max)
			{
				max = Stu[count].FinalScore;
				maxnum = count;
			}
			if (Stu[count].FinalScore < min)
			{
				min = Stu[count].FinalScore;
				minnum = count;
			}
			count++;
			printf("继续吗？摁0退出手动输入");
			scanf("%d",&con);
		}
	}
	else if(Foption == 1)
	{
		   count =0;
		   while (!feof(S_data)) 
			{
				fscanf(S_data,"%d %d\n",&Stu[count].CourseScore,&Stu[count].TestScore);
				printf("course score:%d\n",Stu[count].CourseScore);
				printf("Test score:%d\n",Stu[count].TestScore);
		        Stu[count].FinalScore = Stu[count].CourseScore * 0.2 + Stu[count].TestScore * 0.8;
		        	fprintf(S_T_data,"学生%d的总分：%d\n",count+1,Stu[count].FinalScore);
					if (Stu[n].FinalScore > max)
			    {
				max = Stu[count].FinalScore;
				maxnum = count;
			    }
				if (Stu[count].FinalScore < min)
				{
					min = Stu[count].FinalScore;
					minnum = count;
				}
			count++;
			}
		    
		
	    
	}
printf("重读文件请摁1,手动添加请摁2，退出请按0");
scanf("%d",&Foption);
}
	fclose(S_data);
	fclose(S_T_data);
	for (int i = 0; i < n; i++) {
		printf ("%s的总成绩%d",Stu[i].name,Stu[i].FinalScore);

    }
	printf ("分数最高的学生是%s分数为：%d\n",Stu[maxnum].name,Stu[maxnum].FinalScore);
    printf ("分数最低的学生是%s分数为：%d\n",Stu[minnum].name,Stu[minnum].FinalScore);
}
