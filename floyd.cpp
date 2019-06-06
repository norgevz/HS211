#include<bits/stdc++.h>

using namespace std;

int n , m;
const int oo  = 1e9;
vector<vector<int>> dp;

void read_graph(){
	cin >> n >> m;
	dp = vector<vector<int>> (n + 1, vector<int>(n + 1, oo));

	for(int i = 1; i <= n; i++){
		dp[i][i] = 0;
	}

	for(int i = 0; i < m; i++){
		int u , v, w;
		cin >> u >> v >> w;
		dp[u][v] = min(dp[u][v], w);
		dp[v][u] = min(dp[v][u], w);
	}
}	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	read_graph();

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	int a = 2, b = 5;
	cout << dp[a][b] << endl;
}