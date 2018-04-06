#include <bits/stdc++.h>
using namespace  std;

#define N 3000000
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
#define inf 2e9


int n ,  m , k;
map < int , vector < pii > > adj;
int a[N] , dis[N] , mark[N];

int bfs(int s , int limit){
    for(int i = 0  ; i<= n ; i++) dis[i] = inf;

    priority_queue < pii , vector < pii >  , greater <pii> > q;

    q.push(MP(0,s));

    dis[s] = 0;
    int mmin = inf;
     int cnt = 0;

    while(!q.empty()){
         int u = q.top().ss;
         q.pop();
         cnt += mark[u];
         if(mark[u] == 1 && cnt > 1){
             if(dis[u] > limit) break;
             mmin = min(mmin,dis[u]);
         }
         for(int i = 0 ; i< adj[u].size() ; i++){
            int v = adj[u][i].ss;
            int cost = adj[u][i].ff;
            if(dis[u] + cost < dis[v]){
                dis[v] = dis[u]+cost;
                q.push(MP(dis[v],v));
            }
         }
    }

    return mmin;

}
int main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0);
    scaaa(n,m,k);

    F(i,k){
         sca(a[i]);
         mark[a[i]] = 1;
    }


    F(i,m){
         int b , c , cost;
         scaaa(b,c,cost);
         adj[b].push_back(MP(cost,c));
         adj[c].push_back(MP(cost,b));
    }

    int mmin = inf;
    F(i,k){
        mmin =  min(mmin,bfs(a[i] , mmin));
//        break;
    }

    printf("%d\n",mmin);
}
