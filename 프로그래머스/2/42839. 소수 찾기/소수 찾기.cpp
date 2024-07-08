#include <string>
#include <vector>
#include<set>
#include<algorithm>
#include<iostream>

using namespace std;

bool prime(int x){
    if(x <= 1){
        return 0;
    }
    for(int i = 2;i*i <= x;i++){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
} 

int solution(string numbers){
    int answer = 0;
    set<int> number;
    sort(numbers.begin(),numbers.end());
    
    do{
        for(int i = 1;i <= numbers.length();i++){
            string x = numbers.substr(0,i);
            int num = stoi(x);
            if(prime(num)){
                number.insert(num);
            }
        }
    }while(next_permutation(numbers.begin(),numbers.end()));
    
    answer = number.size();
    return answer;
}