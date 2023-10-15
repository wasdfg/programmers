#include <string>
#include<iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int x1 = -1,y1 = -1,x2 = -1,y2 = -1;
    for(int i = 0;i < wallpaper.size();i++){
        int size = wallpaper[i].size();
        for(int j = 0;j < size;j++){
            if(wallpaper[i][j] == '#'){
                if(y1 <= j){
                if(y1 < 0){
                    y1 = j;
                }
                }
                if(x1 < 0){
                    x1 = i;
                }
                if(y2 < j)
                    y2 = j+1;
                if(x2 < i+1)
                    x2 = i+1;
            }
        }
    }
    answer.push_back(x1);
    answer.push_back(y1);
    answer.push_back(x2);
    answer.push_back(y2);
    return answer;
}

int main(void){
    vector<string> s = {"#.", ".."};
    solution(s);
    for(int i = 0;i < solution(s).size();i++){
        cout<<solution(s)[i]<<" ";
    }

}