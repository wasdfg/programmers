#include <iostream>
#include <vector>

using namespace std;

int solution(int n){
    int ans = 0;
    while(n > 0){
        if(n % 2 == 1){
            n--;
            ans++;
        }
        n/=2;
    }
    return ans;
}