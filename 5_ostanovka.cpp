#include <iostream>
#include <map>

int main(){
	int n, k;
	std::cin>>n>>k;
	std::map<int, std::pair<int ,int>> prospect; //по координате храним минимальную и максимальную остановку в этой точке
	int coord;
	for(int i=1; i<=n; i++){
		std::cin>>coord;
		if(prospect.find(coord) != prospect.end()){
			prospect[coord].second = i;
		}
		else{
			prospect[coord] = {i, i};
		}
	}
	std::map<int, std::pair<int ,int>>::iterator l, r;
	for(int i=0; i<k; i++){
		std::cin>>coord;
        r = prospect.lower_bound(coord);
		if(r == prospect.end()){
            r--;
            std::cout<<r->second.second<<std::endl;
        }
        else if(r->first == coord){
            std::cout<<r->second.first<<std::endl;
        }
        else if(r == prospect.begin()){
            std::cout<<r->second.first<<std::endl;
        }
        else{//Есть остановки и справа, и слева. Надо проверить расстояние до них
            l = r;
            l--;
            if(coord-l->first <= r->first-coord){
                std::cout<<l->second.second<<std::endl;
            }
            else{
                std::cout<<r->second.first<<std::endl;
            }
        }
	}
    return 0;
}