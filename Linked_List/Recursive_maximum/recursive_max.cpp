#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[],int size){
    struct Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1; i<size; i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}


int Recursive_Max_Element(struct Node *p){
    static int x=0;
    if(p==NULL)return INT_MIN;
    else{
        int x=Recursive_Max_Element(p->next);
        if(x>p->data)return x;
        else{
            return p->data;
        }
    }
}

int recursive_max2(struct Node *p){
    int x=0;
    if(p==NULL)return INT_MIN;
    x=recursive_max2(p->next);
    return x>p->data?x:p->data;
}


int main()
{ 
    int a[10]={1,-254,3,4,5,6,7,8,-2*9,-10};
    Create(a,10);
    cout<<"Maximum element is "<<recursive_max2(first);
      
    return 0;
}
