#include <string>
#include <vector>
#include<iostream>

using namespace std;

string ttn(int a,int b){
    char number[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string num = "";
    while(a/b != 0){  //16 % 16 
        num = number[a % b] + num;
        a /= b;
    }
    num  = number[a % b] + num;
    return num;
}

string solution(int n, int t, int m, int p){
    string allnum = "";
    string answer = "";
    int i = 0;
    while(allnum.size() <= t*m){
        allnum+=ttn(i,n);
        i++;
    }
    cout<<allnum<<endl;
    int count=0;
    for(int i=0;i< allnum.size();i++){
        if(count==t) 
            break;
        if(i%m+1 == p){
            answer+= allnum[i];
            count++;
        }
    }
    return answer;
}