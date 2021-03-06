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

    int n, m;
    cin >> n >> m;
    const int INF = 1001001001;

    vvi f(n, vi(n,INF));

    rep(i,n){
        f[i][i]=0;
    }

    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        f[a][b]=c;
    }

    ll ans=0;
    rep(k,n){
        rep(i,n){
            rep(j,n){
                // ワーシャルフロイド方法
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                if(f[i][j]!=INF){
                    ans += f[i][j];
                }
            }
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}