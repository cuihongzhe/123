#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct book
{
    bool borrow;
    //����Ƿ���
    int num;
    //���
    int a,b,c;
    //������������������ʣ������
    char name[99];
    //����
    char author[99];
    //����
    char unit[99];
    //���浥λ
    int price;
    //�۸�
    int year,month,day;
    //������
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
    printf("����������鼮��Ϣ�����������ߣ����浥λ���۸񣬳������ڣ������գ�\n");
    scanf("%s %s %s %d%d%d%d",p->data.name,p->data.author,p->data.unit,&p->data.price,&p->data.year,&p->data.month,&p->data.day);
    p->data.num=n++;
    //���ȷ����
    p->data.borrow=0;
    //δ�����0
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
        }//�㷨�ɼ�
    }
    if(f)
    {
        p->data.a=1;
        p->data.b=0;
        p->data.c=1;
    }
    //ͬ���鼮����
    q=p;
}
void find()
{
    printf("����������\n");
    char book[99];
    scanf("%s",book);
    bool f=1;
    for(node *i=head; i!=NULL; i=i->next)
    {
        if(!strcmp(book,i->data.name))
        {
            f=0;
            printf("�麨�ţ�%d\n������%s\n���ߣ�%s\n���������%d\n���������%d\nʣ��������%d\n���浥λ��%s\n�۸�%d\n����ʱ�䣺�o%d.%d.%d\n",i->data.num,i->data.name,i->data.author,i->data.a,i->data.b,i->data.c,i->data.unit,i->data.price,i->data.year,i->data.month,i->data.day);
            if(i->data.borrow)
                printf("���\n");
            else
                printf("δ���\n");
            printf("\n\n");
        }
    }
    if(f)
        printf("δ�ҵ�����鼮\n\n\n");
}
void buy()
{
    int num;
    printf("�����빺�����\n");
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
            //ͬ���鼮����
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
    //ɾ���鼮
}
void borrow()
{
    printf("������������\n");
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
    printf("�����뻹�����\n");
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
    printf("�������޸����\n");
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
            printf("�����鼮��Ϣ\n");
            scanf("%s %s %s %d%d%d%d",i->data.name,i->data.author,i->data.unit,&i->data.price,&i->data.year,&i->data.month,&i->data.day);
            int t;
            printf("�������1��δ�������0\n");
            scanf("%d",&t);
            i->data.borrow=t;
            //�����鼮��Ϣ
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
            //ͬ���鼮����
        }
    }
    if(f)
        printf("���޴���\n");
}
void show()
{
    for(node *i=head; i!=NULL; i=i->next)
    {
        printf("��ţ�%d\n����?��%s\n����?��%s\n���������%d\n���������%d\nʣ�ந������%d\n���浥λ��%s\n�۸�%d\n����ʱ�䣺�o%d.%d.%d\n",i->data.num,i->data.name,i->data.author,i->data.a,i->data.b,i->data.c,i->data.unit,i->data.price,i->data.year,i->data.month,i->data.day);
        if(i->data.borrow)
            printf("���\n");
        else
            printf("δ���\n");
        printf("\n\n");
    }
}
void file()
{
    FILE *fp;
    if((fp=fopen("file","w"))==NULL)
    {
        printf("�ļ�����\n");
        exit(0);
    }
    for(node *i=head; i!=NULL; i=i->next)
    {
        fprintf(fp,"��ţ�%d ������%s ���ߣ�%s ���������%d ���������%d ʣ��������%d ���浥λ��%s �۸�%d ����ʱ�䣺%d.%d.%d ",i->data.num,i->data.name,i->data.author,i->data.a,i->data.b,i->data.c,i->data.unit,i->data.price,i->data.year,i->data.month,i->data.day);
        if(i->data.borrow)
            fprintf(fp,"��� ");
        else
            fprintf(fp,"δ��� ");
    }
    fclose(fp);
}
int main()
{
    for(;;)
    {
        p=(node *)malloc(sizeof(node));
		printf("��������������Ϊ0ʱ����\n");
        scanf("%s",p->data.name);
        if(p->data.name[0]=='0')
            break;
		printf("�����鼮��Ϣ�����ߣ����浥λ���۸񣬳���ʱ�䣨�����գ�\n");
        scanf("%s %s %d%d%d%d",p->data.author,p->data.unit,&p->data.price,&p->data.year,&p->data.month,&p->data.day);
        p->data.num=n++;
        //���������鼮���
        p->data.borrow=0;
        //δ�����0
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
    //��������
    int m;
    printf("��������1����������2����������3����������4����������5,�޸�����6��ȫ����ʾ����7��д���ļ�����8����������0\n");
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
            printf("��������\n\n\n");
            break;
        }
        }
        printf("��������1����������2����������3����������4����������5,�޸�����6��ȫ����ʾ����7��д���ļ�����8����������0\n");
    }
    return 0;
}