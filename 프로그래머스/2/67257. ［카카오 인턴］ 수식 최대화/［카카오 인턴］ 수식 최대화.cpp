#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> operator_priority_vec = 
{
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
};

long long Operation(int index, long long operand1, long long operand2)
{
    if(index == 0)
        return operand1 + operand2;
    else if(index == 1)
        return operand1 - operand2;
    else
        return operand1 * operand2;
}

long long GetOperationValue(int rep, const string& expression)
{
    stack<long long> operand_stack;
    stack<int> operator_stack;
    string temp_string;
    
    for(const char ch : expression)
    {
        if('0' <= ch && ch <= '9')
        {
            temp_string += ch;
        }
        else
        {
            operand_stack.push(stoll(temp_string));
            temp_string.clear();
            
            int operator_index = -1;
            switch(ch)
            {
            case '+':
                operator_index = 0; break;
                    
            case '-':
                operator_index = 1; break;
            
            case '*':
                operator_index = 2; break;
            }
            
            while(operand_stack.size() >= 2 &&
                  !operator_stack.empty() && 
                  operator_priority_vec[rep][operator_stack.top()] >= operator_priority_vec[rep][operator_index])
            {
                long long operand2 = operand_stack.top();
                operand_stack.pop();

                long long operand1 = operand_stack.top();
                operand_stack.pop();

                operand_stack.push(Operation(operator_stack.top(), operand1, operand2));
                operator_stack.pop();
            }
            
            operator_stack.push(operator_index);
        }
    }
    
    operand_stack.push(stoll(temp_string));
    while(!operator_stack.empty())
    {
        long long operand2 = operand_stack.top();
        operand_stack.pop();
        
        long long operand1 = operand_stack.top();
        operand_stack.pop();
        
        operand_stack.push(Operation(operator_stack.top(), operand1, operand2));
        operator_stack.pop();
    }
    
    
    cout << abs(operand_stack.top()) << endl; 
    return abs(operand_stack.top());
}


long long solution(string expression) 
{
    long long answer = 0;
    
    for(vector<vector<int>>::size_type i = 0; i < operator_priority_vec.size(); i++)
        answer = max(answer, GetOperationValue(i, expression));
    
    return answer;
}