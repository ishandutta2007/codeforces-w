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

int a[105];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int s=0,p=0,ng=0;
        ii {
            cin>>a[i],s+=a[i];
            if(a[i]>0) p+=a[i];
            else ng+=-a[i];
        };
        if(s == 0) {
            cout << "NO" << endl;
            continue;
        }
        if(p<ng) sort(a+1,a+1+n);
        else {
            sort(al(a));
            reverse(al(a));
        }
        cout<<"YES\n";
        ii cout<<a[i]<<" ";cout<<endl;
    }
}