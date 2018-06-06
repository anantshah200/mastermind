// Program : Random code generator and score guesses in Mastermind
// Author : Anant Shah
// Date : 10-5-2018

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char* code(){
	// This function will generate a random code
	int CODE_SIZE = 4; // The number of keys will be 4
	char color; // Store the color of the peg
	int rand_num; // Store the random number which defines the letter
	char *main_code = malloc(CODE_SIZE*sizeof(char)); // Define a memory space for the code
	srand(time(0));
	for(int i=0;i<CODE_SIZE;i++){
		rand_num = rand()%6+1; // This will generate a random number between 1 and  6
		switch(rand_num){
			case 1 : color = 'R'; // Color red
				break;
			case 2 : color = 'G'; // Color green
				break;
			case 3 : color = 'Y'; // Color yellow
				break;
			case 4 : color = 'W'; // Color white
				break;
			case 5 : color = 'B'; // Color blue
				break;
			case 6 : color = 'O'; // Color orange
				break;
			default : exit(0); // Default condition
				break;
		}
		*(main_code+i) = color;  
	}
	return main_code; // Return the randomly generated code
}

char* score(char *main_code,char *guess_code){
	int SIZE = 6; // Size of each array 
	int main_count[SIZE];
	int guess_count[SIZE];
	int CODE_SIZE = 4;
	int i;
	int NO_BLACK[SIZE];
	int NO_WHITE[SIZE];
	int TOT_BLACK=0,TOT_WHITE=0;
	/* Initialization loop */
	for(i=0;i<SIZE;i++){
		main_count[i]=0;
		guess_count[i]=0;
		NO_BLACK[i]=0;
		NO_WHITE[i]=0;
	}
	for(i=0;i<CODE_SIZE;i++){
		switch(*(main_code+i)){
			case 'R' : main_count[0]+=1;
				if(*(guess_code+i)==*(main_code+i))
					NO_BLACK[0]+=1;
				break;
			case 'G' : main_count[1]+=1;
				if(*(guess_code+i)==*(main_code+i))
					NO_BLACK[1]+=1;
				break;
			case 'Y' : main_count[2]+=1;
				if(*(guess_code+i)==*(main_code+i))
					NO_BLACK[2]+=1;
				break;
			case 'W' : main_count[3]+=1;
				if(*(guess_code+i)==*(main_code+i))
					NO_BLACK[3]+=1;
				break;
			case 'B' : main_count[4]+=1;
				if(*(guess_code+i)==*(main_code+i))
					NO_BLACK[4]+=1;
				break;
			case 'O' : main_count[5]+=1;
					if(*(guess_code+i)==*(main_code+i))
						NO_BLACK[5]+=1;
				break;
			default : exit(0); // Default condition
				break; 
		}
		switch(*(guess_code+i)){
			case 'R' : guess_count[0]+=1;
				break;
			case 'G' : guess_count[1]+=1;
				break;
			case 'Y' : guess_count[2]+=1;
				break;
			case 'W' : guess_count[3]+=1;
				break;
			case 'B' : guess_count[4]+=1;
				break;
			case 'O' : guess_count[5]+=1;
				break;
			default : exit(0);
				break;	
		}
	} // We have obtained the counts of all the letters in the secret code and the guess	
	for(i=0;i<SIZE;i++){
		if(main_count[i]>=1)
		{
			if(main_count[i]>=guess_count[i]) NO_WHITE[i]=guess_count[i];
			else	NO_WHITE[i]=main_count[i];
		}
	}
	for(i=0;i<SIZE;i++){
		NO_WHITE[i] = NO_WHITE[i] - NO_BLACK[i];
		TOT_BLACK = TOT_BLACK + NO_BLACK[i];
		TOT_WHITE = TOT_WHITE + NO_WHITE[i];
	}	
	char *guess_score = malloc((TOT_BLACK+TOT_WHITE)*sizeof(char));
	for(i=0;i<TOT_BLACK+TOT_WHITE;i++){
		if(i<TOT_BLACK) *(guess_score+i)='B';
		else		*(guess_score+i)='W';
	}
	return guess_score;
}

int main(int argc,char **argv){
	int CODE_SIZE = 4;
	char *player_code;
	char *guess_score;
	player_code = code();
	int CHANCES = 0;
	char *guess=malloc(CODE_SIZE*sizeof(char));
	scanf("%s",guess);
	guess_score = score(player_code,guess);
	while((strcmp(guess_score,"BBBB")!=0)&&(CHANCES<=5)){
		printf("Guess : %s \n",guess);
		printf("Score : %s \n",guess_score);
		scanf("%s",guess);
		guess_score = score(player_code,guess);
		CHANCES+=1;
	}
	if(CHANCES>10){
		printf("Sorry! You took too many chances \n");
	}
	else{
	printf("Score : %s \n",guess_score);
	printf("Congratulations!! : You have successfully finished the game");
	}
}
