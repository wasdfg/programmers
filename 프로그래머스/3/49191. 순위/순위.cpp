#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results){
    int answer = 0;
    vector<vector<bool>> fw(n,vector<bool>(n,0));
    for(int i = 0;i < results.size();i++){
        fw[results[i][0]-1][results[i][1]-1] = true;
    }
    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(fw[i][k] && fw[k][j]){
                    fw[i][j] = true;
                }
            }
        }
    }
    for(int i = 0;i < n;i++){
        int count = 0;
        for(int j = 0;j < n;j++){
            if(fw[i][j] || fw[j][i]){
                count++;
            }
        }
        if(count == n - 1){
            answer++;
        }
    }
    return answer;
}