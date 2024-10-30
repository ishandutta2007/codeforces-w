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

int a[20][10005];
vector<int> g[20];
int dp[16][1<<16], yes[17][17];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    ii jj cin>>a[i][j];
    if(n == 1) {
        int ans=2e9;
        for(int i=2;i<=m;++i) ans=min(ans,abs(a[1][i]-a[1][i-1]));
        cout<<ans<<endl;
        return 0;
    }
    int lo=0,hi=1e9;
    while(lo<hi) {
        int mid=(lo+hi+1)/2;
        for(int i=1;i<=n;++i) g[i-1].clear();
        for(int i=1;i<=n;++i) {
            for(int j=i+1;j<=n;++j) {
                int ok=1;
                for(int k=1;k<=m;++k) if(abs(a[i][k]-a[j][k])<mid) {ok=0;break;}
                if(ok) {
                    g[i-1].push_back(j-1);
                    g[j-1].push_back(i-1);
                }
            }
        }
        int okk=0;
        for(int i=0;i<n;++i) {
            memset(dp,0,sizeof(dp));
            dp[i][1<<i]=1;
            for(int j=1;j<1<<n;++j) {
                for(int k=0;k<n;++k) {
                    if(!dp[k][j]) continue;
                    for(int v:g[k]) {
                        if(j>>v&1) continue;
                        dp[v][j^(1<<v)]=1;
                    }
                }
            }
            for(int j=0;j<n;++j) {
                // i -> j
                if(i!=j && dp[j][(1<<n)-1]) {
                    int ok=1;
                    for(int k=2;k<=m;++k) {
                        if(abs(a[j+1][k]-a[i+1][k-1])<mid) {
                            ok=0;
                            break;
                        }
                    }
                    if(ok) {
                        okk=1;
                        break;
                    }
                } else {
                    yes[i][j] = yes[j][i] = 0;
                }
            }
            if(okk) break;
        }
        if(okk) lo=mid;
        else hi=mid-1;
    }
    cout<<lo<<endl;
}