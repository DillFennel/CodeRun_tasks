#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <stack>

int main(){
    int n, m;
    std::cin>>n>>m;

    std::map <int, std::vector<int>> graph;
    int a, b;
    for(int i=0; i<m; i++){
        std::cin>>a>>b;
        if(a != b and graph[b].count(a) == 0){
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    
    std::list <int> komp;
    std::stack <int> verces = {1};

    while(not(verces.empty())){
        
    }
}