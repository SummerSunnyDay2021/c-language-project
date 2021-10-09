/*
    2021年7月28日 14点38分

    龙棋游戏，
    小的时候玩的龙棋，C语言的复刻版

    由两个玩家轮流下，玩家 1 用 X 表示，玩家 2 用 O 表示
    当任意三个同样的棋子连成一条线者获胜。

*/

#include<stdio.h>

int main(void){
    // player1 player2 -- 1 or 2
    unsigned char player = 1;
    unsigned char p1, p2;
    unsigned char game_stop = 'Y';
    unsigned char winner = 0;
    unsigned char cnt = 0;
    unsigned char Game_Array[3][3] = {
        { '1', '2', '3' },
        { '4', '5', '6' }, 
        { '7', '8', '9' } 
    };

    printf("---+---+---\n");
    printf(" %c | %c | %c \n", Game_Array[0][0], Game_Array[0][1], Game_Array[0][2] );
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", Game_Array[1][0], Game_Array[1][1], Game_Array[1][2] );
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", Game_Array[2][0], Game_Array[2][1], Game_Array[2][2] );
    printf("---+---+---\n");

    while(game_stop != 'n'){

        if(player==1){

            P1_Start:
            printf("玩家 1 输入:");
            scanf("%d", &p1);
            getchar();
            printf("玩家 1 输入的是:%d\n", p1);

            if( (p1>9) || (p1<1) || (Game_Array[p1/3][p1%3 - 1]=='O') || (Game_Array[p1/3][p1%3 - 1]=='X') ){
                printf("玩家 1 输入数据不对，重新输入。\n");
                goto P1_Start;
            }else{
                Game_Array[p1/3][p1%3 - 1] = 'X';
            }

            player = 2;
        }else if(player==2){

            P2_Start:
            printf("玩家 2 输入:");
            scanf("%d", &p2);
            getchar();
            printf("玩家 2 输入的是:%d\n", p2);

            if( (p2>9) || (p2<1) || (Game_Array[p2/3][p2%3 -1] == 'O') || (Game_Array[p2/3][p2%3 -1] == 'X') ){
                printf("玩家 2 输入数据不对，重新输入。\n");
                goto P2_Start;
            }else{
                Game_Array[p2/3][p2%3 -1] = 'O';
            }
            player = 1;
        }

        printf("---+---+---\n");
        printf(" %c | %c | %c \n", Game_Array[0][0], Game_Array[0][1], Game_Array[0][2] );
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", Game_Array[1][0], Game_Array[1][1], Game_Array[1][2] );
        printf("---+---+---\n");
        printf(" %c | %c | %c \n", Game_Array[2][0], Game_Array[2][1], Game_Array[2][2] );
        printf("---+---+---\n");

        if      ( ( Game_Array[0][0] == Game_Array[0][1] ) && ( Game_Array[0][1] == Game_Array[0][2] ) ){
            if(Game_Array[0][1] == 'X')
                winner = 1;
            else 
                winner = 2;
        }else if( (Game_Array[1][0] == Game_Array[1][1] ) && ( Game_Array[1][1] == Game_Array[1][2] ) ){
            if(Game_Array[1][1] == 'X')
                winner = 1;
            else 
                winner = 2;

        }else if( (Game_Array[2][0] == Game_Array[2][1] ) && ( Game_Array[2][1] == Game_Array[2][2] ) ){
            if(Game_Array[2][1] == 'X')
                winner = 1;
            else 
                winner = 2;

        }else if( (Game_Array[0][0] == Game_Array[1][0] ) && ( Game_Array[1][0] == Game_Array[2][0] ) ){
            if(Game_Array[1][0] == 'X')
                winner = 1;
            else 
                winner = 2;

        }else if( (Game_Array[0][1] == Game_Array[1][1]) && (Game_Array[1][1] == Game_Array[2][1]) ){
            if(Game_Array[1][1] == 'X')
                winner = 1;
            else 
                winner = 2;

        }else if( (Game_Array[0][2] == Game_Array[1][2]) && (Game_Array[1][2] == Game_Array[2][2]) ){
            if(Game_Array[1][2] == 'X')
                winner = 1;
            else 
                winner = 2;

        }else if( (Game_Array[0][0] == Game_Array[1][1]) && (Game_Array[1][1] == Game_Array[2][2]) ){
            if(Game_Array[1][1] == 'X')
                winner = 1;
            else 
                winner = 2;

        }else if( (Game_Array[0][2] == Game_Array[1][1]) && (Game_Array[1][1] == Game_Array[2][0]) ){
            if(Game_Array[1][1] == 'X')
                winner = 1;
            else 
                winner = 2;
        }

        if(winner!=0){
            printf("游戏结束，玩家 %d 获胜\n", winner);
            game_stop = 'n';
        }

        // determine winner
        for(unsigned char i = 0; i < 3; i++){
            for(unsigned char j = 0; j < 3; j++){
                if((Game_Array[i][j]=='X')||(Game_Array[i][j]=='O')){
                    cnt++;
                }
            }
        }

        if( (cnt==9)&&(winner == 0) ){
            printf("平局，棋盘已满，游戏结束\n");
            game_stop = 'n';
        }  
    }

    return 0;
}