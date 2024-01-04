#include <string>
#include <vector>
#include<queue>
#include<iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0,sts,nds,mix;
    priority_queue<int,vector<int>,greater<int>> mapgi;
    for(int i = 0;i < scoville.size();i++){
        mapgi.push(scoville[i]);
    }
    while(mapgi.size() > 1){
        if(mapgi.top() >= K){
            break;
        }
        sts = mapgi.top();
        mapgi.pop();
        nds = mapgi.top();
        mapgi.pop();
        mix = sts + (nds * 2);
        mapgi.push(mix);
        answer++;
    }
    if(mapgi.top() < K){
        answer = -1;
    }
    return answer;
}