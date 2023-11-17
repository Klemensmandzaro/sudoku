#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
void set_cursor(int,int);
void printArray(int sudoku[][9]);
bool validateRow(int num, int row[]);
int i, j;
int main() {
    int sudoku[9][9]={
            {1,2,3,4,5,6,7,8,9,},
            {1,2,3,4,5,6,7,8,9,},
            {1,2,3,4,5,6,7,8,9,},
            {1,2,3,4,5,6,7,8,9,},
            {1,2,3,4,5,6,7,8,9,},
            {1,2,3,4,5,6,7,8,9,},
            {1,2,3,4,5,6,7,8,9,},
            {1,2,3,4,5,6,7,8,9,},
            {1,2,3,4,5,6,7,8,9,},
    };
    int a;
    system("chcp 437");
    system("cls");
    printArray(sudoku);
    int x=1 , y=1;
    int c;
    while (true)
    {
        set_cursor(x,y);
        switch(c=getch())
        {
            case KEY_UP:
                if(y>1) y-=2; break;
            case KEY_DOWN:
                if(y<=15) y+=2; break;
            case KEY_LEFT:
                if(x>1) x-=2; break;
            case KEY_RIGHT:
                if(x<=15) x+=2; break;
            default:
                if (isdigit(c))
                {
                    c-=48;
                    int tab_col[9];
                    int tab_sq[9];
                    for (int i=0; i<9; i++)
                    {
                        tab_col[i]=sudoku[i][(x - 1) / 2];
                    }
                    int corner_x=floor(((x - 1) / 2)/3)*3;
                    int corner_y=floor(((y - 1) / 2)/3)*3;
                    for (int i=0; i<3; i++)
                    {
                        for (int j=0; j<3; j++)
                        {
                            tab_sq[(i*3)+j]=sudoku[corner_y+i][corner_x+j];
                        }
                    }

                    if (validateRow(c, sudoku[(y-1)/2])
                    && validateRow(c, tab_col)
                    && validateRow(c, tab_sq))
                    {
                        cout << c;
                        sudoku[(y - 1) / 2][(x - 1) / 2] = c;
                    }
                }
        }
    }
    cin>>a;
    return 0;
}

void printArray(int sudoku[][9])
{
    for (int i=0; i<=18; i++)
    {
        for (int j=0; j<=18; j++)
        {
            if (i%6==0)
            {
                if (i==0 && j==0)
                {
                    cout<<char(201);
                }
                else if ((i==6 || i==12) && j==0)
                {
                    cout<<char(204);
                }
                else if (i==18 && j==0)
                {
                    cout<<char(200);
                }
                else if ((i==6 || i==12) && j==18)
                {
                    cout<<char(185);
                }
                else if (i==18 && j==18)
                {
                    cout<<char(188);
                }
                else if (i==0 && j==18)
                {
                    cout<<char(187);
                }
                else if ((j==6 || j==12) && i==0)
                {
                    cout<<char(203);
                }
                else if ((j==6 || j==12) && (i==6 || i==12))
                {
                    cout<<char(206);
                }
                else if ((j==6 || j==12) && i==18)
                {
                    cout<<char(202);
                }
                else if (i==0 && (j%2==0 && j%3!=0))
                {
                    cout<<char(209);
                }
                else if (i==18 && (j%2==0 && j%3!=0))
                {
                    cout<<char(207);
                }
                else if ((i==6 || i==12) && (j%2==0 && j%3!=0))
                {
                    cout<<char(216);
                }
                else
                {
                    cout<<char(205);
                }

            }
            else if (j%6==0)
            {
                if ( j==0 && (i%2==0 && i%3!=0))
                {
                    cout<<char(199);
                }
                else if ( j==18 && (i%2==0 && i%3!=0))
                {
                    cout<<char(182);
                }
                else if (( j==6 || j==12) && (i%2==0 && i%3!=0))
                {
                    cout<<char(215);
                }
                else
                {
                    cout << char(186);
                }
            }
            else if(i%2==0 && i%3!=0)
            {
                if (j%2==1)
                {
                    cout<<char(196);
                }
                else
                {
                    cout<<char(197);
                }

            }
            else if(j%2==0 && j%3!=0)
            {
                cout<<char(179);
            }
            else
            {
                cout<<sudoku[(i-1)/2][(j-1)/2];
            }
        }
        cout<<endl;
    }
}

void set_cursor(int x = 0 , int y = 0)
{
    HANDLE handle;
    COORD coordinates;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition ( handle , coordinates );
}

bool validateRow(int num, int row[])
{
    for (int i=0; i<9; i++)
    {
        if (row[i]==num) return false;
    }
    return true;
}