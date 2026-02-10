#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Room
{
    char type;
    int money;
    vector<int> next;
};

static vector<Room> graph;
static vector<bool> visited;
static queue<int> que;

static int current_money;

static int n = 0;

void BFS(int v);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<string> answers;

    while(true)
    {
        cin >> n;
        if(n == 0)
            break;

        graph.clear();
        visited.clear();

        graph.resize(n + 1);
        visited.resize(n + 1);

        que = queue<int>();
        current_money = 0;

        for(int i = 1; i <= n; i++)
        {
            cin >> graph[i].type >> graph[i].money;

            int next_room;
            while(true)
            {
                cin >> next_room;
                if(next_room == 0)
                    break;

                graph[i].next.push_back(next_room);
            }
        }
        
        BFS(1);
        answers.push_back(visited[n] ? "Yes" : "No");     
    }

    for(const string& answer : answers)
        cout << answer << '\n';
}

void BFS(int v)
{
    que.push(v);

    while(!que.empty())
    {
        int r_idx = que.front();
        que.pop();

        Room room = graph[r_idx];

        switch(room.type)
        {
        case 'L':
            current_money = max(current_money, room.money);
            break;

        case 'T':
            if(current_money < room.money)
                continue;

            current_money -= room.money;
            break;

        default:
            break;
        }

        visited[r_idx] = true;
        if(r_idx != n)
        {
            for(int n : room.next)
                if(!visited[n])
                    que.push(n);
        }
    }
}