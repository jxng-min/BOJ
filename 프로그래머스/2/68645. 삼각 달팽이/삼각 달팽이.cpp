#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> solution(int n) 
{
    vector<vector<int>> vec(n, vector<int>(n, 0));
    
    int r = 0;
    int c = 0;
    int num = 1;
    for(int i = 0; i < n; i++)
    {
        int turn = i % 3;
        switch(turn)
        {
        case 0:
            while(r < n && vec[r][c] == 0)
                vec[r++][c] = num++;
            r--;
            c++;
            break;

        case 1:
            while(c < n && vec[r][c] == 0)
                vec[r][c++] = num++;
            r--;
            c -= 2;
            break;

        case 2:
            while(r >= 0 && c >= 0 && vec[r][c] == 0)
                vec[r--][c--] = num++;
            r += 2;
            c++;
            break;

        }
    }
    
    vector<int> answer;
    for (int i = 0; i < n; i++)
        copy(vec[i].begin(), vec[i].begin() + (i + 1), back_inserter<vector<int>>(answer));
    
    return answer;
}