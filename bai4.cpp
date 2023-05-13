#include<stdio.h>
#include<string.h>
//Em nghĩ ý thầy là nhập thông tin nhân viên và lưu nó vào file LUONG.DAT
//Sau đó lấy thông tin từ file LUONG.DAT vừa lưu ở trên để tính lương cho từng nhân viên
//Cuối cùng là lưu nó vào một file khác(trong bài này em lưu nó vaof file TINHLUONG.DAT) 
//Vì thầy không nói rõ cách nhập như thế nào nên đây là cách nhập theo code của em
//INPUT:
//số lượng nhân viên                2
//nhan vien a                       nguyen van a
//mnv                               1
//bậc lương                         1
//nhan vien b                       nguyen van b
//mnv                               2
//bậc lương                         2
//.....
struct nhanvien{
    char ten[100];
    int mnv;
    int bacluong;
    long long luong;
};
int main(){
    int n;
    scanf("%d",&n);
    struct nhanvien s[1000];
    for(int i=0;i<n;i++){
        getchar();
        gets(s[i].ten);
        scanf("%d%d",&s[i].mnv,&s[i].bacluong);
    }
    //Lưu thông tin nhập vào file LUONG.DAT
    FILE *p=fopen("LUONG.DAT","w");
    for(int i=0;i<n;i++){
        fprintf(p,"%s\n%d\n%d\n",s[i].ten,s[i].mnv,s[i].bacluong);
    }
    fclose(p);
    //Đọc thông tin từ file LUONG.DAT
    p=fopen("LUONG.DAT","r");
    struct nhanvien a[1000];
    for(int i=0;i<n;i++){
        char tmp[100];
        fgets(tmp,100,p);
        tmp[strcspn(tmp,"\n")]=0;
        strcpy(a[i].ten,tmp);
        fscanf(p,"%d%d",&a[i].mnv,&a[i].bacluong);
        a[i].luong=(long long)a[i].bacluong*1700000;
        if(i!=n){
            char c;
            fscanf(p,"%c",&c);
        }
    }
    fclose(p);
    //xuất kết quả vào file TINHLUONG.DAT
    p=fopen("TINHLUONG.DAT","w");
    for(int i=0;i<n;i++){
        fprintf(p,"%s %d %d %lld\n",a[i].ten,a[i].mnv,a[i].bacluong,a[i].luong);
    }
    fclose(p);
}