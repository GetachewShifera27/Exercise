//evaluate postfix expression by accepting the postfix expression as input and using stack to evaluate the expression
#include <iostream>
#include<string>
#include<sstream>
using namespace std;
#define max 20
int stack[max];
int top=-1;
void push(int item){
    if(top==max-1){
        cout<<"overflow";
    }
    else{
        top++;
        stack[top]=item;
    }
}
int pop(){
    if (top==-1)
    {
        /* code */
        cout<<"underflow messages";
        return -1;
    }
    else{
        int x=stack[top];
        top--;
        return x;
    }
 
}
int main(){
    string input;
    cout<<"enter the postfix expression"<<endl;
    getline(cin, input);
    stringstream ss(input);
    string token;
    while(ss >> token){
        if(isdigit(token[0]) || (token[0]=='-' && token.length()>1)){
            // handle negative numbers if needed, but for now assume positive
            push(stoi(token));
        }
        else{
            int op2=pop();
            int op1=pop();
            switch(token[0]){
                case '+':
                    push(op1+op2);
                    break;
                case '-':
                    push(op1-op2);
                    break;
                case '*':
                    push(op1*op2);
                    break;
                case '/':
                    push(op1/op2);
                    break;
            }
        }
    }
    cout<<"the result is : "<<pop()<<endl;
    return 0;
}