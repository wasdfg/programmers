#include <string>
#include <vector>
#include<set>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> total;
    for(int i = 0; i < numbers.size();i++){
        for(int j = i+1;j < numbers.size();j++){
            total.insert(numbers[i]+numbers[j]);
        }
    }
    for(auto a:total){
        answer.push_back(a);
    }
    sort(answer.begin(),answer.end());
    return answer;
}