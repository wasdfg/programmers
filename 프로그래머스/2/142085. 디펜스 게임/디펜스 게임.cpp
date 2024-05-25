#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    int i=0;
    for(; i<enemy.size(); i++) {
        if(n-enemy[i]>=0) {
            n-=enemy[i];
            pq.push(enemy[i]);
        } else {
            if(k > 0) {
                if(!pq.empty() && pq.top() >= enemy[i]) {
                    n+=pq.top();
                    pq.pop();
                    
                    n-=enemy[i];
                    pq.push(enemy[i]);
                }
                k--;
            } else {
                break;
            }
        }
    }
    
    
    return i;
}