#include <bits/stdc++.h>

using namespace std;

int t, n;
long long ans;
char str[100001][81];

int char_to_index(char c) {
	return c - 'a';
}

struct Trie {
	bool is_leaf;
	Trie* next[26];
	int size;
	Trie() :is_leaf(false), size(0) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (next[i]) delete next[i];
		}
	}
	void insert(char* key) {
		if (*key == '\0') {
			is_leaf = true;
			return;
		}
		int index = char_to_index(*key);
		if (!next[index]) {
			next[index] = new Trie();
			size++;
		}
		next[index]->insert(key + 1);
	}
	void find_at_first(char* key) {
		ans++;
		if (*key == '\0')    return;
		int index = char_to_index(*key);
		if (next[index]) next[index]->find(key + 1);
	}
	void find(char* key) {
		if (*key == '\0') {
			return;
		}
		int index = char_to_index(*key);
		if (size > 1 || is_leaf) {
			ans++;
		}
		if (next[index]) next[index]->find(key + 1);
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	Trie* root;
	while (cin >> n) {
		root = new Trie();
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> str[i];
			root->insert(str[i]);
		}
		for (int i = 0; i < n; i++) {
			root->find_at_first(str[i]);
		}
		cout << fixed << setprecision(2)<< (double)ans / (double)n << "\n";
		delete root;
	}
	return 0;
}