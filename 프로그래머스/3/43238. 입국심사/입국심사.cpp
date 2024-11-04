#include <string>
#include <vector>
#include<algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0,left,right,mid,check;
    sort(times.begin(),times.end());
    left = times[0],right = times[times.size()-1] * (long long)n;
    while(left <= right){
        mid = (left+right)/2;
        check = 0;
        for(int i = 0;i < times.size();i++){
            check+=(mid/times[i]);
        }
        if(check < n){
            left = mid+1;
        }
        else{
            answer = mid;
            right = mid-1;
        }
    }
    return answer;
}