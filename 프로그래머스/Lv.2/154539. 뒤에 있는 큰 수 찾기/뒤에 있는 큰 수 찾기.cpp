#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    stack<int> nearbig;
    answer.resize(numbers.size(),0);
    for(int i = numbers.size()-1;i >= 0;i--){
         while(1){
            if(nearbig.empty()){
                answer[i] = -1;
                break;
            }
            if(nearbig.top()>numbers[i]){
                answer[i] = nearbig.top();
                break;
            }
            nearbig.pop();
        }
        nearbig.push(numbers[i]);
    }
    return answer;
}