#include <string>
#include <vector>
#include<map>
#include<algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0,sum = 0;
    map<int,int> tg;
    vector<int> tmp;
    for(int i = 0;i < tangerine.size();i++){
        tg[tangerine[i]]++;
    }
    for(auto a:tg){
        tmp.push_back(a.second);
    }
    sort(tmp.begin(),tmp.end(),greater<int>());
    for(auto a:tmp){
        if(a + sum >= k){
            answer++;
            break;
        }
        else{
            sum+=a;
            answer++;
        }
    }
    return answer;
}