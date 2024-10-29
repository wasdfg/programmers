#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0,now = 0;
    queue<int> q;
    for(int i = 0;i < truck_weights.size();i++){
        while(1){
            if(q.size() == bridge_length){
                now-=q.front();
                q.pop();
            }
            if(now+truck_weights[i] <= weight){
                break;
            }
            q.push(0);
            answer++;
        }
        q.push(truck_weights[i]);
        now+=truck_weights[i];
        answer++;
    }
    answer+=bridge_length;
    return answer;
}