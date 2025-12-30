#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}},mark,name1[40],name2[40];
int a[6],turn=1,scoreP1=0,scoreP2=0,modechoice;

void drawBoard()
{
    printf("\n");
    if (modechoice==1)
    {
        printf("    --------------------\n");
        printf("       STANDARD MODE    \n");
        printf("    --------------------\n");
    }
    if(modechoice==2)
    {
        printf("    --------------------\n");
        printf("         PRO MODE       \n");
        printf("    --------------------\n");
    }
    printf("\n");
    printf("    ------+-----+-------\n");
    printf("    |  %c  |  %c  |  %c  |\n", board[0][0], board[0][1], board[0][2]);
    printf("    +-----+-----+-----+\n");
    printf("    |  %c  |  %c  |  %c  |\n", board[1][0], board[1][1], board[1][2]);
    printf("    +-----+-----+-----+\n");
    printf("    |  %c  |  %c  |  %c  |\n", board[2][0], board[2][1], board[2][2]);
    printf("    ------+-----+------ \n");
    printf("\n");
}

void queue(int box)
{
    int temp, flagi=0;
    char b[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    if (turn>=6)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(b[i][j]=='0'+a[0])
                {
                    board[i][j]='0'+a[0];
                    flagi=1;
                    break;//breaking from j
                }
            }
            if(flagi==1)
                break;//breaking from i
        }
        for(int i=0;i<5;i++)
        {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
        a[5]=box;
    }
    else
        a[turn]=box;
}

void inputPRO(int n,char ch)
{
    int flagi=0,count=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]=='0'+n)
            {
                for(int k=0;k<6;k++)
                {
                    if(a[k]!=n) //if not in queue
                        count++;
                    if(count==6)
                    {
                        board[i][j]=ch;
                        flagi=1;
                        queue(n);
                        break;//breaking from j as k already is on its last iteration
                    }
                }
            }
        }
        if(flagi==1)
            break;//breaking from i
    }
    if (flagi==0)
    {
        printf("Wrong choice!! Do again\n");
        turn--;
        system("cls");
    }
}

void inputStandard(int box,char mark)
{
    int flagi=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]=='0'+box)
            {
                board[i][j]=mark;
                flagi=1;
                break;//breaking from j
            }
        }
        if(flagi==1)
            break;//breaking from i
    }
    if (flagi==0)
    {
        printf("Wrong choice!! Do again\n");
        turn--;
    }
}

int checkWin()
{
    for (int i=0;i<3;i++)
    {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return 1;
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return 1;
    }
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return 1;
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return 1;

    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return -1;
        }
    }
    return 0;
}

void standardMode()
{
    char temp1[40]; 
    int temp2, flag=-1, box;

    printf("Mark of %s (X/O): ",name1);
    while (1)
    {
        scanf(" %c", &mark);

        if (mark == 'o' || mark == 'O')
        {
            strcpy(temp1, name1);
            strcpy(name1, name2);
            strcpy(name2, temp1);//player switch

            temp2 = scoreP1;
            scoreP1 = scoreP2;
            scoreP2 = temp2;//score switch
            break;
        }
        else if (mark != 'x' && mark != 'X')
        {
            printf("Wrong Input\nEnter mark again: ");
        }
        else break;
    }

    system("cls");
    drawBoard();

    while(flag==-1)
    {
        if (turn%2!=0)
        {
            system("cls");
            printf("%s's turn (X)\n",name1);
            drawBoard();
            printf("Enter input no: ");
            scanf("%d", &box);
            if(box!=1 && box!=2 && box!=3 && box!=4 && box!=5 && box!=6 && box!=7 && box!=8 && box!=9 )
            {
                printf("Wrong Choice!! Do again\n");
                continue;
            }
            inputStandard(box,'X');
            turn++;
            flag=checkWin();

            if (flag == 0)
            {
                drawBoard();
                printf("Match Drawn\n");
                break;
            }
            if(flag==1)
            {
                printf("%s wins\n",name1);
                scoreP1+=10;
                break;
            }
        }
        else
        {
            system("cls");
            printf("%s's turn (O)\n",name2);
            drawBoard();
            printf("Enter input no: ");
            scanf("%d", &box);
            if(box!=1 && box!=2 && box!=3 && box!=4 && box!=5 && box!=6 && box!=7 && box!=8 && box!=9 )
            {
                printf("Wrong Choice!! Do again\n");
                continue;
            }
            inputStandard(box,'O');
            turn++;
            flag=checkWin();

            if (flag == 0)
            {
                drawBoard();
                printf("Match Drawn\n");
                break;
            }
            if(flag==1)
            {
                printf("%s wins\n",name2);
                scoreP2+=10;
                break;
            }
        }
    }
}

