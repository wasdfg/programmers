#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<int> nums){
    int answer = 0;
    vector<bool> num(200001,false);
    sort(nums.begin(),nums.end());
    unique(nums.begin(),nums.end());
    for(int i = 0;i < nums.size()/2;i++){
        if(num[nums[i]] == false){
            num[nums[i]] = true;
            answer++;
        }
    }
    return answer;
}