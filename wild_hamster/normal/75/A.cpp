#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 (33LL+(ll)1e+17)
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
typedef long long ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag;
string s;
ll a[100500];
int main()
{
   cin >> n >> m;
   k = n+m;

   vector <ll> f;
   f.clear();
   while (k)
   {
    if (k % 10 != 0)
    {
        f.push_back(k%10);
    }
    k /= 10;
   }

    reverse(f.begin(),f.end());
   k = 0;
   for (i = 0; i < f.size(); i++)
       k = k*10 + f[i];
       
   f.clear();
   while (n)
   {
    if (n % 10 != 0)
    {
        f.push_back(n%10);
    }
    n /= 10;
   }

    reverse(f.begin(),f.end());
   n = 0;
   for (i = 0; i < f.size(); i++)
       n = n*10 + f[i];
       
   f.clear();
   while (m)
   {
    if (m % 10 != 0)
    {
        f.push_back(m%10);
    }
    m /= 10;
   }

    reverse(f.begin(),f.end());
   m = 0;
   for (i = 0; i < f.size(); i++)
       m = m*10 + f[i];
   //cout << m << " " << n << " " << k << endl;
   if (m + n == k)
      cout << "YES" << endl;
   else
       cout << "NO" << endl;
    return 0;
}