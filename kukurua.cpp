#include <stdio.h>
#include <stdlib.h>
struct node
{ //链表结点类型，包含一个存放整型数据的 data 成员，和一个指向下一个结点的next成员
    int data;
    struct node *next;
};
typedef struct node *Rlist;
//第一关代码
struct node *createRlist()
{
    //函数功能：创建一个有一个空循环链表，返回值为头指针
    Rlist head = (Rlist)malloc(sizeof(struct node)); //头指针
    head->next = NULL;
    return head;
}
void insertOrder(struct node *list, int insData)
{
    //在单向递增有序的循环链表（表头指针list）中插入数据元素insData，使之依然有序 。
    Rlist p;
    Rlist q = (Rlist)malloc(sizeof(struct node));
    q->data = insData;

    if (list->next) //判断循环链表是否为空
    {
        if (list->next->next == list) //只有一个结点时
        {
            p = list->next;
            if (p->data >= insData)
            {
                list->next = q;
                q->next = p;
            }
            else if (p->data < insData)
            {
                q->next = list;
                p->next = q;
            }
        }
        else
        {
            int flag = 1;
            p = list->next;

            while (p != list)
            {
                if (p->data >= insData)
                {
                    flag = 0;
                    q->next = p;
                    list->next = q;
                    break;
                }
                p = p->next;
            }
            if (flag)
            {
                while (p->next != list)
                    p = p->next;

                q->next = list;
                p->next = q;
            }
        }
    }
    else
    {
        Rlist p = (Rlist)malloc(sizeof(struct node));
        p->data = insData;
        list->next = p;
        p->next = list;
    }
}

int deleteData(struct node *list, int delData)
{
    //在单向递增有序循环链表（表头指针list）中删除所有值为delData的结点,返回值为删除结点的个数
    Rlist p = list;
    int number = 0;
    while (p->next!=list)
    {
        if (p->next->data == delData)
        {
            p->next = p->next->next;
            number++;
        }
        p = p->next;
    }    
    return number;
}

void printRlist(struct node *list)
{
    //从链表第一个结点开始输出单向循环链表中各数据元素的值，每输出一个数据元素空一格
    Rlist p = list->next;
    while (p != list)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int destroyRlist(struct node *list)
{
    //从第一个结点开始释放循环链表各结点占用的空间,返回值为最后一个结点的值
    int data;
    Rlist p = list->next;
    list->next = NULL;
    list = p;
    while (list!=NULL)
    {
        data = list->data;
        p = p->next;
        free(list);
        list = p;
    }
    return data;
}

int main()
{
    struct node *head = createRlist();
    int num, data;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &data);
        insertOrder(head, data);
    }
    printRlist(head);
    scanf("%d",&data);
    printf("\n%d ",deleteData(head,data));
    printf("\n%d ",destroyRlist(head));

    system("pause");
    return 1;
}
