#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//test
int numlamp(int n,int k){
    int cnt = 0;
    if(k == 0)return n;
    while(n > 0){
        n-= 2*k;
        cnt ++;
    }
    return cnt;
}

int main()
{
    int n;
    int m;
    int k;
    int pos;
    int res = 0;
    int ptr = 0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d",&pos);
        int nolight = pos - k - ptr;
        if(nolight > 0){
            res += numlamp(nolight,k);
        }
        ptr = pos + k;
    }
    if(ptr < n) res += numlamp(n-ptr,k);

    if(k == 0){
        res = n - m + 1; 
    }
    printf("%d",res);
    return 0;
}
