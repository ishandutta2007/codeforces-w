#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int maxn = 200005;
int a[maxn], deg[maxn];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        ll ans=0;
        ii cin>>a[i],ans+=a[i],deg[i]=0;
        for(int i=1;i<n;++i) {
            int u,v;
            cin>>u>>v;
            deg[u]++;deg[v]++;
        }
        vector<int> v;
        for(int i=1;i<=n;++i) {
            for(int j=1;j<deg[i];++j) v.push_back(a[i]);
        }
        sort(all(v),greater<int>());
        cout<<ans<<" ";
        for(ll i:v) {
            ans+=i;
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}