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
	printf("��ȡ�ļ�����1,�ֶ���������2���˳��밴0");
	  scanf("%d",&Foption);
	int count=0;
	S_T_data=fopen("T_data.txt","w");
	S_data=fopen("data.txt", "r");
	while(Foption!=0) 
	{
	
	if (Foption == 2)
	{
		printf("����������ѧ����Ϣ,����0������");
		bool con = true;
		
		while (con)
		{
			printf ("����������ѧ��%dѧ��\n",count+1);
			scanf("%d",&Stu[count].number);
			printf ("����������ѧ��%d����\n" ,count+1);
			getchar();
			gets(Stu[count].name);
		     printf ("�γ���\n" );
			gets(Stu[count].CourseName);
			printf("�γ����\n");
			scanf("%d",&Stu[count].CourseNum);
			printf ("����������ѧ��%dƽʱ�ɼ�\n",count+1);
			scanf("%d",&Stu[count].CourseScore);
			printf("����������ѧ��%d��ĩ�ɼ�\n",count+1);
			scanf("%d",&Stu[count].TestScore);
		    Stu[count].FinalScore = Stu[count].CourseScore * 0.2 + Stu[count].TestScore * 0.8;
			fprintf(S_T_data,"ѧ��%d���ܷ֣�%d\n",count+1,Stu[count].FinalScore);
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
			printf("��������0�˳��ֶ�����");
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
		        	fprintf(S_T_data,"ѧ��%d���ܷ֣�%d\n",count+1,Stu[count].FinalScore);
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
printf("�ض��ļ�����1,�ֶ��������2���˳��밴0");
scanf("%d",&Foption);
}
	fclose(S_data);
	fclose(S_T_data);
	for (int i = 0; i < n; i++) {
		printf ("%s���ܳɼ�%d",Stu[i].name,Stu[i].FinalScore);

    }
	printf ("������ߵ�ѧ����%s����Ϊ��%d\n",Stu[maxnum].name,Stu[maxnum].FinalScore);
    printf ("������͵�ѧ����%s����Ϊ��%d\n",Stu[minnum].name,Stu[minnum].FinalScore);
}
