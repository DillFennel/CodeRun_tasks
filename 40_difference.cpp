#include <iostream>
#include <unordered_map>

int func() 
{
    int n;
    std::cin>>n;
    std::unordered_map<int, int> prod_to_cat;
    int prod, cat;
    for(int i=0; i<n; i++){
        std::cin>>prod>>cat;
        if(prod_to_cat.find(prod) != prod_to_cat.end()){
            std::cerr<<"Error: Two products have same id";
            exit(2);
        }
        prod_to_cat[prod] = cat;
    }
    std::unordered_map<int, int> last_cat_pos;
    int curr_val;
    int min_raz = -1;
    for(int i=0; i<n; i++){
        std::cin>>curr_val;
        if(last_cat_pos.find(prod_to_cat[curr_val]) != last_cat_pos.end()){
            if(min_raz < 0 || min_raz > i-last_cat_pos[prod_to_cat[curr_val]]){
                min_raz = i-last_cat_pos[prod_to_cat[curr_val]];
            }
        }
        last_cat_pos[prod_to_cat[curr_val]] = i;
    }
    return min_raz;
}
int main(){
    std::cout<<func()<<std::endl;
}