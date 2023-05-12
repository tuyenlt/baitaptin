#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int a[1000];
int n;

void handInput(){
    printf("nhap so phan tu :");
    scanf("%d",&n);
    printf("nhap cac phan tu:\n");
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
}
void randomInput(){
    printf("nhap so phan tu :");
    scanf("%d",&n);
    for(int i=0;i<n;i++)a[i] = (rand() % 2000) - 1000;
}

void printOut(){
    for(int i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
}

void maxAndMin(){
    int max = a[0];
    int min = a[0];
    for(int i=1;i<n;i++){
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }
    printf("MAX is: %d, MIN is %d\n",max,min);
}

void nevEndAt6(){
    for(int i=0;i<n;i++){
        if(a[i] < 0 && (-a[i]) % 10 == 6){
            printf("Phan tu am dau tien tan cung la 6: %d\n",a[i]);
            return;
        }
    }
    printf("khong ton tai phan tu am tan cung la 6\n");
}

void minPositiveNumPos(){
    int min_pos = 0;
    while(a[min_pos] <= 0 && min_pos < n) min_pos++;
    if(min_pos == n){
        printf("mang khong chua phan tu duong \n");
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i] > 0 && a[i] < a[min_pos]) min_pos = i;
    }
    printf("vi tri phan tu duong nho nhat la: %d\n",min_pos);
}

long long getSumALL(){
    long long sum = 0;
    for(int i=0;i<n;i++) sum += a[i];
    return sum;
}

double getAverage(){
    return (double)getSumALL()/ n;
}

void find(){
    int x;
    printf("nhap x:");
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        if(a[i] == x){
            printf("x duoc tim thay tai vi tri thu: %d\n", i+1);
            return;
        }
    }
    printf("x khong ton tai trong mang\n");
}

void sort(int flag){ // 0 : decrase; 1 : incrase
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<i;j++){
            if( (a[j] > a[j+1]) ==  flag){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    printf("mang da duoc sap xep\n");
}

void printReverse(){
    for(int i=n-1;i>=0;i--)printf("%d ",a[i]);
    printf("\n");
}

void insert(){
    int x,k;
    printf("nhap phan tu x va vi tri k:");
    scanf("%d%d",&x,&k);
    for(int i=n;i>=k;i--){
        a[i] = a[i-1];
    }
    a[k] = x;
}

void delete(){
    int k;
    printf("nhap vi tri muon xoa");
    scanf("%d",&k);
    for(int i=k;i<n-1;i++){
        a[i] = a[i+1];
    }
}

void countAndSumPossitive(){
    int cnt = 0;
    long long sum = 0;
    for(int i=0;i<n;i++){
        if(a[i] > 0){
            cnt++;
            sum+=a[i];
        }
    }
    printf("co %d phan tu duong va tong bang %lld\n",cnt,sum);
}

void palindromeCheck(){
    int i=0;
    int j=n-1;
    while(i < j){
        if(a[i] != a[j]){
            printf("mang khong doi xung\n");
            return;
        }
        i++;
        j--;
    }
    printf("mang la mang doi xung\n");
}

void isIncrase(){
    for(int i=0;i<n;i++){
        if(a[i] > a[i+1]){
            printf("mang khong sap xep theo thu tu tang\n");
            return;
        }
    }
    printf("mang duoc sap sep theo thu tu tang\n");
}

int main(){
    srand((int)time(0));
    printf("1:khoi tao bang tay\n");
    printf("2:khoi tao ngau nhien\n");
    printf("nhap lua chon:");
    int opt;
    scanf("%d",&opt);
    if(opt == 1)handInput();
    else if(opt == 2)randomInput();
    system("cls");
    do{
        printf("Thao tac tren mang\n");
        printf("1:in mang\n");
        printf("2:phan tu lon nhat va nho nhat\n");
        printf("3:phan tu am dau tien tan cung la 6\n");
        printf("4:vi tri phan tu duong nho nhat\n");
        printf("5:Tong cua mang\n");
        printf("6:trung binh cong\n");
        printf("7:tim phan tu\n");
        printf("8:sap xep\n");
        printf("9:in day dao nguoc\n");
        printf("10:chen phan tu\n");
        printf("11:xoa phan tu\n");
        printf("12:so phan tu duong va tong\n");
        printf("13:kiem tra doi xung\n");
        printf("14:kiem tra mang tang dan\n");
        printf("15:thoat chuong trinh\n");
        printf("nhap lua chon:");
        scanf("%d",&opt);
        system("cls");
        int flag; // for sort option
        switch (opt)
        {
            case 1:
                printOut();
                break;
            case 2:
                maxAndMin();
                break;
            case 3:
                nevEndAt6();
                break;
            case 4:
                minPositiveNumPos();
                break;
            case 5:
                printf("tong cua mang la:%lld\n",getSumALL());
                break;
            case 6:
                printf("trung binh cong cua mang la:%lf",getAverage());
                break;
            case 7:
                find();
                break;
            case 8:
                printf("1:tang dan \n0:giam dan \n");
                scanf("%d",&flag);
                sort(flag);
                break;
            case 9:
                printReverse();
                break;
            case 10:
                insert();
                break;
            case 11:
                delete();
                break;
            case 12:
                countAndSumPossitive();
                break;
            case 13:
                palindromeCheck();
                break;
            case 14:
                isIncrase();
                break; 
            default:
                break;
        }
        system("pause");
        system("cls");

    }while(opt != 15);
    return 0;
}