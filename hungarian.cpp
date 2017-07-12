#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edges;
vector<int> matching;
bool* checked;

int N,M,T;

void _init() {
	vector<int> tmp;
	for(int i = 0; i < N + M; ++i) {
		edges.push_back(tmp);
		matching.push_back(-1);
	}
	checked = new bool[N + M];
}

void _destroy() {
	delete [] checked;
}

bool _dfs(int index) {
	vector<int> edge = edges[index];
	for(int i = 0; i < edge.size(); ++i) {
		int v = edge[i];
		if(checked[v]) continue;
		checked[v] = true;
		if(matching[v] == -1 || _dfs(v)) {
			matching[index] = v;
			matching[v] = index;
			return true;
		}
	}
	return false;
}

int main() {
	cin>>N>>M; //the number of nodes in the left and right side
	cin>>T; //the number of edges
	_init();
	for(int t = 0; t < T; ++t) {
		int a, b;
		cin>>a>>b; //an edge from index(a) in the left to index(b) in the right (  Note that a is from [0, N), b is from [N, N+M).  )
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	int matchingNum = 0;
	for(int i = 0; i < N; ++i) {
		if(matching[i] == -1) {
			memset(checked, false, sizeof(bool) * (N + M));
			checked[i] = true;
			if(_dfs(i)) ++matchingNum;
		}
	}
	_destroy();
	cout<<"Max matching number: "<<matchingNum<<endl;
	return 1;
}