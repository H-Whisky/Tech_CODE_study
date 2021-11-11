/*
��Ŀ����
����һ���ַ��� s ��һ���ǿ��ַ��� p���ҵ� s �������� p ����ĸ��λ�ʵ��Ӵ���������Щ�Ӵ�����ʼ������
�ַ���ֻ����СдӢ����ĸ�������ַ��� s �� p �ĳ��ȶ������� 20100��
˵����
��ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ����������Ǵ������˳��
ʾ�� 1:
����:
s: ��cbaebabacd�� p: ��abc��
���:
[0, 6]
����:
��ʼ�������� 0 ���Ӵ��� ��cba��, ���� ��abc�� ����ĸ��λ�ʡ�
��ʼ�������� 6 ���Ӵ��� ��bac��, ���� ��abc�� ����ĸ��λ�ʡ�

����˼·
��1��ʹ������ѭ��ʶ��s��ǰp.length()���ַ���p�������ַ����ֱ��¼��sSave��pSave��
��2���ж��Ӵ��Ƿ���p����ĸ��λ�ʡ�
��3�����ַ���s��Ӧ�û������ڼ������Ի���ֱ���ﵽ�ַ���������ÿ����һ���������Ӵ��Ƿ���p����ĸ��λ���жϡ�
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
		//�ж��Ӵ��Ƿ���p����ĸ��λ��
		s_sub = s.substr(index, p.length());
		if (s_sub != p) {
			answer.push_back(index);
		}
	}

	for (index = 1; index < (int)s.length() - (int)p.length() + 1; index++) {
		sSave[s[index - 1] - 'a']--;
		sSave[s[index + p.length() - 1] - 'a']++;
		if (pSave == sSave) {
			//�ж��Ӵ��Ƿ���p����ĸ��λ��
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