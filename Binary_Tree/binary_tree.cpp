#include <stdio.h>
#include<iostream>
using namespace std;
class Node
{
    public:
    Node *lchild;
    int data;
    Node *rchild;
    
}*root=NULL;

class Queue 
{
    
    int size;
    int front;
    int rear;
    Node **Q;
    
    public:
    Queue(int s)
    {
        size=s;
        front=rear=0;
        Q=new Node*[size];
        
    }
    void enqueue(Node* x);
    Node* dequeue();
    int isEmpty();
};

void Queue::enqueue(Node* x)
{
    if((rear+1)%size==front)
    {
        cout<<"Queue is Full"<<endl;
    }
    else
    {
        rear=(rear+1)%size;
        
        Q[rear]=x;
    }
}

Node* Queue::dequeue()
{
    Node*x=NULL;
    if(front==rear)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        front=(front+1)%size;
        x=Q[front];
    }
    
return x;
}


int Queue::isEmpty()
{
    if(front==rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void TreeCreate()
{
    int x;
    Queue q(500);
    Node *p,*t;
    root=new Node;
    cout<<"Enter Root Element "<<endl;
    cin>>x;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        p=q.dequeue();
        cout<<"Enter Left Child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        
        cout<<"Enter Right Child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

void Preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
int main()
{
    TreeCreate();
    Preorder(root);
    
    return 0;
}

