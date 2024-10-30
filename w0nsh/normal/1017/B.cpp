#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

#define int long long

int n;
std::string A, B;

signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int ones = 0;
	int zeros = 0;
	int ones2 = 0;
	int zeros2 = 0;
	std::cin >> n >> A >> B;
	FOR(i, n){
		if(A[i] == '0'){
			zeros++;
			if(B[i] == '0') zeros2++;
		}else{
			ones++;
			if(B[i] == '0') ones2++;
		}
	}
	std::cout << ones2*zeros + (ones-ones2)*zeros2 << "\n";
	return 0;
}