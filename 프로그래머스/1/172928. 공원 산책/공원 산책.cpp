#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes){
    vector<vector<int>> maps(park.size(),vector<int>(park[0].length(),0));
    vector<int> answer;
    int x,y;
    bool check = true;
    for(int i = 0;i < park.size();i++){
        for(int j = 0;j < park[i].length();j++){
            if(park[i][j] == 'S'){
                maps[i][j] = 2;
                y = i,x = j;
            }
            if(park[i][j] == 'X'){
                maps[i][j] = 1;
            }
        }
    }
    for(int i = 0;i < routes.size();i++){
        char a = routes[i][2];
        int num = a - '0';

        if(routes[i][0] == 'E'){
            for(int j = 1;j <= num;j++){
                if(x+j >= park[0].length() || maps[y][x+j] == 1){
                    check = false;
                    break;
                }
            }
            if(check == true){
                x+=num;
            }
        }
        else if(routes[i][0] == 'W'){
            for(int j = 1;j <= num;j++){
                if(x-j < 0 || maps[y][x-j] == 1){
                    check = false;
                    break;
                }
            }
            if(check == true){
                x-=num;
            }
        }
        else if(routes[i][0] == 'S'){
            for(int j = 1;j <= num;j++){
                if(y+j >= park.size() || maps[y+j][x] == 1){
                    check = false;
                    break;
                }
            }
            if(check == true){
                y+=num;
            }   
        }
        else if(routes[i][0] == 'N'){
            for(int j = 1;j <= num;j++){
                if(y-j < 0 || maps[y-j][x] == 1){
                    check = false;
                    break;
                }
            }
            if(check == true){
                y-=num;
            }       
        }
        check = true;
    }
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}