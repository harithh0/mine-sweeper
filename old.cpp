#include <iostream>

const int LENGTH = 11;

struct Tile
{
    bool mine = false;
    bool revealed = true;
    int number = 0;
};

void printField(Tile field[][LENGTH])
{
    // IN THE END, I AND J WILL START AT 1 AND BOTH GO TO LENGTH-1
    int i = 1, j = 1;
    for (i = 0; i < LENGTH - 1; i++)
    {
        for (j = 0; j < LENGTH - 1; j++)
        {
            /*
            if (!field[i][j].revealed)
            {
                std::cout << "*";
            }
            else if (field[i][j].number == 0)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << field[i][j].number;
            }
            */

            if (field[i][j].mine)
            {
                std::cout << "M";
            }
            if (field[i][j].number == 0)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << field[i][j].number;
            }
        }

        std::cout << std::endl;
    }
}

void generateMines(Tile field[][LENGTH])
{
    int randNum = 0, i = 1, j = 1;
    for (i = 1; i < LENGTH - 1; i++)
    {
        for (j = 1; j < LENGTH - 1; j++)
        {
            randNum = rand() % 5 + 1;
            if (randNum == 1)
            {
                field[i][j].mine = true;
            }
        }
    }
}

void generateNums(Tile field[][LENGTH])
{
    int mineCount = 0, i = 1, j = 1, check = 0;
    for (i = 1; i < LENGTH - 1; i++)
    {
        for (j = 1; j < LENGTH - 1; j++)
        {
            // Check the EIGHT surrounding tiles, increase count if it is a mine
            for (check = 0; check < 9; check++)
            {
                if (field[(i - 1) + (check / 3)][(j - 1) + (check % 3)].mine)
                    mineCount++;
            }

            field[i][j].number = mineCount;
            mineCount = 0;
        }
    }
}

void selectTile(Tile field[][LENGTH]);

int main()
{
    srand(time(0));

    Tile field[LENGTH][LENGTH];
    generateMines(field);
    generateNums(field);
    printField(field);

    return 0;
}