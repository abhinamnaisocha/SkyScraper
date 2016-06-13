												//HEADER FILES AND CLASSES//
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<process.h>
using namespace std; 

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

//This will set the position of the cursor

    void gotoXY(int x, int y) {

    //Initialize the coordinates

    COORD coord = {x, y};

    //Set the position

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    return;

}
											//DECLARATIONS//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void randm(int [][9],int[][9]);
void display(int [][9]);
int st();
void credit();
void strt();
void rules(void);
void loading();
void win(void);
void lose(void);
void Count(int [][9]);
void cxdisplay(int [9],int,int);
void cydisplay(int [9],int,int);
void solution(int [][9]);

void main()												//Main function//
{
	int saved_sky[9][9]={				           //Saved 2d Array//
							{1,7,4,2,8,5,3,9,6},
							{3,9,6,4,1,7,5,2,8},
							{8,5,2,9,6,3,1,7,4},
	                        {4,1,7,5,2,8,6,3,9},
							{6,3,9,7,4,1,8,5,2},
							{2,8,5,3,9,6,4,1,7},
							{7,4,1,8,5,2,9,6,3},
							{9,6,3,1,7,4,2,8,5},
							{5,2,8,6,3,9,7,4,1}
						   };
	
	int sky[9][9];
menu:
	system("cls");
	randm(sky,saved_sky);
	st();
	display(sky);
	goto menu;
	
	system("pause");
			

}
void randm(int sky[][9],int saved_sky[][9])  //Generates randomized 2d array form saved 2d array//
{
	int random,a;
	srand(time(0));					//Seeding for rand function through Computer Time//
	random=rand()%9;				//rand()%9 Generates random numbers below 9 as sudoku is of 9X9 Grid//
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			a=random+saved_sky[i][j];
			if(a>9)
			{
				a=a-9;
			}
			sky[i][j]=a;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void display(int sky[][9])    //Arranges the randomized 2d array to look like a Sudoku Box//
{
	int r1,r2,i,j,x=6,y=2,chance=7;
	int key,ii[81],jj[81],blanks=0,total_blanks=0;
	int xx,yy;
	int a=0,b=0;
	srand((unsigned)time);
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			
			ii[a]=i;jj[b]=j;
			a++;b++;
			total_blanks++;
					
		}
	}
	
	gotoXY(0,0);
	cout<<"\n";

	for(i=0;i<9;i++)
		{
			cout<<"    +---+---+---+---+---+---+---+---+---+\n";
		
			cout<<"    |";
			for(j=0;j<9;j++)
			{
				
				cout<<" "<<"  |";
				"|";
			}
			cout<<endl;
           }
	cout<<"    +---+---+---+---+---+---+---+---+---+\n";
	cout<<"\n\n You have 7 Chance"; 
	Count(sky);
	gotoXY(5+1,2);
	blanks=total_blanks;
	
	while(1)     //Loop for taking input from user// 
	{

		kbhit(); //function that determine whether a key is pressed or not//
		key=getch(); //function to take input of a key//
		switch(key)
	{
		case 0x48: //key code for up (arrow) key//
			{
			if(y<=2)
			{	
				break;
			}
			y-=2;
			gotoXY(x,y);
			break;
			}
		case  0x50  ://key code for down (arrow) key//
			{
			if(y>=18)
			{
				break;
			}
			y+=2;
			gotoXY(x,y);
			break;
			}
		case 0x4B ://key code for left (arrow) key//
			{
			if(x<=5+1)
			{
				break;
			}
			x-=4;
			gotoXY(x,y);
			break;
			}
		case 0x4D : //key code for right (arrow) key//
			{
				if(x>=35+1)
				{	
					break;
				}
				x+=4;
				gotoXY(x,y);
				break;
			}
		int number; 
		case 49://Key code for 1 (key)//
		case 50://Key code for 2 (key)//
		case 51://Key code for 3 (key)//
		case 52://Key code for 4 (key)//
		case 53://Key code for 5 (key)//
		case 54://Key code for 6 (key)//
		case 55://Key code for 7 (key)//
		case 56://Key code for 8 (key)//
		case 57://Key code for 9 (key)//
			{
				if(key==49)
					number=1;
				if(key==50)
					number=2;
				if(key==51)
					number=3;
				if(key==52)
					number=4;
				if(key==53)
					number=5;
				if(key==54)
					number=6;
				if(key==55)
					number=7;
				if(key==56)
					number=8;
				if(key==57)
					number=9;
				xx=(x/4)-1;				
				yy=(y/2)-1;
										
					//Loop that runs no of blanks time to check the input//
					for(int v=0;v<blanks;v++)
					{
						//Condition that checks for the coordinates of the blank//
						if(ii[v]==yy&&jj[v]==xx)
						{
							//Condtion that checks if user input is equal to the number of sudoku at the same coordinates//
							//If condition is true blanks will decrease gradually//
							if(number==sky[yy][xx])
							{
						    jj[v]=600;
							ii[v]=600;
							cout<<number;
							gotoXY(x,y);
							total_blanks--;
							//If blanks are decreased to null,win funtion is called and palyer wins the game//
							if(total_blanks<=0)
							{
								win();
								return;
							}
							}
							//Other wise if player inputs other than the number of sundoku at that coordinate the chances will decrease//
							//Player has only three chances//
							else
							{
							gotoXY(0,22);
							chance--;
							//If chances become  null then lose fuction is called and player will lose the game//
							if(chance==0)
							{
								lose();
								solution(sky);
								return;
							}
							cout<<"You Have "<<chance<<" Chances Left ";
							gotoXY(x,y);
							cout<<" ";
							gotoXY(x,y);
							
							
							}
						}
					
				}
			}
		}
	}
	

}


