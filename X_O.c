#include <stdio.h>
//chihab
const int R_SIZE=3;
const int C_SIZE=3;
const char list[9]  = {  '0' , '1','2','3','4','5','6','7','8'};
const char RED[10] = "\033[0;31m";
const char  White[10] = "\033[0;37m";
const char GREEN[10] = "\033[0;32m";

int win = 0;

void fillTheList(char matrix[C_SIZE][R_SIZE]){

	int k=0;
	for (int i = 0; i <= C_SIZE-1; ++i){
			for (int j = 0; j <=R_SIZE-1 ; ++j){

				matrix[i][j]=list[k];
				k+=1;
			}
		}


}
void printTheGame(char matrix[C_SIZE][R_SIZE]){
	
	for (int i = 0; i <= C_SIZE-1; ++i){
			printf("----------------\n");
			for (int j = 0; j <=R_SIZE-1 ; ++j){

				if(matrix[i][j]=='O'){
					printf("%s",GREEN);
				}else{
					if (matrix[i][j]=='X')
					{
						printf("%s",RED);
					}
				}
				printf("%c",matrix[i][j]);
				printf("%s",White);
				printf(" | ");
			}

			printf("\n");
		}
			
			printf("----------------\n\n");



}
int checkForWin(char matrix[C_SIZE][R_SIZE],char player){

	for(int i =0;i<=C_SIZE-1;i++){
	if(player == matrix[i][0] && player == matrix[i][1] &&player == matrix[i][2] ){
		printf("%c is the winner",player);
		return 1;
	}
	}

	for(int i =0;i<=C_SIZE-1;i++){
	if(player == matrix[0][i] && player == matrix[1][i] &&player == matrix[2][i] ){
		printf("%c is  the winner",player);
		return 1;
	}
	}
	if(player  == matrix[0][0] && player  == matrix[1][1] && player == matrix[2][2] ){
		printf("%c is  the winner",player);
		return 1;	
	}

	if(player  == matrix[2][0] && player  == matrix[1][1] && player == matrix[0][2] ){
		printf("%c is  the winner",player);
		return 1;	
	}
	return 0;
	/*winning combinations


	[	[0 0 0]
		[0 0 0]
		[0 0 0]
		[0 . .]
		[. O .]
		[. . 0]
		[. . O]
		[. O .]
		[O . .]
		
		[O..]
		[O..]
		[O..]


		]
	*/
}
void play(char player,int place,char matrix[C_SIZE][R_SIZE]){
	
	int k=0;
	for (int i = 0; i <= C_SIZE-1; ++i){
			for (int j = 0; j <=R_SIZE-1 ; ++j){
				if(k==place){
					int t =0;
					for(int c=0;c<9;c++){
						//printf("%c != %c\n",list[c],matrix[i][j]);
						
					}
						if(matrix[i][j]!='O' && matrix[i][j]!='X'  ){
						matrix[i][j]=player;
						printTheGame(matrix);							
						win = checkForWin(matrix,player);
						}

					
					}
					k++;
			}
			printf("\n");
		}
}
int main(int argc, char const *argv[])
{
	char m[C_SIZE][R_SIZE];
	char temp;
	int k=0;
	int turn =0;
	//filling the list 

	int place;
	fillTheList(m);
	printTheGame(m);
	while(!win){
	if(turn==0){
		printf(" O in =>");
		scanf("%d",&place);
		play('O',place,m);
		turn=1;
	}else{
		printf(" X in =>");
		scanf("%d",&place);
		play('X',place,m);
		turn=0;

	}}
}
