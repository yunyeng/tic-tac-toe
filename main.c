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
#define ARR_SIZE(arr) ( sizeof((arr)) / sizeof((arr[0])) )

int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

char place(int i){
	if(i == 0) return (char) ' ';
	else if(i == 1) return (char) 'X';
	else if(i == 2) return (char) 'O';
	return ' ';
}

int boardFull(){
	for(int i=0; i<9; i++)
		if(board[i] == 0)
			return 0;
	return 1;
}

int isEmpty(int i){
	return board[i] == 0;
}

int placeComputer(int c){
	if(!boardFull()){
		if(isEmpty(c) != 1){
			placeComputer(rand() % 9);
		} else {
			return c;
		}	
	} else {
		return -1;
	}
}

void clearBoard(){
	for(int i=0; i<9; i++) board[i] = 0;
}

void render(){
	for(int i=0; i<9; i++){
		if(i % 3 == 0){
			printf("\n------------------------------\n");
			printf("|        |        |          |\n");
		}
		if(board[i] != 0){
			printf("|%d   %c   ", i, place(board[i]));
		} else{
			 printf("|%d       ",i);
		}
		if(i % 3 == 2) printf("  |");
		if(i % 3 == 2){
			printf("\n|        |        |          |");
		}
	}
	printf("\n------------------------------");
}

int check(int who){
	if(board[0] == who && board[1] == who && board[2] == who){
		return 1;
	} else if(board[3] == who && board[4] == who && board[5] == who){
		return 1;
	} else if(board[6] == who && board[7] == who && board[8] == who){
		return 1;
	} else if(board[0] == who && board[3] == who && board[6] == who){
		return 1;	
	} else if(board[1] == who && board[4] == who && board[7] == who){
		return 1;		
	} else if(board[2] == who && board[5] == who && board[8] == who){
		return 1;	
	} else if(board[0] == who && board[4] == who && board[8] == who){
		return 1;	
	} else if(board[2] == who && board[4] == who && board[6] == who){
		return 1;	
	}
	return 0;
}

void multiplayer(){
	int gameOver = 0;
	while(gameOver == 0){
		int userx;
		int usero;
		printf("\nPlayer X your turn!");
		render();
		printf("\nWhere do you want to put X? (0-8)\n");
		scanf("%d", &userx);
		if(!isEmpty(userx)){
			printf("\nYou need to choose somewhere else!\n");
			continue;
		} else {
			board[userx] = 1;
		}
		
		if(check(1) == 1){
					gameOver = 2;
					render();
					break;
				} else if(check(2) == 1){
					gameOver = 1;
					render();
					break;
				} else if(boardFull()){
					gameOver = 3;
					render();
					break;
				}
		
		
		render();
		printf("\nPlayer O your turn!");
		printf("\nWhere do you want to put O? (0-8)\n");
		scanf("%d", &usero);
		if(!isEmpty(usero)){
			printf("\nYou need to choose somewhere else!\n");
			continue;
		} else {
			board[usero] = 2;
		}
		
		
		if(check(1) == 1){
			gameOver = 2;
			render();
			break;
		} else if(check(2) == 1){
			gameOver = 1;
			render();
			break;
		} else if(boardFull()){
			gameOver = 3;
			render();
			break;
		}
	
	
	
	}
	
	if(gameOver == 2){
				printf("\nPlayer X Wins!\n");
			} else if(gameOver == 1){
				printf("\nPlayer O Wins!\n");
			} else if(gameOver == 3){
				printf("\nDRAWS!");
			}
	
	
	char playAgain;
	printf("\n\nPlay Again? (Y/N)\n\n");
	scanf(" %c", &playAgain);
	playAgain = tolower(playAgain);
	if(playAgain == 'y'){
		clearBoard();
		main();
	}
}

void singleGame(){
	srand(time(NULL));
		char XorO;
		int gameOver = 0;
		int again = 0;
		printf("Type X or O\n");
		scanf(" %c", &XorO);
		XorO = tolower(XorO);
		int computer;
		int user;
		while(gameOver == 0 && XorO != 'q'){
		    if(XorO == 'x'){
					/* SHOW THE XOX BOARD */
					render();
					/* SHOW THE XOX BOARD */
					printf("\n\n\nWhere do you want to put X? (0-8)\n");
					scanf("%d", &user);
					if(!isEmpty(user)){
						printf("\nYou need to choose somewhere else!\n");
						continue;
					} else {
						board[user] = 1;
					}
					
					computer = rand() % 9;
					while(!isEmpty(computer)){
						computer = rand() % 9;
					}
					board[computer] = 2;
					
					if(check(1) == 1){
						gameOver = 2;
						render();
						break;
					} else if(check(2) == 1){
						gameOver = 1;
						render();
						break;
					} else if(boardFull()){
						gameOver = 3;
						render();
						break;
					}
		    } else if(XorO == 'o'){
				computer = rand() % 9;
				if(again == 0){
					if(isEmpty(computer)){ 
						board[computer] = 1;
					} else {
						computer = rand() % 9;
						continue;
					}
				}
				again = 0;
				/* SHOW THE XOX BOARD */
				render();
				/* SHOW THE XOX BOARD */
				if(check(2) == 1){
					gameOver = 2;
					break;
				} else if(check(1) == 1){
					gameOver = 1;
					break;
				} else if(boardFull()){
					gameOver = 3;
					break;
				}
				printf("\n\n\nWhere do you want to put O? (0-8)\n");
				scanf("%d", &user);
				if(!isEmpty(user)){
					printf("\nYou need to choose somewhere else!\n");
					again = 1;
				} else {
					board[user] = 2;
					computer = rand() % 9;
				}
				
				
		    } else {
				printf("Type ONLY X or O\n");
				printf("Type X or O\n");
				scanf(" %c", &XorO);
				XorO = tolower(XorO);
		    }
		
		}
		
		if(gameOver == 1){
			printf("\nYOU LOST!");
		} else if(gameOver == 2){
			printf("\nYOU WIN!");
		} else if(gameOver == 3){
			printf("\nDRAWS!");
		}
		
		char playAgain;
		printf("\n\nPlay Again? (Y/N)\n\n");
		scanf(" %c", &playAgain);
		playAgain = tolower(playAgain);
		if(playAgain == 'y'){
			clearBoard();
			main();
		}
}


int main() {
	char type;
	printf("Single Game or MultiPlayer? (S / M)\n");
	scanf(" %c", &type);
	type = tolower(type);
	if(type == 's'){
		clearBoard();
		singleGame();		
	} else if(type == 'm'){
		clearBoard();
		multiplayer();
	} else {
		printf("Type 'S' for Single Game or 'M' for Multiplayer.\n");
		clearBoard();
		main();
	}

	
	return 0;
}
