/*****************Binary search ***************/
/********Author: Bhavya Jindal****************/
/*********************************************/
/*
#include<stdio.h>
int binary_search(int A[5],int n,int Skey)
{
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(A[mid]==Skey)
        {
            return mid;
        }
        else
        {
            if(Skey<A[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
    }
    return -1;
}
/*************************/
/*int main()
{
    int i,n,z,c;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element you wamt to search : ");
    scanf("%d",&c);
    z=binary_search(a,n,c);
    if(z==-1){
        printf("Element Not Found !!!\n");
    }
    else
        printf("Element Found At Index : %d",z);
}
*/
#include<stdio.h>
#include<stdlib.h>
/**********************/
struct node
{
    int pno;
    int AT;
    int BT;
    int prt;
    int CT;
    int TAT;
    int WT;
    int RT;
    struct node *next;
};
/**********************/
struct node *Getnode()
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    return t;
}
/**********************/
void InsBeg(struct node **START,int pn,int at,int bt,int priority)
{
    struct node *p;
    p=Getnode();
    p->pno = pn;
    p->AT = at;
    p->BT = bt;
    p->prt = priority;
    p->next = (*START);
    (*START) = p;
}
/**********************/
void InsAft(struct node **q,int pn,int at,int bt,int priority)
{
    struct node *p=*q;
    struct node *r;
        r=Getnode();
        r->pno=pn;
        r->AT=at;
        r->BT=bt;
        r->prt=priority;
        if(p->next!=NULL)
        {
            r->next=p->next;
        }
        else
        {
            r->next=NULL;
        }
        p->next=r;
}
