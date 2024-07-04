#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> month = {31,29,31,30,31,30,31,31,30,31,30,31};
    vector<string> day = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int num = 0;
    for(int i = 0;i < a-1;i++){
        num+=month[i];
    }
    num+=b;
    num+=4;
    answer = day[num%7];
    return answer;
}