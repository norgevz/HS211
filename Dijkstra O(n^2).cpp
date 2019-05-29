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

    while(true){
    	int min_node = -1;
    	for(int i = 1; i <= n; i++){
    		if(!done[i] && (min_node == -1 || dp[min_node] > dp[i])){
    			min_node = i;
    		}
    	}

    	if(min_node == -1){
    		break;
    	}

    	done[min_node] = true;

    	for(int i = 0; i < G[min_node].size(); i++){
    		int v = G[min_node][i].first;
    		int cost = G[min_node][i].second;
    		dp[v] = min(dp[v] , dp[min_node] + cost);
    	}
    }

    for(int i = 1; i <= n; i++){
    	cout << dp[i] << " ";
    }
    cout << endl;
   
}