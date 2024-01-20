#include <string>
#include <vector>
#include<map>
#include<iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> wear;
    for(int i = 0;i < clothes.size();i++){ //map을 사용해서 옷 종류를 집어넣음
        if(wear[clothes[i][1]] == 0){ //같은 옷 종류의 수를 구함
            wear[clothes[i][1]] = 1;
        }
        else{
            wear[clothes[i][1]]++;
        }
    }
    for(auto iter : wear){ //옷을 입는다 안입는다 2가지 방법이 있으므로 조합을 사용한다
	    answer *= iter.second+1;
    }
    answer--; //전부 안입는것은 제외
    return answer;
}
