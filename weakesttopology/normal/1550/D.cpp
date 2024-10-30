#include <bits/stdc++.h>

template <int P>
struct Z {
  int x;
  Z() : x(0) {}
  Z(int64_t x_) {
    x = x_ % P;
    if (x < 0) x += P;
  }
  Z& operator+=(Z rhs) {
    x += rhs.x;
    if (x >= P) x -= P;
    return *this;
  }
  Z& operator-=(Z rhs) {
    x -= rhs.x;
    if (x < 0) x += P;
    return *this;
  }
  Z& operator*=(Z rhs) {
    x = int64_t(x) * rhs.x % P;
    return *this;
  }
  Z& operator/=(Z rhs) {
    return *this *= rhs.power(-1);
  }
  Z power(int64_t p) const {
    p %= P - 1;
    if (p < 0) p += P - 1;
    Z res = 1;
    for (Z y = *this; p; p >>= 1, y *= y) {
      if (p & 1) res *= y;
    }
    return res;
  }
  Z operator-() const {
    return Z() - *this;
  }
  bool operator==(Z rhs) const {
    return x == rhs.x;
  }
  bool operator!=(Z rhs) const {
    return x != rhs.x;
  }
  friend Z operator+(Z lhs, Z rhs) {
    return lhs += rhs;
  }
  friend Z operator-(Z lhs, Z rhs) {
    return lhs -= rhs;
  }
  friend Z operator*(Z lhs, Z rhs) {
    return lhs *= rhs;
  }
  friend Z operator/(Z lhs, Z rhs) {
    return lhs /= rhs;
  }
  friend std::ostream& operator<<(std::ostream& out, Z a) {
    return out << a.x;
  }
  friend std::istream& operator>>(std::istream& in, Z& a) {
    int64_t x;
    in >> x;
    a = Z(x);
    return in;
  }
};
using Zp = Z<(int)1e9 + 7>;

template <typename T>
struct Combinatorics {
  std::vector<T> f, inv, pref, suff;
  Combinatorics(int N) : f(N), inv(N), pref(N), suff(N) {
    f[0] = inv[0] = 1;
    for (int x = 1; x < N; ++x) {
      f[x] = x * f[x - 1];
      inv[x] = 1 / f[x];
    }
  }
  T interpolate(const std::vector<T>& y, T x) {
    int n = y.size();
    pref[0] = suff[n - 1] = 1;
    for (int i = 0; i + 1 < n; ++i) {
      pref[i + 1] = pref[i] * (x - i);
    }
    for (int i = n - 1; i > 0; --i) {
      suff[i - 1] = suff[i] * (x - i);
    }
    T res = 0;
    for (int i = 0, sgn = (n % 2 ? +1 : -1); i < n; ++i, sgn *= -1) {
      res += y[i] * sgn * pref[i] * suff[i] * inv[i] * inv[n - 1 - i];
    }
    return res;
  }
  T C(int n, int k) {
    return k < 0 || n < k ? 0 : f[n] * inv[k] * inv[n - k];
  }
  T S(int n, int k) {
    return k == 0 ? n == 0 : C(n + k - 1, k - 1);
  }
};

constexpr int inf = std::numeric_limits<int>::max();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int N, l, r;
    std::cin >> N >> l >> r;
    int szmax = (N + 1) / 2;
    Combinatorics<Zp> C(N + 1);
    auto solve = [&](int x) {
      int lpos = std::max(1, l - x), rpos = std::min(N, r - x);
      int lneg = std::max(1, l + x), rneg = std::min(N, r + x);
      int szpos = rpos - lpos + 1, szneg = rneg - lneg + 1;
      if (1 < std::min(lpos, lneg) || std::max(rpos, rneg) < N ||
          rpos < lpos || rneg < lneg) {
        return Zp();
      }
      int lcap = std::max(lpos, lneg), rcap = std::min(rpos, rneg);
      if (lcap <= rcap) {
        int szcap = rcap - lcap + 1;
        Zp res = C.C(szcap, szmax - (szpos - szcap));
        if (N % 2) {
          res += C.C(szcap, szmax - 1 - (szpos - szcap));
        }
        return res;
      } else {
        return Zp(szpos + szneg == N && std::abs(szpos - szneg) <= 1 ? 1 : 0);
      }
    };
    int c = std::min(-(l - 1), r - N);
    Zp ans = c * C.C(N, szmax) * (1 + N % 2);
    for (int i = 1; i <= N; ++i) {
      ans += solve(c + i);
    }
    std::cout << ans << '\n';
  }
  exit(0);
}