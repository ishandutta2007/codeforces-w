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
typedef pair<int,int> pii;

void exgcd(int a,int b,int &d,int &x,int &y)
{
    if(!b) {d=a;x=1;y=0;}
    else {exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int ok=0;
        for(int i=0;;++i) {
            if(i*3>n) break;
            for(int j=0;;++j) {
                if(i*3+5*j>n) break;
                for(int k=0;;++k) {
                    if(i*3+5*j+7*k > n) break;
                    if(i*3+5*j+7*k == n) {
                        cout<<i<<" "<<j<<" "<<k<<endl;
                        ok=1;
                        break;
                    }
                }
                if(ok) break;
            }
            if(ok) break;
        }
        if(!ok) cout<<-1<<endl;
    }
}