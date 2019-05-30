#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6;
const int inf = 1e9;

vector<pair<int, int>> G[N];

int n, m ;

void read_graph(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x , y, cost;
		cin >> x >> y >> cost;
		G[x].push_back(make_pair(y , cost));
		G[y].push_back(make_pair(x , cost));
	}
}

int dp[N];
bool done[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    read_graph();

    for(int i = 1; i <= n; i++){
    	dp[i] = inf;
    }

    int source = 1;
    dp[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >>> Q;

    Q.push(make_pair(dp[source], source));

    while(!Q.empty()){
    	pii top = Q.top(); Q.pop();
    	int u = top.second;
    	if(done[u]){
    		continue;
    	}

    	done[u] = true;

    	for(int i = 0; i < G[u].size(); i++){
    		int v = G[u][i].first;
    		int cost = G[u][i].second;

    		if(!done[v] && dp[v] > dp[u] + cost){
    			dp[v] = dp[u] + cost;
    			Q.push(make_pair(dp[v] , v));
    		}
    	}
    }

    for(int i = 1; i <= n; i++){
    	cout << dp[i] << ' ';
    }
    
    cout << endl;
   
}