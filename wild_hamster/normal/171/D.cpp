#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <set>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
vector <ll> azaza;
ll i,n,j,k,k1,d,x,m,p,a[200500],b[200500],rez[200500];
ll gcd(ll a, ll b)
{
 if (b == 0) return a;
    else return gcd(b,a%b);
}
ll Abs(ll a)
{
if (a > 0) return a;
   return -a;
}

int main()
{
cin >> n;
if (n == 1) cout << 2 << endl;
if (n == 2) cout << 3 << endl;
if (n == 3) cout << 1 << endl;
if (n == 4) cout << 2 << endl;
if (n == 5) cout << 1 << endl;
return 0;
}