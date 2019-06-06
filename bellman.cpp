#include<bits/stdc++.h>

using namespace std;

int n , m, src;
const int oo  = 1e9;

vector<int> dp;

void read_graph(){

	cin >> n >> m;
	dp = vector<int>(n + 1, oo);
	cin >> src;
	
	dp[src] = 0;
	vector<pair<int, pair<int, int>>> edges;
	
	for(int i = 0; i < m; i++){
		int u , v, w;
		cin >> u >> v >> w;
		edges.push_back(make_pair(w, make_pair(u , v)));
		edges.push_back(make_pair(w, make_pair(v , u)));
	}

}	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	read_graph();

	for(int i = 0; i < n - 1; i++ ){
		for(int j = 0 ; j < edges.size(); j++){
			int u = edges[j].second.first;
			int v = edges[j].second.second;
			int w = edges[j].first;

			dp[v] = min(dp[v] , dp[u] + w);
		}
	}

	for(int i = 1; i <= n; i++){
		cout << dp[i] << ' ';
	}
	cout << endl;
}