#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[1005];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int sum=0;
        ii cin>>a[i],sum+=a[i];
        cout << (sum+n-1)/n << endl;
    }
}