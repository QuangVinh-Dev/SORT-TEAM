#include<iostream>
using namespace std;
//Phan vung mang
void Partition(int arr[],int low,int hight)
{
    //Tao pivot
    int pivot=arr[(low+hight)/2];
    int i=low;
    int j=hight;
    while(arr[i]<pivot) i++;//Neu phan tu ben trai nho hon pivot thi tang i
    while(arr[j]>pivot) j--;//Neu phan tu ben phai lon hon pivot thi giam j
    //Neu i<=j thi doi cho 2 phan tu do
    if(i<=j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    //Lap lai den khi i>j
    while(i>j);
    //Phan vung ben trai
    if(low<j) Partition(arr,low,j);
    //Phan vung ben phai
    if(i<hight) Partition(arr,i,hight);
}
//Ham sap xep QuickSort
void QuickSort(int arr[],int n)
{
    Partition(arr,0,n-1);
}
int main()
{
    int arr[1000];
    int n;
    cout<<"Nhap so phan tu cua mang: ";cin>>n;
    cout<<"Nhap mang: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    QuickSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}