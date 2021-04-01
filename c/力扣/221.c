#include <stdio.h>
int ssmin(int a, int b, int c)
{
    a = a < b ? a : b;
    c = c > a ? a : c;
    return c;
}
int maximalSquare(char matrix[][], int matrixSize)
{
    int n = matrixSize;
    int dp[n][n];
    int s = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || matrix[i][j] == "0")
            {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1;
            }
            else
                dp[i][j] = ssmin(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
            s = s > dp[i][j] ? s : dp[i][j];
        }
    return s;
}

int main()
{
    char a[5][5] = {{"1", "0", "1", "0", "0"}, {"1", "0", "1", "1", "1"}, {"1", "1", "1", "1", "1"}, {"1", "0", "0", "1", "0"}};
    printf("%d", maximalSquare(a, 5));
    return 0;
}
