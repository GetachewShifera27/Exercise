//linear search by accept from user
#include <iostream>
using namespace std;
int linearsearch(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i; // element found at index i
        }
    }
    return -1; // element not found
}
int main(){
    int size,key;
    cout<<"enter the size of array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"enter the elements in array"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"enter the key to search"<<endl;
    cin>>key;
    int result=linearsearch(arr,size,key);
    if(result!=-1){
        cout<<"element found at index "<<result<<endl;
    }
    else{
        cout<<"element not found in the array"<<endl;
    }
    return 0;
}