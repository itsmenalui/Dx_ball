# include "iGraphics.h"
#include<windows.h>
#include<mmsystem.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>



#define Screen_Height 1600
#define Screen_width 884

//const int Screen_Height;
/*
	function iDraw() is called again and again by the system.

	*/
// int ball_dx=5;
// int ball_dy=5;

char name[100]="\0";
char name2[100]="\0";
int name_index=0;
int settings;
int music=1;
int runningGame=0;
int whatToDo=0;
int mapSelectionNum=0;
int board_x=50;
int board_y=50;
int board_length=230;
int board_height =15;
int ball_x =board_x+50 ;
int ball_y =board_y + board_height ;
int ball_radius=20;

char file_path[100] = "Leaderboard.txt";
 FILE* file;

int ball_x_speed;
int ball_y_speed;

int Board_x_speed=0;

int i,j,i1,i2,i3,i4;

int temp_i,temp_j;

int ballAnimCounter = 0;
int MenuAnimationCounter=0;
int menuBallAnimationCounter=0;

int lives=2;
int oneDie=0;
int gameOver=0;
int map=3;
int score=0;
int difficultyNum=1;	

void _music();
int move_temp=0;




char ballName[2][19]={"sprites\\ball1.bmp",
					"sprites\\ball2.bmp"};

char MenuAnimation[2][50]={"images\\menu\\BG1.bmp",
				"images\\menu\\BG2.bmp"};	

char menuBallAnimation[3][50]={
	"images\\flamming\\1.bmp",
	"images\\flamming\\2.bmp",
	"images\\flamming\\3.bmp",
	// "images\\flamming\\2.bmp"
};




typedef struct button{
	float left;
	float right;
	float top;
	float bottom;
}button;			

button start,difficulty,highScore,readMe,quitGame;


void initializeAll(){


// mapSelectionNum=0;
music=1;

start.left=1300;
start.right=1550;
start.top=735;
start.bottom=657;

difficulty.left=1300;
difficulty.right=1550;
difficulty.top=618;
difficulty.bottom=538;

highScore.left=1300;
highScore.right=1550;
highScore.top=500;
highScore.bottom=422;

readMe.left=1300;
readMe.right=1550;
readMe.top=384;
readMe.bottom=305;

quitGame.left=1300;
quitGame.right=1550;
quitGame.top=268;
quitGame.bottom=190;



ball_x_speed=0;
ball_y_speed=0;
ball_x = board_x + board_length/2;
ball_y  = board_y + board_height + ball_radius;



}


int bricks_map_1[34][20]={
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	
};


int bricks_map_2[34][20]={
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,
	0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,
	0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	
};

int bricks_map_3[34][20]={
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	
};

int bricks_map_4[34][20]={
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,
	0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,0,0,0,
	0,0,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,0,0,
	0,0,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,
	0,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,
	0,0,0,0,0,2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	
};

int bricks_map_1_backup[34][20]={
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	
};


int bricks_map_2_backup[34][20]={
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,
	0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,
	0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	
};

int bricks_map_3_backup[34][20]={
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	
};

int bricks_map_4_backup[34][20]={
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,
	0,0,0,0,0,2,2,0,0,0,0,0,0,2,2,0,0,0,0,0,
	0,0,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,0,0,
	0,0,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,
	0,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,
	0,0,0,0,0,2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	
};


void _reset()
{
	lives=2;
	gameOver=0;
	mapSelectionNum=0;
	runningGame=0;
	oneDie=0;
	score=0;
	ball_x = board_x + board_length/2;
	ball_y  = board_y + board_height + ball_radius;
	ball_x_speed=0;
	ball_y_speed=0;
	difficultyNum=1;
	name_index=0;
	name[name_index]='\0';
	// for(i=0;i<100;i++)
	// {
	// 	name[i]=name2[i];
	// }
	
	for(i=0;i<34;i++)
	{
		for(j=0;j<20;j++)
		{
			bricks_map_1[i][j]=bricks_map_1_backup[i][j];
		}
	}
	for(i=0;i<34;i++)
	{
		for(j=0;j<20;j++)
		{
			bricks_map_2[i][j]=bricks_map_2_backup[i][j];
		}
	}
	for(i=0;i<34;i++)
	{
		for(j=0;j<20;j++)
		{
			bricks_map_3[i][j]=bricks_map_3_backup[i][j];
		}
	}
	for(i=0;i<34;i++)
	{
		for(j=0;j<20;j++)
		{
			bricks_map_4[i][j]=bricks_map_4_backup[i][j];
		}
	}

}

