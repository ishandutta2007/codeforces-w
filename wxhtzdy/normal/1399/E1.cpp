#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int N=200050;
vector<pii> E[N];
int sz[N];

void DFS(int u,int p){
    sz[u]=0;
    int cnt=0;
    for(auto e:E[u])if(e.first!=p){
        DFS(e.first,u);
        sz[u]+=sz[e.first];
        ++cnt;
    }
    if(cnt==0)sz[u]=1;
}

ll u[N],v[N],w[N];

ll Get(ll x,ll y){return x*y-(x/2)*y;}

int main(){
    for(int t=ri();t--;){
        int n;ll S;
        rd(n,S);
        for(int i=0;i<n;i++)E[i].clear();
        for(int i=0;i<n-1;i++){
            rd(u[i],v[i],w[i]);
            --u[i],--v[i];
            E[u[i]].pb({v[i],i});
            E[v[i]].pb({u[i],i});
        }
        DFS(0,-1);
        set<pair<ll,int>> s;
        ll sum=0;
        for(int i=0;i<n-1;i++){
            sum+=w[i]*min(sz[u[i]],sz[v[i]]);
            s.insert({Get(w[i],min(sz[u[i]],sz[v[i]])),i});
        }
        int ans=0;
        while(S<sum){
            auto it=prev(s.end());
            auto val=*it;
            sum-=val.first;
            int i=val.second;
            ++ans,w[i]/=2;
            s.erase(it);
            s.insert({Get(w[i],min(sz[u[i]],sz[v[i]])),i});
        }
        printf("%i\n",ans);
    }
	return 0;
}