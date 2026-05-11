#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* top=NULL;
void push(int item){
    if(top==NULL){
        node *newnode=new node();
        newnode->data=item;
        newnode->next=NULL;
        top=newnode;
    }
    else{
        node *newnode=new node();
        newnode->data=item;
        newnode->next=top;
        top=newnode;
    }
}
void pop(){
    if (top==NULL)
    {
        /* code */
        cout<<"underflow messages";
    }
    else{
        int x=top->data;
        top=top->next;
        cout<<" the poed value is :" <<x;
    }
    
}
void display(){
    if(top==NULL){
        cout<<"Empty list"<<endl;
    }
    else{
        node* temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
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
                cout<<"invalid choice"<<endl;
        }
    }while(c!=4);
    return 0;
}