#include <string>
#include <vector>

using namespace std;
long long isprime(long long num){
    if(num == 1)
        return 0;
    long long save = 1;
    for(long long i = 2;i * i<=num;i++){
        if(num % i == 0){
            save = i;
            if(num / i <= 10000000) 
                return (num / i);
        }
    }
    return save;
}

vector<int> solution(long long begin, long long end){
    vector<int> answer;
    for(int i = begin;i <= end;i++){
        answer.push_back(isprime(i));
    }
    return answer;
}