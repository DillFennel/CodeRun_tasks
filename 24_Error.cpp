#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;
int main() 
{
    int n;
    cin>>n;
    pair<long double, long double> p_inp[n];
    long double p_b, p_a_b;
    long double p_a = 0;
    for(int i=0; i<n; i++){
        cin>>p_b>>p_a_b;
        p_inp[i] = {p_b, p_a_b};
        p_a += p_b*p_a_b;
    }
    for(int i=0; i<n; i++){
        printf("%10.12Lf\n", (p_inp[i].first*p_inp[i].second)/p_a);
    }
	return 0;
}