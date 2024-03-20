#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    pair<int,int> save;
    int start = 0,end = 0,check = sequence[0],len = sequence.size()+1;
    while(start <= end && end < sequence.size()){
        if(check < k){
            end++;
            check+=sequence[end];
        }
        else if(check == k){
            if(end-start+1 < len){
                len = end-start+1;
                save = {start,end};
            }
            else if(end-start+1 == len){
                if(save.first > start){
                    save = {start,end};
                }
            }
            check-=sequence[start];
            start++;
        }
        else{
            check-=sequence[start];
            start++;
        }
    }   
    answer.push_back(save.first);
    answer.push_back(save.second);
    return answer;
}