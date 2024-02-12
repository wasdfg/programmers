#include <string>
#include <vector>
#include<algorithm>

using namespace std;
int sector;

bool cmp(string &a,string &b){
    if(a[sector] == b[sector]){
        return a < b;
    }
    return a[sector] < b[sector];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    sector = n;
    sort(strings.begin(),strings.end(),cmp);
    for(int i = 0;i < strings.size();i++){
        answer.push_back(strings[i]);
    }
    return answer;
}