#include <string>
#include <vector>
#include<algorithm>
#include<map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string,int> rank;
    for(int i = 0;i < players.size();i++){
        rank[players[i]] = i;
    }
    for(int i = 0;i < callings.size();i++){
        string call = callings[i];
        int now = rank[call];
        string temp = players[now-1];
		players[now-1] = players[now];
		players[now] = temp;
        rank[call] = now-1;
        rank[temp] = now;
    }
    return players;
}