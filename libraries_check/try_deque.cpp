#include <iostream>
#include <string>
#include <cmath>
#include <set>

using namespace std;

bool shashki(){
	int n, m;
	cin>>n>>m;

	int kolvo;
	int y, x;
	set<pair<int, int>> white;
    cin>>kolvo;
	for(int i=0; i<kolvo; i++){
		cin>>y>>x;
		white.insert({y, x});
	}
	cin>>kolvo;
	set<pair<int, int>> black;
	for(int i=0; i<kolvo; i++){
		cin>>y>>x;
		black.insert({y, x});
	}
	string move;
	cin>>move;
	for(auto w : white){
		for(auto b : black){
			if(w.first>b.first){
				if(w.second > b.second){
					if(w.second-b.second == w.first-b.first){
						if(move == "black"){
							if(w.first != n-1 && w.second != m-1 && white.find({w.first+1, w.second+1})==white.end()){
								return true;
							}
						}
						else{
							if(b.first != 0 && b.second != 0 && black.find({b.first-1, b.second-1})==black.end()){
								return true;
							}
						}
					}
				}
				else{
					if(w.second-b.second == w.first-b.first){
						if(move == "black"){
							if(w.first != n-1 && w.second != 0 && white.find({w.first+1, w.second-1})==white.end()){
								return true;
							}
						}
						else{
							if(b.first != 0 && b.second != m-1 && black.find({b.first-1, b.second+1})==black.end()){
								return true;
							}
						}
					}
				}
			}
			else{
				if(w.second > b.second){
					if(w.second-b.second == w.first-b.first){
						if(move == "black"){
							if(w.first != 0 && w.second != m-1 && white.find({w.first-1, w.second+1})==white.end()){
								return true;
							}
						}
						else{
							if(b.first != n-1 && b.second != 0 && black.find({b.first+1, b.second-1})==black.end()){
								return true;
							}
						}
					}
				}
				else{
					if(w.second-b.second == w.first-b.first){
						if(move == "black"){
							if(w.first != 0 && w.second != 0 && white.find({w.first-1, w.second-1})==white.end()){
								return true;
							}
						}
						else{
							if(b.first != n-1&& b.second != m-1 && black.find({b.first+1, b.second+1})==black.end()){
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
int main(){
	cout<<(shashki() ? "Yes" : "No");

	return 0;
}