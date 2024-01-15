#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

long long solution(vector<int> weights){
    long long answer = 0;
     vector<long long> count(1001, 0);
    for(int i = 0;i < weights.size();i++){
        count[weights[i]]++;
    }
        for(int i = 0;i < weights.size();i++){
            if(weights[i] % 2 == 0) {
            long long base  = (weights[i]/2) * 3;
            if(base <= 1000)    
                answer += count[base];
        }
        if(weights[i] % 3 == 0) {
            long long base  = (weights[i]/3) * 4;
            if(base <= 1000)    
                answer += count[base];
        }
        long long base  = weights[i] * 2;
        if(base <= 1000)    
            answer += count[base];
    }
        for(int i=100; i<=1000; i++) {
        if(count[i] >= 2)
            answer += (long long)(count[i] * (count[i]-1)) / 2;
    }
    return answer;
}