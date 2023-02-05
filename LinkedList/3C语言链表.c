



#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdbool.h>

typedef struct student{
    int score;//数据域；
    struct student *next;//指针域；
}Linklist;

Linklist *creat(int n)//创建链表
{
    Linklist *head,*node,*end;
    head=(Linklist*)malloc(sizeof(Linklist));
    end=head;
    for(int i=0;i<n;i++)
    {
        node=(Linklist*)malloc(sizeof(Linklist));
        scanf("%d",&node->score);
        end->next=node;
        end=node;
    }
    end->next=NULL;
    return head;
}
void change(Linklist*list,int n)//修改链表
//n是要修改的第n个节点，因为链表只能顺序访问不能随机访问，不好用，学这个用来入门数据结构
{
    Linklist*t=list;
    int i=0;
    while(i<n&&t!=NULL)//往后移去找第N个节点
    {
        t=t->next;
        i++;
    }
    if(t!=NULL)
    {
        puts("快点地，输入要修改的值");
        scanf("%d",&t->score);
        printf("修改成功\n");
    }
    else puts("节点不存在哟");
}
void delet(Linklist*list,int n)//删除链表中的值
{
    Linklist *t=list,*in;
    int i=0;
    while(i<n&&t!=NULL) {
        in=t;//in指向的一直是现在t所指向的上一个（先让in指向t，再让t指向下一个）
        t=t->next;
        i++;
    }
    if(t!=NULL) {
        in->next=t->next;//要删除t，让指向它的指针指向下一个，跳过t就是删除了t；
        free(t);//清除t的内存；
    }
    else {
    	puts("节点不存在！请以后再来探索吧");
    }
}
void insert (Linklist*list,int n)//插入链表    （在第n位之后插入值（插完之后是第n+1位））
{
    Linklist*t=list,*in;
    int i=0;
    while(i<n&&t!=NULL) {
        t=t->next;//先找到要插入的位置
        i++;
    }

    if(t!=NULL) {
        in=(Linklist*)malloc(sizeof(Linklist));
        puts("请输入要插入的值：");
        scanf("%d",&in->score);
        in->next=t->next;
        t->next=in;
        puts("插进去了呢");
    }
    else {
    	puts("节点不存在，你别玩我呀");
    } 
}
void coutlist(Linklist*head)//输出链表的值；
{
    while(head->next!=NULL) {
        head=head->next;
        printf("%d ",head->score);
    }
    printf("\n");
}

// 输出链表的长度（带头结点）
// 统计链表的长度
void coutlength(Linklist*list) {
    Linklist*t=list;//非空表的情况下指向的是第一个结点而不是头结点
    int ans=0;
    while(t->next)
    {
        t=t->next;
        ans++;
    }
    printf("%d\n",ans);
}
void find(Linklist*lists,int x)//按值查找w
{
    Linklist* t=lists->next;
    while(t!=NULL&&t->score!=x)
        t=t->next;
    if(t!=NULL)printf("太棒了，找到了呢\n");
    return ;
}
void list()//控制面板
{
    printf("这是一个单链表\n------------------------------------------\nPlease press the button:\n");
    printf("Button 1 ---> 创建单链表\n");				//创建单链表 (带头结点、表尾插入)
    printf("Button 2 ---> 获取链表长度\n");				//获取链表长度
    printf("Button 3 ---> 插入结点\n");				//按序号查找
    printf("Button 4 ---> 按值查找\n");				//按值查找
    printf("Button 5 ---> 删除结点\n");		//插入结点
    printf("Button 6 ---> 修改节点\n");				//删除结点
    printf("Button 7 ---> 输出链表的值\n");							//遍历链表
    printf("Button 8 ---> Exit the program\n-----------------------------------\n");					//退出程序
}

int main()
{
    list();
    Linklist*h;
    int n,x,m;
    while(true)
    {
        scanf("%d",&n);
        if(n==1)
        {
            printf("请输入一个数字，创建长度为n的链表:\n请输入要加入链表的数：");
            scanf("%d",&x);
            h=creat(x);
            printf("Please press the button:\n");
        }
        if(n==2)
        {
            printf("单链表的长度是:");
            coutlength(h);
            printf("Please press the button:\n");
        }
        if(n==3)
        {
            printf("你想插到哪儿？(手动滑稽)");
            scanf("%d",&x);
            insert (h,x);
            printf("Please press the button:\n");
        }
        if(n==4)
        {
            printf("请输入你要找的值");
            scanf("%d",&m);
            find(h,m);
            printf("Please press the button:\n");
        }
        if(n==5)
        {
            printf("你敢删谁？有种你试试！\n");
            scanf("%d",&x);
            delet(h,x);
            printf("还真敢呐，太顶了！\n");
            printf("Please press the button:\n");
        }
        if(n==6)
        {
            printf("你要改那个值？");
            scanf("%d",&x);
            change(h,x);
            printf("Please press the button:\n");
        }
        if(n==7)
        {
            coutlist(h);
            printf("Please press the button:\n");
        }
        if(n==8)
        {
            printf("拜拜了您呐\n");
            return 0;
        }
    }
    return 0;
}
