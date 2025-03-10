#include<iostream>
using namespace std;
void Heapify(int arr[],int n,int i)
{
    int left =2*i+1;
    int right =2*i+2;
    int Largest=i;
    if(left<n && arr[left]>arr[Largest])
    {
        Largest=left;
    }
    if(right<n && arr[right]>arr[Largest])
    {
        Largest=right;
    }
    if( Largest !=i)
    {
        swap(arr[i],arr[Largest]);
        Heapify(arr,n,Largest);
    }
}
void SortHeap(int arr[],int n)
{
    for(int i=n/2 -1;i >=0;i--)
    {
        Heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        Heapify(arr,i,0);
    }
}
int main()
{
    int arr[1000];
    int n;
    cout<<"Nhap so phan tu cua mang: ";cin>>n;
    cout<<"Nhap mang: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    SortHeap(arr,n);
    cout<<"Mang sau khi sap xep: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}