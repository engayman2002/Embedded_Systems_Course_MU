#include <stdio.h>

char Grid[3][3];

void line()
{
    printf("................................................\n");
}

void Init_Grid()
{
    int i,j;
    int k=1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            Grid[i][j]=k+48; //by ASCII Table
            k++;
        }
    }
}

void Print_Grid()
{
    int i,j; // ANSI C
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%c  ",Grid[i][j]);
        }
        printf("\n");
    }
}

char Check_Play(char x,char name)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(x==Grid[i][j])
            {
                Grid[i][j]=name;
                return 1;
            }
        }
    }
    return 0;
}

void Player(char name)
{
    char x,flag;
    while(1)
    {
        printf("This Turn is For Player %c :\n",name);
        Print_Grid();
        line();
        printf("Choose any number that shown on the Grid : ");
		fflush(stdout);
        scanf(" %c",&x);
		fflush(stdin);
        flag=Check_Play(x,name);
        if(flag==1)
        {
            break;
        }
        else
        {
            printf("\n");
            line();
            printf("Oops!, you must type a valid number, Be Careful\n");
            line();
            printf("\n\n");
            line();
        }
    }
}

char check_board_for_winner(char flag)
{
    int i;
    // Two Diagonal
    if( Grid[0][0]==Grid[1][1] && Grid[1][1]==Grid[2][2] )
    {
        return 1;
    }
    else if( Grid[0][2]==Grid[1][1] && Grid[1][1]==Grid[2][0])
    {
        return 1;
    }
    else
    {
        // Horizontal
        for(i=0;i<3;i++)
        {
            if(Grid[i][0]==Grid[i][1] && Grid[i][1]==Grid[i][2])
            {
                return 1;
            }
        }
        // Vertical
        for(i=0;i<3;i++)
        {
            if(Grid[0][i]==Grid[1][i] && Grid[1][i]==Grid[2][i])
            {
                return 1;
            }
        }
    }
    return -1;
}

void Win(char flag)
{
    printf("\n\n");
    line();
    printf("Player %c win the Game\n",flag);
    line();
    Print_Grid();
    line();
}

char Check_Draw()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(Grid[i][j]>47 && Grid[i][j]<58)
            {
                return 0;
            }
        }
    }
    printf("\n");
    line();
    printf("\t\t *** Draw ***\n");
    line();
    printf("*** We will start the game again ***\n");
    line();
    Init_Grid();
    return 1;
}

int main()
{
    int x=-1;
    Init_Grid();
    printf("\t\tThis Game is Prepared by Ayman Mohamed Nabil\n");
    printf("\t\tHello to X-O Game, Let's Play right now.\n");
	fflush(stdout);
    while(1)
    {
        printf("\n\n");
        line();
        Player('X');
        x=check_board_for_winner('X');
        if(x==1)
        {
            Win('X');
            break;
        }
        if(Check_Draw()==1)
        {
            continue;
        }
        printf("\n\n");
        line();
        Player('O');
        x=check_board_for_winner('O');
        if(x==1)
        {
            Win('O');
            break;
        }
        if(Check_Draw()==1)
        {
            continue;
        }
    }
    printf("\n\tThanks for Playing\n");
    line();
    return 0;
}