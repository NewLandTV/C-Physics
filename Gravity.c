#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define GRAVITY 9.81
#define FLOOR_Y 50

typedef struct _Vector2
{
	int x;
	int y;
} Vector2;

void Init();
void Gotoxy(int x, int y);

int main(void)
{
	Init();
	
	int i;
	float time = 0;
	
	Vector2 position = { 0, 0 };
	Vector2 position2 = { 100, 0 };
	Vector2 position3 = { 0, 100 };
	Vector2 position4 = { 100, 100 };
	
	for (i = 0; i < 100; i++)
	{
		Gotoxy(i, FLOOR_Y);
		printf("-");
	}
	
	while (1)
	{
		if (position.x + 1 != 100 && position2.x - 1 != 0 && position3.x + 1 != 100 && position4.x - 1 != 0)
		{
			position.x++;
			position2.x--;
			position3.x++;
			position4.x--;
		}
		else
		{
			position.x = 0;
			position2.x = 100;
			position3.x = 0;
			position4.x = 100;
			
			time = 0;
			
			Sleep(2000);
			
			system("cls");
			
			for (i = 0; i < 100; i++)
			{
				Gotoxy(i, FLOOR_Y);
				printf("-");
			}
		}
		
		position.y = 0;
		position2.y = 0;
		position3.y = FLOOR_Y - 1;
		position4.y = FLOOR_Y - 1;
		
		if (position.y + 0.5 * GRAVITY * time * time < FLOOR_Y && position2.y + 0.5 * GRAVITY * time * time < FLOOR_Y && position3.y - 0.5 * GRAVITY * time * time > 0 && position4.y - 0.5 * GRAVITY * time * time > 0)
		{
			position.y += 0.5 * GRAVITY * time * time;
			position2.y += 0.5 * GRAVITY * time * time;
			position3.y -= 0.5 * GRAVITY * time * time;
			position4.y -= 0.5 * GRAVITY * time * time;
			
			Gotoxy(position.x, position.y);
			printf("*");
			Gotoxy(position2.x, position2.y);
			printf("*");
			Gotoxy(position3.x, position3.y);
			printf("*");
			Gotoxy(position4.x, position4.y);
			printf("*");
		}
		
		time += 0.033333;
		
		Sleep(17);
	}
	
	return 0;
}

void Init()
{
	system("mode con cols=100 lines=60");
	
	CONSOLE_CURSOR_INFO consoleCursorInfo;
	
	consoleCursorInfo.bVisible = 0;
	consoleCursorInfo.dwSize = 1;
	
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
}

void Gotoxy(int x, int y)
{
	COORD position = { x, y };
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
