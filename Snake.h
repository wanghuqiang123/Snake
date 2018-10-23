#pragma once

#include "graphics.h"
#include "conio.h"
#include <mmsystem.h>
#include <time.h>
#include <stdlib.h>
#pragma comment(lib,"winmm.lib")

#define SNAKE_LENGTH 500

enum Ch    //����
{
	up = 72,
	down = 80,
	left = 75,
	right = 77
};

struct Coor   //����
{
	int x;
	int y;
};

struct Snake   //�ߵ�����
{
	int n;   //һ�����Ͷ��ٽ�
	struct Coor szb[SNAKE_LENGTH];   //�����500�ڣ�����ߵ����ꣻ
	Ch ch; //�ߵķ���

}snake;

struct Food
{
	Coor fzb;   //ʳ������ͬһʱ��ֻ��һ��
	int flag;	//ʳ���Ƿ񱻳�
}food;

void InitSnake(int size);
void DrawSnake();
void MoveSnake();
void ChangeSnakeCh();
void DrawFood();
void EatFood();
void CoorFood();