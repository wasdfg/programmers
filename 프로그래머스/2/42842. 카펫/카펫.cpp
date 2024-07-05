#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2,0);
    int area = brown+yellow;
    for(int i = 3;i <= area;i++){
        if(area % i == 0 && (i*2+(area/i-2)*2) == brown){
            answer[0] = max(i,area/i);
            answer[1] = min(i,area/i);
            break;
        }
    }
    return answer;
}