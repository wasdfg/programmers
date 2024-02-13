#include <string>
#include <vector>
#include<bitset>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0;i < numbers.size();i++){
        if(numbers[i] % 2 == 0){
            answer.push_back(numbers[i]+1);
        }
        else{
            long long num = numbers[i];
            long long cnt = 0;
            while(1){
                if((num & (long long)1<<cnt) == 0){
                    break;
                }
                cnt++;
            }
            if(cnt != 0){
                long long temp = (long long)1<<(cnt-1);
                num=num+((long long)1<<cnt)-temp;
            } 
            else
                num+=1<<cnt;
            answer.push_back(num);
        }
    }
    return answer;
}