void Count (int sky[][9])
{
	
	int clueleft[9],clueup[9],clueright[9],cluedown[9];
	
	for(int i=0;i<9;i++)
	{
		int a=1,b=1;
		int maxx=sky[i][0];
		int maxy=sky[0][i];
		for(int j=0;j<9;j++)
		{
			
			if(maxx<sky[i][j])
			{
				a++;
				maxx=sky[i][j];
			}
			if(maxy<sky[j][i])
			{
				b++;
				maxy=sky[j][i];
			}

		 }
		clueleft[i]=a;
		clueup[i]=b;
	}

	for(int i=8;i>=0;i--)
	{
		int a=1,b=1;
		int maxx=sky[i][8];
		int maxy=sky[8][i];
		for(int j=8;j>=0;j--)
		{
			if(maxx<sky[i][j])
			{
				a++;
				maxx=sky[i][j];
			}
			if(maxy<sky[j][i])
			{
				b++;
				maxy=sky[j][i];
			}

		 }
		clueright[i]=a;
		cluedown[i]=b;	

	}
	int x=6,y=0;
	cxdisplay(clueup,x,y);
	y=20;
	cxdisplay(cluedown,x,y);
	x=42,y=2;
	cydisplay(clueright,x,y);
	x=2,y=2;
	cydisplay(clueleft,x,y);
}

void cxdisplay(int arr[9],int x,int y)
{

	for(int i=0;i<9;i++)
	{
		gotoXY(x,y);
		cout<<arr[i];
		x+=4;
		gotoXY(x,y);
	}
}

void cydisplay(int arr[9],int x,int y)
{

	for(int i=0;i<9;i++)
	{
		gotoXY(x,y);
		cout<<arr[i];
		y+=2;
		gotoXY(x,y);
	}
}


//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

