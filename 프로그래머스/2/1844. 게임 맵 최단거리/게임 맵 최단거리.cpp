#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int tx[4] = {0,0,-1,1};
    int ty[4] = {1,-1,0,0};
    queue<pair<int,int>> togo;
    //maps[0][0] = 2;
    togo.push({0,0});
    while(!togo.empty()){
        int x = togo.front().first;
        int y = togo.front().second;
        togo.pop();
        if(x == maps.size() && y == maps.size()){
            break;
        }
        for(int i = 0;i < 4;i++){
            if(x+tx[i] >= 0 && x+tx[i] < maps.size() && y+ty[i] >= 0 && y+ty[i] < maps[0].size()){
                if(maps[x+tx[i]][y+ty[i]] == 1){
                    maps[x+tx[i]][y+ty[i]] += maps[x][y];
                    togo.push({x+tx[i],y+ty[i]});
                }
            }
        }
    }
    if(maps[maps.size()-1][maps[0].size()-1] == 1){
        return -1;
    }
    else{
        answer = maps[maps.size()-1][maps[0].size()-1];
        return answer;
    }
}