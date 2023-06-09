#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
char game[50];
char player_name[100];
float moneycome,moneygo,netprofit=0;
float MONEY()
{
    float money;
    a:
    printf("\nHow much money(Rs) do you want to bet?");
    scanf("%f",&money);
    if(money==0)
    {
        fflush(stdin);
        printf("wrong input\n\n\a");
        goto a;
    }
    return money;
}
int rand_value(int sleeptime, int maxrand)
{
    static int roll;
    time_t t;
    sleep(sleeptime);
    srand((unsigned)(time(&t)));
    roll=rand()%maxrand+1;
    return roll;
}

void NumGuess()
{
        FILE *fp;
        fp=fopen("1funfair.txt","a");
        system("color 9F");
        printf("\n********WELCOME TO NUMBER GUESSING GAME");
        strcpy(game,"NUMBER GUESSING GAME");
        printf("\nRULES:");
        printf("\n1-If you guess the number in 2 or less than 2 chances then you will win and you will get 50 percent increase on your bet money");
        printf("\n2-If you guess the number in more than 3 chances then , you will loose both your bet money and game");
        printf("\n3-If you guess the number in 3 chances then game will be a draw and you will get half of your bet money");
        float m=MONEY();
        int w_n;
        w_n=rand_value(0,10);
        int guess=1,num;
        b:
        printf("\nGuess a number from 1 to 10 : ");
        scanf("%d",&num);
        if(num<1||num>10)
        {
            printf("wrong input\n\n\a");
            fflush(stdin);
            goto b;
        }
        while(1)
            {
            if(num==w_n)
                {
                printf("\nYou won");
                printf("\nYou guess this number in %d times",guess);
                break;
                }
            else
                {
                if(num<w_n)
                    printf("\ntoo low");
                else
                {
                    printf("\ntoo high");
                }
                printf("\ntry to guess again : ");
                scanf("%d",&num);
                getchar();
                guess++;
                }

            }
        if(guess>3)
                {
                printf("\n\nfinally you loose because you guess the number in more than 2 times ");
                printf("\nso,you loose your rupees %.1f",m);
                moneycome=m;
                moneygo=0;
                }

        else if(guess==3)
            {
            printf("\n\nfinally game draws");
            printf("\nyou loose your half money,so you will get rupees %.1f",m/2);
            moneycome=m/2;
            moneygo=0;
            }
        else
            {
            printf("\n\nfinally you won");
            printf("\nyou won rupees %.1f",m+(m/2));
            moneycome=0;
            moneygo=m/2;
            }
netprofit+=(moneycome-moneygo);
fprintf(fp,"\n%s\t\t%s\t\t%.1f\t\t\t%.1f\t\t\t%.1f\n",game,player_name,m,moneycome,moneygo);
fclose(fp);
getchar();
}



