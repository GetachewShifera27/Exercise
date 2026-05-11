#include <iostream>
using namespace std;
#define max 5
int stack[max];
int top=-1;
void push(int item){
    if(top==max-1){
        cout<<"overflow";
    }
    else{
        top++;
        stack[top]=item;
        cout<< item << "pushed to the stack";
    }
}
void pop(){
    if (top==-1)
    {
        /* code */
        cout<<"underflow messages";
    }
    else{
        int x=stack[top];
        top--;
        cout<<" the poed value is :" <<x;
    }
    
}
void display(){
    if(top==-1){
        cout<<"Empty list"<<endl;
    }
    else{
        for(int i=top;i>=0;i--){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int c,k;
    do{
        cout<<"1.push"<<endl;
        cout<<"2.pop"<<endl;
        cout<<"3.display"<<endl;
        cout<<"4.exit"<<endl;
        cout<<"enter your choice"<<endl;
        cin>>c;
        switch(c){
            case 1:
                cout<<"enter the item to be inserted"<<endl;
                cin>>k;
                push(k);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                cout<<"invalid choice";
        }
    }while(c!=4);
    return 0;
}