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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

int a[505][505],b[505][505];
int main() {
    int n,m;
    cin>>n>>m;
    ii jj cin>>a[i][j];
    ii jj cin>>b[i][j];
    ii jj a[i][j]^=b[i][j];
    ii jj {
        if(a[i][j]==1) {
            int ok=0;
            for(int k=j+1;k<=m;++k) {
                if(a[i][k]==1) {
                    a[i][j]=0;a[i][k]=0;
                    if(i+1>n) return cout<<"No",0;
                    a[i+1][j]^=1;a[i+1][k]^=1;
                    ok=1;
                    break;
                }
            }
            if(!ok) return cout<<"No",0;
        }
    }
    cout<<"Yes";
}