#include <iostream>
#include <math.h>
using namespace std;
struct TreeNode{ // dinh nghia cac node
     int data;
    TreeNode* left; //tao con tro trai co dang TreeNode
    TreeNode* right; //tao con tro phai co dang TreeNode
};
// Ham kiem tra so nguyen to
bool IsPrime(int n){
    if (n < 2) return false; // neu phan tu nho hon 2 thi khong phai so nguyen to
    for (int i = 2; i <= sqrt(n); i ++ ){ // cho chay tu 2 toi sqrt(n) de tim kiem n co chia het cho so nao hay khong
        if (n % i == 0) return false; //neu chia het thi khong phai so nguyen to
    }
    return true;
}

//ham sap xep mang
void SapXepMang(int temp[], int size) { //sap xep theo thuat toan bubble sort
    for (int i = 0; i < size - 1; i++) { // so sanh tung phan tu voi nhau
        for (int j = 0; j < size - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                swap(temp[j], temp[j + 1]); // hoan doi neu tha dieu kien
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
    TreeNode* root = creatNode(a[mid]); //tao 1 con tro co cau truc TreeNode va gan gia tri nut do la a[mid]
    // xay dung cay tu hai node con hai ben
    root -> left = Nhapcay(a, left, mid -1); //goi lai ham nhap cay de xay dung cay nhi phan ben trai
    root -> right = Nhapcay(a, mid + 1, right); //tuong tu xay cay nhi phan ben phai
    return root;
}

// tao ham duyet cay de dam bao cay dang dung thu tu
void DuyetCay(TreeNode* root){
    if (root == NULL) return; //neu nhu  nut goc khong co gia tri thi thoat ham
    DuyetCay(root->left); //Duyet cac phan tu ben trai
    cout<< root->data<<" ";
    DuyetCay(root->right); // Duyet cac phan tu ben phai
}

//cau a: Tim so nguyen to lon nhat
int TimSNT_MAX(TreeNode* root){
    int solonnhat = 0; // cho so lon nhat la 0 va thay doi khi tim thay so lon hon
    while (root != NULL){
        if (IsPrime(root->data)){ //xac dinh coi cac du lieu cua nut co phai so nguyen to khong
            solonnhat = root->data; // neu phai thi gan gia tri so lon nhat bang gia tri cua nut do
        }
        root = root->right; //tiep tuc tim kiem tim kiem ben phai vi cac phan tu sau ben phai luon lon hon nut goc cua cay
    }
    return solonnhat;
}

//cau b: Ham tim dong co so nguyen to
void TimDongCoSNT(int temp[], int& d, TreeNode* root) {
    if (root == NULL) return;
    if (IsPrime(root->data)) {  //xac dinh coi cac du lieu cua nut co phai so nguyen to khong
        temp[d++] = root->data; //luu du lieu cua nut do vao 1 mang tam
    }
    TimDongCoSNT(temp, d, root->left); //tiep tuc voi nhanh trai
    TimDongCoSNT(temp, d, root->right); // tiep tuc voi nhanh phai
}
void TimDong(int temp[], int m, int n, int a[][3]){
     cout<<"Dong co chua so nguyen to la: "<<endl;
    bool found = false; //dat 1 ham tim kiem de xac dinh co dong nao chua so nguyen to khong

    for (int i = 0; i < m; i++) {
        bool coso = false; // ham tim kiem so nguyen to

        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m * n; l++) {
                if (temp[l] == a[i][j]) { // Neu phan tu trong mang tam trung voi phan tu trong ma tran
                    coso = true; // tra ve ket qua la tim thay
                    break; //thoat ham de tranh lap lai
                }
            }
            if (coso) break; // thoat vong lap neu phat hien thay so nguyen to
        }

        if (coso) {
            cout << i << " "; // in ket qua la dong co chua so nugyen to
            found = true; // tra co ket qua la co dong co chua so nguyen to
        }
    }

    if (!found) { // neu ket qua tra ve khong thay thi in ra khong co dong nao chua so nguyen to
        cout << "Khong co dong nao chua so nguyen to.";
    }

    cout << endl;
}
//cau c: Tim nhung dong chi chua so nguyen to
void TimDongChiCoSNT(int a[][3], int m, int n){
    cout<<"Cac dong chi chua so nguyen to: "<<endl;
    for (int i = 0; i < m; i++){ // tao dieu kien chay tu 0 toi m-1 de kiem dong chi chua so nguyen to
        bool codong = true; // tao ham dung sai ban dau de xac dinh co dong nao chi chua so nguyen to khong
        for (int j = 0; j < n; j++){
            if (!IsPrime(a[i][j])) // neu cac phan tu cua dong do co phan tu nao khong phai so nguyen to thi thoat ham
                codong = false;
                break;
        }
        if (codong) // neu ham xac dinh dong chi chua so nguyen to tra ve gia tri dung thi in ra dong do
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
    int temp[m*n]; //tao mang tam co kich thuoc = m * n
    int d = 0;
    for (int i = 0; i < m; i++){ // ham sap xep mang 2 chieu thanh mang 1 chieu
        for (int j = 0; j < n; j ++){
            temp[d++] = a[i][j]; // luu  cac gia tri cua mang 2 chieu tuan tu vao mang 1 chieu
        }
    }
    SapXepMang(temp, m*n); // goi lai ham sap xep mang de sap xep mang 1 chieu
    Nhapcay(temp,0, m*n -1); //goi ham nhap cay de nhap cac gia tri tu mang da sap xep vao cac not tren cay
    TreeNode* root = Nhapcay(temp, 0, m*n -1);
    
    //cau a
    int caua = TimSNT_MAX(root); //gan gia tri cua ham tim so nguyen to lon nhat
   
   //cau b
   TimDongCoSNT(temp, d, root); // goi ham tim dong co chua so nguyen to
   TimDong(temp,m,n,a); // goi ham tim dong de tim phan tu trong mang tam ung voi phan tu nao trong mang 2 chieu
   if (caua != 0){ // neu ket qua tra ve tim so nguyen to lon nhat khac 0 thi in gia tri do ra
   cout<<"So nguyen to lon nhat trong mang la: "<<caua<<endl;
   }
   else // va neu ham tra ve gia tri 0 thi in ra
   cout<<"Khong co so nguyen to trong mang!"<<endl;
   // ham duyet cay de dam bao cay dung thu tu
   if (root == NULL) {
    cout << "Cây rỗng, không thể duyệt\n"; // neu nut khong co gia tri tuc la cay rong
} else {
    cout << "Bắt đầu duyệt cây...\n"; // neu co gia tri thi in cac gia tri do ra
    DuyetCay(root);
}
   return 0;
}

