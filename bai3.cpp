#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int GCD(int a, int b){
	if(b == 0)return a;
	return GCD(b, a%b);
}

int LCD(int a, int b){
	return (a*b)/GCD(a,b);
}

typedef struct phanso{
	int t;
	int m;
}ps;


void nhapPhanSo(ps *a){
	printf("Nhap tu va mau phan so:");
	scanf("%d%d",&a->t,&a->m);
}

void inPhanSo(ps a){
	printf("%d / %d\n",a.t,a.m);
}

void rutgon(ps *a){
	int tmp = GCD(a->t,a->m);
	a->t /= tmp;
	a->m /= tmp;
}

void quydong(ps *a, ps *b){
	int tmp = LCD(a->m,b->m);
	a->t *= (tmp / a->m);
	b->t *= (tmp / b->m);
	b->m = tmp;
	a->m = tmp;
}

ps tong(ps a,ps b){
	ps ans;
	quydong(&a,&b);
	ans.t = a.t + b.t;
	ans.m = a.m;
	rutgon(&ans);
	return ans;
}

ps hieu(ps a,ps b){ // a - b
	ps ans;
	quydong(&a,&b);
	ans.t = a.t - b.t;
	ans.m = a.m;
	rutgon(&ans);
	return ans;	
}

ps tich(ps a,ps b){
	ps ans;
	ans.t = a.t*b.t;
	ans.m = a.m*b.m;
	rutgon(&ans);
	return ans;
}

ps thuong(ps a, ps b){
	ps ans;
	ans.t = a.t * b.m;
	ans.m = a.m * b.t;
	rutgon(&ans);
	return ans;
}

int xetdau(ps a){
	if(a.t*a.m > 0) return 1;
	else if(a.t*a.m == 0) return 0;
	else return -1;
}

int sosanh(ps a, ps b){
	if(xetdau(hieu(a,b)) > 0)return 1;
	else if(xetdau(hieu(a,b)) == 0)return -1;
	else return -1;
}


int main() {
	int opt;
	ps a,b;
	do{
		printf("Thao tac tren phan so \n");
		printf("1:cong 2 phan so\n");
		printf("2:tru 2 phan so\n");
		printf("3:tich 2 phan so\n");
		printf("4:thuong 2 phan so\n");
		printf("5:xet dau phan so\n");
		printf("6:so sanh 2 phan so\n");
		printf("7:quy dong mau 2 phan so\n");
		printf("8:thoat\n");
		printf("nhap lua chon:");
		scanf("%d",&opt);
        system("cls");
		switch (opt){
			case 1:
                nhapPhanSo(&a);
                nhapPhanSo(&b);
                printf("tong 2 phan so vua nhap la:");
                inPhanSo(tong(a,b));
				break;
			case 2:
                nhapPhanSo(&a);
                nhapPhanSo(&b);
                printf("hieu 2 phan so vua nhap la:");
                inPhanSo(hieu(a,b));
				break;
			case 3:
                nhapPhanSo(&a);
                nhapPhanSo(&b);
                printf("tich 2 phan so vua nhap la:");
                inPhanSo(tich(a,b));
				break;
			case 4:
                nhapPhanSo(&a);
                nhapPhanSo(&b);
                printf("thuong 2 phan so vua nhap la:");
                inPhanSo(thuong(a,b));
				break;
			case 5:
                nhapPhanSo(&a);
                int k = xetdau(a);
                if(k == 1) printf("phan so duong\n");
                else if(k == 0)printf("phan so bang 0\n");
                else printf("phan so am\n");
				break;
			case 6:
                printf("phan so a:");
                nhapPhanSo(&a);
                printf("phan so b:");
                nhapPhanSo(&b);
                k = sosanh(a,b);
                if(k == 1) printf("a lon hon b\n");
                else if(k == 0)printf("phan so a bang phan so b \n");
                else printf("phan so a be hon b\n");
				break;
			case 7:
                nhapPhanSo(&a);
                nhapPhanSo(&b);
                quydong(&a,&b);
                printf("2 phan so sau khi quy dong la:\n");
                inPhanSo(a);
                printf("va \n");
                inPhanSo(b);
				break;
			case 8:
				break;
		}
        system("pause");
        system("cls");
	}while(opt != 8);
	return 0;
}