#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

bool same(string s1, string s2) {

	vector<bool> ch(26, 0);

	for (int i = 0; i < s1.length(); ++i) {
		ch[s1[i] - 'a'] = true;
	}

	for (int i = 0; i < s2.length(); ++i) {
		if (ch[s2[i] - 'a']) {
			return true;
		}
	}

	return false;
}

long countSimilarPairs(vector<string>& words) {
	int length = words.size();

	long count = 0;

	set<string> wordsets;

	for (int i = 0; i < length; ++i) {
		sort(words[i].begin(), words[i].end());
	}

	for (int i = 0; i < length; ++i) {
		wordsets.insert(words[i]);
	}

	for (int i = 0; i < length; ++i) {
		string str1 = words[i];
		for (int j = i + 1; j < length; ++j) {
			string str2 = words[j];
			if (same(str1, str2)) {
				++count;
			}
		}
	}

	return count;
}

int main() {
	int size;
	cin >> size;

	vector<string> words;

	for (int i = 0; i < size; ++i) {
		string input;
		cin >> input;
		words.push_back(input);
	}

	cout<<countSimilarPairs(words);

	return 0;
}