void brickshow_map_1() {
	
	for(i=0;i<34;i++)
	{
		for(j=0;j<20;j++)
		{
			if(bricks_map_1[i][j] == 1)
			{
				if( i %4 == 0)
				{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\green1.bmp");
				}
				else if(i%3 == 0)
				{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\blue1.bmp");
				}
				else if(i%2 == 0)
				{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\red1.bmp");
				}
				else
				{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\brown1.bmp");					
				}
			}                   
		}
	}        


  
}                                                                                                                                                                   

void brickshow_map_2() {
	
	for(i=0;i<34;i++)
	{
		for(j=0;j<20;j++)
		{
			if(bricks_map_2[i][j] == 1)
			{
				if(j%4 == 0)
				{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\green1.bmp");
				}
				else if(j%3 == 0)
				{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\blue1.bmp");
				}
				else if(j%2 == 0)
				{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\red1.bmp");
				}
				else
				{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\brown1.bmp");					
				}
			}                   
		}
	}        
}

void brickshow_map_3() {
	for(i=0;i<34;i++)
	{
		for(j=0;j<20;j++)
		{
			if(bricks_map_3[i][j] == 1)
			{
				if( i>7 && i<11 && j>6 && j<13)
				{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\red1.bmp");
				}
				
				else
				{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\green1.bmp");					
				}
			}                   
		}
	}         
}

void brickshow_map_4() {
	for(i=0;i<34;i++)
	{
		for(j=0;j<20;j++)
		{
			if(bricks_map_4[i][j] == 1)
			{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\red1.bmp");
			}                   
		}
	} 
	iShowBMP(640,480,"images\\menu\\skull2.bmp");        
}


void Ball() {
	//main ball
	 iFilledCircle(ball_x,ball_y,ball_radius);
	//iShowBMP(ball_x,ball_y,ballName[ballAnimCounter]);
	iSetColor(0,0,255);

}

void Board(){
	// iFilledRectangle(board_x,board_y,board_length,board_height);
	//iSetColor(255,0,0);
	iShowBMP2(board_x,board_y,"sprites\\board\\boardDefault1.bmp",0);
}

void Ball_X_Movement(){
	//automovement
	if(ball_x > (Screen_Height-ball_radius) || ball_x-ball_radius <0)
	{
		ball_x_speed  = - ball_x_speed ;
	}
	
	ball_x += ball_x_speed;
}

void Ball_Y_Movement(){
	//automovement
	if(ball_y > (Screen_width-ball_radius) || ball_y-ball_radius <0)
	{
		ball_y_speed  = - ball_y_speed ;
	}
	
	ball_y += ball_y_speed;
}

void Board_x_movement(){
	if(board_x>0 && board_x+230<Screen_width)
	{
		Board_x_speed=10;
	}
}
void drawBricks() {
	iShowBMP(300,300,"sprites\\bricks\\blue1.bmp");
}

void broken_brick_map1()
{
	for(i=0;i<34;i++)
	{
		for(j=0;j<20;j++)
		{
			if(bricks_map_1[i][j] == 2)
			{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\brokenDark.bmp");
			}
		}
	}
}

void broken_brick_map2()
{
	for(i=0;i<34;i++)
	{
		for(j=0;j<20;j++)
		{
			if(bricks_map_2[i][j] == 2)
			{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\brokenDark.bmp");
			}
		}
	}
}

void broken_brick_map3()
{
	for(i=0;i<34;i++)
	{
		for(j=0;j<20;j++)
		{
			if(bricks_map_3[i][j] == 2)
			{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\brokenDark.bmp");
			}
		}
	}
}

void broken_brick_map4()
{
	for(i=0;i<34;i++)
	{
		for(j=0;j<20;j++)
		{
			if(bricks_map_4[i][j] == 2)
			{
				iShowBMP((j)*80,Screen_width-(i+1)*26,"sprites\\bricks\\red1.bmp");
			}
		}
	}
}

void Ball_collision_map1() {
	
	for(i1=0;i1<34;i1++)
	{
		for(i2=0;i2<20;i2++)
		{
			if(bricks_map_1[i1][i2] == 1)
			{	
				
					if((ball_x+ball_radius >= i2*80) && (ball_x-ball_radius <= i2*80+80) && (ball_y-ball_radius <= Screen_width- i1*26) && (ball_y+ball_radius >= Screen_width- (i1*26+26)))
					{	
							bricks_map_1[i1][i2] = 2;
							score += 12;
							if(music==1)
							{
								PlaySound("sound\\brick1st.wav", NULL, SND_ASYNC);
							}
							if(ball_x < i2*80 || ball_x > i2*80+80)
							{
								ball_x_speed = - ball_x_speed;
							}

							if(ball_y  < Screen_width- (i1*26+26)  || ball_y > i1*26)
							{
								ball_y_speed = -ball_y_speed;
							}
							
							return;
								
					}	
			}

			if(bricks_map_1[i1][i2] == 2)
			{	
				
					if((ball_x+ball_radius >= i2*80) && (ball_x-ball_radius <= i2*80+80) && (ball_y-ball_radius <= Screen_width- i1*26) && (ball_y+ball_radius >= Screen_width- (i1*26+26)))
					{	
							bricks_map_1[i1][i2] = 0;
							score += 25;
							if(music==1)
							{
								PlaySound("sound\\brick2nd.wav", NULL, SND_ASYNC);
							}
							if(ball_x < i2*80 || ball_x > i2*80+80)
							{
								ball_x_speed = - ball_x_speed;
							}

							if(ball_y  < Screen_width- (i1*26+26)  || ball_y > i1*26)
							{
								ball_y_speed = -ball_y_speed;
							}

							return;
								
					}
			}	
		}
	}
	

}

