#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0,len = citations.size();
    sort(citations.begin(),citations.end());
    for(int i = 0;i < len;i++){
        int tmp = len - i;
        if(citations[i] >= tmp){
            answer = tmp;
            break;
        }
    }
    return answer;
}