int luck(int *a)
{
    switch(*a)
    {
    case 2:
        printf("got ladder\n");
        *a=38;
        printf("reached at %d\n",*a);
        break;
    case 4:
        printf("got ladder\n");
        *a=14;
        printf("reached at %d\n",*a);
        break;
    case 9:
        printf("got ladder\n");
        *a=31;
        printf("reached at %d\n",*a);
        break;
    case 45:
        printf("snakes mouth\n");
        *a=15;
        printf("reached at %d\n",*a);
        break;
    case 50:
        printf("snakes mouth\n");
        *a=11;
        printf("reached at %d\n",*a);
        break;
    case 52:
        printf("got ladder\n");
        *a=88;
        printf("reached at %d\n",*a);
        break;
    case 62:
        printf("snakes mouth\n");
        *a=57;
        printf("reached at %d\n",*a);
        break;
    case 80:
        printf("got ladder\n");
        *a=99;
        printf("reached at %d\n",*a);
        break;
    case 92:
        printf("snakes mouth\n");
        *a=53;
        printf("reached at %d\n",*a);
        break;
    case 98:
        printf("snakes mouth\n");
        *a=8;
        printf("reached at %d\n",*a);
        break;

    }
}
void Snake_Ladder()
{
    FILE *fp;
    fp=fopen("1funfair.txt","a");
    strcpy(game,"SNAKE AND LADDER GAME");
    system("color 3F");
    printf("***WELCOME TO SNAKE AND LADDER GAME computer vs you***\n");
    printf("\nRULES:");
    printf("\n1-Both will start from 1\nif You reach at 100 before computer then you will win and if computer reached at 100 before you then computer will win\n");
    printf("2-if you will win then you will get 50 percent increase on your bet money");
    printf("\n2-If you loss then you will loss your bet money");
    printf("\n3-If you accept loss and press 2 then game will be a draw and you will get half of your bet money");
    float m=MONEY();
    int a[10][10]={100,99,98,97,96,95,94,93,92,91,81,82,83,84,85,86,87,88,89,90,80,79,78,77,76,75,74,73,72,71,61,62,63,64,65,66,67,68,69,70,60,59,58,57,56,55,54,53,52,51,41,42,43,44,45,46,47,48,49,50,40,39,38,37,36,35,34,33,32,31,21,22,23,24,25,26,27,28,29,30,20,19,18,17,16,15,14,13,12,11,1,2,3,4,5,6,7,8,9,10};
    int choice=1,you=1,comp=1,i,j;
    printf("10X10 grid is\n");
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%d\t",a[i][j]);
        }
         printf("\n");
    }
    int check=0;
    while(choice!=2&&you!=100&&comp!=100)
    {
        p:
        printf("\nenter your choice: 1 to roll the dice , 2 to exit this game if you accept loss:");
        scanf("%d",&choice);
        fflush(stdin);
        if(choice<1||choice>2)
        {
           printf("wrong input\a");
           goto p;
        }
        if(choice==1)
        {
            int a=rand_value(1,6);
            printf("\ndice:%d\n",a);
            if((you+a)<=100)
            {

            you+=a;
            printf("you: %d\n",you);
            int *p=&you;
            luck(p);
            if(you==100)
            {
                printf("you won the match");
                printf("\nyou won rupees %.1f",m+(m/2));
                moneycome=0;
                moneygo=m/2;
                check++;
                break;
            }
            }
            else{
                printf("you can not move forward at this chance\n");
            }

            int b=rand_value(1,6);
            printf("\ndice:%d\n",b);
            if((comp+b)<=100)
            {
            comp+=b;
            printf("computer:%d\n",comp);
            int *q=&comp;
            luck(q);
            if(comp==100)
            {
                printf("computer won the match");
                printf("\nso,you loose your rupees %.1f",m);
                moneycome=m;
                moneygo=0;
                check++;
                break;
            }
            }
            else{
                printf("computer can not move forward at this chance\n");
            }
        }
    }
    if(check==0)
    {
        printf("you accepted loss");
        printf("\nso you loose your half money,so you will get rupees %.1f",m/2);
        moneycome=m/2;
        moneygo=0;
    }
netprofit+=(moneycome-moneygo);
fprintf(fp,"\n%s\t\t%s\t\t%.1f\t\t\t%.1f\t\t\t%.1f\n",game,player_name,m,moneycome,moneygo);
fclose(fp);
getchar();
}


