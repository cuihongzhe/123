#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct book
{
    bool borrow;
    //标记是否借出
    int num;
    //书号
    int a,b,c;
    //库存数量，借出数量，剩余数量
    char name[99];
    //书名
    char author[99];
    //作者
    char unit[99];
    //出版单位
    int price;
    //价格
    int year,month,day;
    //年月日
};
struct node
{
    book data;
    node *next;
};
node *p,*q,*head=NULL;
int n=1;
void add()
{
    p=(node *)malloc(sizeof(node));
    printf("请输入相关书籍信息：书名，作者，出版单位，价格，出版日期（年月日）\n");
    scanf("%s %s %s %d%d%d%d",p->data.name,p->data.author,p->data.unit,&p->data.price,&p->data.year,&p->data.month,&p->data.day);
    p->data.num=n++;
    //书号确定¨
    p->data.borrow=0;
    //未借出归0
    p->next=NULL;
    q->next=p;
    q=p;
    bool f=1;
    for(node *i=head; i!=q; i=i->next)
    {
        if(!strcmp(p->data.name,i->data.name))
        {
            f=0;
            i->data.a++;
            i->data.c++;
            p->data.a=i->data.a;
            p->data.b=i->data.b;
            p->data.c=i->data.c;
        }//算法可简化
    }
    if(f)
    {
        p->data.a=1;
        p->data.b=0;
        p->data.c=1;
    }
    //同化书籍数量
    q=p;
}
void find()
{
    printf("请输入书名\n");
    char book[99];
    scanf("%s",book);
    bool f=1;
    for(node *i=head; i!=NULL; i=i->next)
    {
        if(!strcmp(book,i->data.name))
        {
            f=0;
            printf("书酣号：%d\n书名：%s\n作者：%s\n库存数量：%d\n借出数量：%d\n剩余数量：%d\n出版单位：%s\n价格：%d\n出版时间：阰%d.%d.%d\n",i->data.num,i->data.name,i->data.author,i->data.a,i->data.b,i->data.c,i->data.unit,i->data.price,i->data.year,i->data.month,i->data.day);
            if(i->data.borrow)
                printf("借出\n");
            else
                printf("未借出\n");
            printf("\n\n");
        }
    }
    if(f)
        printf("未找到相关书籍\n\n\n");
}
void buy()
{
    int num;
    printf("请输入购书书号\n");
    scanf("%d",&num);
    node *h=(node *)malloc(sizeof(node));
    h->next=head;
    for(node *i=head; i!=NULL; i=i->next)
    {
        if(i->data.num==num)
        {
            for(node *k=head; k!=NULL; k=k->next)
            {
                if(!strcmp(k->data.name,i->data.name))
                {
                    k->data.a--;
                    k->data.c--;
                }
            }
            //同化书籍数量
            if(i==head)
                head=head->next;
            else if(i==q)
            {
                h->next=i->next;
                q=h;
                free(i);
            }
            else
            {
                h->next=i->next;
                free(i);
            }
            break;
        }
        else
            h=i;
    }
    //删除书籍
}
void borrow()
{
    printf("请输入借阅书号\n");
    int num;
    scanf("%d",&num);
    for(node *i=head; i!=NULL; i=i->next)
    {
        if(i->data.num==num)
        {
            i->data.borrow=1;
            i->data.b++;
            i->data.c--;
        }
    }
}
void back()
{
    printf("请输入还书书号\n");
    int num;
    scanf("%d",&num);
    for(node *i=head; i!=NULL; i=i->next)
    {
        if(i->data.num==num)
        {
            i->data.borrow=0;
            break;
        }
    }
}
void revise()
{
    printf("请输入修改书号\n");
    int num;
    scanf("%d",&num);
    bool f=1;
    for(node *i=head; i!=NULL; i=i->next)
    {
        if(i->data.num==num)
        {
            f=0;
            char ch[100];
            strcpy(ch,i->data.name);
            printf("输入书籍信息\n");
            scanf("%s %s %s %d%d%d%d",i->data.name,i->data.author,i->data.unit,&i->data.price,&i->data.year,&i->data.month,&i->data.day);
            int t;
            printf("借出输入1，未借出输入0\n");
            scanf("%d",&t);
            i->data.borrow=t;
            //输入书籍信息
            i->data.a=1;
            i->data.b=0;
            i->data.c=1;
            for(node *j=head; j!=NULL; j=j->next)
            {
                if(!strcmp(ch,j->data.name)&&i->data.num!=j->data.num)
                {
                    j->data.a--;
                    j->data.c--;
                }
                if(!strcmp(i->data.name,j->data.name)&&i->data.num!=j->data.num)
                {
                    j->data.a++;
                    j->data.c++;
                    i->data.a=j->data.a;
                    i->data.b=j->data.b;
                    i->data.c=j->data.c;
                }
            }
            //同化书籍数量
        }
    }
    if(f)
        printf("查无此书n");
}
void show()
{
    for(node *i=head; i!=NULL; i=i->next)
    {
        printf("书号：%d\n书名?：%s\n作者?：%s\n库存数量：%d\n借出数量：%d\n剩余数量：%d\n出版单位：%s\n价格：%d\n出版时间：阰%d.%d.%d\n",i->data.num,i->data.name,i->data.author,i->data.a,i->data.b,i->data.c,i->data.unit,i->data.price,i->data.year,i->data.month,i->data.day);
        if(i->data.borrow)
            printf("借出\n");
        else
            printf("未借出\n");
        printf("\n\n");
    }
}
void file()
{
    FILE *fp;
    if((fp=fopen("file","w"))==NULL)
    {
        printf("文件错误\n");
        exit(0);
    }
    for(node *i=head; i!=NULL; i=i->next)
    {
        fprintf(fp,"书号：%d 书名：%s 作者：%s 库存数量：%d 借出数量：%d 剩余数量：%d 出版单位：%s 价格：%d 出版时间：%d.%d.%d ",i->data.num,i->data.name,i->data.author,i->data.a,i->data.b,i->data.c,i->data.unit,i->data.price,i->data.year,i->data.month,i->data.day);
        if(i->data.borrow)
            fprintf(fp,"借出 ");
        else
            fprintf(fp,"未借出 ");
    }
    fclose(fp);
}
int main()
{
    for(;;)
    {
        p=(node *)malloc(sizeof(node));
		printf("输入书名，书名为0时结束\n");
        scanf("%s",p->data.name);
        if(p->data.name[0]=='0')
            break;
		printf("输入书籍信息：作者，出版单位，价格，出版时间（年月日）\n");
        scanf("%s %s %d%d%d%d",p->data.author,p->data.unit,&p->data.price,&p->data.year,&p->data.month,&p->data.day);
        p->data.num=n++;
        //递增排序书籍书号
        p->data.borrow=0;
        //未借出归0
        p->next=NULL;
        if(head==NULL)
            head=p;
        else
            q->next=p;
        q=p;
    }
    for(node *i=head; i!=NULL; i=i->next)
    {
        i->data.b=0;
        i->data.a=0;
        for(node *j=head; j!=NULL; j=j->next)
        {
            if(!strcmp(i->data.name,j->data.name))
            {
                i->data.a++;
                i->data.c=i->data.a;
            }
        }
    }
    //数量计算
    int m;
    printf("进书输入1，查书输入2，购书输入3，借书输入4，还书输入5,修改输入6，全部显示输入7，写入文件输入8，结束输入0\n");
    while(~scanf("%d",&m))
    {
        if(!m)
            break;
        switch(m)
		{
		case 1:
        {
            add();
            break;
        }
        case 2:
        {
            find();
            break;
        }
        case 3:
        {
            buy();
            break;
        }
        case 4:
        {
            borrow();
            break;
        }
        case 5:
        {
            back();
            break;
        }
        case 6:
        {
            revise();
            break;
        }
        case 7:
        {
            show();
            break;
        }
        case 8:
        {
            file();
            break;
        }
        default:
        {
            printf("操作错误\n\n\n");
            break;
        }
        }
        printf("进书输入1，查书输入2，购书输入3，借书输入4，还书输入5,修改输入6，全部显示输入7，写入文件输入8，结束输入0\n");
    }
    return 0;
}