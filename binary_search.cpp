//binary search by accept from user
#include <iostream>
using namespace std;
int binarysearch(int arr[],int size,int key){
    int low=0;
    int high=size-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1; // not found
}
int main(){
    int size,key;
    cout<<"enter the size of array"<<endl;
    cin>>size;
    int arr[size];
    cout<<"enter the elements in sorted order"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"enter the key to search"<<endl;
    cin>>key;
    int result=binarysearch(arr,size,key);
    if(result!=-1){
        cout<<"element found at index "<<result<<endl;
    }
    else{
        cout<<"element not found in the array"<<endl;
    }
    return 0;
}