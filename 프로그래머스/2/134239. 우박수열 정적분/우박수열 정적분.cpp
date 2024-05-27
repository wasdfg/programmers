#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> ubak;
    vector<double> area;
    double save = k;
    ubak.push_back(k);
    while(k != 1){
        if(k % 2 == 0){
            ubak.push_back(k/2);
            k/=2;
        }
        else{
            ubak.push_back(k*3+1);
            k = k * 3 + 1;
        }
    }
    double whole = 0.0;
    for(int i = 0;i < ubak.size()-1;i++){
        double x = (ubak[i]+ubak[i+1])/2.0;
        whole+=x;
        area.push_back(x);
    }
    int t = ubak.size()-1;
    for(int i = 0;i < ranges.size();i++){
        if(t+ranges[i][1] < ranges[i][0]){
            answer.push_back(-1.0);
        }
        else{
            if(ranges[i][0] == 0 && ranges[i][1] == 0){
                answer.push_back(whole);
            }
            else{
                double check = 0.0;
                for(int j = ranges[i][0];j < t+ranges[i][1];j++){
                    check+=area[j];
                }
                answer.push_back(check);
            }
        }
    }
    return answer;
}