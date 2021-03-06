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

vi dep;
vvi to;

void dfs(int v, int _dep=0, int p=-1){
  dep[v] = _dep;
  for(int u:to[v]){
    if(u==p){
      continue;
    }
    dfs(u,_dep+1, v);
  }
}

int main()
{
	// IO高速化のおまじない
  ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

  int n, q;
  cin >> n >> q;
  to.resize(n);
  rep(i,n-1){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  dep.resize(n);
  dfs(0);

  rep(qi, q){
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    int ans = (dep[c]+dep[d])%2;

    if(ans==0){
      cout << "Town" << endl;
    }else{
      cout << "Road" << endl;
    }
  }

  return EXIT_SUCCESS;
}