void Ball_collision_map2() {
	for(i1=0;i1<34;i1++)
	{
		for(i2=0;i2<20;i2++)
		{
			if(bricks_map_2[i1][i2] == 1)
			{	
					if((ball_x+ball_radius >= i2*80) && (ball_x-ball_radius <= i2*80+80) && (ball_y-ball_radius <= Screen_width- i1*26) && (ball_y+ball_radius >= Screen_width- (i1*26+26)))
					{	
							bricks_map_2[i1][i2] = 2;
							score += 12;
							if(music==1)
							{
								PlaySound("sound\\brick1st.wav", NULL, SND_ASYNC);
							}
							if(ball_x < i2*80 || ball_x > i2*80+80)
							{
								ball_x_speed = - ball_x_speed;
							}

							if(ball_y  < Screen_width- (i1*26+26)  || ball_y > i1*26)
							{
								ball_y_speed = -ball_y_speed;
							}
							return;		
					}	
			}

			if(bricks_map_2[i1][i2] == 2)
			{	
					if((ball_x+ball_radius >= i2*80) && (ball_x-ball_radius <= i2*80+80) && (ball_y-ball_radius <= Screen_width- i1*26) && (ball_y+ball_radius >= Screen_width- (i1*26+26)))
					{	
							bricks_map_2[i1][i2] = 0;
							score += 25;
							if(music==1)
							{
								PlaySound("sound\\brick2nd.wav", NULL, SND_ASYNC);
							}
							if(ball_x < i2*80 || ball_x > i2*80+80)
							{
								ball_x_speed = - ball_x_speed;
							}

							if(ball_y  < Screen_width- (i1*26+26)  || ball_y > i1*26)
							{
								ball_y_speed = -ball_y_speed;
							}
							return;	
					}
			}	
		}
	}
}

void Ball_collision_map3() {
	for(i1=0;i1<34;i1++)
	{
		for(i2=0;i2<20;i2++)
		{
			if(bricks_map_3[i1][i2] == 1)
			{	
					if((ball_x+ball_radius >= i2*80) && (ball_x-ball_radius <= i2*80+80) && (ball_y-ball_radius <= Screen_width- i1*26) && (ball_y+ball_radius >= Screen_width- (i1*26+26)))
					{	
							bricks_map_3[i1][i2] = 2;
							score += 12;
							if(music==1)
							{
								PlaySound("sound\\brick1st.wav", NULL, SND_ASYNC);
							}
							if(ball_x < i2*80 || ball_x > i2*80+80)
							{
								ball_x_speed = - ball_x_speed;
							}

							if(ball_y  < Screen_width- (i1*26+26)  || ball_y > i1*26)
							{
								ball_y_speed = -ball_y_speed;
							}
							return;		
					}	
			}

			if(bricks_map_3[i1][i2] == 2)
			{	
					if((ball_x+ball_radius >= i2*80) && (ball_x-ball_radius <= i2*80+80) && (ball_y-ball_radius <= Screen_width- i1*26) && (ball_y+ball_radius >= Screen_width- (i1*26+26)))
					{	
							bricks_map_3[i1][i2] = 0;
							score += 25;
							if(music==1)
							{
								PlaySound("sound\\brick2nd.wav", NULL, SND_ASYNC);
							}
							if(ball_x < i2*80 || ball_x > i2*80+80)
							{
								ball_x_speed = - ball_x_speed;
							}

							if(ball_y  < Screen_width- (i1*26+26)  || ball_y > i1*26)
							{
								ball_y_speed = -ball_y_speed;
							}
							return;	
					}
			}	
		}
	}
}

