#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int left, int right) {//1과 완전제곱수만 홀수개이고 완전제곱수는 홀수의 합으로 이루어져있다
    int answer = 0;
    for(int i = left;i <= right;i++){
        int odd = 1,count = 3;
            if(i == 1){
                answer-=1;
            }
            else{
                while(i > odd){
                    odd= odd+count;
                    count+=2;
                }
                if(i == odd){
                    answer-=i;
                }
                else{
                    answer+=i;
                }
            }
    }
    return answer;
}