void SPC()
{
        FILE *fp;
        fp=fopen("1funfair.txt","a");
        strcpy(game,"STONE,PAPER,SCISSOR GAME");
        system("color 2F");
        printf("\n\nWELCOME TO STONE,PAPER,SCISSOR GAME");
        printf("\n\nRULES:");
        printf("\n1-You have only 3 chances");
        printf("\n2-If you won,you will get 50 percent increased of your bet money");
        printf("\n3-If you loose , you will loose your bet money");
        printf("\n4-If game draws,you will get half of your bet money");
        float m=MONEY();
        getchar();
        int pc_points=0;
        int your_points=0;
        int i=0;
        while(i<=2)
            {
            char a[]="spc";
            int b=rand_value(1,2);
            char c;
            printf("\n\nEnter s for stone , p for paper and c for scissor:");
            scanf("%c",&c);
            fflush(stdin);
            if(c!='s'&&c!='p'&&c!='c')
            {
                printf("\nyou has given wrong input\a");
                continue;
            }
            if(a[b]==c)
                {
                printf("\ngame draw because computer chooses %c",a[b]);
                printf("\nyour points till now=%d,computer points till now=%d",your_points,pc_points);
                }
            else if((a[b]=='c'&&c=='p')||(a[b]=='s'&&c=='c')||(a[b]=='p'&&c=='s'))
                {
                printf("\nyou loose because computer chooses %c",a[b]);
                pc_points++;
                printf("\nyour points till now=%d,computer points till now=%d",your_points,pc_points);
                }
            else
                {
                printf("\nyou won because computer chooses %c",a[b]);
                your_points++;
                printf("\nyour points till now=%d,computer points till now=%d",your_points,pc_points);
                }
            i++;
            }
        printf("\n\noverall your points=%d",your_points);
        printf("\noverall computer points=%d",pc_points);
        if(pc_points>your_points)
            {
            printf("\n\nfinally you loose");
            printf("\nyou loose your rupees %.1f",m);
            moneycome=m;
            moneygo=0;
            }
        else if(pc_points==your_points)
            {
            printf("\n\nfinally game draws");
            printf("\nyou loose your half money,so you will get rupees %.1f ",m/2);
            moneycome=m/2;
            moneygo=0;
            }
        else
            {
            printf("\nfinally you won");
            printf("\nyou win rupees %.1f",m+(m/2));
            moneycome=0;
            moneygo=m/2;
            }
netprofit+=(moneycome-moneygo);
fprintf(fp,"\n%s\t%s\t\t%.1f\t\t\t%.1f\t\t\t%.1f\n",game,player_name,m,moneycome,moneygo);
fclose(fp);
getchar();
}


char square[10]={'o','1','2','3','4','5','6','7','8','9'};
void board()
{
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n",square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n",square[4],square[5],square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n",square[7],square[8],square[9]);

    printf("     |     |     \n\n");
}
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if(square[3] == square[5] && square[5] == square[7])
        return 1;

    else if(square[1]!='1'&&square[2]!='2'&& square[3]!= '3'&&square[4]!='4'&&square[5]!='5'&&square[6]!='6'&&square[7]!='7'&&square[8]!='8'&&square[9]!='9')
        return 0;
    else
        return  -1;
}
void TTT()
{
    FILE *fp;
    fp=fopen("1funfair.txt","a");
    strcpy(game," TIC TAC TOE GAME");
    system("color FD");
    printf("\n\nWELCOME TO TIC TAC TOE GAME");
        printf("\n\nRULES:You are player 1");
        printf("\n1-If you won,you will get 50 percent increased of your bet money");
        printf("\n2-If you loose , you will loose your bet money");
        printf("\n3-If game draws,you will get half of your bet money");
        float m=MONEY();
    int player=1,i,choice;
    char mark;
    do
    {
        board();
        player=(player%2)?1:2;
        printf("\nPlayer %d, enter a number:  ",player);
        scanf("%d",&choice);
        getchar();
        mark=(player==1)?'X':'O';
        if(choice==1&&square[1]=='1')
            square[1]=mark;
        else if(choice==2&&square[2]=='2')
            square[2]=mark;
        else if(choice==3&&square[3]=='3')
            square[3]=mark;

        else if(choice==4&&square[4]=='4')
            square[4]=mark;
        else if(choice==5&&square[5]=='5')
            square[5]=mark;
        else if(choice==6&&square[6]=='6')
            square[6]=mark;
        else if(choice==7&&square[7]=='7')
            square[7]=mark;
        else if(choice==8&&square[8]=='8')
            square[8]=mark;

        else if(choice==9&&square[9]=='9')
            square[9] = mark;

        else
        {
            printf("Invalid move\a ");
            player--;
            getchar();
        }
        i=checkwin();
        player++;
    }while(i ==  - 1);

    board();

    if(i==1)
        {
        int p=player-1;
        if(p==1)
            {
                printf("==>\aPlayer %d win ",p);
                printf("\nyou win rupees %.1f",m+(m/2));
                moneycome=0;
                moneygo=m/2;
            }
        else
        {
            printf("==>\aPlayer %d win ",p);
            printf("\nyou loose your rupees %.1f",m);
            moneycome=m;
            moneygo=0;

        }
        }
    else
        {
        printf("==>\aGame draw");
        printf("\nyou loose your half money,so you will get rupees %.1f ",m/2);
        moneycome=m/2;
        moneygo=0;
        }
    square[0]='0';
    square[1]='1';
    square[2]='2';
    square[3]='3';
    square[4]='4';
    square[5]='5';
    square[6]='6';
    square[7]='7';
    square[8]='8';
    square[9]='9';
    netprofit+=(moneycome-moneygo);
    fprintf(fp,"\n%s\t\t%s\t\t%.1f\t\t\t%.1f\t\t\t%.1f\n",game,player_name,m,moneycome,moneygo);
    fclose(fp);
    getchar();
}


