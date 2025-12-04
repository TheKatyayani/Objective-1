#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int x = 1;              // player position (0 to 2)
    int step = 0;           // obstacle vertical movement
    int obstaclePos = rand() % 3;   // 0,1,2 lane
    
    int lives =3;
    
    int score=0;
    
    int speed_curser;
    if(score<=5){
    	speed_curser=120;
	}else if(score>5 && score<=10){
		speed_curser=50;
	}else{
		speed_curser=10;
	}

   
    while (1) {

        // ---- INPUT ----
        if (_kbhit()) {
            char ch = getch();

            if (ch == 75 && x > 0)        // LEFT arrow
                x--;

            if (ch == 77 && x < 2)        // RIGHT arrow
                x++;
        }

        // ---- DRAW ----
         
        system("cls");
        printf("LIVES: %d\n",lives);
        printf("score: %d\n",score);
        
        printf("|--- --- ---|\n");
		int i;
        for (i = 0; i < 10; i++) {
            if (i == step) {

                if (obstaclePos == 0)
                    printf("| %d        |\n", 1);

                else if (obstaclePos == 1)
                    printf("|     %d    |\n", 1);

                else if (obstaclePos == 2)
                    printf("|        %d |\n", 1);

            } else {
                printf("|           |\n");
            }
        }

        // ---- PLAYER ----
        if (x == 0)
            printf("| %d        |\n", 6);
        else if (x == 1)
            printf("|     %d    |\n", 6);
        else if (x == 2)
            printf("|        %d |\n", 6);

        // ---- COLLISION ----
        
        
        if (step == 10 && x == obstaclePos) {
            printf("\nGAME OVER!\n");
            
          //  break;
          lives--;
          if(lives==0){
          	
          	printf("\n FINAL GAME OVER\n");
          	break;
		  }
	  }
		  if(x!=obstaclePos && step==10){
		  	score++;
		  	
		  }
		 
        

        Sleep(speed_curser);

        // Move obstacle down
        step++;

        // Reset when reaches bottom
        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3; // new lane
        }
    }

    return 0;
}