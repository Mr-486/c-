# include<stdio.h>
# include<assert.h>
# include<stdlib.h>
# include<string.h>
# include<windows.h>
# pragma warning(disable:4996)
# define MAZEROW 10
# define MAZECOL 10
# define MAXSIZE 100

typedef struct Position
{
	int x;
	int y;
}PosType, * PPosType;

typedef struct
{
	PosType seat;
	int dir;
}SElemType;

typedef struct Stack
{
	SElemType data[MAXSIZE];
	int top;
}MazeStack, * pMazeStack;

void InitMazeStack(pMazeStack sm);
void PushStack(pMazeStack sm, SElemType data);
void PopStack(pMazeStack sm, SElemType * tmp);
int EmptyStack(pMazeStack sm);
void FootPrint(PosType curpos, char *p);
int MazePath(char maze[MAZEROW][MAZECOL], PosType start, PosType end);
void PrintMaze(char maze[MAZEROW][MAZECOL]);
void PrintPath(char maze[MAZEROW][MAZECOL]);
void PrintSeat(char maze[MAZEROW][MAZECOL]);
void Exploration(char maze[MAZEROW][MAZECOL], PosType start, PosType end);
void MarkPrint(PosType curpos, char *p);

int EmptyStack(pMazeStack sm)
{
	if(sm->top == -1)
	  return 1;
	else
	  return 0;
}

void InitMazeStack(pMazeStack sm)
{
	sm->top = -1;
}

void PushStack(pMazeStack sm, SElemType data)
{
	if(sm->top == MAXSIZE-1)
	 {
	 	printf("栈已满，不能入栈\n");
	 }
	else
	 {
	 	sm->top++;
	 	sm->data[sm->top] = data;
	 }
}

void PopStack(pMazeStack sm, SElemType *tmp)
{
	if(sm->top == -1)
	 {
	 	printf("栈空，不能出栈\n");
	 }
	else
	 {
	 	*tmp = sm->data[sm->top];
	 	sm->top--;
	 }
}

void FootPrint(PosType curpos, char *p)
{
	*(p+10 * curpos.x + curpos.y) = '$';
}

void MarkPrint(PosType curpos, char *p)
{
    *(p + 10*curpos.x + curpos.y) = '@';
}

PosType NextPos(PosType curpos, int dir)
{
	switch(dir)
	 {
	 	case 1:
	 		curpos.y++;
	 		break;
	 	case 2:
	 		curpos.x++;
	 		break;
	 	case 3:
	 		curpos.y--;
	 		break;
	 	case 4:
	 		curpos.x--;
	 		break;
	 	default:
	 		printf("参数有误！\n");
	 		break;
	 }
	return curpos;
}

int IsPass(PosType curpos, char maze[MAZEROW][MAZECOL])
{
	if(maze[curpos.x][curpos.y] == '0')
	 {
	 	return 1;
	 }
	else
	 {
	 	return 0;
	 }
}

int MazePath(char maze[MAZEROW][MAZECOL], PosType start, PosType end)
{
	MazeStack sm;
	InitMazeStack(&sm);
	PosType curpos = start;
	do
	 {
	 	if(IsPass(curpos, maze))
	 	 {
	 	 	FootPrint(curpos, &maze[0][0]);
	 	 	SElemType data;
	 	 	data.seat = curpos;
	 	 	data.dir = 1;
	 	 	PushStack(&sm, data);
	 	 	if(curpos.x == end.x && curpos.y == end.y)
	 	 	 {
	 	 	 	return 1;
			 }
			curpos = NextPos(curpos, 1);
		  }
		else
		 {
		 	if(!EmptyStack(&sm))
		 	 {
		 	 	SElemType data;
		 	 	PopStack(&sm, &data);
		 	 	while(data.dir == 4 && !EmptyStack(&sm))
		 	 	  {
		 	 	  	MarkPrint(data.seat, &maze[0][0]);
		 	 	  	PopStack(&sm, &data);
				  }
			    if(data.dir<4)
				  {
				  	data.dir++;
				  	PushStack(&sm, data);
				  	curpos = NextPos(data.seat, data.dir);
				  } 
			 }
		 }
	  printf("----------------------------------\n");
	  printf("开始探索迷宫：（‘$’代表路径，‘@’代表探索过但是不通的地方）\n");
	  printf("----------------------------------\n");
	  PrintMaze(maze);
	  Sleep(1000);
	  //system("cls");
	 }while (!EmptyStack(&sm));
	 return 0;
}

void PrintMaze(char maze[MAZEROW][MAZECOL])
{
	int i = 0;
	for (i = 0; i< MAZEROW; i++)
	 {
	 	int j = 0;
	 	for (j = 0; j < MAZECOL; j++)
	    {
	    	printf("%c", maze[i][j]);
		}
		printf("\n");
	 }
	printf("\n");
}

