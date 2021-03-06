// Snake.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Snake.h"

int Move_flag = 0;


int main()
{
	//初始化随机种子
	srand((unsigned int)time(NULL));
	//初始化
	InitSnake(3);

	//按键之前  移动+绘图（循环）

	while (1)
	{
		while (!_kbhit())  //如果没有按键按下
		{
			if (food.flag == 0)
			{
				CoorFood();
			}
			
			cleardevice();
			MoveSnake();
			DrawSnake();
			DrawFood();
			EatFood();
			Sleep(90);
		}
		ChangeSnakeCh();
	}
	return 0;
}

//initial snake
void InitSnake(int size)    //size为蛇的节数
{
	initgraph(640, 480);   //初始化窗口

	 //初始化音乐
	mciSendString(L"", 0, 0, 0);  //声卡驱动发送string
	mciSendString(L"", 0, 0, 0); 

	snake.n = size;
	//snake.ch = right;
	for (int i = 0; i < snake.n; i++)
	{
		snake.szb[i].x = (snake.n - i) * 10;
		snake.szb[i].y = 0;
	}
}

void DrawSnake()
{
	setlinecolor(RED);		//设置线条颜色色
	setfillcolor(RED);		//设置蛇的正方形的填充颜色

	for (int i = 0; i < snake.n; i++)
	{
		fillrectangle(snake.szb[i].x, snake.szb[i].y,
			snake.szb[i].x + 10, snake.szb[i].y + 10);  //填充矩形类型
	}

}

void MoveSnake()   //移动蛇
{
	// right x+=10
	//left x-=10
	//up y -= 10
	//down y+=10
	if (Move_flag == 1)
	{
		for (int i = snake.n - 1; i > 0; i--)
		{
			snake.szb[i].x = snake.szb[i - 1].x;
			snake.szb[i].y = snake.szb[i - 1].y;
		}
	}
	switch (snake.ch)
	{
	case up:
		snake.szb[0].y -= 10;
		break;
	case down:
		snake.szb[0].y += 10;
		break;
	case right:
		snake.szb[0].x += 10;
		break;
	case left:
		snake.szb[0].x -= 10;
		break;
	default:
		break;
	}
}

void ChangeSnakeCh()
{
	int move;
	move = _getch();
	
	switch (move)
	{
	case up:             //改变蛇的方向
		if (snake.ch != down)
			snake.ch = up;
		break;
	case down:
		if(snake.ch != down)
			snake.ch = down;
		break;
	case left:
		if(snake.ch != right)
			snake.ch = left;
		break;
	case right:
		if(snake.ch != left)
			snake.ch = right;
		break;
	default:
		break;
	}
	Move_flag = 1;
}

//绘制食物的坐标
void CoorFood()
{
	food.fzb.x = rand() % 64*10;
	food.fzb.y = rand() % 48*10;

	food.flag = 1;
}

//绘制食物
void DrawFood()
{
	setlinecolor(GREEN);
	setfillcolor(GREEN);
	fillroundrect(food.fzb.x,food.fzb.y,
		food.fzb.x+10,food.fzb.y+10,10,10);
}

//吃到食物
void EatFood()
{
	if (snake.szb[0].x == food.fzb.x && snake.szb[0].y == food.fzb.y)
	{
		snake.n++;

		food.flag = 0;
		
	}
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
