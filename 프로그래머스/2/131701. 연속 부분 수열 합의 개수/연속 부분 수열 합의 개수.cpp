#include <string>
#include <vector>
#include<deque>
#include<set>
#include<iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0,sum = 0;
    set<int> check;
    vector<int> copy(elements.size()*2,0);
    for(int i = 0;i < elements.size();i++){
        copy[i] = elements[i];
        copy[i+elements.size()] = elements[i];
    }
    for(int i = 0;i < elements.size();i++){
        int sum = elements[i];
        check.insert(sum);
        int count = 1;
        int e = i;
        while(count < elements.size()){
            count++;
            e++;
            sum+=copy[e];
            check.insert(sum);
        }
    }
    answer = check.size();
    return answer;
}