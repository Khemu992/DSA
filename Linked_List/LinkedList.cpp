#include <iostream>
using namespace std;

struct Node     //Self Refrential structure************
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL;
struct Node *t=NULL;
/*
void Create(int A[], int n)
{
    struct Node *t, *last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    
    for(int i=1; i<n; i++)
    {
        t=new Node;
        t->data=A[i];
        last->next=t;
        last=t;
    }
    
}
*/
void CreateLoop(int A[],int n)
{
    struct Node *t,*last;
    first=new Node;
    first->data=A[0];
    last=first;
    for(int i=1; i<n; i++)
    {
        t=new Node;
        t->data=A[i];
        last->next=t;
        last=t;
    }
    struct Node *p=first;
    for(int i=0; i<2; i++)
    {
        p=p->next;
    }
    last->next=p;
}
void Create2(int B[], int n)
{
    struct Node *t, *last;
    second=new Node;
    second->data=B[0];
    second->next=NULL;
    last=second;
    
    for(int i=1; i<n; i++)
    {
        t=new Node;
        t->data=B[i];
        last->next=t;
        last=t;
    }
    
}

void Display(struct Node *p)
{
    cout<<"LInked List are "<<endl;
    
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void RDisplay(struct Node *p)
{
    
    if(p)
    {
        cout<<p->data<<" ";
        RDisplay(p->next);
    }
}
int Count(struct Node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}
int RCount(struct Node *p)
{
    
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        
        return RCount(p->next)+1;
    }
}
int Sum(struct Node *p)
{
    int s=0;
    while(p)
    {
        s=s+p->data;
        p=p->next;
    }
    return s;
}
int RSum(struct Node *p)
{
    
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        
        return RSum(p->next)+p->data;
    }
}
int Max(struct Node *p)
{
    int max=-32460;
    while(p)
    {
        if(p->data>max)
        {
            max=p->data;
            p=p->next;
        }
        else
        {
            p=p->next;
        }
    }
    return max;
}

struct Node* LinearSearch(struct Node *p,int key)
{

 while(p!=NULL)
    {
        if(key==p->data)
        {
            return p;
            p=p->next;
        }
        else
        {
            p=p->next;
        }
    }
    return NULL;
}

struct Node* ImproveLinearSearch(struct Node *p,int key)
{ 
    struct Node *q=NULL;
    
    while(p)
    {
        if(p==first&&p->data==key)
        {
            return p;
        }
        else if(p->data==key && p!=first)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return first;
        }
        else
        {
             q=p;
            p=p->next;
        }
      
    }
    return NULL;
}

void Insert(struct Node *p,int pos,int x)
{
    struct Node *t;
    if(pos==0)
    {
        t=new Node;
        t->data=x;
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        for(int i=0; i<pos-1; i++)
        {
            p=p->next;
        }
        if(p)
        {
             t=new Node;
             t->data=x;
             t->next=p->next;
            p->next=t;
        }
       
    }
}

void CreateByInsertLast(struct Node *p,int x)
{
    struct Node *t;
    t=new Node;
    t->data=x;
    if(p==NULL)
    {
        t->next=NULL;
        first=t;
    }
    else
    {
        while(p->next)
        {
            p=p->next;
        }
        p->next=t;
        t->next=NULL;
    }
    
}

void InsertInSort(struct Node *p,int x)
{
    struct Node *q=NULL;
    struct Node *t=new Node;
    t->data=x;
    if(p->data>x)
    {
        t->next=first;
        first=t;
    }
    else
    {
        while(p && p->data<x)
        {
        q=p;
        p=p->next;
        }
        if(q->next)
        {
        t->next=q->next;
        q->next=t;
        }
        else
        {
        t->next=NULL;
        q->next=t;
        }
    }
    
}

int Delete(struct Node *p,int pos)
{
    int x=0;
    struct Node *q;
    if(pos==1)
    {
        q=first;
        first=first->next;
        x=q->data;
        delete q;
    }
    else
    {
        for(int i=0; i<pos-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        
    }
    return x;
}
int isSorted(struct Node *p)
{
    int x=-32768;
    while(p)
    {
        if(p->data<x)
        {
            return 0;
        }
        else
        {
            x=p->data;
            p=p->next;
        }
    }
    return 1;
}

void RemoveDublicate(struct Node *p)
{
    struct Node *q=p->next;
    while(q)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}
void ReverseLLbyElement(struct Node *p)
{
    int A[Count(p)];
    int i=0;
    
    while(p)
    {
        A[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;
    i--;
    while(p)
    {
        p->data=A[i];
        p=p->next;
        i--;
    }
    
}
void ReverseLLbyLinks(struct Node *p)
{
    struct Node *r=NULL,*q=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Merging(struct Node *first, struct Node *second)
{
    struct Node *last;
    if(first->data<second->data)
    {
        t=last=first;
        first=first->next;
        last->next=NULL;
    }
    else
    {
        t=last=second;
        second=second->next;
        last->next=NULL;
    }   
    while(first&&second)
    {
        if(first->data<second->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
        else
        {
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }
    }
    if(first)
    {
        last->next=first;
    }
    else
    {
        last->next=second;
    }
}

int isLoop(struct Node *p)
{
    struct Node *q=first;
    do
    {
        p=p->next;
        q=q->next;
        if(q)
        {
            q=q->next;
        }
        else
        {
            return 0;
        }
    }while(p&&q&&p!=q);
    
    if(p==q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}
int main()
{
    
    int A[]={8,5,4,7,3,9};
    //Create(A,4);
    //cout<<"Linked List By Recursion "<<endl;
    //Display(first);
    
    //int B[]={4,7,12,14};
    //Create2(B,4);
    //cout<<"Linked List By Recursion "<<endl;
    //Display(second);
    //cout<<"Number Of Nodes by Recursion is "<<RCount(first)<<endl;
    //cout<<"Sum is "<<Sum(first)<<endl;
    //cout<<"Sum by Recursion is "<<RSum(first)<<endl;
    //cout<<"Max ele. is "<<Max(first)<<endl;
    /*
    if(ImproveLinearSearch(first,147))
    {
        cout<<"yes,Element is Present "<<endl;
    }
    else
    {
        cout<<"No, Element is not Present"<<endl;
    }
    Display(first);
    */
    /*
    Insert(first,0,11);
    Insert(first,1,22);
    Insert(first,2,33);
    Insert(first,3,44);
    Display(first);
    */
    
    /*
    CreateByInsertLast(first,11);
    CreateByInsertLast(first,22);
    CreateByInsertLast(first,32);
    CreateByInsertLast(first,15);
    CreateByInsertLast(first,25);
    CreateByInsertLast(first,12);
    CreateByInsertLast(first,21);
    CreateByInsertLast(first,26);
    CreateByInsertLast(first,53);
    Display(first);
    */
    //InsertInSort(first,10);
    //Display(first);
    //Delete(first,6);
    //Display(first);
    
    /*
    if(isSorted(first))
    {
        cout<<"Liked List is Sorted "<<endl;
    }
    else
    {
        cout<<"Liked List is Not Sorted "<<endl;
    }
    */
    
    //RemoveDublicate(first);
    //Display(first);
    
    //ReverseLLbyElement(first);
    //Display(first);
    
    //ReverseLLbyLinks(first);
    //Display(first);
    //Merging(first,second);
    //Display(t);
    CreateLoop(A,6);
    if(isLoop(first))
    {
        cout<<"It is a loop "<<endl;
    }
    else{
        cout<<"Not a loop "<<endl;
    }

    return 0;
}



