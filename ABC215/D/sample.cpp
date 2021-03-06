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

	// n : 正整数列Aの数
	// m : 条件となる値の上限
	int n, m;
	cin >> n >> m;
	const int L=100001L;
	vector<bool> x(L);
	rep(i,n){
		int a;
		cin >> a;
		x[a] = true;
	}

	vi d;
	// 約数判定;
	for(int i=2;i<L;i++){
		bool flag=false;
		for(int j=i; j<L; j+=i){
			if(x[j]){
				flag = true;
			}
		}
		if(flag){
			d.push_back(i);
		}
	}

	vector<bool> ok(m+1, true);
	for(int i:d){
		for(int j=i;j<=m;j+=i){
			// 約数の一部である場合はfalseとする
			ok[j] = false;
		}
	}

	// 答えの個数をカウント
	int cnt=0;
	rep1(i,m){
		if(ok[i]){
			cnt++;
		}
	}

	cout << cnt << endl;

	// 答えとなる値を出力
	rep1(i,m){
		if(ok[i]){
			cout << i << endl;
		}
	}

    return EXIT_SUCCESS;
}