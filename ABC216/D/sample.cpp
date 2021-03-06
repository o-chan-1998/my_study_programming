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

	// n : 2n個のボール
	// m : 筒の本数
	int n,m;
	cin >> n >> m;
	vvi a(m);
	vvi pos(n);

	rep(i,m){
		int k;
		cin >> k;
		a[i] = vi(k);
		rep(j,k){
			// i番目の筒にk個値を標準入力
			cin >> a[i][j];
		}
		rep(j,k){
			// indexの調整
			a[i][j]--;
			// i番目の筒のj番目に入っている値をpushする
			pos[a[i][j]].push_back(i);
		}
	}

	vi cnt(n);
	queue<int> q;
	// i番目の筒の一番最後の数値のカウンターを作る
	rep(i,m){
		int t = a[i].back();
		cnt[t]++;
	}

	rep(i,n){
		// カウンターが2の場合、キューに入れる
		if(cnt[i]==2){
			q.push(i);
		}
	}

	int take = 0;
	// キューに値がある間中ループする
	while(q.size()){
		int x = q.front();
		q.pop();
		take++;
		// 取り出し場合は2つ分なので、rep(i,2)
		rep(i,2){
			int p = pos[x][i];
			a[p].pop_back();
			if(a[p].size()){
				int t = a[p].back();
				cnt[t]++;
				if(cnt[t]==2){
					q.push(t);
				}
			}
		}
	}

	// n個取り出せた場合は成功
	if(take==n){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

    return EXIT_SUCCESS;
}