void proMode()
{
    int flag=0,box,temp2;
    char temp1[40];

    printf("Mark of %s (X/O): ",name1);
    while (1)
    {
        scanf(" %c",&mark);

        if (mark=='o'||mark=='O')
        {
            strcpy(temp1,name1);
            strcpy(name1,name2);
            strcpy(name2,temp1);//player switch

            temp2=scoreP1;
            scoreP1=scoreP2;
            scoreP2=temp2;//score switch
            break;
        }
        else if (mark!='x' && mark!='X')
        {
            printf("Wrong Input\nEnter mark again: ");
        }
        else break;
    }

    system("cls");
    drawBoard();

    while(flag!=1)
    {
        if (turn%2!=0)
        {
            system("cls");
            printf("%s's turn (X)\n",name1);
            drawBoard();
            printf("Enter input no: ");
            scanf("%d",&box);
            if(box!=1 && box!=2 && box!=3 && box!=4 && box!=5 && box!=6 && box!=7 && box!=8 && box!=9 )
            {
                printf("Wrong Choice!! Do again\n");
                continue;
            }
            inputPRO(box,'X');
            turn++;
            drawBoard();
            flag=checkWin();

            if(flag==1)
            {
                printf("%s wins\n",name1);
                scoreP1+=20;
                break;
            }
        }
        else
        {
            system("cls");
            printf("%s's turn (O)\n",name2);
            drawBoard();
            printf("Enter input no: ");
            scanf("%d",&box);
            if(box!=1 && box!=2 && box!=3 && box!=4 && box!=5 && box!=6 && box!=7 && box!=8 && box!=9 )
            {
                printf("Wrong Choice!! Do again\n");
                continue;
            }
            inputPRO(box,'O');
            turn++;
            drawBoard();
            flag=checkWin();

            if(flag==1)
            {
                printf("%s wins\n",name2);
                scoreP2+=20;
                break;
            }
        }
    }
}

void displayScoreCard()
{
    printf(" %s\t \t %s\n",name1,name2);
    printf("\n %d\t \t %d\n",scoreP1,scoreP2);
}

int main()
{
    printf("\n");
    printf("   ---------------------\n");
    printf("   WELCOME TO TIC TAC TOE\n");
    printf("   ---------------------\n");
    printf("SCORING SYSTEM:\n");
    printf("\n10 points for WIN in STANDARD MODE\n20 points for WIN in PRO MODE\n0 points for DRAW or LOSS.\n\n");

    printf("Enter the name of Player 1 : ");
    scanf(" %39[^\n]", name1);
    printf("Enter the name of Player 2 : ");
    scanf(" %39[^\n]", name2);

    printf("Enter 1 for STANDARD MODE, 2 for PRO MODE and 0 to EXIT GAME.\n");
    scanf("%d",&modechoice);

    while(modechoice!=0)
    {
        if(modechoice==1)
            standardMode();
        if(modechoice==2)
            proMode();

        printf("   ---------------------\n");
        printf("   SCORECARD\n");
        printf("   ---------------------\n");
        displayScoreCard();

        printf("Enter 1 for STANDARD MODE, 2 for PRO MODE and 0 to EXIT GAME.\n");
        scanf("%d",&modechoice);

        if(modechoice==1||modechoice==2)
        {
            turn=1;

            char temp='1';
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    board[i][j]=temp++;

            for(int i=0;i<6;i++)
                a[i]=0;  

            system("cls");
        }
    }

    system("cls");
    printf("   ---------------------\n");
    printf("   FINAL SCORECARD\n");
    printf("   ---------------------\n");
    displayScoreCard();
    return 0;
}
