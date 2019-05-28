#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

struct dynamic_array{
	int * s;
	int size;
	int first_empty;

    dynamic_array(){
    	first_empty = 0;
    	s = new int[32];
    	size = 32;
    }

    void set(int i, int value){
    	s[i] = value;
    }

    int get(int i){
    	return s[i];
    }

    void push_back(int value){
    	s[first_empty] = value;
    	first_empty++;

    	if(first_empty >= size){
    		int * new_array = new int[2 * size];
    		for(int i = 0 ; i < size; i++){
    			new_array[i] = s[i];
    		}
			size = 2 * size;
			s = new_array;
    	}
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


}