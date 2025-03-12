#include <iostream>
#include <math.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};
// Ham kiem tra so nguyen to
bool IsPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i ++ ){
        if (n % i == 0) return false;
    }
    return true;
}

//ham sap xep mang
void SapXepMang(int temp[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                swap(temp[j], temp[j + 1]);
            }
        }
    }
}

TreeNode* creatNode(int val){
    TreeNode* Node = new TreeNode(); // tao ra 1 node moi va cap phat vung nho cho no
    Node ->data=val;
    Node->left=NULL; //con tro tro den ben trai
    Node->right=NULL;//con tro tro den ben phai
    return Node;
   
}

//Ham nhap cay
TreeNode* Nhapcay(int a[], int left, int right){
    if (left > right) return NULL; // thoat ham neu vi tri ko hop le
    int mid = (left + right)/2;
    TreeNode* root = creatNode(a[mid]);
    // xay dung cay tu hai node con hai ben
    root -> left = Nhapcay(a, left, mid -1);
    root -> right = Nhapcay(a, mid + 1, right);
    return root;
}

// tao ham duyet cay de dam bao cay dang dung thu tu
void DuyetCay(TreeNode* root){
    if (root == NULL) return;
    DuyetCay(root->left); //Duyet cac phan tu ben trai
    cout<< root->data<<" ";
    DuyetCay(root->right); // Duyet cac phan tu ben phai
}

//cau a: Tim so nguyen to lon nhat
int TimSNT_MAX(TreeNode* root){
    int solonnhat = 0; // cho so lon nhat la 0 va thay doi khi tim thay so lon hon
    while (root != NULL){
        if (IsPrime(root->data)){
            solonnhat = root->data;
        }
        root = root->right;
    }
    return solonnhat;
}

//cau b: Ham tim dong co so nguyen to
void TimDongCoSNT(int temp[], int& d, TreeNode* root) {
    if (root == NULL) return;
    if (IsPrime(root->data)) {
        temp[d++] = root->data;
    }
    TimDongCoSNT(temp, d, root->left);
    TimDongCoSNT(temp, d, root->right);
}
void TimDong(int temp[], int m, int n, int a[][3]){
     cout<<"Dong co chua so nguyen to la: "<<endl;
    bool found = false; // Kiểm tra nếu không có dòng nào hợp lệ

    for (int i = 0; i < m; i++) {
        bool coso = false; // Kiểm tra từng dòng

        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m * n; l++) {
                if (temp[l] == a[i][j]) { // Nếu phần tử trong temp trùng với phần tử trong ma trận
                    coso = true;
                    break; // Không cần kiểm tra tiếp trong temp[]
                }
            }
            if (coso) break; // Thoát vòng lặp nếu tìm thấy ít nhất một số nguyên tố
        }

        if (coso) {
            cout << i << " "; // In số dòng chứa số nguyên tố
            found = true;
        }
    }

    if (!found) {
        cout << "Khong co dong nao chua so nguyen to.";
    }

    cout << endl;
}
//cau c: Tim nhung dong chi chua so nguyen to
void TimDongChiCoSNT(int a[][3], int m, int n){
    cout<<"Cac dong chi chua so nguyen to: "<<endl;
    for (int i = 0; i < m; i++){
        bool codong = true;
        for (int j = 0; j < n; j++){
            if (!IsPrime(a[i][j]))
                codong = false;
                break;
        }
        if (codong)
            cout<<i<<" ";
        
    }
    cout<<endl;
}


int main(){
    int a[2][3] ={
        {1,3,4},
        {2,5,7}
    };
    int m = 2, n= 3;
    int temp[m*n];
    int d = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j ++){
            temp[d++] = a[i][j];
        }
    }
    SapXepMang(temp, m*n);
    Nhapcay(temp,0, m*n -1);
    TreeNode* root = Nhapcay(temp, 0, m*n -1);
   int caua = TimSNT_MAX(root);
   
   
   TimDong(temp,m,n,a);
   if (caua != 0){
   cout<<"So nguyen to lon nhat trong mang la: "<<caua<<endl;
   }
   else
   cout<<"Khong co so nguyen to trong mang!"<<endl;
   TimDongCoSNT(temp, d, root);
   if (root == NULL) {
    cout << "Cây rỗng, không thể duyệt\n";
} else {
    cout << "Bắt đầu duyệt cây...\n";
    DuyetCay(root);
}
   return 0;
}

