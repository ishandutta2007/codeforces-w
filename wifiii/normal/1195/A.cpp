#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[1005];
int main()
{
    int n,k;
    cin>>n>>k;
    int cnt=0;
    ii
    {
        int tmp;
        cin>>tmp;
        a[tmp]++;
    }
    int x=(n+1)/2,ans=0;
    for(int i=1;i<=k;++i)
    {
        if(!x) break;
        ans += 2 * min(x, a[i]/2);
        x -= min(x, a[i]/2);
    }
    for(int i=1;i<=k;++i)
    {
        if(!x) break;
        if(a[i]) x--,ans++;
    }
    cout<<ans<<endl;
}