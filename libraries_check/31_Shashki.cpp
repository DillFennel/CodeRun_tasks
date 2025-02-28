#include <iostream>
#include <set>
#include <string>

using namespace std;

void read_shashki(set<pair<int, int>>& shashki, int n, int m){
	int kolvo, i, j;
	cin>>kolvo;
	for(int k=0; k<kolvo; k++){
		cin>>i>>j;
		shashki.insert({i-1, j-1});
	}
}
bool eat(set<pair<int, int>> player, set<pair<int, int>> oponent, int n, int m){
	int y, x;
	pair<int, int> diags[4] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
	for(auto piece: player){
		for(int i=0; i<4; i++){
			//Проверить диагональ
			y = piece.first + diags[i].first;
			x = piece.second + diags[i].second;
			if(oponent.find({y, x}) != oponent.end() && (diags[i].first == -1 && y>0 || diags[i].first == 1 && y<n-1) && (diags[i].second == -1 && x>0 || diags[i].second == 1 && x<m-1)){
				y += diags[i].first;
				x += diags[i].second;
				if(player.find({y, x}) == player.end() && oponent.find({y, x}) == oponent.end()){
					return true;
				}
			}
		}
	}
	return false;
}


int main(){
	int n,m;
	cin>>n>>m;
	set<pair<int, int>> white;
	read_shashki(white, n, m);
	set<pair<int, int>> black;
	read_shashki(black, n, m);
	string move;
	cin>>move;
	if(move == "white"){
		cout<<(eat(white, black, n, m) ? "Yes" : "No");
	}
	else{
		cout<<(eat(black, white, n, m) ? "Yes" : "No");
	}
}
/*
4 4
1
2 2
3
0 0
1 1
3 3
black

*/