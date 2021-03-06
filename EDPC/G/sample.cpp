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

int n,m,u,v;
vi edge[110000];

int memo[110000];
bool done[110000];

int dp(int v){
    if(done[v]){
        return memo[v];
    }
    int ans=0;
    for(int to:edge[v]){
        ans = max(ans, dp(to)+1);
    }
    done[v]=true;
    memo[v]=ans;
    return ans;
}

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> m;
    rep(i,m){
        cin >> u >> v;
        edge[u].push_back(v);
    }
    int ans=0;
    rep1(v,n){
        ans = max(ans, dp(v));
    }
    cout << ans << endl;

    return EXIT_SUCCESS;
}