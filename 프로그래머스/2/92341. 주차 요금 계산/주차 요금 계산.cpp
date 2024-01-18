#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool cmp(string &a,string &b){
    if(a.substr(6,4) == b.substr(6,4)){
        return a.substr(0,5) < b.substr(0,5);
    }
    else{
        return a.substr(6,4) < b.substr(6,4);
    }
}

vector<int> solution(vector<int> fees, vector<string> records){
    vector<int> answer;
    int totalminute;
    int money = 0;
    string carnum;
    bool notchecked;
    sort(records.begin(), records.end(), cmp);
    for (int i = 0; i < records.size(); i++){
        money = 0;
        totalminute = 0;
        notchecked = false;
        carnum = records[i].substr(6, 4);
        while (i < records.size() && carnum == records[i].substr(6, 4)){
            if (records[i].length() == 13){ // in
                totalminute -= (stoi(records[i].substr(0, 2)) * 60 + stoi(records[i].substr(3, 2)));
                notchecked = true;
                if (i < records.size()){
                    i++;
                }
            }
            else{ // out
                totalminute += (stoi(records[i].substr(0, 2)) * 60 + stoi(records[i].substr(3, 2)));
                notchecked = false;
                if (i < records.size()){
                    i++;
                }
            }
        }
        if (notchecked == 1){
            totalminute += 1439;
            if (totalminute <= fees[0]){
                money += fees[1];
            }
            else{
                money += fees[1];
                totalminute -= fees[0];
                if (totalminute % fees[2] != 0){
                    money += ((totalminute / fees[2]) + 1) * fees[3];
                }
                else{
                    money += (totalminute / fees[2]) * fees[3];
                }
            }
        }
        else{
            if (totalminute <= fees[0]){
                money += fees[1];
            }
            else{
                money += fees[1];
                totalminute -= fees[0];
                if (totalminute % fees[2] != 0){
                    money += ((totalminute / fees[2]) + 1) * fees[3];
                }
                else{
                    money += (totalminute / fees[2]) * fees[3];
                }
            }
        }
        answer.push_back(money);
        i--;
    }
    return answer;
}