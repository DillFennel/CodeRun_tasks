#include <iostream>
#include <map>

using namespace std;

int main() 
{
	map<int, int> count_elem;

	int n;
	cin>>n;
	int value;
	for(int i=0; i<n; i++){
		cin>>value;
		auto f = count_elem.find(value);
		if(f != count_elem.end()){
			count_elem[value]++;
		}
		else{
			count_elem[value] = 1;
		}
	}
	int ans = 0;
	for(auto i: count_elem){
		if (i.second == 1){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}