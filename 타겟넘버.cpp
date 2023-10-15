#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> numbers, int target){
    //모든 값을 더하고 타겟값과의 차를 구해서 순열로 나오는 경우를 확인
    int sum = 0;
    for(int i = 0;i < numbers.size();i++){
        sum+=numbers[i];
    }
    
    sum = (sum - target) / 2;
    stable_sort(numbers.begin(),numbers.end());
    
    int answer = 0;
    
    for (int i = 1; i <= numbers.size(); i++) {
		vector<bool> v(numbers.size() - i, false);
		v.insert(v.end(),i, true);
    do {
        int check = 0;
        for(int i = 0;i < numbers.size();i++){
            if(v[i]){
            check+=numbers[i];
            }
        }
        if(check == sum){
            answer++;
        }
    }while (next_permutation(v.begin(), v.end()));
    }

    return answer;
}