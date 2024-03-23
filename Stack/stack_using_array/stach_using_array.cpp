
#include <iostream>
using namespace std;

struct Stack{
    int size=10;
    int top=-1;
    int *S=new int[10];
};

void push(struct Stack *st,int x){
    if(st->top==st->size-1)cout<<"Full "<<endl;
    else {
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(struct Stack *st){
    int x=-1;
    if(st->top==-1)cout<<"empty "<<endl;
    else {
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st,int pos){
    int x=-1;
    if(st.top-pos+1<0)cout<<"Invalid index "<<endl;
    else {
        x=st.S[st.top-pos+1];
    }
    return x;
}

int stack_top(struct Stack st){
    if(st.top==-1)return -1;
    return st.S[st.top];
}

int is_empty(struct Stack st){
    if(st.top==-1)return 1;
    return 0;
}

int is_full(struct Stack st){
    if(st.top==st.size-1)return 1;
    return 0;
}

void display(struct Stack st){
    if(st.top==-1)cout<<"Stack  is empty"<<endl;
    else {
        cout<<"stack is "<<endl;
        for(int i=0; i<=st.top; i++){
            cout<<st.S[i]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
struct Stack st;
display(st);

cout<<"Enter how many elements you want to insert "<<endl;
int n;
cin>>n;
cout<<"Enter elements one by one "<<endl;
for(int i=0; i<n; i++){
    int x;
    cin>>x;
    push(&st,x);
}
display(st);


cout<<"Element at position 4 is "<<peek(st,4)<<endl;
cout<<"Poped element is "<<pop(&st)<<endl;
display(st);

cout<<"Poped element is "<<pop(&st)<<endl;
display(st);

cout<<"Element at position 2 is "<<peek(st,2)<<endl;

    return 0;
}
