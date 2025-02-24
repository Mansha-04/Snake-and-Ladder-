#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

 int main(){
	int num;
	printf("Enter number of player between 2 and 4:\n");
	scanf("%d",&num);
	while(num>4 || num<2){
		printf("Please enter valid number of players between 2 and 4:\n");
		scanf("%d",&num);
	}
	char names[num][100];
	for(int i=0;i<num;i++){
		printf("Enter name of Player %d:\n",i+1);
		scanf("%s",&names[i]);
	}

	srand(time(0));


	drawboard(num,names);	


	return 0;
}
void drawboard(int num,char names[][100]){
	int positions[num];
	for(int i=0;i<num;i++){
		positions[i]=0;
	}
	
	int board[100];
	for(int i=0;i<100;i++){
		board[i]=i;
	}
	
	//Ladders
	board[1]=22;
	board[7]=11;
	board[16]=92;
	board[28]=53;
	board[31]=50;
	board[38]=79;
	board[61]=77;
	board[69]=88;
	board[74]=95;

	//Snakes
	board[98]=3;
	board[30]=13;
	board[40]=19;
	board[58]=36;
	board[66]=49;
	board[81]=60;
	board[91]=75;

	playturns(board,positions,num,names);


	
}
void playturns(int board[],int positions[],int num,char names[][100]){
	int count=0;
	while(1){
		int i=count%num;
		int val=rolldice();
		int dest=positions[i]+val;
		if(dest>99){
			printf("Player %s cannot move beyond square 100. Stay at square %d\n",names[i],positions[i]+1);
			continue;
		}
		else{
			if(board[dest]!=dest){
				if(board[dest]>dest){
					printf("Player %s found a ladder! You move up to square %d!\n",names[i],board[dest]+1);
				}
				else{
					printf("Yikes! A snake bites you Player %s and you slide down to square %d!\n",names[i],board[dest]+1);
				}
				dest=board[dest];
				
			}
			else{
				printf("Player %s is at square %d\n",names[i],dest+1); 
			}	
			positions[i]=dest;
			if (positions[i] == 99) {
            			printf("Congratulations, %s! You've reached the top and won the game!\n", names[i]);
            			exit(0);
			}
		}

		
		count++;
	}
}
//int search(int positions[],int num){
//	for(int i=0;i<num;i++){
//		if(positions[i]==100){
//			return i;
//		}
//	}
//	return -1;
//}
int rolldice(){
	int dicenum=rand()%6+1;
	printf("You rolled a %d!\n",dicenum);
	return dicenum;
}




