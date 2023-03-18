// This is a Tic Tac Toe game source code created by Nrupraj Bhendarkar using C programmming.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void in();
void out();
void reset();
char arr[10], box[9], player[3][15];
int i, p = 2, h = 2, r = 0, boxno, re_entered;

int main()
{
    printf("\n  Lets play Game...\n  Press any key to start | 0 to Exit.\n");
    char a = getch();
    static int once = 1;
    switch (a)
    {
    case '0':
        system("cls");
        printf("\n  Thanks for using our program...\n");
        printf("\n\t\t\t~ @its_nrup\n\n\n\n");
        exit(0);
    default:
        h--;
        if (once == 1)
        {
            printf("\n\n\tUsername for Player 1 : ");
            scanf("%s", &player[1]);
            printf("\tUsername for Player 2 : ");
            scanf("%s", &player[2]);
            once = 2;
        }
        reset();
        out();
    }
    return 0;
}

void out()
{
    system("cls");
    printf("\n    %c  |  %c  |  %c  ", arr[1], arr[2], arr[3]);
    printf("\n  _____|_____|_____\n       |     |     ");
    printf("\n    %c  |  %c  |  %c  ", arr[4], arr[5], arr[6]);
    printf("\n  _____|_____|_____\n       |     |     ");
    printf("\n    %c  |  %c  |  %c\n", arr[7], arr[8], arr[9]);

    in();
}

void in()
{
    if (arr[1] == 'X' && arr[2] == 'X' && arr[3] == 'X' || arr[7] == 'X' && arr[8] == 'X' && arr[9] == 'X' || arr[1] == 'X' && arr[4] == 'X' && arr[7] == 'X' || arr[3] == 'X' && arr[6] == 'X' && arr[9] == 'X' || arr[1] == 'X' && arr[5] == 'X' && arr[9] == 'X' || arr[3] == 'X' && arr[5] == 'X' && arr[7] == 'X' || arr[2] == 'X' && arr[5] == 'X' && arr[8] == 'X' || arr[4] == 'X' && arr[5] == 'X' && arr[6] == 'X' || arr[1] == '0' && arr[2] == '0' && arr[3] == '0' || arr[7] == '0' && arr[8] == '0' && arr[9] == '0' || arr[1] == '0' && arr[4] == '0' && arr[7] == '0' || arr[3] == '0' && arr[6] == '0' && arr[9] == '0' || arr[1] == '0' && arr[5] == '0' && arr[9] == '0' || arr[3] == '0' && arr[5] == '0' && arr[7] == '0' || arr[2] == '0' && arr[5] == '0' && arr[8] == '0' || arr[4] == '0' && arr[5] == '0' && arr[6] == '0')
    {
        if (p == 1)
            p = 2;
        else
            p = 1;
        goto end;
    }
    if (r == 9)
    {
        printf("\n  ooops!!!\n  Its Tie\n");
        printf("\n  Lets play again :) \n");
        getch();
        reset();
        out();
    }

    printf("\n  Player %d : %s\n  Enter the box number {", p, player[p]);
    int q;
    for (i = 0; i < boxno; i++)
        printf(" %c", box[i]);
    printf("\n  ");
    scanf("%d", &q);

    if (box[q - 1] != ' ')
    {
        box[q - 1] = ' ';
        r++;
        if (q > 0 && q < 10)
        {
            if (p == 1)
            {
                arr[q] = 'X';
                p = 2;
            }
            else
            {
                arr[q] = '0';
                p = 1;
            }

            out();
        }
        else
        {
            printf("\n  Enter valid input...\n");
            in();
        }
    }
    else
    {
        printf("\n  Entered Box is already Filled !!!\n  Please try another one.\n");
        in();
    }
end:
    printf("\n  Congrats\n  Player %d [ %s ] Won...\n", p, player[p]);
    if (h == 1)
    {
        getch();
        h++;
    }
    main();
}

void reset()
{
    r = 0;
    for (i = 0; i < 10; i++)
        arr[i] = ' ';

    for (i = 0; i < 9; i++)
        box[i] = '1' + i;
    box[i] = ' ';

    if (p == 1)
        p = 2;
    else
        p = 1;

    boxno = 9;
}
