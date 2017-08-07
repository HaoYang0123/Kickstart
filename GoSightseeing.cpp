#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class City{
public:
	int s, f, d;

public:
	City() {}
	City(int a, int b, int c) : s(a), f(b), d(c) {}
};

void dfs(vector<City> & city, int N, int index, long long curTime, long long Ts, long long Tf, int curNum, int & maxNum)
{
	if(curTime > Tf) 
		return;
	if(index == N) {
		if(curTime <= Tf && curNum > maxNum) maxNum = curNum;
		return;
	}
	City curCity = city[index];
	if(curTime + Ts <= curCity.s) { //上一个城市参观了后，到达下个城市的车还没来，则参观这个城市，反正车也没来
		dfs(city, N, index + 1, curCity.s + curCity.d, Ts, Tf, curNum + 1, maxNum);
	}
	else { //如果当前参观了，车早来了，需要有两种情况来反映，是否参观当前城市
		if(N - 1 - index < maxNum) return; //后面所有城市都参观都比当前的最大值小，说明不用继续了
		long long time1 = (long long)curCity.s, time2 = (long long)curCity.s;
		//while(time1 < curTime) time1 += curCity.f;
		//while(time2 < curTime + Ts) time2 += curCity.f;
		if(time1 < curTime) {
			long long x1 = (curTime - time1) / (long long)curCity.f;
			time1 = (long long)curCity.s + (x1 - 1) * (long long)curCity.f;
			while(time1 < curTime) time1 += (long long)curCity.f;
		}
		if(time2 < curTime + Ts) {
			long long x2 = (curTime + Ts - time2) / (long long)curCity.f;
			time2 = (long long)curCity.s + (x2 - 1) * (long long)curCity.f;
			while(time2 < curTime + Ts) time2 += (long long)curCity.f;
		}
		dfs(city, N, index + 1, time1 + curCity.d, Ts, Tf, curNum, maxNum);
		dfs(city, N, index + 1, time2 + curCity.d, Ts, Tf, curNum + 1, maxNum);
	}
}

int main()
{
	ifstream fi("A-large.in");
	ofstream fo("res.txt");
	int T;
	fi>>T;
	for(int t = 1; t <= T; ++t) {
		int N, Ts, Tf;
		fi>>N>>Ts>>Tf;
		vector<City> city(N + 1);
		int curTime = 0;
		for(int i = 1; i < N; ++i) {
			int s, f, d;
			fi>>s>>f>>d;
			city[i].s = s;
			city[i].f = f;
			city[i].d = d;
		}
		int curNum = 0, maxNum = -1;
		dfs2(city, N, 1, curTime, Ts, Tf, curNum, maxNum);
		if(maxNum == -1) {
			fo<<"Case #"<<t<<": IMPOSSIBLE"<<endl;
		}
		else {
			fo<<"Case #"<<t<<": "<<maxNum<<endl;
		}
		fo.flush();
	}
	fo.close();
	return 1;
}
