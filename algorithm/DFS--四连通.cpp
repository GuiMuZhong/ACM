int W, H;
char room[50][50];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void DFS(int sx, int sy)
{
    int i, x, y;

    room[sx][sy] = '#';

    for(i = 0; i < 4; i++)
    {
        x = sx + dx[i];
        y = sy + dy[i];
        if (x >= 0 && x < H && y >= 0 && y < W && room[x][y] == '.')
        {
            DFS(x, y);
        }
    }
}
