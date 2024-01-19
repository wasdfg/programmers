#include <string>
#include <vector>
#include<algorithm>
#include<cmath>

using namespace std;

bool isprime(long long num){
    if(num < 2){
        return false;
    }
    for(int i = 2;i <= sqrt(num);i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s = "";
    string check = "";
    while(n > 0){
        s+=to_string(n % k);
        n/=k;
    }
    reverse(s.begin(),s.end());
    for(int i = 0;i < s.length();i++){
        if(s[i] == '0'){
            if(!check.empty() && isprime(stoll(check))){
                answer++;
            }
            check = "";
        }
        else{
            check+=s[i];
        }
    }
    if (!check.empty() && isprime(stoll(check))) {
        answer++;
    } 
    return answer;
}