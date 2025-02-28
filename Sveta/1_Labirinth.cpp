#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int labyrinth [n][m];
    int inp_value;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cin>>inp_value;
            labyrinth[y][x] = inp_value;
        }
    }
    int y=0,x=0;
    queue<pair<int, int>> coords_to_go;
    while((y!=n-1 || x!=m-1) && not(coords_to_go.empty())){
        //Идем наверх
        if(y!=0 && labyrinth[y-1][x] == 0){
            labyrinth[y-1][x] = labyrinth[y][x] + 1;
            coords_to_go.push({y+1, x});
        }
        //Идем вправо
        if(x!=m-1 && labyrinth[y][x+1] == 0){
            labyrinth[y][x+1] = labyrinth[y][x] + 1;
            coords_to_go.push({y, x+1});
        }
        //Идем вниз
        if(y!=n-1 && labyrinth[y+1][x] == 0){
            labyrinth[y+1][x] = labyrinth[y][x] + 1;
            coords_to_go.push({y+1, x});
        }
        //Идем влево
        if(x!=0 && labyrinth[y][x-1] == 0){
            labyrinth[y][x-1] = labyrinth[y][x] + 1;
            coords_to_go.push({y, x-1});
        }
        y = coords_to_go.front().first;
        x = coords_to_go.front().second;
        coords_to_go.pop();
    }
    cout<<labyrinth[n-1][m-1];
}