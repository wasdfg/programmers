#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int t = right-left+1;
    for(long long i = 0;i < t;i++){
        int y = (int)(left / n + 1);
        int x = (int)(left % n + 1);
        left++; 
        answer.push_back(max(x,y));
    }
    return answer;
}