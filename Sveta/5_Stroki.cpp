#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool check(unordered_map<char, int>& m){
    for(auto i: m){
        if(i.second != 1){
            return 0;
        }
    }
    return 1;
}
int main(){
    string inp, goal;
    cin>>inp>>goal;
    unordered_map<char, int> found;
    for(auto c: goal){
        found[c] = 0;
    }

    for(int i=0; i<goal.size(); i++){
        if(found.find(inp[i]) != found.end()){
            found[inp[i]]++;
        }
    }
    vector<int> ans;
    if(check(found)){
        ans.push_back(0);
    }
    for(int i=goal.size(); i<inp.size(); i++){
        if(found.find(inp[i]) != found.end()){
            found[inp[i]]++;
        }
        if(found.find(inp[i-goal.size()]) != found.end()){
            found[inp[i-goal.size()]]--;
        }
        if(check(found)){
            ans.push_back(i-goal.size()+1);
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
}