/*
    五子棋
    使用 C 语言复刻一个五子棋游戏
    2021年7月29日 15:19:19 ☆4 晴
    
    搞了两天，终于搞完了，
	是否完美还有待测试。 
 
*/

#include<stdio.h>

int main(void){

    unsigned char P1_Name[32] = "Player 1";
    unsigned char P2_Name[32] = "Player 2";

	unsigned char Player	 = 1; 
    unsigned char win_player = 0;

    // Row -- 行 Columns -- 列
    unsigned int P1_Row, P1_Columns;
    unsigned int P2_Row, P2_Columns;

    // 0 - not finish 1 -- game finish
    unsigned char GameFinish  = 0;  

    // CB -- Checkerboard
    unsigned char CB[9][9] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    };

    // dispaly ckeckerboard
    void dp_cb(void){
    	printf("      1    2    3    4    5    6    7    8    9 \n");
        printf("   +----+----+----+----+----+----+----+----+----+\n");
        printf(" 1 |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n", CB[0][0], CB[0][1], CB[0][2], CB[0][3], CB[0][4], CB[0][5], CB[0][6], CB[0][7], CB[0][8]);
        printf("   +----+----+----+----+----+----+----+----+----+\n");
        printf(" 2 |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n", CB[1][0], CB[1][1], CB[1][2], CB[1][3], CB[1][4], CB[1][5], CB[1][6], CB[1][7], CB[1][8]);
        printf("   +----+----+----+----+----+----+----+----+----+\n");
        printf(" 3 |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n", CB[2][0], CB[2][1], CB[2][2], CB[2][3], CB[2][4], CB[2][5], CB[2][6], CB[2][7], CB[2][8]);
        printf("   +----+----+----+----+----+----+----+----+----+\n");  
        printf(" 4 |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n", CB[3][0], CB[3][1], CB[3][2], CB[3][3], CB[3][4], CB[3][5], CB[3][6], CB[3][7], CB[3][8]);
        printf("   +----+----+----+----+----+----+----+----+----+\n");    
        printf(" 5 |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n", CB[4][0], CB[4][1], CB[4][2], CB[4][3], CB[4][4], CB[4][5], CB[4][6], CB[4][7], CB[4][8]);
        printf("   +----+----+----+----+----+----+----+----+----+\n");    
        printf(" 6 |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n", CB[5][0], CB[5][1], CB[5][2], CB[5][3], CB[5][4], CB[5][5], CB[5][6], CB[5][7], CB[5][8]);
        printf("   +----+----+----+----+----+----+----+----+----+\n");    
        printf(" 7 |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n", CB[6][0], CB[6][1], CB[6][2], CB[6][3], CB[6][4], CB[6][5], CB[6][6], CB[6][7], CB[6][8]);
        printf("   +----+----+----+----+----+----+----+----+----+\n");    
        printf(" 8 |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n", CB[7][0], CB[7][1], CB[7][2], CB[7][3], CB[7][4], CB[7][5], CB[7][6], CB[7][7], CB[7][8]);
        printf("   +----+----+----+----+----+----+----+----+----+\n");
        printf(" 9 |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n", CB[8][0], CB[8][1], CB[8][2], CB[8][3], CB[8][4], CB[8][5], CB[8][6], CB[8][7], CB[8][8]);
        printf("   +----+----+----+----+----+----+----+----+----+\n");
    }

    char input_check(unsigned int dat0_in, unsigned int dat1_in){
        if( (dat0_in>0) && (dat0_in<10) && (dat1_in>0) && (dat1_in<10) && (CB[dat0_in-1][dat1_in-1]!='X') && (CB[dat0_in-1][dat1_in-1]!='O') )
            return 1;
        else    
            return 0;
    }

    char winner(void){
        unsigned char row = 0;
        unsigned char columns = 0;

        for(row=1;row<10;row++){
            for(columns=1;columns<10;columns++){
                unsigned char cnt = 0;
                unsigned char equ = 0;
                
				for(cnt=1;cnt<5;cnt++){
					
					if(CB[row-1][columns-1] == CB[row-1+cnt][columns-1])
						equ++;
					else 
						equ = 0;
				}
					
				if( equ == 4 ){	
					if( CB[row-1][columns-1]=='X' )
						return 1;
					else if( CB[row-1][columns-1]=='O' )
						return 2;
				}else
					equ = 0;
				
				for(cnt=1;cnt<5;cnt++){
					 
					if(CB[row-1][columns-1] == CB[row-1][columns-1+cnt])
						equ++;
					else 
						equ = 0;
				}	
				if( equ == 4 ){	
					if( CB[row-1][columns-1]=='X' )
						return 1;
					else if( CB[row-1][columns-1]=='O' )
						return 2;
					
				}else
					equ = 0;
				
				for(cnt=1;cnt<5;cnt++){

                    if(CB[row-1][columns-1] == CB[row-1+cnt][columns-1+cnt])
						equ++;
					else 
						equ = 0;
				}   
				if( equ == 4 ){	
					if( CB[row-1][columns-1]=='X' )
						return 1;
					else if( CB[row-1][columns-1]=='O' )
						return 2;
				}else
					equ = 0;
            }
        }
        return 0;
	}

    printf("   +-------------------------------------------+\n");
    printf("   |                                           |\n");
    printf("   |               五子棋游戏                  |\n");
    printf("   |                                           |\n");
    printf("   |                                           |\n");    
    printf("   | 游戏规则：                                |\n");
    printf("   | 电脑提示输入的时候，输入对应的坐标（1,3） |\n");
	printf("   | 像这样 1 3，中间用空格隔开                |\n");
    printf("   +-------------------------------------------+\n");
    printf("\n\n\n");
    dp_cb();
    printf("   ------->\n");
    printf("   游戏开始\n");
    printf("   输入玩家 1 的姓名: ");
    scanf("%s", P1_Name);
    getchar();

    printf("   输入玩家 2 的姓名: ");
    scanf("%s", P2_Name);
    getchar();

    while(!GameFinish){	
		if(Player == 1){	
	        P1_Start:
	        printf("   玩家 %s 输入: ", P1_Name);
	        scanf("%u %u", &P1_Row, &P1_Columns);
	        getchar();
	        printf("   玩家 %s 输入的是:(%u, %u)\n",P1_Name , P1_Row, P1_Columns);
	
	        if(input_check(P1_Row, P1_Columns)){
	            CB[P1_Row-1][P1_Columns-1] = 'X';
	        }else{
	            printf("   玩家 %s 输入错误，重新输入\n", P1_Name);
	            goto P1_Start;
	        }
	        
	        dp_cb();
	        Player = 2; 
			 
		}
		
        win_player = winner();
        
        if(win_player == 1){
            printf("   +-------------------------------------------+\n");
            printf("   游戏结束\n");
            printf("   玩家 %s 获胜。\n", P1_Name);
            Player	   = 0;
            GameFinish = 1;
        }
		
		if(Player == 2){
	        P2_Start:
	        printf("   玩家 %s 输入: ", P2_Name);
	        scanf("%u %u", &P2_Row, &P2_Columns);
	        getchar();
	        printf("   玩家 %s 输入的是:(%u, %u)\n",P2_Name , P2_Row, P2_Columns);
	
	        if(input_check(P2_Row, P2_Columns))
	            CB[P2_Row-1][P2_Columns-1] = 'O';
	        else{
	            printf("   玩家 %s 输入错误，重新输入\n", P2_Name);
	            goto P2_Start;
	        }
	        
	        dp_cb();
	        Player = 1;
        
		}
		
        win_player = winner();
        
        if(win_player == 2){
            printf("   +-------------------------------------------+\n");
            printf("   游戏结束\n");
            printf("   玩家 %s 获胜。\n", P2_Name);
            Player     = 0;
			GameFinish = 1;			
		}
    }
    return 0;
}