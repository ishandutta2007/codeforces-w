#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int x0,x1,x2,y0,y1,y2;
        cin>>x0>>x1>>x2>>y0>>y1>>y2;
        int ans=0,n=x0+x1+x2;
        int p=min(x2,y1);
        x2-=p,y1-=p;ans+=2*p;
        p=min(x1,y0);
        x1-=p,y0-=p;
        p=min(x1,y1);
        x1-=p,y1-=p;
        ans-=2*x1;
        cout<<ans<<endl;
    }
}