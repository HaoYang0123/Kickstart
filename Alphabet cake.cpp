#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void updateMap(char map[][27], int R, int C, int i, int j)
{
	char cc[4] = {' ', ' ', ' ', ' '};
	vector<pair<int, int>> pos;
	pos.push_back(pair<int, int>(-1,-1));
	pos.push_back(pair<int, int>(-1,-1));
	pos.push_back(pair<int, int>(-1,-1));
	pos.push_back(pair<int, int>(-1,-1));
	for(int k = i - 1; k >= 0; --k) {
		if(map[k][j] != '?') {
			cc[0] = map[k][j];
			pos[0] = pair<int, int>(k, j);
			break;
		}
	}
	for(int k = i + 1; k < R; ++k) {
		if(map[k][j] != '?') {
			cc[1] = map[k][j];
			pos[1] = pair<int, int>(k, j);
			break;
		}
	}
	for(int k = j - 1; k >= 0; --k) {
		if(map[i][k] != '?') {
			cc[2] = map[i][k];
			pos[2] = pair<int, int>(i, k);
			break;
		}
	}
	for(int k = j + 1; k < C; ++k) {
		if(map[i][k] != '?') {
			cc[3] = map[i][k];
			pos[3] = pair<int, int>(i, k);
			break;
		}
	}
	for(int k = 0; k < 4; ++k) {
		if(cc[k] == ' ') continue;
		char cur = cc[k];
		pair<int, int> curPos = pos[k];
		if(k < 2) {
			int curI = curPos.first;
			int minJ = j, maxJ = j;
			while(minJ >= 0 && map[curI][minJ] == map[curI][j]) --minJ;
			while(maxJ < C && map[curI][maxJ] == map[curI][j]) ++maxJ;
			map[i][j] = cur;
			bool flag = true;
			if(k == 0) {
				for(int i2 = curI + 1; i2 <= i; ++i2) {
					for(int j2 = minJ + 1; j2 < maxJ; ++j2) {
						if(map[i2][j2] != cur && map[i2][j2] != '?') {
							flag = false;
							break;
						}
					}
				}
			}
			else {
				for(int i2 = i; i2 < curI; ++i2) {
					for(int j2 = minJ + 1; j2 < maxJ; ++j2) {
						if(map[i2][j2] != cur && map[i2][j2] != '?') {
							flag = false;
							break;
						}
					}
				}
			}
			if(flag) return;
		}
		else {
			int curJ = curPos.second;
			int minI = i, maxI = i;
			while(minI >= 0 && map[minI][curJ] == map[i][curJ]) --minI;
			while(maxI < R && map[maxI][curJ] == map[i][curJ]) ++maxI;
			map[i][j] = cur;
			bool flag = true;
			if(k == 2) {
				for(int j2 = curJ + 1; j2 <= j; ++j2) {
					for(int i2 = minI + 1; i2 < maxI; ++i2) {
						if(map[i2][j2] != cur && map[i2][j2] != '?') {
							flag = false;
							break;
						}
					}
				}
			}
			else {
				for(int j2 = j; j2 < curJ; ++j2) {
					for(int i2 = minI + 1; i2 < maxI; ++i2) {
						if(map[i2][j2] != cur && map[i2][j2] != '?') {
							flag = false;
							break;
						}
					}
				}
			}
			if(flag) return;
		}
	}
}

int main()
{
	ifstream fi("A-small-practice.in");
	ofstream fo("res.txt");
	int T;
	fi>>T;
	for(int t = 1; t <= T; ++t)
	{
		int R, C;
		fi>>R>>C;
		char map[27][27];
		for(int i = 0; i < R; ++i) {
			for(int j = 0; j < C; ++j) {
				char tmp;
				fi>>tmp;
				map[i][j] = tmp;
			}
		}
		for(int i = 0; i < R; ++i) {
			for(int j = 0; j < C; ++j) {
				if(map[i][j] != '?') continue;
				updateMap(map, R, C, i, j);
			}
		}

		fo<<"Case #"<<t<<":"<<endl;
		for(int i = 0; i < R; ++i) {
			for(int j = 0; j < C; ++j) {
				fo<<map[i][j];
			}
			fo<<endl;
		}
	}
	fo.close();
	return 1;
}