#include<bits/stdc++.h>
using namespace std;

map<string, int> dogam;
string names[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string pokemon;
		cin >> pokemon;
		dogam.insert(make_pair(pokemon, i));
		names[i] = pokemon;
	}

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (isdigit(str[0])) {
			cout << names[stoi(str)] << '\n';
		}
		else {
			cout << dogam.find(str)->second << '\n';
		}
	}

	return 0;
}