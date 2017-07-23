#include <iostream>
#include <vector>
#include <string>
using namespace std;

void updateMap(vector<string> & mm, int n, int m) {
	int n2 = mm.size(); 
	int m2 = mm[0].size();
	while(m2 < m) {
		for(int i = 0; i < mm.size(); ++i) {
			mm[i] = mm[i] + mm[i];
		}
		m2 = m2 * 2;
	}
	while(n2 < n) {
		int msize = mm.size();
		for(int i = 0; i < msize; ++i) {
			mm.push_back(mm[i]);
		}
		n2 = n2 * 2;
	}
}

bool isIn(vector<vector<int>> & v, int n, int m) {
	vector<vector<int>> tmp(n, vector<int>(m));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			tmp[i][j] = 0;
		}
	}
	for(int i = 0; i < v.size(); ++i) {
		for(int j = 0; j < v[i].size(); ++j) {
			tmp[i][v[i][j]] = 1;
		}
	}
	for(int j = 0; j < tmp[0].size(); ++j) {
		int sum = 0;
		for(int i = 0; i < tmp.size(); ++i) {
			sum += tmp[i][j];
		}
		if(sum == tmp.size()) return true;
	}
	return false;
}

bool isIn(vector<int> & v1, int m, vector<int> & v2) {
	vector<int> vv(m);
	for(int i = 0; i < v1.size(); ++i) vv[v1[i]] = 1;
	for(int i = 0; i < v2.size(); ++i) {
		if(vv[v2[i]] == 1) return true;
	}
	return false;
}

bool isIn(vector<string> & map, vector<string> & mm) { //map是否在mm里面

	updateMap(mm, map.size(), map[0].size());
	int mi = -1;
	vector<vector<int>> allMatched;
	vector<int> allMatchedJ;
	string m1 = map[0];
	for(int i = 0; i < mm.size(); ++i) {
		auto ind = mm[i].find(m1);
		if(ind == string::npos) continue;
		mi = i;
		break;
	}
	if(mi == -1) return false;
	string mm2 = mm[mi];
	auto mj = mm2.find(m1);
	while(mj != string::npos) {
		allMatchedJ.push_back(mj);
		mj = mm2.find(m1, mj + 1);
	}
	allMatched.push_back(allMatchedJ);
	for(int i = 1; i < map.size(); ++i) {
		string tmp = map[i];
		string tmp2 = mm[mi + i];
		auto ind = tmp2.find(tmp);
		if(ind == string::npos) return false;
		vector<int> tmps;
		while(ind != string::npos) {
			tmps.push_back(ind);
			ind = tmp2.find(tmp, ind + 1);
		}
		if(!isIn(allMatchedJ, mm[0].size(), tmps)) return false;
		allMatched.push_back(tmps);
	}
	return isIn(allMatched, allMatched.size(), mm[0].size());
}

int main() {
	int N, M, K;
	while(cin>>N>>M>>K) {
		vector<string> map;
		for(int i = 0; i < N; ++i) {
			string tmp;
			cin>>tmp;
			map.push_back(tmp + tmp);
		}
		for(int i = 0; i < N; ++i) map.push_back(map[i]);
		for(int i = 0; i < K; ++i) {
			int H, W;
			cin>>H>>W;
			vector<string> mm;
			for(int j = 0; j < H; ++j) {
				string tmp;
				cin>>tmp;
				mm.push_back(tmp);
			}
			bool flag = isIn(mm, map);
			if(flag) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
