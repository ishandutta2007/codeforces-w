#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
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
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

const int maxn = 300005;
int l[maxn],r[maxn],pl[maxn],sl[maxn],pr[maxn],sr[maxn];
int main() {
    int n;
    cin>>n;
    ii cin>>l[i]>>r[i];
    pl[0]=-1,pr[0]=1e9;
    for(int i=1;i<=n;++i) {
        pl[i]=max(pl[i-1],l[i]);
        pr[i]=min(pr[i-1],r[i]);
    }
    sl[n+1]=-1,sr[n+1]=1e9;
    for(int i=n;i>=1;--i) {
        sl[i]=max(sl[i+1],l[i]);
        sr[i]=min(sr[i+1],r[i]);
    }
    int ans=0;
    for(int i=1;i<=n;++i) {
        int maxl = max(pl[i-1], sl[i+1]);
        int minr = min(pr[i-1], sr[i+1]);
        ans = max(ans, minr - maxl);
    }
    cout << ans << endl;
}