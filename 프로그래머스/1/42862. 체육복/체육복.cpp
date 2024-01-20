#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve){
    int answer = 0;
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    vector<bool> have(n,true);
    for(int i = 0;i < lost.size();i++){
        have[lost[i]] = false;
    }
    answer = n - lost.size();
    for(int i = 0;i < reserve.size();i++){
        if(find(lost.begin(),lost.end(),reserve[i]) != lost.end() && have[reserve[i]] == false){
            have[reserve[i]] = true;
            reserve.erase(reserve.begin()+i);
            answer++;
            i--;
        }
    }
    for(int i = reserve.size()-1;i >= 0;i--){
        if(have[reserve[i]] == false){
            have[reserve[i]] = true;
            answer++;
        }
        else if(reserve[i]+1 <= n && have[reserve[i]+1] == false){
            have[reserve[i]+1] = true;
            answer++;
        }
        else if(reserve[i]-1 >= 1 && have[reserve[i]-1] == false){
            have[reserve[i]-1] = true;
            answer++;
        }
    }
    return answer;
}