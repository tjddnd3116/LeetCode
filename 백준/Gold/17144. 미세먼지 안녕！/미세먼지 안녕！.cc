#include<iostream>
#include<cstring>
 
#define endl "\n"
#define MAX 50
using namespace std;
 
int R, C, T, Answer;
int MAP[MAX][MAX];
int C_MAP[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
pair<int, int> Air_Cleaner[2];
 
void Input()
{
    cin >> R >> C >> T;
    int Idx = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == -1)
            {
                Air_Cleaner[Idx].first = i;
                Air_Cleaner[Idx].second = j;
                Idx++;
            }
        }
    }
}
 
void Print()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (MAP[i][j] == -1) cout << "- ";
            else cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
    cout << "######################################################" << endl;
}
 
void Copy_MAP(int A[][MAX], int B[][MAX])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            A[i][j] = B[i][j];
        }
    }
}
 
void Dust_Expansion()
{
    Copy_MAP(C_MAP, MAP);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (MAP[i][j] != 0 && MAP[i][j] != -1)
            {
                int Cnt = 0;
                int Value = MAP[i][j] / 5;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
 
                    if (nx >= 0 && ny >= 0 && nx < R && ny < C)
                    {
                        if (MAP[nx][ny] != -1)
                        {
                            C_MAP[nx][ny] = C_MAP[nx][ny] + Value;
                            Cnt++;
                        }
                    }
                }
                C_MAP[i][j] = C_MAP[i][j] - (Cnt * Value);
            }
        }
    }
    Copy_MAP(MAP, C_MAP);
}
 
void Move_Dust()
{
    for (int Idx = 0; Idx < 2; Idx++)
    {
        if (Idx == 0)
        {
            // 1. 공기청정기 위에서부터 (0, 0)까지 모든 값 떙겨주기
            for (int i = Air_Cleaner[Idx].first - 1; i > 0; i--)
            {
                MAP[i][0] = MAP[i - 1][0];
            }
            // 2. 가장 윗줄 땡겨주기
            for (int i = 0; i < C - 1; i++)
            {
                MAP[0][i] = MAP[0][i + 1];
            }
            // 3. 반대편 세로라인 땡겨주기
            for (int i = 1; i <= Air_Cleaner[Idx].first; i++)
            {
                MAP[i - 1][C - 1] = MAP[i][C - 1];
            }
            // 4. 공기청정기 라인 땡겨주기
            for (int i = C - 1; i > 1; i--)
            {
                MAP[Air_Cleaner[Idx].first][i] = MAP[Air_Cleaner[Idx].first][i - 1];
            }
            MAP[Air_Cleaner[Idx].first][1] = 0;
        }
        else
        {
            for (int i = Air_Cleaner[Idx].first + 1; i < R - 1; i++)
            {
                MAP[i][0] = MAP[i + 1][0];
            }
            for (int i = 0; i < C - 1; i++)
            {
                MAP[R - 1][i] = MAP[R - 1][i + 1];
            }
            for (int i = R - 1; i >= Air_Cleaner[Idx].first; i--)
            {
                MAP[i][C - 1] = MAP[i - 1][C - 1];
            }
            for (int i = C - 1; i > 1; i--)
            {
                MAP[Air_Cleaner[Idx].first][i] = MAP[Air_Cleaner[Idx].first][i - 1];
            }
            MAP[Air_Cleaner[Idx].first][1] = 0;
        }
    }
}
 
int Count_Dust()
{
    int Sum = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (MAP[i][j] == -1) continue;
            Sum = Sum + MAP[i][j];
        }
    }
    return Sum;
}
 
void Solution()
{
    for (int i = 0; i < T; i++)
    {
        Dust_Expansion();
        Move_Dust();
    }
    
    Answer = Count_Dust();
}
 
void Solve()
{
    Input();
    Solution();
    cout << Answer << endl;
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}