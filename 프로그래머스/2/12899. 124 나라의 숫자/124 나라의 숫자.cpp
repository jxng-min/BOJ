#include <string>
#include <vector>

using namespace std;

string solution(int n) 
{
    vector<char> char_map = {'4', '1', '2'};
    
    string answer = "";
    int mod = 0;
    while(n > 0)
    {
        mod = n % 3;
        n /= 3;
        
        if(mod == 0)
            n -= 1;
        
        answer = char_map[mod] + answer;
    }
    
    return answer;
}