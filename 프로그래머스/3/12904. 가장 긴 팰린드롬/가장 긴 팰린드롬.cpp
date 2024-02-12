#include <iostream>
#include <string>

using namespace std;

int solution(string s){
    int answer=0;
    int left,right;
    for(int i = 0;i < s.length();i++){
        left = i,right = i;
        while(left >= 0 && right < s.length()){
            if(s[left] != s[right]){
                break;
            }
            left--;
            right++;
        }
        int odd = right - left - 1;
        left = i-1,right = i;
        while(left >= 0 && right < s.length()){
            if(s[left] != s[right]){
                break;
            }
            left--;
            right++;
        }
        int even = right - left - 1;
        int check = max(odd,even);
        answer = max(answer,check);
    }
    return answer;
}