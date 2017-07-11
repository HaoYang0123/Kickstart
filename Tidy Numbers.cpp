#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	ifstream fi("B-large-practice.in");
	ofstream fo("res.txt");
	int T;
	fi>>T;
	for(int t = 1; t <= T; ++t) {
		long long N, oldN; //for large-data, N<=10^18
		long long res = 0;
		fi>>N;
		oldN = N;
		vector<int> digits; //store every bits in N
		while(N != 0) {
			int d = N % 10;
			digits.push_back(d);
			N = N / (long long)10;
		}
		reverse(digits.begin(), digits.end());
		int index = 1; //find the first bit (index) that digits[index] < digits[index - 1]
		while(index < digits.size() && digits[index] >= digits[index - 1]) ++index;
		if(index >= digits.size()) res = oldN;
		else {
			for(int i = index; i < digits.size(); ++i) digits[i] = 9; //make the biggest one
			--digits[index - 1];
			int index2 = index - 1;
			while(index2 - 1 >= 0 && digits[index2 - 1] > digits[index2]) { //when the former digit is bigger than the latter one, this violate the rule
				digits[index2] = 9;
				--digits[index2 - 1];
				--index2;
			}
			long long tmp = 1;
			for(int i = digits.size() - 1; i >= 0; --i) {
				res += (long long)(tmp * (long long)digits[i]);
				tmp *= (long long)10;
			}
		}
		fo<<"Case #"<<t<<": "<<res<<endl;
	}
	fo.close();
	return 1;
}