#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N;
vector<int> v, idx;

int main() {
    FASTIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.pb(a), idx.pb(a);
    }
    sort(all(idx));
    idx.erase(unique(all(idx)), idx.end());
	

    for (auto& i : v) {
        auto pos = lower_bound(all(idx), i) - idx.begin();
        cout << pos << ' ';
    }
}
