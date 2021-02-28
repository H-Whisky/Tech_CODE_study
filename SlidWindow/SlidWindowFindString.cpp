/*
题目描述
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
说明：
字母异位词指字母相同，但排列不同的字符串。不考虑答案输出的顺序。
示例 1:
输入:
s: “cbaebabacd” p: “abc”
输出:
[0, 6]
解释:
起始索引等于 0 的子串是 “cba”, 它是 “abc” 的字母异位词。
起始索引等于 6 的子串是 “bac”, 它是 “abc” 的字母异位词。

解题思路
（1）使用线性循环识别s的前p.length()个字符和p的所有字符并分别记录于sSave、pSave。
（2）判断子串是否与p是字母异位词。
（3）在字符串s上应用滑动窗口技术线性滑动直至达到字符串结束，每滑动一步都进行子串是否与p是字母异位词判断。
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {
	vector<int> answer;
	string s_sub;
	if (p.length() > s.length()) {
		return answer;
	}
	vector<int> sSave(26, 0), pSave(26, 0);
	for (int i = 0; i < p.length(); i++) {
		pSave[p[i] - 'a']++;
		sSave[s[i] - 'a']++;
	}
	int index = 0;
	if (pSave == sSave) {
		//判断子串是否与p是字母异位词
		s_sub = s.substr(index, p.length());
		if (s_sub != p) {
			answer.push_back(index);
		}
	}

	for (index = 1; index < (int)s.length() - (int)p.length() + 1; index++) {
		sSave[s[index - 1] - 'a']--;
		sSave[s[index + p.length() - 1] - 'a']++;
		if (pSave == sSave) {
			//判断子串是否与p是字母异位词
			s_sub = s.substr(index, p.length());
			if (s_sub != p) {
				answer.push_back(index);
			}
		}
	}
}


int main() {
	string s = "cbaebabacd";
	string p = "abc";
	vector<int> answer;
	answer=findAnagrams(s, p);



	cin.get();
	return (0);
}