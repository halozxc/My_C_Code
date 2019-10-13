#include<stdio.h>
#include<stdlib.h>
typedef struct tagNode
{
    float coef;
    int exp;
    tagNode *next;
};
typedef tagNode *Node;
Node init_Node()
{
    Node h=NULL,t=NULL;
    Node p=(Node)malloc(sizeof(tagNode));
    //printf("������ϵ����ָ��(����0������)\n");
    scanf("%f %d",&p->coef,&p->exp);
    while(p->coef!=0)
    {
        if(h==NULL)
        {
            t=h=p;

        }
        else
        {
            t->next=p;
            t=t->next;
        }
        t->next=NULL;
        p=(Node)malloc(sizeof(tagNode));
        scanf("%f %d",&p->coef,&p->exp);
    }

return h;
}
void print_poly(Node p,int x)
    {
    printf("Y%d=",x);
    Node h=p;
    while(h!=NULL)
    {
        if(p==h)
        {
            if(h->exp==0) printf("%.1f",h->coef,h->exp);
            else printf("%.1fx^%d",h->coef,h->exp);
        
        }
        else 
        {
            
            if(h->coef>1) {
                printf("+%.1fx^%d",h->coef,h->exp);
            }
            else {
                printf("%.1fx^%d",h->coef,h->exp);
            }
        }
        
        h=h->next;
    }
    printf("\n");
    
    }
void add_poly(Node pa,Node pb,int o)
{
	Node p=pa;//链表1，将来的结果也放在此
	Node q=pb;//链表2
	Node pre=pa;
	Node u;//临时用
	float x;

	while (p!=NULL && q!=NULL)//当两个链表都不为空
	{
//比较链表1跟链表2当前节点的指数大小，链表1也是存放结果的地方
		if (p->exp<q->exp) 
		{
			pre=p;
            //p指向要比较的下一个结点。pre指向的是结果链表的最后一个结点。
			p=p->next; 
		}
		else if (p->exp==q->exp)//假如链表1和链表2的指数相等，就要系数相加
		{
			if(o>0)x=p->coef+q->coef;
            else x=p->coef-q->coef;
			
            if (x!=0)//相加后的系数不为0，有必要保留一个结点就可以了
			{
				p->coef=x;
				pre=p;
			}
			else 
                                     //如果相加后，系数是0，不需要保留任何一个结点，
                                       //在这里删除链表1的结点，下面删除链表2的结点
			{
				pre->next=p->next;//保持链表1的连续性
				free(p);
			}
			p=pre->next;//p指向要比较的下一个结点
			                         //下面的代码是进行链表2结点的删除工作
                                     //因为指数相等，仅仅需要保留一个结点就可以了
			                         //而结果直接保存在链表1中，所以，删除链表2的结点。
			u=q;
			q=q->next;
			free(u);
		}
		else
                                                //如果链表2的当前节点指数小，
                                                //那么要把链表2的当前节点加入到结果链表中（即是链表1）
		{
                                                //相当于把结点插入到链表1中，
                                                //用u作为临时变量，保存链表2的下一个当前节点的位置。
			u=q->next;
			q->next=p;
			pre->next=q;
			pre=q;//pre指向了新插入的节点
			if(o<0) pre->coef=-1*pre->coef;//如果是减法就改符号
            q=u;
		}
	
	}
//如果链表2比链表1长，那么需要把链表2多余的部分加入结果链表中。
//链表1比链表2长，则什么都不用做。
	if (q) 
	{
			pre->next=q;
	}
	free(pb);
}

int main()
    {
    int x=0;
    scanf("%d",&x);
    Node x1=init_Node();//建立多项式1
    print_poly(x1,1);
    Node x2=init_Node();//建立多项式2
     print_poly(x2,2);
    add_poly(x1,x2,x);//x是用来控制加减法的
    printf("%d",x1->coef);
    //print_poly(x1,3);
    return 0;
    }
