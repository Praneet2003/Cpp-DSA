#include<iostream>
using namespace std;
int reverseInt(int arr[],int n){
    int start = 0;
    int end= n-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int num[20];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    cout<<"After Reversing the string:- "<<endl;
    int ans = reverseInt(num,n);
    cout<<ans;
}