#include<iostream>
#include<ctime>
#include<cstdlib>
#include<time.h>
using namespace std;
//Ham tao mang ngau nhien
void createArray_Random(int arr[],int size)
{
    for(int i=0; i < size;i++)
    {
        arr[i]=rand()%(size*10);//so ngau nhien tu 0->size*10
    }
}

//Heap sort
void Heapify(int arr[],int n,int i)
{
    int left=2*i+1; // gia tri cua nut trai
    int right=2*i+2; // gia tri cua nut phai
    int largest=i; // gia su nut ban dau la lon nhat
    if(left<n && arr[left]>arr[largest]) largest = left; // neu phan tu ben trai lon hon co hieu thi gan gia tri vo no
    if(right<n && arr[right]>arr[largest]) largest =right; // neu phan tu ben phai lon hon co hieu thi gan gia tri vo no
    // Nếu largest thay đổi, hoán đổi và đệ quy
    if (largest != i) // neu phan tu lon nhat khac voi phan tu dang xet
    {
        swap(arr[i], arr[largest]); // hoan doi 2 phan tu do voi nhau
        Heapify(arr, n, largest); //goi lai ham heap sort de tiep tuc sap xep
    }
}
    //Ham sap xep Heap
void HeapSort(int arr[],int n)
{
    //xay dung cay
    for(int i=(n/2)-1;i>=0;i--) Heapify(arr,n,i);
    //doi cho node dau tien voi node cuoi cung
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]); // dua phan tu lon nhat hien tai ve cuoi mang
        Heapify(arr,i,0); // goi ham de tiep tuc duy tri tinh chat cua cay
    }
}
//Hàm đo thời gian chạy
void MeasureTime(int size)
{
    int* arr=new int[size];


    createArray_Random(arr,size);

    clock_t start, end;

    double  time_use_Heap,time_use_Merge,time_use_Quick;
    //Đo thời gian thực hiện heap sort
    int *arr_Heap=new int [size];//cấp phát mảng động
    //Cấp phát mảng ngẫu nhiên
    copy(arr,arr+size,arr_Heap);// Sao chép nội dung của arr vào arr_heap để đảm bảo cùng dữ liệu ban đầu
    createArray_Random(arr_Heap,size);
    start=clock();//bắt đầu đo thời gian
    HeapSort(arr_Heap,size);//gọi hàm Heáport để sắp xếp mảng arr_Heap
    end =clock();//kết thúc đo thời gian
    time_use_Heap=(double)(end-start)/CLOCKS_PER_SEC;//tính thời gian chạy đổi sang giây
    delete[] arr_Heap;//giải phóng bộ nhớ
    cout<<"Thoi gian thuc hien HeappSort: "<<time_use_Heap<<"s"<<endl;
    delete[] arr;
}
int main()
{
    srand(time(0));
    // taoj kich thuoc cho mang ngau nhien
    int sizes[] = {10, 100, 200, 300, 400, 500, 600, 700, 800, 900, 
        1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    cout<<"Đang chờ thời gian chạy ..."<<endl;
    for(int i=0;i<20;i++)
    {
        MeasureTime(sizes[i]);
    }
    return 0;
}