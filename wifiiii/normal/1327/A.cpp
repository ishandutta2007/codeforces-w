#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[10005];
int main()
{
    for(int i=1;i<=10000;++i) a[i]=a[i-1]+2*i-1;
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(k<=10000 && n>=a[k] && ((n&1)^(k&1))==0) cout<<"YES"<<endl;
        else cout << "NO" << endl;
    }
}