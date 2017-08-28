/*********************
*****最简单贪吃蛇****
-------------------------------------
****by_啊o额iu鱼****
********************/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define H 15
#define W 30
#define N 10
void move();
void start();
void draw();
void getturn();
void turn(char direction);
void judge();
void getfood();
void over();
int a, b, x, y, l = 0, n, i, j;
int x1, y1;
char *head, *tail, *tt, map[H][W];
char *belly[H * W], *food;
char left, right, front, back;
int main()
{
	start();
}

void start()
{
	for (i = 0; i != H; ++i)
		for (j = 0; j != W; ++j)
		{
			if ((i == 0) || (i == H - 1) || (j == 0) || (j == W - 1))
				map[i][j] = '9';
			else
				map[i][j] = '0';
		}
	x = W / 2, y = H / 2;
	head = &map[y][x + 1];
	belly[l] = &map[y][x];
	tail = &map[y][x - 1];
	*head = '1';
	*belly[0] = '2';
	*tail = '3';
	left = 'w', right = 's';
	front = 'd', back = 'a';
	turn(front);
	getfood();
		draw();
	while (1)
	{
		usleep(1000000/N);
		getturn();
		move();
		judge();
		clrscr();
		draw();
	}
}

void getturn()
{
	char t, t1;
	while (kbhit())
	{
		t = getch();
		if (t == left)
		{
			turn(left);
			left = back;
			back = right;
			right = front;
			front = t;
			goto gett;
		}
		else if (t == right)
		{
			turn(right);
			right = back;
			back = left;
			left = front;
			front = t;
			goto gett;
		}
	}
	turn(front);
  gett:;
	while (kbhit())
		t = getch();
}

void getfood()
{
	do
	{
		x1 = random() % (W - 2) + 1;
		y1 = random() % (H - 2) + 1;
	}
	while (map[y1][x1] != '0');
	food = &map[y1][x1];
	*food = '4';
}

void turn(char direction)
{
	switch (direction)
	{
	case 'w':
		--y;
		break;
	case 's':
		++y;
		break;
	case 'a':
		--x;
		break;
	case 'd':
		++x;
		break;
	}

}

void move()
{
	tt = belly[l];
	for (i = l; i != 0; --i)
		belly[i] = belly[i - 1];
	belly[0] = head;
	head = &map[y][x];
	*belly[0] = '2';
}

void judge()
{
	switch (*head)
	{
	case '2':;
	case '9':
		over();
		break;
	case '4':
		getfood();
		++l;
		belly[l] = tt;
		break;
	case '0':
		*head = '1';
		*tail = '0';
		tail = tt;
		*tail = '3';
		break;
	}
}

void draw()
{
	for (i = 0; i != H; ++i)
	{
		for (j = 0; j != W; ++j)
			switch (map[i][j])
			{
			case '0':
				printf(" ");
				break;
			case '9':
				printf("#");
				break;
			case '1':
				printf("O");
				break;
			case '2':
				printf("o");
				break;
			case '3':
				printf(".");
				break;
			case '4':
				printf("♥");
				break;
			}
		printf("\n");
	}
}

void over()
{
	printf("\tGame over!!!\n");
	printf("\t\tAgain?\n");
	getch();
	clrscr();
	start();
} 