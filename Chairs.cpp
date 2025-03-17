#include <iostream>
#include <list>

int func() 
{
    int n, m;
    std::cin>>n>>m;
    if(n==0 or m==0){
        return 0;
    }
    std::list<int> sup, buy;
    int inp;
    for(int i=0; i<n; i++){
        std::cin>>inp;
        sup.push_back(inp);
    }
    sup.sort();
    for(int i=0; i<m; i++){
        std::cin>>inp;
        buy.push_back(inp);
    }
    buy.sort();
    int pribl=0;
    while(!(sup.empty()) && !(buy.empty()) && sup.front() < buy.back()){
        pribl += buy.back() - sup.front();
        buy.pop_back();
        sup.pop_front();
    }
    return pribl;
}
int main(){
    std::cout<<func()<<std::endl;
}