void Ball_collision_map4() {
	for(i1=0;i1<34;i1++)
	{
		for(i2=0;i2<20;i2++)
		{
			if(bricks_map_4[i1][i2] == 1)
			{	
					if((ball_x+ball_radius >= i2*80) && (ball_x-ball_radius <= i2*80+80) && (ball_y-ball_radius <= Screen_width- i1*26) && (ball_y+ball_radius >= Screen_width- (i1*26+26)))
					{	
							bricks_map_4[i1][i2] = 2;
							score += 12;
							if(music==1)
							{
								PlaySound("sound\\brick1st.wav", NULL, SND_ASYNC);
							}
							if(ball_x < i2*80 || ball_x > i2*80+80)
							{
								ball_x_speed = - ball_x_speed;
							}

							if(ball_y  < Screen_width- (i1*26+26)  || ball_y > i1*26)
							{
								ball_y_speed = -ball_y_speed;
							}
							return;		
					}	
			}

			if(bricks_map_4[i1][i2] == 2)
			{	
					if((ball_x+ball_radius >= i2*80) && (ball_x-ball_radius <= i2*80+80) && (ball_y-ball_radius <= Screen_width- i1*26) && (ball_y+ball_radius >= Screen_width- (i1*26+26)))
					{	
							bricks_map_4[i1][i2] = 0;
							score += 25;
							if(music==1)
							{
								PlaySound("sound\\brick2nd.wav", NULL, SND_ASYNC);
							}
							if(ball_x < i2*80 || ball_x > i2*80+80)
							{
								ball_x_speed = - ball_x_speed;
							}

							if(ball_y  < Screen_width- (i1*26+26)  || ball_y > i1*26)
							{
								ball_y_speed = -ball_y_speed;
							}
							return;	
					}
			}	
		}
	}
}


void ball_board_collision(){
	if (ball_y-ball_radius < board_y+board_height  &&  ball_x + ball_radius > board_x && ball_x - ball_radius < board_x+ board_length)
	{
		ball_y_speed =-ball_y_speed;
	}
}

void _menuShow(){

	iShowBMP(0,0,"images\\menu\\BG3.bmp");
	//iShowBMP2(830,330,"images\\menu\\flame.bmp",16777215);
	iShowBMP(1350,554,"images\\menu\\ylw.bmp");
	// iShowBMP(1350,554,"images\\menu\\settingWritten.bmp");
	iShowBMP(1320,554,"images\\menu\\setting.bmp");
	iShowBMP2(550,100,menuBallAnimation[menuBallAnimationCounter],16777215);

	
}

void _readMe()
{
	iShowBMP(0,0,"images\\menu\\HowToPlay.bmp");
	iShowBMP2(670,8,"images\\menu\\returnButton.bmp",16777215); 
	iShowBMP2(765,8,"images\\menu\\homeButton.bmp",16777215);

	
}

void _highScores()
{
	iShowBMP(486,0,"images\\menu\\highScoresBG2.bmp");
	iShowBMP2(670,8,"images\\menu\\returnButton.bmp",16777215); 
	iShowBMP2(765,8,"images\\menu\\homeButton.bmp",16777215);
	// file=fopen("leaderboard.txt","r");
	// fscanf(file,"%[^\n]",name);
	// iText(300,500,name,GLUT_BITMAP_HELVETICA_18);
	// // fscanf(file,"%s",name);
	// fscanf(file,"%[^\n]",name);
	// iText(300,600,name,GLUT_BITMAP_HELVETICA_18);
	// // fscanf(file,"%s",name);
	// fscanf(file,"%[^\n]",name);
	// iText(300,700,name,GLUT_BITMAP_HELVETICA_18);
	// fclose(file);
				
    
	
}



void _displayLeaderboard() {
    
	FILE* file = fopen(file_path, "r");
    
	
	if (file != NULL) 
	{
        char names[100][100];
        int scores[100];     

        int entryCount = 0;
        
        while (entryCount < 100 && fscanf(file, "%s %d", names[entryCount], &scores[entryCount]) == 2) {
            entryCount++;
        }

        
        for (int i = 0; i < entryCount - 1; i++) 
		{
            for (int j = i + 1; j < entryCount; j++)
			 {
                if (scores[i] < scores[j]) {
                    char tempName[100];
                    int tempScore;
					tempScore = scores[i];
                    scores[i] = scores[j];
                    scores[j] = tempScore;
                    strcpy(tempName, names[i]);
                    strcpy(names[i], names[j]);
                    strcpy(names[j], tempName);
                }
            }
        }

        
        glColor3f(0.0, 0.0, 0.0);

        int displayCount = 15;
		if (entryCount < 15)
		{
			displayCount = entryCount;
		}
        for (int i = 0; i < displayCount; i++) 
		{
            char matha[100];
            snprintf(matha, sizeof(matha), "%s: %d", names[i], scores[i]);
            iText(680, 700 - i * 30, matha, GLUT_BITMAP_HELVETICA_18);
        }

        fclose(file);
    } 
}






