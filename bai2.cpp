#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

typedef struct dathuc
{
	// gioi han bac da thuc la 20 de thuan loi cho viec tinh toan
	float a[20];
	int bac;
}dt;

void khoitao(dt *d){
	memset(d->a,0,20*sizeof(float));
}

void nhapDaThuc(dt *d){
	printf("nhap bac da thuc: ");
	scanf("%d",&d->bac);
	printf("nhap cac so hang cua da thuc theo thu tu An An-1 ...\n");
	khoitao(d);
	for(int i=d->bac; i>=0;i--){
		scanf("%f",&d->a[i]);
	}
}

void inDaThuc(dt d){
	int i;
	for(i=d.bac; i>=1;i--){
		if(d.a[i] != 0)printf("%.2fx^%d + ",d.a[i],i);
	}
	printf("%.2f\n", d.a[0]);
}

void tinhDaThuc(dt d){
	float x;
	printf("nhap gia tri x:");
	scanf("%f",&x);
	double ans = 0;
	for(int i=0;i<=d.bac;i++){
		ans += d.a[i]*pow(x,i);
	}
	printf("gia tri da thuc: %lf\n",ans);
}

dt tongDathuc(dt a,dt b){
	dt ans;
	khoitao(&ans);
	int max = a.bac > b.bac ? a.bac : b.bac;
	ans.bac = max;
	for(int i=0;i<=max;i++){
		ans.a[i] = a.a[i] + b.a[i];
	}
	return ans;
}
dt hieuDathuc(dt a,dt b){
	dt ans;
	khoitao(&ans);
	int max = a.bac > b.bac ? a.bac : b.bac;
	ans.bac = max;
	for(int i=0;i<=max;i++){
		ans.a[i] = a.a[i] - b.a[i];
	}
	return ans;
}

dt nhanDathuc(dt a,dt b){
	dt ans;
	khoitao(&ans);
	for(int i=0;i<=a.bac;i++){
		for(int j=0;j<=b.bac;j++){
			ans.a[i+j] += a.a[i]*b.a[j];
		}
	}
	ans.bac = a.bac + b.bac;
	return ans;
}

dt daoham(dt d){
	dt ans;
	memset(ans.a,0,20*sizeof(float));
	ans.bac = d.bac - 1;
	for(int i=d.bac;i>=1;i--){
		ans.a[i-1] = d.a[i]*i;
	}
	return ans;
}

dt nhanHeso(dt d,int a,int bac){ //ham ho tro cho phep chia
	dt ans;
	khoitao(&ans);
	for(int i=bac;i<=bac + d.bac;i++){
		ans.a[i] = d.a[i-bac]*a;
	}
	return ans;
}

dt chiaDathuc(dt a,dt b){ // bac a > bac b
	dt ans;
	dt du;
	dt tmp;
	khoitao(&ans);
	khoitao(&du);
	int m = a.bac - b.bac;
	int i =  a.bac;
	int j = b.bac;
	ans.bac = m;
	while(m >= 0){
		ans.a[m] = a.a[i] / b.a[j];
		tmp = nhanHeso(b,ans.a[m],m);
		a = hieuDathuc(a,tmp);
		m--;
		i--;
	}
	return ans;
}

dt chiaLaydu(dt a,dt b){
	dt ans;
	dt du;
	khoitao(&ans);
	khoitao(&du);
	int m = a.bac - b.bac;
	int i =  a.bac;
	ans.bac = m;
	while(m >= 0){
		ans.a[m] = a.a[i] / b.a[b.bac];
		a = hieuDathuc(a,nhanHeso(b,ans.a[m],m));
		m--;
		i--;
	}
	int k = 19;
	while(a.a[k] == 0 && k>0)k--;
	a.bac = k;
	return a;
}

int main() {
	int opt;
	dt a,b,c;
	do{
		printf("1:tinh gia tri da thuc\n");
		printf("2:tong 2 da thuc\n");
		printf("3:hieu hai da thuc\n");
		printf("4:tich 2 da thuc\n");
		printf("5:thuong 2 da thuc\n");
		printf("6:dao ham cap 1 cua da thuc\n");
		printf("7:tinh da thuc du trong phep chia\n");
		printf("8:thoat chuong trinh\n");
		printf("nhap lua chon:");
		scanf("%d",&opt);
		system("cls");
		switch (opt)
		{
		case 1:
			nhapDaThuc(&a);
			tinhDaThuc(a);
			break;
		case 2:
			nhapDaThuc(&a);
			nhapDaThuc(&b);
			c = tongDathuc(a,b);
			printf("tong hai da thuc la da thuc:\n");
			inDaThuc(c);
			break;
		case 3:
			nhapDaThuc(&a);
			nhapDaThuc(&b);
			c = hieuDathuc(a,b);
			printf("hieu hai da thuc la da thuc:\n");
			inDaThuc(c);
			break;
		case 4:
			nhapDaThuc(&a);
			nhapDaThuc(&b);
			c = nhanDathuc(a,b);
			printf("tich hai da thuc la da thuc:\n");
			inDaThuc(c);
			break;
		case 5:
			printf("nhap da thuc chia truoc !\n");
			nhapDaThuc(&a);
			nhapDaThuc(&b);
			c = chiaDathuc(a,b);
			printf("thuong hai da thuc la da thuc:\n");
			inDaThuc(c);
			break;
		case 6:
			nhapDaThuc(&a);
			printf("dao ham cap 1 cua da thuc:\n");
			inDaThuc(daoham(a));
			break;
		case 7:
			printf("nhap da thuc chia truoc !\n");
			nhapDaThuc(&a);
			nhapDaThuc(&b);
			c = chiaLaydu(a,b);
			printf("du trong phep chia 2 da thuc la da thuc:\n");
			inDaThuc(c);
			break;
		default:
			break;
		}
		system("pause");
		system("cls");	
	}while(opt != 8);
	return 0;
}