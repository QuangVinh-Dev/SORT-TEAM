#include <iostream>
using namespace std;

// Ham dua mot node ve vi tri dung trong heap
void XayCay(int a[], int n, int i) {
    int solonnhat = i;      // dat node goc la lon nhat
    int left = 2 * i + 1; // gia tri node trai
    int right = 2 * i + 2;// gia tri node phai

    // neu con trai lon hon node goc
    if (left < n && a[left] > a[solonnhat]) 
        solonnhat = left;

    // neu con phai lon hon node goc
    if (right < n && a[right] > a[solonnhat]) 
        solonnhat = right;

    // neu solonnhat thay doi, hoan doi va goi de quy
    if (solonnhat != i) {
        swap(a[i], a[solonnhat]);
        XayCay(a, n, solonnhat);
    }
}

// Ham xay cay giam dan
void HeapSort(int arr[], int n) {
    // tao max heap
    for (int i = n / 2 - 1; i >= 0; i--) 
        XayCay(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Dua phan tu lon nhat len cuoi
        XayCay(arr, i, 0);    // Xay dung lai heap
    }
}

// Ham sap xep chan le
void SapXepChanLe(int arr[], int n) {
    int left = 0, right = n - 1; // cho 2 con tro dau va cuoi
    while (left < right) {
        while (left < right && arr[left] % 2 == 0) left++;  // tim so le ben trai
        while (left < right && arr[right] % 2 != 0) right--; // tim so chan ben phai
        if (left < right) swap(arr[left], arr[right]); // doi cho de dua chan ve dau, le ve cuoi
    }
}

int main() {
    int a[] = {12, 7, 9, 10, 5, 2, 8, 1, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);

    // goi ham sap xep chan le
    SapXepChanLe(a, n);

    // tim vi tri dau tien cua so le
    int dem = 0;
    while (dem < n && a[dem] % 2 == 0){
        dem++;
    }

    // sap xep chan le bang heap sort
    HeapSort(a, dem);         // sap xep day so chan
    HeapSort(a + dem, n - dem); // sap xep day so le

    // in ket qua
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) 
        cout << a[i] << " ";

    return 0;
}