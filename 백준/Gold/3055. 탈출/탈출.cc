//백준 3055, 탈출

#include <iostream>
#include <queue>

int R, C;
int grid[51][51];

int distD[51][51];
int distW[51][51];

bool visitD[51][51];
bool visitW[51][51];

std::queue<std::pair<int, int>> qD;
std::queue<std::pair<int, int>> qW;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfsW(){
    while(!qW.empty()){
        auto curr = qW.front(); qW.pop();
        for(int k{0}; k<4; ++k){
            int nx = curr.first + dx[k];
            int ny = curr.second + dy[k];
            if(nx >= R || nx < 0 || ny >= C || ny < 0) continue;
            if(visitW[nx][ny] || grid[nx][ny] == 'X' || grid[nx][ny] == 'D') continue;
            qW.push({nx, ny});
            distW[nx][ny] = distW[curr.first][curr.second] + 1;
            visitW[nx][ny] = true;
        }
    }
}


void bfsD(){
    while(!qD.empty()){
        auto curr = qD.front(); qD.pop();
        for(int k{0}; k<4; ++k){
            int nx = curr.first + dx[k];
            int ny = curr.second + dy[k];
            if(nx >= R || nx < 0 || ny >= C || ny < 0) continue;
            if(visitD[nx][ny] || grid[nx][ny] == '*' || grid[nx][ny] == 'X') continue;
            if(distW[nx][ny] != 0 && distW[nx][ny] <= distD[curr.first][curr.second]+1) continue;
            qD.push({nx, ny});
            distD[nx][ny] = distD[curr.first][curr.second] + 1;
            visitD[nx][ny] = true;
        }
    }
}

int main (){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int x, y;
    std::cin >> R >> C;

    for(int i{0}; i<R; ++i){
        std::string s;
        std::cin >> s;
        for(int j{0}; j<C; ++j){
            grid[i][j] = s[j];
            if(grid[i][j] == '*'){
                qW.push({i, j});
                distW[i][j] = 1;
                visitW[i][j] = true;
            }
            else if(grid[i][j] == 'S'){
                qD.push({i, j});
                distD[i][j] = 1;
                visitD[i][j] = true;
            }
            else if(grid[i][j] == 'D'){
                x = i;
                y = j;
            }
        }
    }

    bfsW();
    bfsD();

    if(distD[x][y] == 0) std::cout << "KAKTUS";
    else std::cout << distD[x][y]-1;

    return 0;
}