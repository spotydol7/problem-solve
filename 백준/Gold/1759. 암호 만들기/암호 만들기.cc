#include <bits/stdc++.h>
using namespace std;

int L, C;
char characters[16];
vector<char> str;

void backtracking(int depth) {
	if (str.size() == L) {
		int vowel = 0;
		for (int i = 0; i < L; i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') vowel++;
		}
		if (vowel >= 1 && L - vowel >= 2) {
			for (int i = 0; i < L; i++) {
				cout << str[i];
			}
			cout << '\n';
		}
		return;
	}

	for (int i = depth; i < C; i++) {
		str.push_back(characters[i]);
		backtracking(i + 1);
		str.pop_back();
	}
}

int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> characters[i];
	}

	sort(characters, characters + C);
	backtracking(0);

	return 0;
}