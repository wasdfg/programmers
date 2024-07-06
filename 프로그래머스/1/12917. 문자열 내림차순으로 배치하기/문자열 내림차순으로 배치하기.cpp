#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string up = "";
    string low = "";
    for(int i = 0;i < s.length();i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            up+=s[i];
        }
        else{
            low+=s[i];
        }
    }
    sort(low.begin(),low.end(),greater<int>());
    sort(up.begin(),up.end(),greater<int>());
    answer+=low;
    answer+=up;
    return answer;
}