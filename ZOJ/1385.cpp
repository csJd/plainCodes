#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int INF = 0x7fffffff;
const int VN  = 105;

int n;
int w[VN][VN];
int charge[VN];
int d[VN];
int pre[VN];
bool inq[VN];
int pos=0;

void init(){
    for(int i=0; i<=n; ++i){
        w[i][i] = INF;
        for(int j=i+1; j<=n; ++j)
            w[i][j]=w[j][i]=INF;
    }
}

// 获得从开始点到当前点的路径，转化成字符串
void dfs(int u, char *str){
    if(u==-1)return;
    dfs(pre[u],str);
    str[pos++] = u+'0';
}

bool cmp(int origin, int now){
    char str1[100], str2[100];

    //1. 获取原来的路径
    pos=0;
    dfs(origin,str1);
    str1[pos] = '\0';

    //2.获取当前点的路径
    pos=0;
    dfs(now, str2);
    str2[pos++] = origin+'0';
    str2[pos]   = '\0';

    //3.比较是否比原来的字典序小
    if(strcmp(str1, str2)==1)return true;
    return false;
}

void SPFA(int src){
    memset(inq, 0, sizeof(inq));
    memset(pre, -1, sizeof(pre));
    int i,j;
    for(i=1; i<=n; ++i) d[i]=INF;
    d[src] = 0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int u = q.front(); q.pop();
        inq[u] = false;
        for(int v=1; v<=n; ++v)if(w[u][v]!=INF){
            int tmp = d[u]+w[u][v]+charge[v];
            if(d[v] > tmp){
                d[v] = tmp;
                pre[v] = u;
                if(!inq[v]){
                    inq[v] = true;
                    q.push(v);
                }
            }
            else if(d[v] == tmp && cmp(v, u)){
                pre[v] = u;
            }
        }
    }
}
// 打印路径
void print_path(int u){
    if(pre[u]==-1){
        printf("%d",u);
        return;
    }
    print_path(pre[u]);
    printf("-->%d",u);
}
int main(){

    int i,j,src,des;
    while(scanf("%d",&n),n){
        init();
        for(i=1; i<=n; ++i){
            for(j=1; j<=n; ++j){
                scanf("%d",&w[i][j]);
                if(w[i][j]==-1) w[i][j]=INF;
            }
        }
        for(i=1; i<=n; ++i)
            scanf("%d",&charge[i]);

        while(scanf("%d%d",&src,&des)){
            if(src==-1&&des==-1) break;
            // 备份
            int tmp1=charge[src], tmp2=charge[des];
            charge[src]=0, charge[des]=0; // 起始点和终点Tax收费为0
            SPFA(src);
            printf("From %d to %d :\n",src,des);
            printf("Path: ");
            print_path(des);
            printf("\nTotal cost : %d\n\n", d[des]);
            // 恢复
            charge[src]=tmp1, charge[des]=tmp2;
        }

    }
    return 0;
}
