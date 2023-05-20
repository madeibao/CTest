
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
void reset(char arr[ROW][COL])//将棋盘arr[ROW][COL]数据赋值为空格
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void dis_play(char arr[ROW][COL])//打印棋盘
{
	for (int i = 0; i < ROW; i++)//for每一次进去，打印一行数组和一条分割线
	{	                         //数组行为:（空格）元素（空格）|（空格）元素（空格）|（空格）元素（空格）
		                         //分割线为： -      -      -   |   -      -     -   |   -     -      -
  		for (int j = 0; j < COL; j++)//一行数组
		{
			printf(" %c ", arr[i][j]);
			if (j < COL - 1)//为了美观，最后的“|”不打印
			{
				printf("|");
			}

		}
		printf("\n");
		for (int k = 0; k < COL; k++)//一行分割线
		{
			printf("---");
			if (k < COL - 1)//为了美观，最后的“|”不打印
			{
				printf("|");
			}

		}
		printf("\n");
	}

}

void player_move(char arr[ROW][COL])//玩家下棋
{
	int row = 0, col = 0;

	while (1)
	{
		printf("玩家下棋，请输入坐标>:");
		scanf("%d %d", &row, &col);
		if (arr[row - 1][col - 1] == ' ')//判断是否可以下棋
		{
			arr[row - 1][col - 1] = '*';
			break;
		}
		printf("输入错误，请再次输入\n");

	}
}



void computer_move(char arr[ROW][COL])//电脑下棋
{
	int row = rand() % ROW;//生成行号
	int col = rand() % COL;//生成列标
	printf("电脑下棋:>\n");
	while (1)
	{

		if (arr[row][col] == ' ')//判断是否可以下棋
		{
			arr[row][col] = '#';
			break;
		}
		row = rand() % ROW;
		col = rand() % COL;

	}
}
int is_full(char arr[ROW][COL])//用于在is_win（）中判断是否为平局
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}

	}
	return 1;
}

char is_win(char arr[ROW][COL])//三子棋胜利无非就三种情况：行相同、列相同和对角线相同。除开胜利还有平局
{
	for (int i = 0; i < ROW; i++)//判断行
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
			return arr[i][0];
	}
	for (int i = 0; i < COL; i++)//判断列
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
			return arr[0][i];
	}
	//判断对角线
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
		return arr[0][0];
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' ')
		return arr[0][2];

	//判断平局
	if (is_full(arr))
	{
		return 'q';
	}

	//都不满足游戏继续运行 return ‘c’
	return 'c';
}


void meau()
{
	printf("------------------\n");
	printf("|     1.play     |\n");
	printf("|----------------|\n");
	printf("|     0.exit     |\n");
	printf("------------------\n");
}

void game()
{
	char arr[ROW][COL];//初始化棋盘
	char ch;
	reset(arr);//将棋盘里每一个元素赋值为空格
	dis_play(arr);
	do
	{

		player_move(arr);
		dis_play(arr);
		ch=is_win(arr);
		if (ch != 'c')
		{
			break;
		}

		computer_move(arr);
		dis_play(arr);
		ch=is_win(arr);
		if (ch != 'c')
		{
			break;
		}

	} while (1);
	switch (ch)//根据返回字符判断结果
	{
	case '#':
		printf("电脑胜利\n"); break;
	case '*':
		printf("玩家胜利\n"); break;
	case 'q':
		printf("平局\n"); break;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		meau();
		scanf("%d", &input);
		switch (input)
		{
		case 1 :
			game(); break;
		case 0 :
			break;
		default :
			printf("输入错误\n");
		}
	} while (input);

	return 0;
}
