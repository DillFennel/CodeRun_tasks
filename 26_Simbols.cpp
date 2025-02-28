#include <iostream>
#include <string>
#include <map>

using namespace std;

int func(){
	string inp, c;
	cin>>inp>>c;
	map<char, int> found_char;
	for(auto i:c){
		found_char[i] = 0;
	}
	int min_len = 0;
	bool flag;
    int l=0, r=-1;
	while(r<inp.size() && l<inp.size()){
        if(c.find(inp[]))
    }
	return min_len;
}
int main(){
	cout<<func();
	return 0;
}