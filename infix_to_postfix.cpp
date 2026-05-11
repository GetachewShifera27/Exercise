// change 4*3+6(4/2) to postfix
#include<iostream>
using namespace std;
#define max 20
char stack[max];
int top=-1; 
void push(char item){
    if(top==max-1){
        cout<<"overflow";
    }
    else{
        top++;
        stack[top]=item;
    }
}
char pop(){
    if (top==-1)
    {
        /* code */
        cout<<"underflow messages";
        return -1;
    }
    else{
        char x=stack[top];
        top--;
        return x;
    }
    
}
int precedence(char x){
    if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    else{
        return 0;
    }
}
int main(){
    string infix,postfix="";
    cout<<"enter the infix expression"<<endl;
    cin>>infix;
    for(int i=0;i<infix.length();i++){
        char x=infix[i];
        if(isalnum(x)){
            postfix+=x;
        }
        else if(x=='('){
            push(x);
        }
        else if(x==')'){
            while(stack[top]!='('){
                postfix+=pop();
            }
            pop();
        }
        else{
            while(precedence(stack[top])>=precedence(x)){
                postfix+=pop();
            }
            push(x);
        }
    }
    while(top!=-1){
        postfix+=pop();
    }
    cout<<"the postfix expression is : "<<postfix<<endl;
    return 0;
}