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
#include <assert.h>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 131072
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,c,ans, curL, curR, SQ;
string s,t;
ll a[500500];
vector<ll> f;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n >> l >> y;
 	for (i = 0; i < 60; i++)
        if ((1LL<<i) > n)
            break;
    k = (1LL<<i);
    r = i-1;
    for (i = l-1; i <= y-1; i++)
    {
        x = n;
        for (j = r; j >= 0; j--)
        {
            if ((i&((1LL<<j)-1)) == (1LL<<j)-1)
            {
                tot += x%2;
                break;
            }
            x/=2;
        }
    }
    cout << tot << endl;
    return 0;
}