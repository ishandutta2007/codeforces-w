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
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

ll a[100005], b[100005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ii cin >> a[i];
    ii b[i] = a[i] - a[i-1];
    ll delta = 0;
    for(int i=2;i<=n;++i) delta += min(0ll, b[i]);
    ll an = a[n];
    cout << ((-delta+an+1)>>1) << endl;
    int q;
    cin >> q;
    while(q--) {
        int l,r,x;
        cin>>l>>r>>x;
        if(r == n) an += x;
        if(l > 1) delta -= min(0ll, b[l]);
        b[l]+=x;
        if(l > 1) delta += min(0ll, b[l]);
        if(r < n) delta -= min(0ll, b[r+1]);
        b[r+1]-=x;
        if(r < n) delta += min(0ll, b[r+1]);
        cout << ((-delta+an+1)>>1) << endl;
    }
}