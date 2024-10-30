#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

const string A[] = {
    "Washington", "Adams", "Jefferson", "Madison",
    "Monroe", "Adams", "Jackson", "Van Buren",
    "Harrison", "Tyler", "Polk", "Taylor",
    "Fillmore", "Pierce", "Buchanan", "Lincoln",
    "Johnson", "Grant", "Hayes", "Garfield",
    "Arthur", "Cleveland", "Harrison", "Cleveland",
    "McKinley", "Roosevelt", "Taft", "Wilson",
    "Harding", "Coolidge", "Hoover", "Roosevelt",
    "Truman", "Eisenhower", "Kennedy", "Johnson",
    "Nixon", "Ford", "Carter", "Reagan"
};

int main()
{
    int n;
    cin >> n;
    cout << A[n - 1] << endl;

    return 0;
}