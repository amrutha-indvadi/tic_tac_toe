#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef enum
{
	O='O',
	X='X',
	Empty = ' '
};

char Board[3][3];
int CurrentPlayer = O;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Initialization()
{
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			Board[i][j] = Empty;
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void PrintBoard()
{
	printf("\n");
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			printf(" \033[47m\033[30m %c \033[0m ", Board[i][j]);
		}
		printf("\n\n");
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void WinCondition()
{
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if ((Board[1][1] == O && Board[1][2] == O && Board[1][3] == O) || (Board[2][1] == O && Board[2][2] == O && Board[2][3] == O) || (Board[3][1] == O && Board[3][2] == O && Board[3][3] == O) || (Board[1][1] == O && Board[2][2] == O && Board[3][3] == O) || (Board[1][3] == O && Board[2][2] == O && Board[3][1] == O))
			{
				printf("\' %c \' is the winner\n",O);
				exit(0);
			}

			if ((Board[1][1] == X && Board[1][2] == X && Board[1][3] == X) || (Board[2][1] == X && Board[2][2] == X && Board[2][3] == X) || (Board[3][1] == X && Board[3][2] == X && Board[3][3] == X) || (Board[1][1] == X && Board[2][2] == X && Board[3][3] == X) || (Board[1][3] == X && Board[2][2] == X && Board[3][1] == X))
			{
				printf("\' %c \' is the winner",X);
				exit(0);
			}
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main()
{
	int Row, Col;
	Initialization();

	while (1)
	{
		if (CurrentPlayer == O)
		{
			PrintBoard();

			printf("\n Player O's turn\n Enter axis: ");
			scanf("%d %d", &Row, &Col);

			if (Row >= 1 && Row <= 3 && Col >= 1 && Col <= 3)
			{
				if (Board[Row][Col] == Empty)
				{
					Board[Row][Col] = O;
					CurrentPlayer = X;
					system("cls");
					WinCondition();
				}
				else
					printf("Enter valid move\n");
			}
		}

		if (CurrentPlayer == X)
		{
			PrintBoard();

			printf("\n Player X's turn\n Enter axis: ");
			scanf("%d %d", &Row, &Col);

			if (Row >= 1 && Row <= 3 && Col >= 1 && Col <= 3)
			{
				if (Board[Row][Col] == Empty)
				{
					Board[Row][Col] = X;
					CurrentPlayer = O;
					system("cls");
					WinCondition();
				}
				else
					printf("Enter valid move\n");
			}
		}
	}
	return 0;
}