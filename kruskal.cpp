#include<bits/stdc++.h>

using namespace std;

const int oo  = 1e9;


struct DisjoinSet{

	vector<int> par;
	vector<int> size;

	int n;

	DisjoinSet(){
	}

	DisjoinSet(int _n){

		n = _n;
		par.resize(n + 1);
		size.resize(n + 1, 1);

		for(int i = 0; i <= n; i++){
			par[i] = i;
		}
	}

	int get_id(int u){
		if(par[u] == u){
			return u;
		}
		return get_id(par[u]);
	}	

	void join(int u, int v){
		u = get_id(u);
		v = get_id(v);

		if(u == v){
			return;
		}

		if(size[u] < size[v]){
			par[u] = v;
			size[v] += size[u];
		}else{
			par[v] = u;
			size[u] += size[v];
		}
	}

	int get_size(int u){
		u = get_id(u);
		return size[u];
	}
};

int n , m;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	vector<pair<int, pair<int, int>>> edges;

	for(int i = 0; i < m; i++){
		int u , v , w;
		cin >> u >> v >> w;
		edges.push_back(make_pair(w , make_pair(u, v)));
	}

	sort(edges.begin(), edges.end());

	DisjoinSet ds(n);
	
	int cost = 0;

	for(int i = 0; i < edges.size(); i++){
		int w = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		int id_u  = ds.get_id(u);
		int id_v  = ds.get_id(v);

		if(id_v != id_u){
			cout << u << " " << v << " " << w << endl;
			cost += w;
			ds.join(u, v);
		}
	}

	cout << cost << endl;

}	