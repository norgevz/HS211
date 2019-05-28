#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6;

vector<int> G[N];
int n, m;

void read_graph(){
	cin >> n >> m;
	for(int i  = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

int dtime[N], low_dtime[N];
bool marks[N];
int ttime = 0;
int subtrees = 0;
int root;
bool art[N];

void dfs(int u, int par){

	marks[u] = true;
	dtime[u] = low_dtime[u] = ++ttime;
	 

	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];

		if(!marks[v]){

			if(u == root){
				subtrees++;
			}
			dfs(v, u);

			if(dtime[u] <= low_dtime[v]){
				art[u] = true;
			}
			low_dtime[u] = min(low_dtime[u], low_dtime[v]);
		}
		else{
			if(v != par)
				low_dtime[u] = min(low_dtime[u] , dtime[v]);
		}
	}

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	read_graph();

	for(int i = 1; i <= n; i++){
		if(!marks[i]){
			root = i;
			subtrees = 0;
			dfs(i, -1);
			art[root] = subtrees > 1;
		}
	}

	for(int i = 1; i <= n; i++){
		if(art[i]){
			cout << i << " ";
		}
	}
	cout << endl;
}