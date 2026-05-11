#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* f=NULL;
node* r=NULL;
void enqueue(int item){
    node* newnode=new node();
    newnode->data=item;
    newnode->next=NULL;
    if(f==NULL){
        f=r=newnode;
    }
    else{
        r->next=newnode;
        r=newnode;
    }
}
void dequeue(){
    if (f==NULL)
    {
        /* code */
        cout<<"underflow messages";
    }
    else{
        int x=f->data;
        f=f->next;
        cout<<" the poed value is :" <<x;
    }
    
}
void display(){
    if(f==NULL){
        cout<<"Empty list"<<endl;
    }
    else{
        node* temp=f;
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
        cout<<"1.enqueue"<<endl;
        cout<<"2.dequeue"<<endl;
        cout<<"3.display"<<endl;
        cout<<"4.exit"<<endl;
        cout<<"enter your choice"<<endl;
        cin>>c;
        switch(c){
            case 1:
                cout<<"enter the item to be inserted"<<endl;
                cin>>k;
                enqueue(k);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                cout<<"invalid choice"<<endl;
        }
    }while(c!=4);
    return 0;
}