#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0,y = 0;
    char c;
    for(auto c:s){
        if(c == 'p' || c == 'P'){
            p++;
        }
        else if(c == 'y' || c == 'Y'){
            y++;
        }
    }
    if(p != y){
        answer = false;
    }
    return answer;
}