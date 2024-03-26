
#include<iostream>
#include<string>
using namespace std;

struct stack{
  int size=10;
  int top=-1;
  char S[10];
};

void push( struct stack *st,char x){
    if(st->top==st->size-1)cout<<"Stack is full "<<endl;
    else {
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(struct stack *st){
    int x=-1;
    if(st->top==-1)cout<<"Stack is empty"<<endl;
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

int ismatching(string s){
    struct stack st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')push(&st,s[i]);
        
        else if(s[i]==')'){
            if(st.top==-1 ||st.S[st.top]!='(')return 0;
            else pop(&st);
        }
        else if(s[i]=='}'){
            if(st.top==-1 || st.S[st.top]!='{')return 0;
            else pop(&st);
        }
        else if(s[i]==']'){
            if(st.top==-1 || st.S[st.top]!='[')return 0;
            else pop(&st);
        }
        
    }
    if(st.top==-1)return 1;
    return 0;
}
int main()
{
    string s;
    cout<<"Enter expression "<<endl;
    cin>>s;
    if(ismatching(s)==1)cout<<"expression "<<s<<" is correct "<<endl;
    else cout<<"expression "<<s<<" is NOT correct "<<endl;

    return 0;
}
