#include<bits/stdc++.h>

using namespace std;

int n , m, src;
const int oo  = 1e9;


struct DS{

	vector<int> par;
	vector<int> size;

	int n;

	void init(int _n){

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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

}	