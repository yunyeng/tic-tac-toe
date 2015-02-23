//
//  main.c
//  XOX
//
//  Created by Yunus YENIGOR on 2/22/15.
//  Copyright (c) 2015 projectmayhem. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char *place(int i){
	if(i == 0) return (char*) ' ';
	else if(i == 1) return (char*) 'X';
	else if(i == 2) return (char*) 'O';
}

int main(int argc, const char * argv[]) {
    
    char choice;
    
    int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};


    printf("Type X or O\n");

    scanf(" %c", &choice);
    choice = tolower(choice);
    int computer;

    
    if(choice == 'x'){
        printf("1    |2    |3    \n  %c  |  %c  |  %c  \n     |     |     \n", place(board[0]), place(board[1]), place(board[2]));
        printf("-----------------\n");
        printf("4    |5    |6    \n  %c  |  %c  |  %c  \n     |     |     \n", place(board[3]), place(board[4]), place(board[5]));
        printf("-----------------\n");
        printf("7    |8    |9    \n  %c  |  %c  |  %c  \n     |     |     \n", place(board[6]), place(board[7]), place(board[8]));
    } else if(choice == 'o'){
		srand(time(NULL));
		computer = rand() % 9;
		for(int i=0; i<3; i++){
			printf("%d    |%d    |%d    \n  %c  |  %c  |  %c  \n     |     |     \n",i+1, i+2, i+3, place(board[0]), place(board[1]), place(board[2]));
			printf("-----------------\n");
			
		}
        
    } else {
        printf("Type ONLY X or O\n");

    }
    

    return 0;
}
