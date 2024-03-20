#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0,w = 0,h = 0;
    for(int i = 0;i < sizes.size();i++){
        if(sizes[i][0] < sizes[i][1]){
            swap(sizes[i][0],sizes[i][1]);
        }
    }
    for(int i = 0;i < sizes.size();i++){
        if(sizes[i][0] > w){
            w = sizes[i][0];
        }
        if(sizes[i][1] > h){
            h = sizes[i][1];
        }
    }
    answer = w*h;
    return answer;
}