void _settings()
{
	iShowBMP(0,0,"images\\menu\\settingBG.bmp");
	if(music==1)
	{
		iShowBMP(500,500,"images\\sound\\on.bmp");
	}
	if(music==0)
	{
		iShowBMP(500,500,"images\\sound\\off.bmp");
	}
	
	iShowBMP2(25,15,"images\\menu\\returnButton.bmp",16777215); 
	iShowBMP2(120,15,"images\\menu\\homeButton.bmp",16777215);
}

void _difficultyShow()
{
	if(difficultyNum ==1)
	{
		iShowBMP(0,0,"images\\menu\\difficultyEasy.bmp");
		// ball_dx=5;
		// ball_dy=5;
		ball_x_speed=4;
		ball_y_speed=4;
		iShowBMP2(1360,10,"images\\menu\\Next.bmp",16777215);
	}	

	if(difficultyNum ==2 )
	{
		iShowBMP(0,0,"images\\menu\\difficultyMedium.bmp");
		// ball_dx=7;
		// ball_dy=7;
		ball_x_speed=5;
		ball_y_speed=5;
		iShowBMP2(1360,10,"images\\menu\\Next.bmp",16777215);
	}

	if(difficultyNum ==3)
	{
		iShowBMP(0,0,"images\\menu\\difficultyHard.bmp");
		// ball_dx=9;
		ball_x_speed=7;
		ball_y_speed=7;
		iShowBMP2(1360,10,"images\\menu\\Next.bmp",16777215);
	}

iShowBMP2(25,15,"images\\menu\\returnButton.bmp",16777215); 
iShowBMP2(120,15,"images\\menu\\homeButton.bmp",16777215);



}



void _lives()
{
	iShowBMP2(170,800,"sprites\\lifes\\life.bmp",16777215);
	char livesStr[2];
	sprintf(livesStr,"%d",lives+1);
	iText(173,828,livesStr,GLUT_BITMAP_HELVETICA_18);
}

void _showEnterName()
{
	iShowBMP(520,220,"images\\map\\enterName.bmp");
}

void _showScore(){	
	//sprintf(scoreStr,"%d",score);
	iSetColor(255,255,255);
	
	//  iShowBMP2(1270,800,"images\\digits\\0.bmp",16777215);
	//  iShowBMP2(1300,800,"images\\digits\\1.bmp",16777215);
	
}

void _mapSelection()
{
	iShowBMP(0,0,"images\\menu\\black.bmp");
	iShowBMP(358,0,"images\\map\\mapselection.bmp");
	iShowBMP(467,510,"images\\map\\map1.bmp");
	iShowBMP(700,510,"images\\map\\map2.bmp");
	iShowBMP(933,510,"images\\map\\map3.bmp");
	iShowBMP(455,174,"images\\map\\map4.bmp");
	iShowBMP2(670,8,"images\\menu\\returnButton.bmp",16777215); 
	iShowBMP2(765,8,"images\\menu\\homeButton.bmp",16777215);

}


void _scorePrinting()
{
	int num_digits=0;
	int digits[6] = {0,0,0,0,0,0};
	int local_score = score;
	while (local_score > 0 && num_digits < 6) {
        digits[num_digits] = local_score % 10; 
        local_score /= 10; 
        num_digits++;
    }
	
	for (i = 6; i >= 0; i--)
	{
		switch (digits[i])
		{
		case 0:
		 	iShowBMP2(1300-i*30,800,"images\\digits\\0.bmp",16777215);
		 	break;
		case 1:
			iShowBMP2(1300-i*30,800,"images\\digits\\1.bmp",16777215);
			break;	
		case 2:
			iShowBMP2(1300-i*30,800,"images\\digits\\2.bmp",16777215);
			break;
		case 3:
			iShowBMP2(1300-i*30,800,"images\\digits\\3.bmp",16777215);
			break;
		case 4:
			iShowBMP2(1300-i*30,800,"images\\digits\\4.bmp",16777215);
			break;
		case 5:
			iShowBMP2(1300-i*30,800,"images\\digits\\5.bmp",16777215);
			break;
		case 6:
			iShowBMP2(1300-i*30,800,"images\\digits\\6.bmp",16777215);
			break;
		case 7:
			iShowBMP2(1300-i*30,800,"images\\digits\\7.bmp",16777215);
			break;
		case 8:
			iShowBMP2(1300-i*30,800,"images\\digits\\8.bmp",16777215);
			break;
		case 9:
			iShowBMP2(1300-i*30,800,"images\\digits\\9.bmp",16777215);
			break;	
		default:
			iShowBMP2(1300-i*30,800,"images\\digits\\0.bmp",16777215);
			break;							
		
		}
	}
}

