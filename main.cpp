#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vb = vector<bool>;
using vi = vector<int>;

auto list = vi{};
auto sz = int{ 0 };
auto isUsed = vb{};
void solve(int n, int m, const vi& v, int idx) {
	if (m == sz) {
		for (const auto& x : list) {
			cout << x << ' ';
		}
		cout << '\n';

		return;
	}

	for (auto i = 0; i < n; ++i) {
		if (isUsed[i]) {
			continue;
		}

		isUsed[i] = true;
		list.push_back(v[i]);
		++sz;
		solve(n, m, v, i + 1);

		isUsed[i] = false;
		list.pop_back();
		--sz;
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m; cin >> n >> m;
	auto v = vi(n);
	for (auto i = 0; i < n; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	isUsed = vb(n, false);

	solve(n, m, v, 0);

	return 0;
}