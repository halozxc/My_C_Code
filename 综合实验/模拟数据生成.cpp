#include<fstream>
#include<iostream>
#include<string>
#include<windows.h>
#include<time.h>
using namespace std;
int main() {
	float count;
	float process;
	srand((unsigned int)time(0));
	long number, coursenum, classname;
	int testscore, coursescore;
	string  course[] = {"��ѧӢ��","�ߵ���ѧ","��ɢ��ѧ","��ѧ����","����������������","����������������ʵ��","��ѧ����"};
	ofstream fout("std.txt");
	string LastName = "���ŷ���������Ի�������֣��������θ�����л���������˲��������ﶭ��Ԭ�ڽ������Ҷ����κ��������Ҧ¬������̷½������ʯ�μ���Τ������������������Ѧ�ֶ��׺���ʷ����ع�ë�¹�����Ǯ�����Ӵ�Ī������";
	string firstname = "��˴ة�����ʳ�������΁��������٩٭��ٹ��ٶ�ނ�����������ɮ���忡ΰ����մ�����ۿ�ƿ���������ʿ׳���ؿ�����������ʵ�����ž��獃����Ѳ˧��ս�ų�����ի���˕������B��A�S衬d���k���`�Z�`����봣ʸʯ��ɰ�Vʾ������������¿�����������ϴ�����������ӽܰ�����������ֶ�����������﬷������ظ�������Լݽ���ں��Ľ�����Ὠ��ǿ���������ʿ����н�������Х��ľ��ɭ��幺����߿�κ����ӥاƹ�����ı��ܱ��ܷ�ɽ���������������c��ʤ���������ΜB���������읻����尲���������������ϲ��������𺫸�����Ƶ������������ڴ�����������׿�܆�չ�۳ڏ|�������ɵ�־��˼��ͦ���@�F껕f���ɕ����ʶε�̩�����������ѡ���¾�������������λ�īŷ����������ٻ�߂�����ױ�����Ǻ���Ůū�����������濹ý��ɩ���ͼ������������㊠�������������������泶��ċ������价�}ɺ���᫝�������������õ���ջ������ޱ��ҷ�о����ݦ������Ө��֥Ƽ��ƻ�ٲ�������ɯ��ݼԷܷܿ�������Ӣ����޹ӱ�M��ݮ��ˮ���������������������������������˪ѩϼ�����I�����¶Ʈ����������������������������ݴ��ź촺����������ƻ���ٳ���������ͮ������������������ع�������ʻ�ӯü�޷��������Ҷ���ڼν�����������Խ��ϣ�����ݵ�ͮ��Ӱ����������˼˿��ˬ����������԰���Ļ���˸��������ȻȽƽ����������";
	//cout << course[0];
	
	for (int i = 1; i <= 15; i++)
	{
		classname = 18000000 + i * 1000;
		for (int j = 1; j <= 40; j++)
		{
			number = classname + j;
			int a = rand() %539;
			int b = rand() % 98;
			
			for (int k = 0; k < 7; k++)
			{
				coursenum = 18000 + k;
				testscore = rand() % 101;
				coursescore = rand() % 101;
				fout << LastName[b * 2] << LastName[b * 2 + 1] << firstname[a * 2] << firstname[a * 2 + 1] << " " << course[k] << " " <<number<<" "<<coursenum<<" "<<classname << " " << coursescore << " " << testscore << endl;
				
						
			}
		}
	system("cls");
				count++;
				process=100*count/15;
				cout<<process<<"%";	
	}
	return 0;
}
