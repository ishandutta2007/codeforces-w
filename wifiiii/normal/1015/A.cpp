#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

int a[105];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) {
        int l,r;
        cin>>l>>r;
        for(int j=l;j<=r;++j) a[j]=1;
    }
    vector<int> ans;
    for(int i=1;i<=m;++i) {
        if(!a[i]) ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(int i:ans) cout<<i<<" ";cout<<endl;
}