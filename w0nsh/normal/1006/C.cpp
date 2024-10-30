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
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = a; i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n;
std::vector<int> A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;	
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	if(n == 1){
		std::cout << "0\n";
		return 0;
	}
	int left = 0;
	int right = n-1;
	ll sum1 = A[0];
	ll sum2 = A[n-1];
	ll max = 0;
	while(left < right){
		if(sum1 == sum2) max = std::max(sum1, max);
		if(sum1 < sum2){
			left++;
			sum1 += A[left];
		}else{
			right--;
			sum2 += A[right];
		}
	}
	std::cout << max << "\n";
	return 0;
}