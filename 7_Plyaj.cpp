#include <iostream>
#include <list>

using namespace std;

int main(){
	int t;
	cin>>t;
	int n;
	list<int> lejaki;
	list<int>::iterator curr_lej;
	int pre_lej, inp_lej, min_xor;
	for(int i=0; i<t; i++){
		cin>>n;
        lejaki.clear();
		for(int lej=0; lej < n; lej ++){
			cin>>inp_lej;
			lejaki.push_back(inp_lej);
		}
		lejaki.sort();
		pre_lej = lejaki.front();
		curr_lej = lejaki.begin();
		curr_lej++;
		min_xor = *curr_lej ^ pre_lej;
		for(; curr_lej!=lejaki.end(); curr_lej++){
            if((*curr_lej ^ pre_lej) < min_xor){
				min_xor = *curr_lej ^ pre_lej;
			}
			pre_lej = *curr_lej;
		}
		cout<<min_xor<<endl;
	}
}