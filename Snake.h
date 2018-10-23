#pragma once

#include "graphics.h"
#include "conio.h"
#include <mmsystem.h>
#include <time.h>
#include <stdlib.h>
#pragma comment(lib,"winmm.lib")

#define SNAKE_LENGTH 500

enum Ch    //方向
{
	up = 72,
	down = 80,
	left = 75,
	right = 77
};

struct Coor   //坐标
{
	int x;
	int y;
};

struct Snake   //蛇的属性
{
	int n;   //一条蛇油多少节
	struct Coor szb[SNAKE_LENGTH];   //定义最长500节，存放蛇的坐标；
	Ch ch; //蛇的方向

}snake;

struct Food
{
	Coor fzb;   //食物坐标同一时间只有一个
	int flag;	//食物是否被吃
}food;

void InitSnake(int size);
void DrawSnake();
void MoveSnake();
void ChangeSnakeCh();
void DrawFood();
void EatFood();
void CoorFood();