void _gameOver()
{
	
	if(ball_y+ball_radius < board_y)
	{
		oneDie=1;
		//gameOver=1;
		
		if(lives==0)
		{
			gameOver=1;
			file = fopen("leaderboard.txt", "a");
			fprintf(file, "%s %d\n",name,score);
			fclose(file);
		}	
		if(oneDie==1)
		{
			lives -= 1;
			ball_x = board_x + board_length/2;
			ball_y  = board_y + board_height + ball_radius;
			iPauseTimer(2);
			iPauseTimer(3);
		}
		
			
	}

	if(gameOver == 1)
	{
		iShowBMP(0,0,"images\\menu\\fullWhite.bmp");
		iShowBMP(100,200,"images\\menu\\gameOverHotash.bmp");
		iShowBMP2(710,500,"images\\menu\\gameOver.bmp",16777215);
		iShowBMP2(650,400,"images\\menu\\yourScore2.bmp",16777215);
		iShowBMP2(630,90,"images\\menu\\b2mm.bmp",16777215);
		iSetColor(255,255,0);
		//iText(1180,430,scoreStr,GLUT_BITMAP_HELVETICA_18);
		

	int num_digits=0;
	int digits[6] = {0,0,0,0,0,0};
	int local_score = score;
	while (local_score > 0 && num_digits < 6) {
        digits[num_digits] = local_score % 10; 
        local_score /= 10; 
        num_digits++;
    }
	


	for (i = 6; i >= 0; i--)
	{
		switch (digits[i])
		{
		case 0:
		 	iShowBMP2(1400-i*55,405,"images\\digits2\\0.bmp",0);
		 	break;
		case 1:
			iShowBMP2(1400-i*55,405,"images\\digits2\\1.bmp",0);
			break;	
		case 2:
			iShowBMP2(1400-i*55,405,"images\\digits2\\2.bmp",0);
			break;
		case 3:
			iShowBMP2(1400-i*55,405,"images\\digits2\\3.bmp",0);
			break;
		case 4:
			iShowBMP2(1400-i*55,405,"images\\digits2\\4.bmp",0);
			break;
		case 5:
			iShowBMP2(1400-i*55,405,"images\\digits2\\5.bmp",0);
			break;
		case 6:
			iShowBMP2(1400-i*55,405,"images\\digits2\\6.bmp",0);
			break;
		case 7:
			iShowBMP2(1400-i*55,405,"images\\digits2\\7.bmp",0);
			break;
		case 8:
			iShowBMP2(1400-i*55,405,"images\\digits2\\8.bmp",0);
			break;
		case 9:
			iShowBMP2(1400-i*55,405,"images\\digits2\\9.bmp",0);
			break;	
		default:
			iShowBMP2(1400-i*55,405,"images\\digits2\\0.bmp",0);
			break;							
		
		}

		iShowBMP2(670,8,"images\\menu\\returnButton.bmp",16777215); 
		iShowBMP2(765,8,"images\\menu\\homeButton.bmp",16777215);
	
	}

	}

}




void iDraw() {
	//place your drawing codes here
	
	
	iClear();

	if(whatToDo==20)
	{
		iShowBMP(0,0,"images\\progressLost.bmp");
	}
	if(mapSelectionNum==1 )
	{
		_mapSelection();
		_showEnterName();
		iText(695,493,name,GLUT_BITMAP_HELVETICA_18);

	}
	
	if(mapSelectionNum==2 )
	{
		_mapSelection();
		// _showEnterName();
	}
	
	if(whatToDo == 0)
	{
		_menuShow();	
	}

	if(whatToDo == 1)
	{
		if(gameOver == 0)
		{
			if(map==1)
			{
				brickshow_map_1();
				Ball_collision_map1();
				broken_brick_map1();
				if( score == 4440)
				{
					iShowBMP(0,0,"images\\winner.bmp");
					iShowBMP2(30,800,"images\\menu\\returnButton.bmp",16777215); 
					iShowBMP2(1500,800,"images\\menu\\homeButton.bmp",16777215);
					iPauseTimer(2);
					iPauseTimer(3);
		
				}
				
			}
			if(map == 2)
			{
				brickshow_map_2();
				Ball_collision_map2();
				broken_brick_map2();
				if( score == 4292)
				{
					iShowBMP(0,0,"images\\winner.bmp");
					iShowBMP2(30,800,"images\\menu\\returnButton.bmp",16777215); 
					iShowBMP2(1500,800,"images\\menu\\homeButton.bmp",16777215);
					iPauseTimer(2);
					iPauseTimer(3);
		
				}
			}

			if(map == 3)
			{
				// iShowBMP(0,0,"images\\menu\\.bmp");
				brickshow_map_3();
				Ball_collision_map3();
				broken_brick_map3();
				if( score == 6660)
				{
					iShowBMP(0,0,"images\\winner.bmp");
					iShowBMP2(30,800,"images\\menu\\returnButton.bmp",16777215); 
					iShowBMP2(1500,800,"images\\menu\\homeButton.bmp",16777215);
					iPauseTimer(2);
					iPauseTimer(3);
		
				}
			}

			if(map == 4)
			{
				// iShowBMP(0,0,"images\\menu\\.bmp");
				brickshow_map_4();
				Ball_collision_map4 ();
				broken_brick_map4();
				if( score ==850)
				{
					iShowBMP(0,0,"images\\winner.bmp");
					iShowBMP2(30,800,"images\\menu\\returnButton.bmp",16777215); 
					iShowBMP2(1500,800,"images\\menu\\homeButton.bmp",16777215);
					iPauseTimer(2);
					iPauseTimer(3);
				}
			}



		Board();
		Ball();
		ball_board_collision();
		_showScore();
		_lives();
		_scorePrinting();
		iShowBMP2(30,800,"images\\menu\\returnButton.bmp",16777215); 
		iShowBMP2(1500,800,"images\\menu\\homeButton.bmp",16777215);
		// printf("%d",score);
		}
		
		_gameOver();
	}

	if( whatToDo == 7)
	{
		_settings();
	}

	if( whatToDo == 4)
	{
		_readMe();
	}

	if( whatToDo == 3)
	{
		_highScores();
		_displayLeaderboard();
	}

	if(whatToDo == 2)
	{
		_difficultyShow();
	}
	
	if(whatToDo == 5)
	{
		
	}
	
	if( whatToDo == 0 )
		{
			_reset();
		}
		
}


