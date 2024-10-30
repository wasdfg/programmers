#include <queue>
#include <vector>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0,check = 0;
    priority_queue<long long> pq(works.begin(),works.end());
    for(int i = 0;i < n;i++){
        int x = pq.top();
        if(x > 0){
            pq.pop();
            x--;
            pq.push(x);
        }
    }
    while(!pq.empty()){
        answer+=(pq.top()*pq.top());
        pq.pop();
    }
    return answer;
}