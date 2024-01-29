
#include <iostream>
using namespace std;

struct queue{
  int size,front,rare;
  int *Q;
}q;
void create()
{
    q.front=0;
    q.rare=0;
    cout<<"Enter size "<<endl;
    cin>>q.size;
    q.Q=new int[q.size];
    
}
 
void enqueue(struct queue *q, int x)
{
    if((q->rare+1)%q->size==q->front-1)
    {
        cout<<"queue is full "<<endl;
    }
    else {
        q->rare=(q->rare+1)%q->size;
        q->Q[q->rare]=x;
    }
}
int dequeue(struct queue *q)
{
    int x=-1;
    if(q->rare==q->front)
    {
        cout<<"Queue is Empty can't delete"<<endl;
    }
    else{
        q->front=(q->front+1)%q->size;
         x=q->Q[q->front];
    }
    return x;
}
void Display(struct queue q)
{
    int i=q.front+1;
    do{
        cout<<q.Q[i]<<" ";
        i=(i+1)%q.size;
    }while(i!=(q.rare+1)%q.size);
    cout<<endl;
}
int main()
{
    create();
    enqueue(&q,3);
    Display(q);
    
    enqueue(&q,4);
    Display(q);
    
    enqueue(&q,5);
    Display(q);
    
    cout<<"deleted ele is "<<dequeue(&q)<<endl;
    Display(q);

    return 0;
}
