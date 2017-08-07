#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void dfs(string & s, string & t, unordered_map<char, pair<int, int>> & maps, int curStep, int & res)
{
	if(curStep >= s.length() + 2) return;
	if(s == t) {
		if(curStep < res) res = curStep;
		return;
	}
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] == t[i]) continue; //m,s,f,t
		pair<int, int> ps = maps[s[i]];
		if(s[i] != 'm' && s[i] != 's' && s[i] != 'f' && s[i] != 't') {
			int newPos = ps.first;
			string newS = s;
			char tmp = newS[i];
			newS[i] = newS[newPos];
			newS[newPos] = tmp;
			dfs(newS, t, maps, curStep + 1, res);
		}
		else {
			int newPos = ps.first, newPos2 = ps.second;
			string newS = s;
			char tmp = newS[i];
			newS[i] = newS[newPos];
			newS[newPos] = tmp;
			dfs(newS, t, maps, curStep + 1, res);
			if(newPos2 != -1) {
				string newS2 = s;
				tmp = newS2[i];
				newS2[i] = newS2[newPos2];
				newS2[newPos2] = tmp;
				dfs(newS2, t, maps, curStep + 1, res);
			}
		}
		break;
	}
}

int main() {
	int T;
	cin>>T;
	while(T--) {
		string s,t;
		cin>>s>>t;
		unordered_map<char, pair<int, int>> maps;
		for(int i = 0; i < t.length(); ++i) {
			auto ind = maps.find(t[i]);
			if(ind == maps.end()) {
				maps[t[i]] = pair<int, int>(i, -1);
			}
			else {
				ind->second.second = i;
			}
		}
		int res = s.length() + 2;
		dfs(s, t, maps, 0, res);
		cout<<res<<endl;
	}
	return 0;
}