/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	 printf("x = %d, y= %d\n",mx,my);
	
	
	if(mx+ board_length <= Screen_Height && mx>=0)
	{
		board_x=mx;
	}
	

	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		if(whatToDo ==0)
		{
		
			if((mx > start.left) && (mx < start.right) && (my > start.bottom) && (my < start.top))
			{
				mapSelectionNum=1;
				// // _mapSelection();
				whatToDo=6;
				// name_index=0;
				// name[name_index]='\0';
				// _showEnterName();
			}

			else if((mx > difficulty.left) && (mx < difficulty.right) && (my > difficulty.bottom) && (my < difficulty.top))
			{
				whatToDo = 7;
			}

			else if((mx > highScore.left) && (mx < highScore.right) && (my > highScore.bottom) && (my < highScore.top))
			{
				whatToDo = 3;
			}

			else if((mx > readMe.left) && (mx < readMe.right) && (my > readMe.bottom) && (my < readMe.top))
			{
				whatToDo = 4;
			}

			else if((mx > quitGame.left) && (mx < quitGame.right) && (my > quitGame.bottom) && (my < quitGame.top))
			{
				exit(0);
			}

		}

		if(whatToDo==20)
		{
			if(mx>530 && mx<1060 && my>275 && my<400)
			{
				whatToDo=0;
			}
			if(mx>530 && mx<1060 && my>105 && my<228)
			{
				whatToDo=1;
			}

		}
		
		if(whatToDo == 4 || whatToDo == 3 )
		{
			if(mx >= 765 && mx <= 835 && my >= 8 && my <= 78)
			{	
				whatToDo =0 ;
			}

			if(mx >= 670 && mx <= 740 && my >= 8 && my <= 78)
			{	
				whatToDo =0 ;
			}
		}

		if(whatToDo == 1)
		{
			

			if(mx >= 30 && mx <= 100 && my >= 800 && my <= 870)
			{	
				whatToDo =20 ;
				iPauseTimer(2);
				iPauseTimer(3);
			}

			if(mx >= 1500 && mx <= 1570 && my >= 800 && my <= 870)
			{	
				whatToDo =20 ;
				iPauseTimer(2);
				iPauseTimer(3);
			}

			if(oneDie == 1)
			{
				if(mx>0 && mx < Screen_Height && my >0 && my < Screen_width)
				{
					oneDie=0;
					
				}
			}

			if(gameOver == 1)
			{
				if(mx >= 765 && mx <= 835 && my >= 8 && my <= 78)
				{	
					whatToDo =0 ;
				}

				if(mx >= 670 && mx <= 740 && my >= 8 && my <= 78)
				{	
					whatToDo =0 ;
				}
			}
		}

		if(whatToDo==7)
		{
			if(mx >= 25 && mx <= 95 && my >= 15 && my <= 85)
			{
				whatToDo = 0;
			}

			if(mx >= 120 && mx <= 190 && my >= 15 && my <= 85)
			{
				whatToDo = 0;
			}
		}

		if(whatToDo == 2)
		{

			if(mx >= 25 && mx <= 95 && my >= 15 && my <= 85)
			{
				whatToDo = 0;
			}

			if(mx >= 120 && mx <= 190 && my >= 15 && my <= 85)
			{
				whatToDo = 0;
			}

			if(difficultyNum ==1)
			{
				if(mx >= 670 && mx <= 925 && my >= 110 && my <= 690)
				{
					difficultyNum = 2;
				}

				if(mx >= 1155 && mx <= 1410 && my >= 110 && my <= 690)
				{
					difficultyNum = 3;
				}

			}

			if(difficultyNum == 2)
			{
				if(mx >= 190 && mx <= 440 && my >= 110 && my <= 690)
				{
					difficultyNum = 1;
				}

				if(mx >= 1155 && mx <= 1410 && my >= 110 && my <= 690)
				{
					difficultyNum = 3;
				}

			}

			if(difficultyNum == 3)
			{
				if(mx >= 190 && mx <= 440 && my >= 110 && my <= 690)
				{
					difficultyNum = 1;
				}

				if(mx >= 670 && mx <= 925 && my >= 110 && my <= 690)
				{
					difficultyNum = 2;
				}

			}

			if(mx>=1360 && mx<=1520 && my>=10 && my<=90)
			{
				whatToDo=1;
			}
		}

		if(mapSelectionNum ==1)
		{
			if( mx>=720 && mx<=865 && my>=270 && my<=311 && name_index!=0)
			{
				mapSelectionNum=2;
			}
		}

		if(mapSelectionNum == 2 )
		{
			if( mx >=467 && mx<=667 && my>=510 && my<=638)
			{
				map=1;
				whatToDo=2;
				mapSelectionNum=0;
			}
			if( mx >=700 && mx<=900 && my>=510 && my<=638)
			{
				map=2;
				whatToDo=2;
				mapSelectionNum=0;
			}
			if( mx >=933 && mx<=1133 && my>=510 && my<=638)
			{
				map=3;
				whatToDo=2;
				mapSelectionNum=0;
			}
			if( mx >=467 && mx<=667 && my>=130 && my<=314)
			{
				map=4;
				whatToDo=2;
				mapSelectionNum=0;
			}



			if(mx >= 765 && mx <= 835 && my >= 8 && my <= 78)
			{	
				whatToDo =0 ;
			}

			if(mx >= 670 && mx <= 740 && my >= 8 && my <= 78)
			{	
				whatToDo =0 ;
			}
		}
		move_temp++;
		if(whatToDo==7)
		{
			if(mx >=500 && mx<=700 && my>=500 && my<=700)
			{
				if(music==1)
				{
					music=0;
					PlaySound(0,0,0);
				}
				else if(music==0)
				{
					music=1;
					_music();
				}	
			}
		}
		
	}



	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}

	if(key == 27)
	{
		if(runningGame == 1)
		{
			iPauseTimer(2);
			iPauseTimer(3);
			runningGame=0;
		}
		else
		{
			iResumeTimer(2);
			iResumeTimer(3);
			runningGame=1;
		}
	}

	if(key == ' ')
	{
		iResumeTimer(2);
		iResumeTimer(3);
	}

	if(mapSelectionNum==1)
	{
		if(key!=8 && name_index <=9)
		{
			name[name_index]= key;
			name_index++;
			name[name_index]='\0';
		}
		else if(key ==8)
		{
			if(name_index==0)
			{
				return;
			}
			name_index--;
			name[name_index]='\0';
		}
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}

	
	
	//place your codes for other keys here
}

