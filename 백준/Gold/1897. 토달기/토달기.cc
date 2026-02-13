#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

static vector<string> V;
static set<string> visited;
static set<char> S;
static queue<string> Q;

static int max_length;
static string answer;

void BFS(string word);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int d = 0;
    string word;
    cin >> d >> word;

    V.resize(d);
    for(int i = 0; i < d; i++)
    {
        cin >> V[i];
        for(const char ch : V[i])
            S.insert(ch);
    }

    BFS(word);
    cout << answer;
}

void BFS(string word)
{
    Q.push(word);
    max_length = word.size();
    answer = word;
    visited.insert(word);

    while(!Q.empty())
    {
        string current_word = Q.front();
        Q.pop();

        for(int i = 0; i <= current_word.size(); i++)
        {
            for(auto iter = S.begin(); iter != S.end(); iter++)
            {
                string new_word = current_word;
                new_word.insert(i, 1, *iter);
                
                auto find_iter = find(V.begin(), V.end(), new_word);
                if(find_iter == V.end())
                    continue;

                auto visit_result = visited.insert(new_word);
                if(!visit_result.second)
                    continue;

                if(max_length < new_word.size())
                    answer = new_word;

                Q.push(new_word);
            }
        }
    }
}