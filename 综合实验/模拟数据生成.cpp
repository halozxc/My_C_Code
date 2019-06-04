#include<fstream>
#include<iostream>
#include<string>
#include<windows.h>
#include<time.h>
using namespace std;
int main() {
	float count;//数据生成完成度 
	float process;
	int classpop=15,pop=40;//classpop指的是班级数目,pop是每个班的人数 
	srand((unsigned int)time(0));//为了保持随机数生态多样性。。 
	long number, coursenum, classname;//number是你的学号，coursenum是课号，classname是班级号码 
	int testscore, coursescore;// testscore是期末考试分数，coursescore是平时分，至于大家很关心的总成绩呢大家就用自己的计分方式计算吧 
	string  course[] = {"大学英语","高等数学","离散数学","大学物理","程序设计与问题求解","程序设计与问题求解实验","大学体育"};//所有的课程都在这里啦，想要继续添加的可以自行添加哦； 
	ofstream fout("std.txt");//输出的文件的名字 
	string LastName = "李张冯王刘杨陈赵黄周吴徐郑马朱胡郭何高孙梁谢宋唐许韩邓曹彭曾萧田董潘袁于蒋蔡余杜叶程苏魏吕丁任沈姚卢姜崔钟谭陆汪范金石廖贾夏韦傅方白邹孟熊秦邱江尹薛阎段雷侯龙史陶黎贺顾毛郝龚邵万钱严覃河戴莫孔向汤";//98个常用姓 
	string firstname = "世舜丞主产仁仇仓仕仞任伋众伸佐佺侃侪促俟信俣修倝倡倧偿储僖僧僳儒俊伟列则刚创剑助劭势勘参叔吏嗣士壮孺守宽宾宋宗宙宣实宰尊峙峻崇崈川州巡帅庚战才承拯操斋昌晁暠曹曾珺玮珹琒琛琩琮琸瑎玚璟璥瑜生畴矗矢石磊砂碫示社祖祚祥禅稹穆竣竦综缜绪舱舷船蚩襦轼辑轩子杰榜碧葆莱蒲天乐东钢铎铖铠铸铿锋镇键镰馗旭骏骢骥驹驾骄诚诤赐慕端征坚建弓强彦御悍擎攀旷昂晷健冀凯劻啸柴木林森朴骞寒函高魁魏鲛鲲鹰丕乒候冕勰备宪宾密封山峰弼彪彭旁日明昪昴胜汉涵汗浩涛淏清澜浦澉澎澔濮濯瀚瀛灏沧虚豪豹辅辈迈邶合部阔雄霆震韩俯颁颇频颔风飒飙飚马亮仑仝代儋利力劼勒卓哲喆展帝弛弢弩彰征律德志忠思振挺掣旲旻昊昮晋晟晸朕朗段殿泰滕炅炜煜煊炎选玄勇君稼黎利贤谊金鑫辉墨欧有友闻问俞倩倪倰偀偲妆佳亿仪寒宜女奴妶好妃姗姝姹姿婵姑姜姣嫂嫦嫱姬娇娟嫣婕婧娴婉姐姞姯姲姳娘娜妹妍妙妹娆娉娥媚媱嫔婷玟环珆珊珠玲珴瑛琼瑶瑾瑞珍琦玫琪琳环琬瑗琰薇珂芬芳芯花茜荭荷莲莉莹菊芝萍燕苹荣草蕊芮蓝莎菀菁苑芸芊茗荔菲蓉英蓓蕾薰颖芃蔓莓曼水淼滟滢淑洁清澜波淞渺漩漪涟湾汇冰冷冽霜雪霞霖香馡馥秋秀露飘育滢馥筠柔竹霭凝晓欢枫巧美静惠翠雅红春岚嵘兰羽素云华丽俪叆呤咛囡彩彤彨怜晴月明晶昭星卿毓可璧青灵彩慧盈眉艳凡凤风贞勤叶雁钰嘉锦黛怡情林梦越悦希宁欣容丹彤颜影韵音银纯纹思丝纤爽舒伊依亚融园文心火炎烁炫煜烟炅然冉平屏评宛玉雨";//500+取名常用字 
    for (int i = 1; i <= classpop; i++)
	{
		classname = 18000 + i ;//班级号码从18001开始 
		for (int j = 1; j <= pop; j++)
		{
			number = classname*1000 + j;//学号从18001001开始 
			int a = rand() %539;
			int b = rand() % 98;
			
			for (int k = 0; k < 7; k++)
			{
				coursenum = 18000 + k;
				testscore = rand() % 101;
				coursescore = rand() % 101;
				fout << LastName[b * 2] << LastName[b * 2 + 1] << firstname[a * 2] << firstname[a * 2 + 1] << " " << course[k] << " " <<number<<" "<<coursenum<<" "<<classname << " " << coursescore << " " << testscore << endl;
				//写入文件 （按照姓名 课程名字 学号 课号 班级号码 平时分 期末考试分数的格式打印到文件）
				//如果要自定义打印格式，请注意 ：LastName[b * 2] << LastName[b * 2 + 1] << firstname[a * 2] << firstname[a * 2 + 1] 是一个不可分割的整体，要整体拷贝粘贴 
						
			}
		}
	system("cls");
				count++;
				process=100*count/15;
				cout<<process<<"%";	
	}
	return 0;
}
