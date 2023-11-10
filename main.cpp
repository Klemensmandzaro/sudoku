#include <iostream>
#include <Windows.h>
using namespace std;
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
    cin>>a;
    return 0;
}