void ballAnimation()
{
	ballAnimCounter++;
	if(ballAnimCounter >= 2)
		ballAnimCounter = 0;
}

void _MenuAnimation()
{
	MenuAnimationCounter++;
	if(MenuAnimationCounter >= 2)
	{
		MenuAnimationCounter=0;
	}
}

void _menuBallAnimation()
{
	menuBallAnimationCounter++;
	if(menuBallAnimationCounter >= 3)
	{
		menuBallAnimationCounter=0;
	}
}

void _music()
{
	if(music==1)
	{
		PlaySound(TEXT("Sound\\default.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	if(music == 0){
		PlaySound(0,0,0);
	}
}

int main() {
	
	_music();
	//iSetTimer(20,ballAnimation);
	
	initializeAll();
	if(whatToDo ==1 && gameOver == 0)
	{
	// iSetTimer(01,Ball);
	// iSetTimer(29,ballAnimation);
	}
	iSetTimer(10,_MenuAnimation);
	iSetTimer(100,_menuBallAnimation);
	iSetTimer(5,Ball_X_Movement);
	iSetTimer(5,Ball_Y_Movement);

	iPauseTimer(2);
	iPauseTimer(3);
	//iSetTimer(200,_gameOver);

	
	// iSetTimer(5,Ball_x_collision);
	// iSetTimer(5,Ball_y_collision);
	//place your own initialization codes here.
	iInitialize(Screen_Height, Screen_width, "DxBall.exe");
	
	
	return 0;
}
