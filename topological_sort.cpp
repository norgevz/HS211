#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6;

vector<int> G[N];
int in_degree[N];
vector<int> topological_sort;

int n, m ;

void read_graph(){

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	read_graph();


	for(int i = 1; i <= n; i++){

		for(int j = 0; j < G[i].size(); j++){
			int v = G[i][j];
			in_degree[v]++;
		}
	}

	queue<int> Q;
	for(int i = 1; i <= n; i++){
		if(in_degree[i] == 0){
			Q.push(i);
		}
	}

	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		topological_sort.push_back(u);

		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i];
			--in_degree[v];
			if(in_degree[v] == 0){
				Q.push(v);
			}
		}
	}

	if(topological_sort.size() != n){
		cout << "No top sort" << endl;
	}
	else{
		for(int i = 0; i < topological_sort.size(); i++){
			cout << topological_sort[i] << " ";
		}
		cout << endl;
	}
    
}