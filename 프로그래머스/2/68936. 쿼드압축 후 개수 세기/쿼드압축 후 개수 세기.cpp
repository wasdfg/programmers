#include <string>
#include <vector>
#include<iostream>

using namespace std;

int zero = 0,one = 0;
vector<vector<int>> cpy;

int daq(int len,int x,int y){
    int start = cpy[x][y];
    int count = 0;
    bool same = 1;
    for(int i = x;i < x+len;i++){
        for(int j = y;j < y+len;j++){
            if(start != cpy[i][j]){
                same = 0;            
            }
            else{
                count++;
            }
        }
    }
    if(same == 0){
        daq(len/2,x,y);
        daq(len/2,x+len/2,y);
        daq(len/2,x,y+len/2);
        daq(len/2,x+len/2,y+len/2);
    }
    else{
        if(count == len*len){
            if(start == 0){
                zero+=1;
            }
            else{
                one+=1;
            }
        }
    }
    return 0;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    cpy.assign(arr.size(),vector<int>(arr.size(),0));
    cpy = arr;
    daq(arr.size(),0,0);
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}