void GUESS_COUNTRY()
{
    FILE *fp;
    fp=fopen("1funfair.txt","a");
    strcpy(game,"COUNTRY GUESSING GAME");
    system("color 4F");
    printf("\n***WELCOME TO COUNTRY GUESSING GAME***");
    printf("\nRULES:\n");
    printf("1:All names are in small letters\n");
    printf("2:-If you guess in only one chances then you will won and you will get 50 percent increased of your bet money\n");
    printf("3-If you guess in two chances then game will draw and you will get half of your bet money\n");
    printf("4:-If you  need more than two chances to guess then you will lose game and you will lose your bet money\n\n");
    float m=MONEY();
    int b;
    char *a[]={"india","america","china","pakistan","australia","nepal","bhutan"};
    b=rand_value(0,7)-1;
    char name[30],n[20];
    strcpy(name,a[b]);
    strcpy(n,name);
    char c[30],x;
    int i;
    printf("\n\n");
    for(i=0;name[i]!='\0';i++)
        {
        c[i]='*';
        printf("*");
        }
    getchar();
    for(i=0;i<2;i++)
        {
        printf("\nguess a letter:");
        scanf("%c",&x);
        fflush(stdin);
        for(int j=0;name[j]!='\0';j++)
            {
                if(name[j]==x)
                    {
                    c[j]=x;
                    name[j]='*';
                    }
            }

        for(i=0;name[i]!='\0';i++)
            {
            printf("%c",c[i]);
            }
        }
    char ans[30];
    printf("\nenter your guessed name:");
    gets(ans);
    int j=0;
    for(i=0;n[i]!='\0';i++)
            {
            if(ans[i]==n[i])
                {
                continue;
                }
            else
                {
                j++;
                break;
                }
            }

        if(j==0)
            {
            printf("\nfinally you won");
            printf("\nyou won rupees %.1f",(m+m/2));
            moneycome=0;
            moneygo=m/2;
            }
        else
            {
            printf("\nyour guess is wrong");
            printf("\nguess a letter , its your last chance:");
            scanf("%c",&x);
            getchar();
            for(int k=0;n[k]!='\0';k++)
                {
                    if(n[k]==x)
                        {
                            c[k]=x;
                            n[j]='*';
                        }
                }
            for(i=0;n[i]!='\0';i++)
                {
                printf("%c",c[i]);
                }
            printf("\nenter your guessed name:");
            gets(ans);
            getchar();
            j=0;
            for(i=0;name[i]!='\0';i++)
            {
            if(ans[i]==n[i])
                {
                continue;
                }
            else
                {
                j++;
                break;
                }
            }

            if(j==0)
            {
                printf("\nfinally game draws");
                printf("you loose your half money,so you will get rupees %.1f",m/2);
                moneycome=m/2;
                moneygo=0;
            }
            else
            {
                printf("\ncorrect guess is %s",a[b]);
                printf("\nfinally you loose");
                printf("\nyou loss your rupees %.1f",m);
                moneycome=m;
                moneygo=0;
            }
            }
netprofit+=(moneycome-moneygo);
fprintf(fp,"\n%s\t\t%s\t\t%.1f\t\t\t%.1f\t\t\t%.1f\n",game,player_name,m,moneycome,moneygo);
fclose(fp);
getchar();
}


