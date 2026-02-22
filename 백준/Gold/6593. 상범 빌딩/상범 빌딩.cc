#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct vector3
{
    int l;
    int r;
    int c;
    int t;

    vector3(int _l = 0, int _r = 0, int _c = 0, int _t = 0)
        : l(_l), r(_r), c(_c), t(_t)
    {}

    bool operator==(const vector3& v)
    {
        if(l == v.l && r == v.r && c == v.c)
            return true;

        return false;
    }
};

vector<vector<vector<char>>> G;
vector<vector<vector<bool>>> V;

int L = 0, R = 0, C = 0;
vector3 s;
vector3 e;

int dl[] = {-1, 0, 0, 0, 0, 1};
int dr[] = {0, -1, 0, 0, 1, 0};
int dc[] = {0, 0, -1, 1, 0, 0};

void BFS(vector3 start);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true)
    {
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0)
            break;

        G.assign(L + 1, vector<vector<char>>(R + 1, vector<char>(C + 1)));
        V.assign(L + 1, vector<vector<bool>>(R + 1, vector<bool>(C + 1)));

    string line;
    getline(cin, line);

    for (int l = 1; l <= L; l++) 
    {
        for (int r = 1; r <= R; r++) 
        {
            getline(cin, line);
            if (line.empty()) 
            { 
                r--; 
                continue; 
            }

            for (int c = 1; c <= C; c++) 
            {
                G[l][r][c] = line[c - 1];

                if (G[l][r][c] == 'S') 
                    s = vector3(l, r, c);
                if (G[l][r][c] == 'E') 
                    e = vector3(l, r, c);
            }
        }
        getline(cin, line);
    }

        BFS(s);
    }
}

void BFS(vector3 s)
{
    queue<vector3> q;
    s.t = 0;
    q.push(s);
    V[s.l][s.r][s.c] = true;

    while(!q.empty())
    {
        vector3 current = q.front();
        q.pop();

        if(current == e)
        {
            cout << "Escaped in " << current.t << " minute(s)." << '\n';
            return;
        }

        for(int dir = 0; dir < 6; dir++)
        {
            int nl = current.l + dl[dir];
            int nr = current.r + dr[dir];
            int nc = current.c + dc[dir];

            if(nl < 1 || nl > L || nr < 1 || nr > R || nc < 1 || nc > C)
                continue;

            if(G[nl][nr][nc] == '#' || V[nl][nr][nc])
                continue;

            q.push(vector3(nl, nr, nc, current.t + 1));
            V[nl][nr][nc] = true;
        }
    }

    if(!V[e.l][e.r][e.c])
        cout << "Trapped!" << '\n';
}