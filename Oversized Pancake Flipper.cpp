#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream fi("A-small-practice.in");
	ofstream fo("res.txt");
	int T;
	fi>>T;
	for(int t = 1; t <= T; ++t) {
		string S;
		int K;
		fi>>S>>K;
		int step = 0;
		bool isOK = true;
		auto index = S.find('-');
		while(index != string::npos) {
			if(index + K > S.length()) {
				isOK = false;
				break;
			}
			++step;
			for(int i = index; i < index + K; ++i) {
				if(S[i] == '+') S[i] = '-';
				else S[i] = '+';
			}
			index = S.find('-');
		}
		if(isOK)
			fo<<"Case #"<<t<<": "<<step<<endl;
		else 
			fo<<"Case #"<<t<<": IMPOSSIBLE"<<endl;
	}
	fo.close();
	return 1;
}