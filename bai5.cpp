#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[500][500];
int m,n;
//Do phải truyền giá trị vào hàm con nhiều nên em khai báo mảng a ,m,n là biến cục bộ luôn cho nhanh
//Câu 1:
void tao_mang(){
    scanf("%d%d",&m,&n);
    srand(time(0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a[i][j]= rand()%100;        //em giới hạn phạm vi ngẫu nhiên từ 0->99 cho dễ nhìn 
        }
    }
}
//Câu 2:
void in_mang(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
//Câu 3:
void min_max(){
    int min=a[0][0],max=a[0][0];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]<min)min=a[i][j];
            if(a[i][j]>max)max=a[i][j];
        }
    }
    printf("Min = %d    Max=%d\n",min,max);
}
//Câu 4:
void sap_xep_zigzag(){                              //zigzag theo hàng ngang
    int tmp[m*n+1];
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            tmp[k++]=a[i][j];
        }
    }
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(tmp[j]<tmp[i]){
                int temp=tmp[i];
                tmp[i]=tmp[j];
                tmp[j]=temp;
            }
        }
    }
    int l=0;
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                a[i][j]=tmp[l++];
            }
        }else{
            for(int j=n-1;j>=0;j--){
                a[i][j]=tmp[l++];
            }
        }
    }
    in_mang();
}
//Câu 5:
void them_dong_cuoi(){
    for(int i=0;i<n;i++){
        scanf("%d",&a[m][i]);
    }
    m++;
    in_mang();
}
//Câu 6:
void them_dong_k(){                             //coi dòng đầu tiên là dòng thứ nhất
    int k;
    scanf("%d",&k);
    k--;
    for(int i=m;i>k;i--){
        for(int j=0;j<n;j++){
            a[i][j]=a[i-1][j];
        }
    }
    m++;
    for(int i=0;i<n;i++){
        scanf("%d",&a[k][i]);
    }
    in_mang();
}
//Câu 7:
void xoa_dong_k(){                              //coi dòng đầu tiên là dòng thứ nhất
    int k;
    scanf("%d",&k);
    k--;
    for(int i=k;i<m-1;i++){
        for(int j=0;j<n;j++){
            a[i][j]=a[i+1][j];
        }
    }
    m--;
    in_mang();
}
//Câu 8:
void max_dong_min_cot(){
    int hang=-1,cot=-1;
    for(int i=0;i<m;i++){
        int p=0;
        for(int j=0;j<n;j++){
            if(a[i][j]>a[i][p]){
                p=j;
            }
        }
        int check=1;
        for(int j=0;j<n;j++){
            if(a[i][p]>a[j][p]){
                check=0;
                break;
            }
        }
        if(check){
            hang=i;
            cot=p;
            break;
        }
    }
    if(hang==-1)printf("khong co gia tri thoa man\n");
    else printf("so o vi tri %d %d la so lon nhat trong hang va nho nhat trong cot\n",hang,cot);
}
//Câu 9:
void tong_2_ma_tran(int x[500][500],int y[500][500],int ans[500][500],int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=x[i][j]+y[i][j];
        }
    }
}

void tich_2_ma_tran(int x[500][500],int y[500][500],int ans[500][500],int m,int n,int p){
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            int tmp=0;
            for(int k=0;k<n;k++){
                tmp+=(x[i][k]*y[k][j]);
            }
            ans[i][j]=tmp;
        }
    }
}
//Câu 10:
int check(int x){
    if(x<2)return 0;
    int p=sqrt(x);
    for(int i=2;i<=p;i++){
        if(x%i==0)return 0;
    }
    return 1;
}

void tong_nt(){
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(check(a[i][j]))ans+=a[i][j];
        }
    }
    printf("tong cac so nguyen to trong ma tran la : %d\n",ans);
}
//Câu 11:
void dem_so_duong_tam_giac_tren(){
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=i;j<n;j++){
            if(a[i][j]>0)count++;
        }
    }
    printf("so cac so duong trong ma tran tam giac tren la : %d\n",count);
}
//Câu 12:
void trung_binh_cong(double s[500][500],int m,int n){
    double ans=0;
    int cot;
    scanf("%d",&cot);
    for(int i=0;i<m;i++){
        ans+=s[i][cot];
    }
    ans/=m;
    printf("trung binh cong tren cot %d la %lf\n",cot,ans);
}
//Câu 13:
void tong_tren_bien(){
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=a[0][i];
    }
    for(int i=1;i<m;i++){
        ans+=a[i][n-1];
    }
    for(int i=0;i<n-1;i++){
        ans+=a[m-1][i];
    }
    for(int i=1;i<m-1;i++){
        ans+=a[i][0];
    }
    printf("tong cac phan tu tren bien cua ma tran la: %d\n",ans);
}

int main(){
    tao_mang();
    in_mang();
    min_max();
    sap_xep_zigzag();
    them_dong_cuoi();
    them_dong_k();
    xoa_dong_k();
    max_dong_min_cot();
    //tong_2_ma_tran(x,y,ans,m,n)                   em có viết hàm ở bên trên 
    //tich_2_ma_tram(x,y,ans,m,n,p)
    tong_nt();
    dem_so_duong_tam_giac_tren();                   //hàm này cho đáp án sai với bài này do ma trận bên trên không vuông
    //trung_binh_cong(s,m,n)                        em có viết hàm bên trên
    tong_tren_bien();
}
