#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int s0=0,s1=0,t0=0,t1=0;
    for(char c:s) if(c=='0') s0++;else s1++;
    for(char c:t) if(c=='0') t0++;else t1++;
    if(s0 != t0) return cout<<-1<<endl,0;
    string p;
    for(int i=0;i<n;++i) {
        if(s[i] != t[i]) p+=s[i];
    }
    int a=0,b=0,ans=0;
    for(int i=0;i<p.size();++i) {
        if(p[i]=='1') {
            if(!a) ++a;
            --a,++b;
        } else {
            if(!b) ++b;
            --b,++a;
        }
        ans=max(ans,a+b);
    }
    cout<<ans<<endl;
}