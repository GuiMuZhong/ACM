int N, M;
char field[110][110];

void DFS(int sx, int sy)
{
    int dx, dy, x, y;

    field[sx][sy] = '.';

    for (dx = -1; dx <= 1; dx++)
    {
        for (dy = -1; dy <= 1; dy++)
        {
            x = sx + dx;
            y = sy + dy;
            if (x >= 0 && x < N && y >= 0 && y < M && field[x][y] == 'W')
            {
                DFS(x, y);
            }
        }
    }
}
