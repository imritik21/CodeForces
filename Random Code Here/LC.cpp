int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
{
    map<int, int> mpx;
    for (auto ele : obstacles)
    {
        mpx[ele[0]]++;
    }
    map<int, int> mpy;
    for (auto ele : obstacles)
    {
        mpy[ele[1]]++;
    }
    long long dist = 0;
    int x = 0, y = 0;
    int n = commands.size();
    int dir = 1; // 1=N , 2=E, 3=S, 4=W
    int maxX = INT_MIN;
    int maxY = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (commands[i] == -2)
        { // move only left
            dir = (dir - 1) % 4;
        }
        else if (commands[i] == -1)
        { // move only right
            dir = (dir + 1) % 4;
        }
        else
        {
            if (dir == 1)
            {
                int j = y;
                if (mpx[x])
                {
                    for (; j <= y + commands[i]; j++)
                    {
                        if (mpy[j] == 1)
                            break;
                    }
                    y += (j - 1);
                }
                else
                    y += commands[i];

                maxY = max(maxY, y);
            }
            else if (dir == 2)
            {
                int j = x;
                if (mpy[y])
                {
                    for (; j <= x + commands[i]; j++)
                    {
                        if (mpx[j] == 1)
                            break;
                    }
                    x += (j - 1);
                }
                else
                    x += commands[i];

                maxX = max(maxX, x);
            }
            else if (dir == 3)
            {
                int j = y;
                if (mpx[x])
                {
                    for (; j >= y - commands[i]; j--)
                    {
                        if (mpy[j] == 1)
                            break;
                    }
                    y -= (j + 1);
                }
                else
                    y -= commands[i];

                maxY = max(maxY, y);
            }
            else
            {
                int j = x;
                if (mpy[y])
                {
                    for (; j >= x - commands[i]; j++)
                    {
                        if (mpx[j] == 1)
                            break;
                    }
                    x -= (j + 1);
                }
                else
                    x -= commands[i];

                maxX = max(maxX, x);
            }
        }
    }
    if (maxX == INT_MIN)
        maxX = 0;
    if (maxY == INT_MIN)
        maxY = 0;
    cout << maxX << " " << maxY << endl;
    cout << x << " " << y;
    dist = abs(maxX * maxX);
    dist += abs(maxY * maxY);
    return dist;
}