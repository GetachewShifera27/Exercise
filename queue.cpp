#include <iostream>
using namespace std;
#define max 5
int queue[max];
int f,r= -1;
int qz=0;

void enqueue(int item){
    if(r==max-1){
        cout<<"overflow";
    }
    else{
        if(f==-1){
            f++;
        }
        r++;
        queue[r]=item;
        qz++;
        cout<< item << "pushed to the queue";
    }
}

void dequeue(){
    if (qz<=0)
    {
        /* code */
        cout<<"underflow messages";
    }
    else{
        int x=queue[f];
        f--;
        qz--;
        cout<<" the poed value is :" <<x;
    }
    
}
void display(){
    if(qz==0){
        cout<<"Empty list"<<endl;
    }
    else{
        for(int i=f;i<=r;i++){
            cout<<queue[i];
        }
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
}
}
