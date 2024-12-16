#include <iostream>
#include <ctime>

typedef struct
{
    bool hasPassed = false;
    char val[2];
} square;

typedef struct
{
    bool hasPassed;
    double val;
} player;

void assignValue(square *field)
{
    char math_op = "+-*/"[rand() % 4];
    int randomNumber = (rand() % 10);
    field->val[0] = math_op;
    field->val[1] = randomNumber + '0' ;
}

int main()
{
    srand(time(0));

    int n = 0, m = 0;

    std::cout << "Enter the size of the matrix: ";
    while (n < 4 || m < 4)
    {
        std::cin >> n >> m;
        if (n < 4 && m < 4)
        {
            std::cout << "Both n and m are less than 4, the minimum requirement is 4!\n";
            continue;
        }
        if (n < 4)
        {
            std::cout << "n is less than 4\n";
        }
        if (m < 4)
        {
            std::cout << "m is less than 4\n";
        }
    }

    square field[n][m];
    for (int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            for (int j = 1; j < m; j++)
            {
                assignValue(&field[i][j]);
            }
        }
        else
        {
            if(i == n - 1)
            {
               for (int j = 0; j < m-1; j++)
                {
                    assignValue(&field[i][j]);
                };
            }
            else
            {
                for (int j = 0; j < m; j++)
                {
                    assignValue(&field[i][j]);
                }
            }
        };
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << "[" << field[i][j].val[0] << field[i][j].val[1] << "] ";
        }
        std::cout << '\n';
    }
    return 0;
}
