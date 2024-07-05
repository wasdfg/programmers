#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0;i <s.length();i++){
        if(s[i]+n > 122){
            answer+=(97+s[i]+n-123);
        }
        else if(s[i] <= 90 && s[i]+n > 90){
            answer+=(65+s[i]+n-91);
        }
        else{
            if(s[i] == 32){
                answer+=" ";
            }
            else{
                answer+=(s[i]+n);
            }
        }
    }
    return answer;
}