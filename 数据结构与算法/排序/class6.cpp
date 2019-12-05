#include <bits/stdc++.h>
#include<time.h>
#include<windows.h>
using namespace std;
const int NUM =100000;
int a[NUM];
int tempArray[NUM];
clock_t start, finish;
long long moveNum = 0;
long long compareNum=0;
int sizeodarray;
struct StaticItem{
    int index;
    string name;
    double value;
    StaticItem(){
        index=0;
        name="null";
        value=0;
    }
    StaticItem(string _name,int _index){
        //��λ
        string unit;
        //ͳ����Ŀ
        name=_name;
        //���
        index=_index;
        //ͳ��ֵ
        value =0;
    }
    void upCount(){
        value++;
    }
    void downCount(){
        value--;
    }
};
class MyStatic{
 vector<StaticItem>  staticPool;
 public :
 StaticItem* add(string name){
    staticPool.push_back(StaticItem(name,rand()));
     return &staticPool.back();
 }
void   toResult(){
    string t;
    cout<<staticPool.size();
    for(int i=0;i<staticPool.size();i++){
      cout<<staticPool[i].name<<"��ͳ�ƽ��Ϊ"<<staticPool[i].value<<endl;
    }
}
} sortStatic;
void newArray(){
    for (int i = 0; i <sizeodarray;i++){
        tempArray[i] = a[i];
    }
}
void myswap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void straightInsert(int *arr, int n,char q)
{


    for (int i = 1; i < n; i++)
    {
        
        compareNum++;
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
        if(q=='<'){
            
            if (arr[j] > temp)
            {
                moveNum++;
                arr[j + 1] = arr[j];
            
            }
            else
            {
                break;
            }
        }
        else if(q=='>'){
           
            if (arr[j] < temp)
            {
                moveNum++;
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        }
        arr[j + 1] = temp;
       //print(arr, n);
    }
}
void popSort(int *arr, int n,char q)
{
    
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < n - i - 1; j++)
        {
            compareNum++;
        if(q=='<'){
            if (arr[j + 1] < arr[j])
            {
                moveNum++;
                myswap(arr[j + 1], arr[j]);
            }
        }
        else if(q=='>'){
            if (arr[j + 1] > arr[j])
            {
                moveNum++;
                myswap(arr[j + 1], arr[j]);
            }
        }
            
        }
        //print(arr, n);
    }
}
int partition(int arr[], int left, int right,char q) //�һ�׼�� ����
{
    
    int i = left + 1;
    int j = right;
    int temp = arr[left];
    while (i <= j)
    {
        
     if(q=='<'){
            while (arr[i] < temp)
        {
           compareNum++;
            i++;
        }
        while (arr[j] > temp)
        {
            compareNum++;
            j--;
        }
     }
     else if (q=='>'){
         while (arr[i] > temp)
        {
            compareNum++;
            i++;
        }
        while (arr[j] < temp)
        {
           compareNum++;
            j--;
        }
    }
        if (i < j){
            swap(arr[i++], arr[j--]);
            moveNum++;
            }

        else
            i++;
    }
    swap(arr[j], arr[left]);
   // print(arr, NUM);
    return j;
}
void quick_sort(int arr[], int left, int right,char q)
{

    
    if (left > right)
        return;
    int j = partition(arr, left, right,q);
    quick_sort(arr, left, j - 1,q);
    quick_sort(arr, j + 1, right,q);
}
/*�ú����������±귶Χ[l1,r1]��[l2,r2]���������кϲ���һ����������*/
void merge(int *arr, int l1, int r1, int l2, int r2,char q)
{
    

    int i = l1;                            //��벿����ʼλ��
    int j = l2;                            //�Ұ벿����ʼλ��
    int n = (r1 - l1 + 1) + (r2 - l2 + 1); //Ҫ�ϲ���Ԫ�ظ���
    vector<int> temp(n);                   //��������
    int k = 0;                             //������������ʼλ��
    while (i <= r1 && j <= r2)
    { //��ѡ����������С��Ԫ�ط��븨��������
        
    if(q=='<'){
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    else if(q=='>'){
        if (arr[i] > arr[j])
            
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
       
    }
    //�������ʣ�ֱ࣬�ӷ��뵽����������
    while (i <= r1){
        moveNum++;
        temp[k++] = arr[i++];
    }
    while (j <= r2){
        moveNum++;
        temp[k++] = arr[j++];
    }
    //����ԭʼ����Ԫ��
    for (int i = 0; i < n; i++)
    {
        moveNum++;
        arr[l1 + i] = temp[i];
    }
}

/*��·�鲢���򣨵ݹ�ʵ�֣�*/
void MergeSort(int *arr, int start, int end,char q)
{
  
    if (start < end)
    {
        int mid = (start + end) >> 1;         //�ָ�����
        MergeSort(arr, start, mid,q);           //��������벿�ֽ��й沢����
        MergeSort(arr, mid + 1, end,q);         //�������Ұ벿�ֽ��й沢����
        merge(arr, start, mid, mid + 1, end,q); //�ϲ��Ѿ��������������
    }
}

int main()
{
    sizeodarray=0;   
    int i=0;
    while(cin>>a[i]){
        i++;
    }
    sizeodarray=i;
    printf("����%d������\n",i);
    newArray();
    straightInsert(tempArray, NUM,'<');
    printf("straightInsert ������������ compareNUM:%lld moveNum:%lld\n",compareNum,moveNum);
    moveNum = 0,compareNum=0;
    straightInsert(tempArray, NUM,'>');
    printf("straightInsert ������������� compareNUM:%lld moveNum:%lld\n",compareNum,moveNum);
    moveNum = 0,compareNum=0;
    straightInsert(tempArray, NUM,'>');
    printf("straightInsert ��˳��������� compareNUM:%lld moveNum:%lld\n",compareNum,moveNum);
    moveNum = 0,compareNum=0;
    newArray();
    popSort(tempArray, NUM,'<');
    printf("popSort ������������ compareNUM:%lld moveNum:%lld\n",compareNum,moveNum);
    moveNum = 0,compareNum=0;
    popSort(tempArray, NUM,'>');
    printf("popSort ������������� compareNUM:%lld moveNum:%lld\n",compareNum,moveNum);
     moveNum = 0,compareNum=0;
    popSort(tempArray, NUM,'>');
    printf("popSort ��˳��������� compareNUM:%lld moveNum:%lld\n",compareNum,moveNum);
    moveNum = 0,compareNum=0;
    newArray();
    quick_sort(tempArray, 0, sizeodarray,'<');
    printf("quick_sort ������������ compareNUM:%lld moveNum:%lld\n",compareNum,moveNum);
    moveNum = 0,compareNum=0;
    quick_sort(tempArray, 0, sizeodarray,'>');
    printf("quick_sort ������������� compareNUM:%lld moveNum:%lld\n",compareNum,moveNum);
     moveNum = 0,compareNum=0;
    quick_sort(tempArray, 0, sizeodarray,'>');
    printf("quick_sort ��˳��������� compareNUM:%lld moveNum:%lld\n",compareNum,moveNum);
    moveNum = 0,compareNum=0;
    newArray();
    MergeSort(tempArray, 0, sizeodarray,'<');
    printf("MergeSort ������������ compareNUM:%lld moveNum:%lld\n",compareNum,moveNum);
    moveNum = 0,compareNum=0;
    MergeSort(tempArray, 0, sizeodarray,'>');
    printf("MergeSort ������������� compareNUM:%lld moveNum:%lld\n",compareNum,moveNum);
    moveNum = 0,compareNum=0;
    MergeSort(tempArray, 0, sizeodarray,'>');
    printf("MergeSort ��˳��������� compareNUM:%lld moveNum:%lld\n",compareNum,moveNum);
    return 0;
}
