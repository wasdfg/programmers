#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(!(s.length() == 6 || s.length() == 4)){
        return 0;
    }
    for(int i = 0;i < s.length();i++){
        if(s[i] < 48 || s[i] > 57){
            return 0;
        }
    }
    return answer;
}