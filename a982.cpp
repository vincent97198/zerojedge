#include <iostream>
#include <cstring>

using namespace std;

void setMap();
void play(int X, int Y);

int N;
int laby_minLen[101][101];
char build;

int main()
{
    while(cin >> N)
    {
        setMap();
        laby_minLen[2][2] = 1;
        play(2, 2);
        if(laby_minLen[N-1][N-1])
            cout << laby_minLen[N-1][N-1] << endl;
        else
            cout << "No solution!\n";
    }
}

void setMap()
{
    memset(laby_minLen, 0, sizeof(laby_minLen));
    for(int i = 1; i<=N; i++)
        for(int j = 1; j<=N; j++)
        {
            cin >> build;
            if(build == '#')
                laby_minLen[i][j] = -1;
            else
                laby_minLen[i][j] = 0;
        }
}


void play(int X, int Y)
{
    if(Y>1)
        if(laby_minLen[Y-1][X] == 0 || laby_minLen[Y-1][X] > laby_minLen[Y][X]+1)
        {
            laby_minLen[Y-1][X] = laby_minLen[Y][X]+1;
            play(X,Y-1);
        }


    if(Y<N)
        if(laby_minLen[Y+1][X]==0 || laby_minLen[Y+1][X]>laby_minLen[Y][X]+1 )
        {
            laby_minLen[Y+1][X] = laby_minLen[Y][X]+1;
            play(X,Y+1);
        }


    if(X>1)
        if(laby_minLen[Y][X-1]==0 || laby_minLen[Y][X-1]>laby_minLen[Y][X]+1)
        {
            laby_minLen[Y][X-1] = laby_minLen[Y][X]+1;
            play(X-1,Y);
        }


    if(X<N)
        if(laby_minLen[Y][X+1]==0 || laby_minLen[Y][X+1] > laby_minLen[Y][X] + 1)
        {
            laby_minLen[Y][X+1] = laby_minLen[Y][X]+1;
            play(X+1,Y);
        }
}
