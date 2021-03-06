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

	// n : 弁当の種類, x : 食べたいたこ焼きの個数, y : 食べたいたい焼きの個数
	int n,x,y;
	cin >> n >> x >> y;
	const int INF =1001001001;

	// たこ焼きj個、たい焼きk個になるように取った時の弁当の最小値
	vvi dp(x+1, vi(y+1,INF));

	dp[0][0]=0;

	rep(i,n){
		// 各種弁当に入っているたこ焼きの個数(a)とたい焼きの個数(b)
		int a,b;
		cin >> a >> b;
		drep(j,x+1){
			drep(k,y+1){
				dp[min(j+a,x)][min(k+b,y)]=min(dp[min(j+a,x)][min(k+b,y)],dp[j][k]+1);
			}
		}
	}

	int ans = dp[x][y];
	if(ans==INF){
		ans = -1;
	}
	cout << ans << endl;

    return EXIT_SUCCESS;
}