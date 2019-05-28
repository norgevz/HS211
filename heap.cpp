#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

struct heap{
	vector<int> data;

	int get_min(){

		if(data.size() == 0){
			throw;
		}

		return data[0];
	}

	void push(int x){
		data.push_back(x);
		int pos = data.size() - 1;

		while(pos > 0){
			int par = (pos - 1) / 2;
			if(data[pos] >= data[par]){
				break;
			}

			swap(data[pos] , data[par]);
			pos = par;
		}
	}

	void pop(){
		if(data.size() == 0){
			throw;
		}
		
		swap(data[0], data[data.size() - 1]);
		data.pop_back();

		int pos = 0;

		while(true){
			int lft = 2 * pos + 1;
			int rgt = 2 * pos + 2;

			int min_node = pos;

			if(lft < data.size() && data[lft] < data[min_node]){
				min_node = lft;
			}

			if(rgt < data.size() && data[rgt] < data[min_node]){
				min_node = rgt;
			}

			if(pos == min_node){
				break;
			}

			swap(data[pos] , data[min_node]);
			pos = min_node;
		}
	}
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    heap x;
    
}