int MAGIC()
{
    FILE *fp;
    fp=fopen("1funfair.txt","a");
    strcpy(game,"MAGIC GAME");
    system("color 02");
    float c;
    printf("WELCOME TO MAGIC GAME\n");
    printf("This game is free\n");
    printf("I will guess how much rupees you will left with you if you follow all steps very carefully.\n");
    printf("Rule:Press enter if you have done the given task.\n");
    printf("1:Think how much rupees you are having wih you.\n");
    getchar();
    printf("2:Let same amount is given to you by your friend so make total money you are having now ,in your mind.\n");
    getchar();
    c=rand_value(0,500)+1;
    printf("3:Let i am giving you %.1f rupees, so make total in your mind.\n",c);
    getchar();
    printf("4:Give half rupees for charity and caculate money you are having now.\n");
    getchar();
    printf("5:Give your friends rupees to your friend.\n");
    getchar();
    printf("You left %.1f rupees with you.\n",c/2);
    printf("now think how i guess this.\n");
float m=0;
moneycome=0;
moneygo=0;
netprofit+=(moneycome-moneygo);
fprintf(fp,"\n%s\t\t\t%s\t\t%.1f\t\t\t%.1f\t\t\t%.1f\n",game,player_name,m,moneycome,moneygo);
fclose(fp);
getchar();
}
int main()
{
FILE *fp;
fp=fopen("1funfair.txt","a");
fputs("\nGame\t\t\t\tPlayer_name\tBet_money\tMoney_come_to_owner\tMoney_go_from_owner\n",fp);
fclose(fp);
int q=0,ch=0;
char password[10],mypassword[]="n123";
printf("\nEnter password : ");
gets(password);
while(mypassword[q]!='\0')
{
    if(mypassword[q]==password[q])
        {
        q++;
        }
    else
        {
        ch++;
        break;
        }
}
if(ch!=0)
    {
    printf("\nWrong password!\nplease provide correct password\n\a");
    main();
    }
while(1)
{
    system("color 70");
    int x;
    printf("\n\n\n************WELCOME TO FUNFAIR GAMES*************\n");
    printf("\nEnter your name : ");
    gets(player_name);
    printf("\nHello ");
    puts(player_name);
    printf("1:number guessing game\n2:Snake Ladder game\n3:Stone Paper Scissor game\n4:Tic Tac Toe game\n5:Country guessing game\n6:Magic game \n7:exit\nEnter choice:");
    scanf("%d",&x);
    system("cls");
    switch(x)
    {
    case 1:
        NumGuess();
        break;
    case 2:
        Snake_Ladder();
        break;
    case 3:
        SPC();
        break;
    case 4:
        TTT();
        break;
    case 5:
        GUESS_COUNTRY();
        break;
    case 6:
        MAGIC();
        break;
    case 7:
        break;
    default:
        printf("wrong input\a");
    }
    if(x==7)
    {
        printf("*********GAME EXIT**********");
        printf("\n\nOwners net profit is Rupees %.1f\n\n",netprofit);
        FILE *fp;
        fp=fopen("1funfair.txt","a");
        fprintf(fp,"\n\nOwners net profit is Rupees %.1f\n\n\n",netprofit);
        fclose(fp);
        fp=fopen("1funfair.txt","r");
        char b;
        while(fscanf(fp,"%c",&b)!=EOF)
            {
                printf("%c",b);
            }
        fclose(fp);
        break;
    }
}
}
/*******************************************************************
END OF PROJECT
 ********************************************************************/


