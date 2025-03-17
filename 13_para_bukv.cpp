#include <iostream>
#include <string>
#include <map>

int main() 
{
    std::string inp;
    getline(std::cin, inp);
    if(inp.size() == 0){
        return 0;
    }
    std::map<std::pair<char, char>, int> podstr;
    for(int i=1; i<inp.size(); i++){
        if(inp[i-1]==' ' || inp[i]==' '){
            continue;
        }
        if(podstr.find({inp[i-1], inp[i]}) != podstr.end()){
            podstr[{inp[i-1], inp[i]}]++;
        }
        else{
            podstr[{inp[i-1], inp[i]}]=1;
        }
    }
    std::pair<char, char> ret;
    int max_val = 0;
    for(auto i:podstr){
        if(i.second >= max_val){
            max_val = i.second;
            ret = i.first;
        }
    }
    std::cout<<ret.first<<ret.second;
	return 0;
}