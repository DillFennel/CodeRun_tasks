#include <iostream>
#include <list>

using namespace std;

int main(){
    int n, goal;
    cin>>n>>goal;
    list<int> numbers;
    int inp_val;
    for(int i=0; i<n; i++){
        cin>>inp_val;
        numbers.push_back(inp_val);
    }
    list<int>::iterator l = numbers.begin(), r=numbers.end();
    r--;
    while(!(r==l || *r+*l==goal)){
        if(*r+*l > goal){
            r--;
        }
        else{
            l++;
        }
    }
    if(r == l){
        cout<<"None"<<endl;
    }
    else{
        cout<<goal<<" = "<<*l<<" + "<<*r<<endl;
    }
}