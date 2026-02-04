#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) 
{
    int answer = 1;
    
    for(int i = 1; i < n / 2 + 1; i++)
    {
        int temp_sum = 0;
        int last_num = i;
        while(n - temp_sum >= last_num)
        {
            temp_sum += last_num;
            last_num++;
        }
        
        answer = temp_sum == n ? answer + 1 : answer;
    }
    
    return answer;
}