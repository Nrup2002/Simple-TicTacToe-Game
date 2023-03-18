#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void in();
void out();
void reset();
char arr[10], box[9], player[3][15], n_player;
int i, p = 2, h = 2, r = 0, boxno, re_entered, rand_num, p_won[3];
void get_line()
{
    printf("\n--------------------------------------------------\n");
}
void scorecard()
{
    printf("\t%s : %d\t%s : %d\tTie : %d", player[1], p_won[1], player[2], p_won[2], p_won[0]);
}

int main()
{
    srand(time(NULL));
    printf("\n\n   Lets play Game...\n   Press any key to start | 0 to Exit.\n\n");
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
    Enter_valid_n_player:
        if (once == 1)
        {
            p_won[1] = 0;
            p_won[2] = 0;
            p_won[0] = 0;
            get_line();
            printf("\t1. Single Player  |  2. Two Player");
            get_line();
            printf("\n   Press key[1/2] to Choose :");
            n_player = getch();

            if (n_player == '2')
            {
                printf("\n\n\tUsername for Player 1 : ");
                scanf("%s", &player[1]);
                printf("\tUsername for Player 2 : ");
                scanf("%s", &player[2]);
            }

            else if (n_player == '1')
            {
                printf("\n\n\tPlease Enter your Username : ");
                scanf("%s", &player[1]);
                char computer[15] = "Computer";
                for (i = 0; i < 8; i++)
                    player[2][i] = computer[i];
            }
            else
                goto Enter_valid_n_player;
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
    get_line();
    printf("\t\t %s VS %s", player[1], player[2]);
    get_line();
    scorecard();
    printf("\n\n\n\t\t  %c  |  %c  |  %c  ", arr[1], arr[2], arr[3]);
    printf(" \n\t\t_____|_____|_____\n\t\t     |     |     ");
    printf("\n\t\t  %c  |  %c  |  %c  ", arr[4], arr[5], arr[6]);
    printf(" \n\t\t_____|_____|_____\n\t\t     |     |     ");
    printf("\n\t\t  %c  |  %c  |  %c\n", arr[7], arr[8], arr[9]);

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
        scorecard();
        printf("\n\n  Lets play again :) \n");
        ++p_won[0];
        getch();
        reset();
        out();
    }

    printf("\n  Player %d : %s\n  Enter the box number {", p, player[p]);
    int q;
    for (i = 0; i < boxno; i++)
        printf(" %c", box[i]);
    printf("\n  ");
    if (n_player == '2' | (n_player == '1' && p == 1))
        scanf("%d", &q);
    else
        do
        {
            q = rand() % 10;
            if (box[q - 1] != ' ' && q != 0)
                break;
        } while (1);

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
    printf("\n  Congrats\n  Player %d [ %s ] Won...\n\n", p, player[p]);
    ++p_won[p];
    scorecard();
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
