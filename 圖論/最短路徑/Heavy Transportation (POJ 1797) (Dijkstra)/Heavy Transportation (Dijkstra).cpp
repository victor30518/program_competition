#include<stdio.h>
#include<memory.h>
#include<iostream>
using namespace std;
#define MAX(x,y) (((x)>(y))?(x):(y))
#define MIN(x,y) (((x)<(y))?(x):(y))

int a[1005][1005],n,m,dp[1005];
bool map[1005];

void dij(int t){
    memset(map,0,sizeof(map[0])*(n+3));
    for(int i=1;i<=n;i++) dp[i] = a[t][i];
    dp[t] = 1000000; map[t] = true;
    for(int i=1;i<n;i++){
        int k=t,temp=0;
        //找剩下的點中容量最大的加入樹
        for(int j=1;j<=n;j++){
            if(map[j]) continue;
            if(temp <= dp[j]){
                temp = dp[j];
                k = j;
            }
        }
        map[k] = true;
        if(map[n]) return;
        //檢查增加k點後,透過它到其他點會不會能載的容量更大
        for(int j=1;j<=n;j++){
            if(map[j])continue;
            dp[j] = MAX(dp[j],MIN(dp[k],a[k][j]));
        }
    }
}
int main(){
    int T,ca=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            memset(a[i],0,sizeof(a[i][0])*(n+3));
        for(int i=0;i<m;i++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            a[v][u] = a[u][v] = MAX(a[u][v],c);
        }
        dij(1);
        printf("Scenario #%d:\n",ca++);
        printf("%d\n\n",dp[n]);
    }
    return 0;
}
