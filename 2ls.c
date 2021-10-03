/**********************  ATUL KESARWANI **********************/
/**********************  1900320100046 ***********************/

#include<stdio.h>
#include<stdlib.h>
struct node
{
 int size;
 int id;
 struct node*next;
};
struct node *Getnode()
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
void InsBeg(struct node **list,int x,int y)
{
    struct node *p;
    p=Getnode();
    p->size=x;
    p->id=y;
    p->next=*list;
    *list=p;
}
void Traversal(struct node *list)
{
    struct node *p;
    p=list;
    while(p!=NULL)
    {
        printf(" %d\t%d\n",p->size,p->id);
        p=p->next;
    }

}
void Allocation(struct node **list,int y,int x)
{
    struct node *p,*q;
    p=*list;
    while(p!=NULL)
    {
        if(p->id==-1)
        {
            if(p->size>=x)
            {
                break;
            }
        }
        p=p->next;
    }
    q=Getnode();
    q->size=x;
    q->id=y;
    p->size=p->size-x;
    q->next=p->next;
    p->next=q;
}
void Allocationbf(struct node **list,int y,int x)
{
     struct node *p,*q,*r;
    p=*list;
   int min=36767,z;
    while(p!=NULL)
    {
        if(p->id==-1)
        {
            if(p->size>=x)
            {
                z=p->size-x;
                if(z<min)
                {
                    min=z;
                    r=p;
                }
            }
        }
        p=p->next;
    }


    q=Getnode();
    q->size=x;
    q->id=y;
    r->size=r->size-x;
    q->next=r->next;
    r->next=q;

}
void Allocationwf(struct node **list,int y,int x)
{
     struct node *p,*q,*r;
    p=*list;
   int max=-1,z;
    while(p!=NULL)
    {
        if(p->id==-1)
        {
            if(p->size>=x)
            {
                z=p->size-x;
                if(z>max)
                {
                    max=z;
                    r=p;
                }
            }
        }
        p=p->next;
    }


    q=Getnode();
    q->size=x;
    q->id=y;
    r->size=r->size-x;
    q->next=r->next;
    r->next=q;

}
void compaction(struct node **list)
{
    struct node *p,*q;
    p=*list;
    int x=0;
    q=(*list);
    p=p->next;
    while(p!=NULL)
        {
            if(p->id==-1)
            {
                x=x+p->size;
                q->next=p->next;
                free(p);
                p=q->next;
            }
            q=p;
            p=p->next;
        }
        (*list)->size=(*list)->size+x;
}
void deallocation(struct node **list,int x)
{
  struct node *p,*q,*r;
  p=*list;
  q=NULL;
  while(p!=NULL)
  {
    if(p->id==x)
    {
      break;
    }
    q=p;
    p=p->next;
    r=p->next;
  }
  p->id=-1;

  if(q->id==-1)
  {
    q->size=q->size+p->size;
    q->next=p->next;
    free(p);
  }
  if(r!=NULL && r->id==-1)
  {
    q->size=q->size+r->size;
    q->next=r->next;
    free(r);
  }

}

void main()
{
    int n=2,s,id,x;
    struct node *START,*p;
    START=NULL;
    p=Getnode();
    p->id=-1;
    p->size=1000;
    p->next=START;
    START=p;

    Traversal(START);
    printf("\n");
    printf("For allooaction of process by first fit scheme click '1' and then process no. and then process size\n");
    printf("For allooaction of process by best fit scheme click '2' and then process no. and then process size\n");
    printf("For allooaction of process by worst fit scheme click '3' and then process no. and then process size\n");
    printf("For Traversal click '4'\n");
    printf("For compaction click '5'\n");
    printf("For deallocation of process click '6' then process no.\n");
    printf("For end of the program click '7'\n");

    while(n>0)
    {
        printf("Enter a number");
        scanf("%d",&x);

        if(x==1)
        {
            printf("Enter process no.:");
            scanf("%d",&id);
            printf("Enter process size");
            scanf("%d",&s);
            Allocation(&START,id,s);
        }
        else if(x==2)
        {
            printf("Enter process no.:");
            scanf("%d",&id);
            printf("Enter process size");
            scanf("%d",&s);
            Allocationbf(&START,id,s);
        }
        else if(x==3)
        {
            printf("Enter process no.:");
            scanf("%d",&id);
            printf("Enter process size");
            scanf("%d",&s);
            Allocationwf(&START,id,s);
        }
        else if(x==5)
        {
            compaction(&START);
        }
        else if(x==4)
        {
            Traversal(START);
        }
        else if(x==6)
        {
            scanf("%d",&id);
            deallocation(&START,id);
        }
        else if(x==7)
        {
            break;
        }
    }


}
