#include<stdio.h>
#include<stdlib.h>
struct node
{
 int info;
 struct node*next;
};
struct node *Getnode()
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
void Traversal(struct node *list)
{
    struct node *p;
    p=list;
    while(p!=NULL)
    {
        printf(" %d",p->info);
        p=p->next;
    }

}
void InsBeg(struct node **list,int x)
{
    struct node *p;
    p=Getnode();
    p->info=x;
    p->next=*list;
    *list=p;
}
void InsAft(int y,int x)
{
    struct node *p,*q;
    p=START;
    while(p!=NULL)
    {
        if(p->info==y)
            break;
        p=p->next;
    }
        q=Getnode();
        q->info=x;
        q->next=p->next;
        p->next=q;
}
void InsEnd(int x)
{
    struct node *p,*q;
    p=START;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    q=Getnode();
    q->info=x;
    q->next=p->next;
    p->next=q;
}
int DelBeg()
{
    int x;
    struct node *p;
    if(START!=NULL)
    {
        p=START;
        START=p->next;
        x=p->info;
        free(p);
        return x;
    }
    else
        printf("void Deletion");

}
void DelAft()
{
    if(p!=NULL && p->next!=NULL)
    {
        q=p->next;
        p->next=q->next;
        x=q->info;
        free(q);
        return(x);
    }
    else
        printf("void deletion");
}
int DelEnd()
{
    struct node *p,*q;
    int x;
        q=NULL;
        p=START;
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
            q->next=NULL;
            x=p->info;
            free(p);
            return(x);


}*/
void main()
{
    struct node *START;
    int z;
    InsBeg(&START,100);
    InsBeg(&START,200);
    InsBeg(&START,300);
    InsBeg(&START,900);
    InsBeg(&START,400);
    Traversal(START);

 /*  z= DelBeg();
   printf("\n");
   Traversal(START);
   printf("\n");
   printf("%d",z);

   printf("\n");
   z= DelEnd();
   printf("\n");
   Traversal(START);
   printf("\n");
   printf("%d",z);*/
}

