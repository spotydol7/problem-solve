#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> names;
vector<string> ancestors;
map<string, vector<string>> adj;

map<string, vector<string>> family;

map<string, int> inDegree;
queue<string> q;

void solve() {
	for (int i = 0; i < n; i++) {
		if (inDegree[names[i]] == 0) {
			q.push(names[i]);

			while (!q.empty()) {
				string cur = q.front();
				q.pop();
				for (string next : adj[cur]) {
					if (--inDegree[next] == 0) {
						q.push(next);
						family[cur].push_back(next);
					}
				}
				sort(family[cur].begin(), family[cur].end());
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		names.push_back(str);
	}
	sort(names.begin(), names.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		string u, v;
		cin >> u >> v;
		adj[v].push_back(u);
		inDegree[u]++;
	}

	for (int i = 0; i < n; i++) {
		if (inDegree[names[i]] == 0)
			ancestors.push_back(names[i]);
	}

	solve();

	cout << ancestors.size() << '\n';
	for (string ancestor : ancestors) {
		cout << ancestor << ' ';
	}
	cout << '\n';

	for (string name : names) {
		cout << name << ' ' << family[name].size() << ' ';
		for (string sons : family[name]) {
			cout << sons << ' ';
		}
		cout << '\n';
	}

	return 0;
}