#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
int x;

bool cmp(vector<int> a,vector<int> b){
    if(a[x-1] == b[x-1]){
        return a[0] > b[0];
    }
    else{
        return a[x-1] < b[x-1];
    }
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    int now = 0;
    x = col;
    sort(data.begin(),data.end(),cmp);
    for(int i = row_begin-1;i <= row_end-1;i++){
        now = 0;
        for(int j = 0;j < data[i].size();j++){
            now += (data[i][j] % (i+1)); 
        }
        answer ^= now;
    }
    return answer;
}