void credit()
{
	gotoXY(60,19);
	cout<<"EFFORTS BY:";
	gotoXY(60,20);
	cout<<"----------";
	gotoXY(65,21);
	cout<<"Muffaddal";
	gotoXY(65,22);
	cout<<"M.Bilal";
	gotoXY(65,23);
	cout<<"M.Ghufran";
	gotoXY(50+15,24);
	cout<<"S.AMMAR";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int st() 
{

    int x , y ;
	int key;
	strt();
	
back:
	credit();
	x=25,y=10;
	gotoXY(x,y);	
	cout<<"PLAY";
	gotoXY(x,11);
	cout<<"Rules";
	gotoXY(x,12);
	cout<<"Exit";
	x=24;y=10;
	gotoXY(x,y);
	do
{
	kbhit();	//Function that determines wether a key is pressed or not//
	key=getch();//Function to take input from user//
	switch(key)
	{
	case 0x48://key code for Up (arrow) key//
		{
			if(y<=10)
			{
				break;
			}
			y--;
			gotoXY(x,y);
			break;
		}
	case  0x50  ://key code for down (arrow) key//
		{
			if(y>=12)
			{
				break;
			}
			y++;
			gotoXY(x,y);
			break;
		}
		case'\r'://key code for Enter key//
		{
			if(y==10)	//Enter game//
			{
				loading();
				return(0);
				break;
			}
			else
			{
				if(y==11)	//Rules//
				{
					gotoXY(0,0);
					rules();
					getch();
					system("cls");
					goto back;
					break;
				}
				else	//Exit//
					exit(0);
			}
		}
			
	}
}
while(1);

    return 0;

}


void solution(int sky[][9])
{	
	int x=5+1,y=2;
	system("cls");
    gotoXY(0,0);
	cout<<"\n";
	
	for(int i=0;i<9;i++)
		{
			cout<<"    +---+---+---+---+---+---+---+---+---+\n";
		
			cout<<"    |";
			for(int j=0;j<9;j++)
			{
				
				cout<<" "<<sky[i][j]<<" |";
				"|";
			}
			cout<<endl;
           }
	cout<<"    +---+---+---+---+---+---+---+---+---+\n";
	Count(sky);
	cout<<"\n\n\t\t  SOLUTION";
	getch();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

void rules(void)
{
	system("cls");
cout<<"A SkyScraper puzzle is a grid of nine by nine squares.\n\n";


cout<<"Skyscrapers is one more family of addictive easy to learn logic puzzles.\nUsing pure logic and";
cout<<"requiring no math to solve,these fascinating puzzles offer \nendless fun and intellectual ";
cout<<"entertainment to puzzle fans of all skills & ages.\n\n";

cout<<"Skyscrapers is a building arranging puzzle. Unlike other logic puzzles, \nSkyscrapers is solved by:\n\n";
cout<<"Pacing buildings in a grid so the number of visible buildings, as viewed from \nthe "; 
cout<<"direction of each clue, is equal to the value of the clue.";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void strt(void)
{
	gotoXY(0,7);
	      cout<<"                        //===  ||    / \\         /\n";
		  Sleep(100);  
          cout<<"                       ||      ||  /     \\     / \n";
		  Sleep(100);  
		  cout<<"                         \\     || =        ||   \n";
          Sleep(100);
		  cout<<"                          ||   ||  \\       ||   \n";
          Sleep(100);
		  cout<<"                      ===//    ||    \\     ||   \n";
          Sleep(100);
		  cout<<"                    ______________________________ \n";
		  Sleep(100);
		  cout<<"       //===   ==== ||=====-\\    ======   ||=====\\  ||======  ||=====-\\ \n";
		    
          cout<<"       ||    /      ||      |  ||      || ||      | ||        ||      |     \n";
		  
		  cout<<"        \\   |       ||=====-/  ||======|| ||=====/  ||======  ||=====-/     \n";
         
		  cout<<"         ||  \\      ||     \\   ||      || ||        ||        ||     \\    \n";
          
		  cout<<"     ===//     ==== ||       \\ ||      || ||        ||======  ||      \\    \n";
         
		 
	Sleep(2800);
	system("cls");
}

void loading()
{
	system("cls");
	gotoXY(25,11);
	cout<<"Loading";
	for(int i=0;i<7;i++)
	{
	Sleep(200);	
	cout<<".";
	}
	system("cls");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void win(void)
{
	system("cls");
	cout<<"\n"
<<" oo   oo  o   o  oo  ooo     o  ooooo o  o o     o  ooooo o  oo  o   o\n"
<<"o  o o  o oo  o o  o o  o   o o   o   o  o o    o o   o   o o  o oo  o\n"
<<"o    o  o o o o o    ooo   ooooo  o   o  o o   ooooo  o   o o  o o o o\n"
<<"o  o o  o o  oo o oo o  o  o   o  o   o  o o   o   o  o   o o  o o  oo\n"
<<" oo   oo  o   o  oo  o   o o   o  o   oooo ooo o   o  o   o  oo  o   o\n\n"
;Sleep(1200);

cout<<"           @   @  @@  @  @    @      @@      @ @ @   @\n";
Sleep(100);
cout<<"            @ @  @  @ @  @     @    @  @    @  @ @@  @\n" ;   
Sleep(100);
cout<<"             @   @  @ @  @      @  @    @  @   @ @ @ @\n";
Sleep(100);
cout<<"             @   @  @ @  @       @@      @@    @ @  @@\n" ;   
Sleep(100);
cout<<"             @    @@  @@@@        @      @     @ @   @\n";
Sleep(1500);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void lose(void)
{
	system("cls");
	
cout<<"\n"
<<"     ppp     p   p       p ppppp     ppp  p      p pppp pppp\n"  
<<"    p   p   p p  pp     pp p        p   p  p    p  p    p   p\n"
<<"    p      ppppp p p   p p ppp      p   p   p  p   ppp  pppp\n"
<<"    p  ppp p   p p  p p  p p        p   p    pp    p    p   p\n"
<<"     ppp   p   p p   p   p ppppp     ppp     p     pppp p    p\n";

Sleep(1000);
}