void PrintPath(char maze[MAZEROW][MAZECOL])
{
	int i = 0;
	for (i = 0; i<MAZEROW; i++)
	 {
	 	int j = 0;
	 	for (j = 0; j<MAZECOL; j++)
	 	 {
	 	 	if (i == 0 || j == 0 || i == MAZEROW - 1 || j == MAZECOL - 1 || maze[i][j] == '$')
	 	 	 {
	 	 	 	printf("%c", maze[i] [j]);
			 }
			else
			 {
			 	printf(" ");
			 }
		 }
	    printf("\n");
	 }
	printf("\n");
}

void PrintSeat(char maze[MAZEROW][MAZECOL])
{
	int i = 0;
	for (i = 0; i < MAZEROW; i++)
	 {
	 	int j = 0;
	 	for (j = 0; j < MAZECOL; j++)
	 	 {
	 	 	if(maze[i][j] == '$')
	 	 	 {
	 	 	 	printf("(%d,%d)-->", i, j);
			 }
		 }
	 }
	printf("over\n");
}

void menu ()
{
	printf("***************************************************\n");
	printf("***************欢迎来到迷宫探索********************\n");
	printf("*****************8&0.退出探索**********************\n");
	printf("*****************8&1.迷宫地图**********************\n"); 
	printf("*****************8&2.迷宫探索**********************\n");
}

void Exploration(char maze[MAZEROW][MAZECOL], PosType start, PosType end)
{
	printf("迷宫地图：\n");
	PrintMaze(maze);
	Sleep(2000);
	system("cls");
	if (MazePath(maze, start, end))
	 {
	 	printf("<---------------------------------------------->\n");
	 	printf("探索成功！\n");
	 	printf("迷宫的现态（包括通络‘$’和已经探索过的位置‘@’）：\n");
	 	PrintMaze(maze);
	 	printf("通路路径：\n");
	 	PrintPath(maze);
	 	printf("迷宫通路坐标：\n");
	 	PrintSeat(maze);
	 }
	else
	 {
	 	printf("此迷宫不存在通路！\n");
	 	PrintMaze(maze);
	 }
}

int main()
{
	/*
	void InitMazeStack(pMazeStack sm);
    void PushStack(pMazeStack sm, SElemType data);
    void PopStack(pMazeStack sm, SElemType * tmp);
    int EmptyStack(pMazeStack sm);
    void FootPrint(PosType curpos, char maze[MAZEROW][MAZECOL]);
    int MazePath(char maze[MAZEROW][MAZECOL], PosType start, PosType end);
    void PrintMaze(char maze[MAZEROW][MAZECOL]);
    void PrintPath(char maze[MAZEROW][MAZECOL]);
    void PrintSeat(char maze[MAZEROW][MAZECOL]);
    void Exploration(char maze[MAZEROW][MAZECOL], PosType start, PosType end);
    */
	int input = 0;
	PosType start = {0,0};
	PosType end ={0,0};
	
	do
	{
		char maze[MAZEROW][MAZECOL] = {{'#','#','#','#','#','#','#','#','#','#'},{'#','0','0','#','0','0','0','#','0','#'},{'#','0','0','#','0','0','0','#','0','#'},{'#','0','0','0','0','#','#','0','0','#'},{'#','0','#','#','#','0','0','0','0','#'},{'#','0','0','0','#','0','0','0','0','#'},{'#','0','#','0','0','0','#','0','0','#'},{'#','0','#','#','#','0','#','#','0','#'},{'#','#','0','0','0','0','0','0','0','#'},{'#','#','#','#','#','#','#','#','#','#'}};
		menu();
		printf("请选择；");
		scanf("%d", &input);
		switch(input)
		 {
		 	case 1:
		 		{
		 			int count = 3;
		 			fflush(stdin);
		 			printf("地图读取中：");
					while (count--)
					 {
					 	Sleep(500);
					 	printf(".");
					 } 
					printf("\n");
					printf("迷宫地图：\n");
					PrintMaze(maze);
				}
				break;
			case 2:
				fflush(stdin);
				printf("请输入入口坐标（1，1）--（8，8）：");
				scanf("%d %d", &start.x, &start.y);
				printf("请输入出口坐标（1，1）--（8，8）：");
				scanf("%d %d", &end.x, &end.y);
				Exploration(maze, start, end);
				break;
			case 0:
				exit(0);
				break;
			default :
				printf("输入有误，请重新输入：\n");
				break;
		 } 
   }while(input);
   
   return 0;
}

