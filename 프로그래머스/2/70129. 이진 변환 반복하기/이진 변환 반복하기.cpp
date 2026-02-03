#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer = {0, 0};
    string temp_string = "";
    
    while(s != "1")
    {
        cout << s << endl;
        for(const char ch : s)
        {
            if(ch == '0')
                answer[1]++;
            else
                temp_string += ch;
        }
        
        int int_s = static_cast<int>(temp_string.size());
        int mod = 0;
        temp_string.clear();
        
        while(int_s > 0)
        {
            mod = int_s % 2;
            int_s /= 2;
            
            temp_string = to_string(mod) + temp_string;
        }
        
        s = temp_string;
        temp_string.clear();
        answer[0]++;
    }
    
    return answer;
}