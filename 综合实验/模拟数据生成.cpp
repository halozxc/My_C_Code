#include<fstream>
#include<iostream>
#include<string>
#include<windows.h>
#include<time.h>
using namespace std;
int main() {
	float count;//����������ɶ� 
	float process;
	int classpop=15,pop=40;//classpopָ���ǰ༶��Ŀ,pop��ÿ��������� 
	srand((unsigned int)time(0));//Ϊ�˱����������̬�����ԡ��� 
	long number, coursenum, classname;//number�����ѧ�ţ�coursenum�ǿκţ�classname�ǰ༶���� 
	int testscore, coursescore;// testscore����ĩ���Է�����coursescore��ƽʱ�֣����ڴ�Һܹ��ĵ��ܳɼ��ش�Ҿ����Լ��ļƷַ�ʽ����� 
	string  course[] = {"��ѧӢ��","�ߵ���ѧ","��ɢ��ѧ","��ѧ����","C����","����ʷ","��ѧ����"};//���еĿγ̶�������������Ҫ�������ӵĿ�����������Ŷ�� 
	ofstream fout("std.txt");//������ļ������� 
	string LastName = "���ŷ���������Ի�������֣��������θ�����л���������˲��������ﶭ��Ԭ�ڽ������Ҷ����κ��������Ҧ¬������̷½������ʯ�μ���Τ������������������Ѧ�ֶ��׺���ʷ����ع�ë�¹�����Ǯ�����Ӵ�Ī������";//98�������� 
	string firstname = "��˴ة�����ʳ�������΁��������٩٭��ٹ��ٶ�ނ�����������ɮ���忡ΰ����մ�����ۿ�ƿ���������ʿ׳���ؿ�����������ʵ�����ž��獃����Ѳ˧��ս�ų�����ի���˕������B��A�S衬d���k���`�Z�`����봣ʸʯ��ɰ�Vʾ������������¿�����������ϴ�����������ӽܰ�����������ֶ�����������﬷������ظ�������Լݽ���ں��Ľ�����Ὠ��ǿ���������ʿ����н�������Х��ľ��ɭ��幺����߿�κ����ӥاƹ�����ı��ܱ��ܷ�ɽ���������������c��ʤ���������ΜB���������읻����尲���������������ϲ��������𺫸�����Ƶ������������ڴ�����������׿�܆�չ�۳ڏ|�������ɵ�־��˼��ͦ���@�F껕f���ɕ����ʶε�̩�����������ѡ���¾�������������λ�īŷ����������ٻ�߂�����ױ�����Ǻ���Ůū�����������濹ý��ɩ���ͼ������������㊠�������������������泶��ċ������价�}ɺ���᫝�������������õ���ջ������ޱ��ҷ�о����ݦ������Ө��֥Ƽ��ƻ�ٲ�������ɯ��ݼԷܷܿ�������Ӣ����޹ӱ�M��ݮ��ˮ���������������������������������˪ѩϼ�����I�����¶Ʈ����������������������������ݴ��ź촺����������ƻ���ٳ���������ͮ������������������ع�������ʻ�ӯü�޷��������Ҷ���ڼν�����������Խ��ϣ�����ݵ�ͮ��Ӱ����������˼˿��ˬ����������԰���Ļ���˸��������ȻȽƽ����������";//500+ȡ�������� 
    for (int i = 1; i <= classpop; i++)
	{
		classname = 18000 + i ;//�༶�����18001��ʼ 
		for (int j = 1; j <= pop; j++)
		{
			number = classname*1000 + j;//ѧ�Ŵ�18001001��ʼ 
			int a = rand() %539;
			int b = rand() % 98;
			
			for (int k = 0; k < 7; k++)
			{
				coursenum = (18000 + k)*10+rand()%4;
				testscore = rand() % 101;
				coursescore = rand() % 101;
				fout << LastName[b * 2] << LastName[b * 2 + 1] << firstname[a * 2] << firstname[a * 2 + 1] << " " << course[k] << " " <<number<<" "<<coursenum<<" "<<classname << " " << coursescore << " " << testscore << endl;
				//д���ļ� ���������� �γ����� ѧ�� �κ� �༶���� ƽʱ�� ��ĩ���Է����ĸ�ʽ��ӡ���ļ���
				//���Ҫ�Զ����ӡ��ʽ����ע�� ��LastName[b * 2] << LastName[b * 2 + 1] << firstname[a * 2] << firstname[a * 2 + 1] ��һ�����ɷָ�����壬Ҫ���忽��ճ�� 
						
			}
		}
	system("cls");
				count++;
				process=100*count/15;
				cout<<process<<"%";	
	}
	return 0;
}
