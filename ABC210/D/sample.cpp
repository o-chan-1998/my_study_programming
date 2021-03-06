#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <bitset>
#include <numeric> // iota関数
#include <fstream>

using namespace std;

#define rep(i, H) for (int i = 0; i < H; i++)
#define rep1(i, H) for (int i = 1; i <= H; i++)
#define drep(i, H) for (int i = H - 1; i >= 0; i--)
#define drep1(i, H) for (int i = H; i >= 1; i--)
#define srep(i, S, T) for (int i = S; i < T; i++)
#define rng(a) a.begin(), a.end()

template <typename T>
using vc = vector<T>;
template <typename T>
using vv = vc<vc<T>>;
template <typename T>
using vvv = vv<vc<T>>;
using vi = vc<int>;
using vvi = vv<int>;
using vvvi = vvv<int>;
using vl = vc<long>;
using vvl = vv<long>;
using ll = long long;
using vll = vc<ll>;
using vvll = vv<ll>;

int main()
{
	// IO高速化のおまじない
  ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

  int h, w;
  ll c;
  cin >> h >> w >> c;

  vvi a(h, vi(w));
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }

  const ll INF=1e18;
  ll ans = INF;

  rep(_,2){
    vvll d(h, vll(w, INF));
    rep(i,h){
      rep(j,w){
        if(i){
          d[i][j]=min(d[i][j], d[i-1][j]);
        }
        if(j){
          d[i][j]=min(d[i][j], d[i][j-1]);
        }
        ans = min(ans, a[i][j]+(i+j)*c+d[i][j]);
        d[i][j] = min(d[i][j], a[i][j]-(i+j)*c);
      }
    }
    reverse(a.begin(), a.end());
  }

  cout << ans << endl;

  return EXIT_SUCCESS;
}