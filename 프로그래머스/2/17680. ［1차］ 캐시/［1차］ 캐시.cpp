#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> LRU;
    if(cacheSize == 0){
        return 5*cities.size();
    }
    for(int i = 0;i < cities.size();i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    }
    for(int i = 0;i < cities.size();i++){     
        if(find(LRU.begin(),LRU.end(),cities[i]) == LRU.end()){
            answer+=5;
            if(LRU.size() == cacheSize){
                LRU.erase(LRU.begin());
            }
        }
        else{
            answer++;
            int pos = find(LRU.begin(),LRU.end(),cities[i])-LRU.begin();
            if(LRU.size() == cacheSize){
                LRU.erase(LRU.begin()+pos);
            }
        }
        LRU.push_back(cities[i]);
    }
    return answer;
}