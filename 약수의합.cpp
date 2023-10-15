#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int n){
    vector<bool> prime(3001,true);
    prime[0] = false;
    prime[1] = false;
    for(int i = 2;i * i <= n;i++){
        for(int j = 2;j *i <= n;j++){
            prime[i*j] = false;
        }
    }
    int answer = 1,isprime=n;
    if(n == 1){
        answer = 1;
    }
    else if(n == 0){
        answer = 0;
    }
    else{
        for(int k = 2;k < prime.size();k++){
            int count = 0,num = 1;
            if(n % k == 0 && prime[k] == true){
                while(n % k == 0){
                    count++;
                    n /= k;
                }
                for(int l = 0;l <= count;l++){
                    num *= k;
                }
                num-=1;
                num/=(k-1);
                answer*=num;
            }
        }
    }
    return answer;
}