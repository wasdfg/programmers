#include <string>
#include <vector>
#include<iostream>

using namespace std;

int gcd(int a,int b){
    int n ;
    while(b!=0){
        n = a%b;
        a = b;
        b = n; 
    }
    return a;
}

int solution(vector<int> arr) {
    int answer;
    answer = arr[0];
    for(int i = 1;i < arr.size();i++){
        answer = (answer * arr[i]) / gcd(answer,arr[i]);
    }
    return answer;
}