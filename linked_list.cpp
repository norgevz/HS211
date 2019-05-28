#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

struct node{

	int value;
	node * next;
	node(int _x){
		value = _x;
		next = NULL;
	}
};

struct linked_list{
	node * root;

	linked_list(){
		root = NULL;
	}

	void push_back(int x){

		node * foo = new node(x);

		if(root == NULL){
			root = foo;
			return;
		}

		node * it = root;

		while(it->next != NULL){
			it = it->next;
		}

		it->next = foo;
	}

	void insert(int pos, int x){
		node * foo = new node(x);

		if(root == NULL){
			root = foo;
			return;
		}

		node * it = root;
		node * prev = NULL;

		for(int i = 0; i < pos; i++){
			prev = it;
			it = it->next;
		}

		if(prev != NULL)
			prev->next = foo;

		foo->next = it;
	}

	void set(int pos, int x){

	}
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


}