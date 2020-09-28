#include <stdio.h>

void display_names() {
	char p1[100],p2[100];
	printf("Enter name of first players\n");                                    //Input name of 1st players
	fgets(p1, sizeof(p1), stdin);

	printf("Enter name of second players\n");
	fgets(p2, sizeof(p2), stdin);

	printf("Player1: ");
	puts(p1);
	printf("Player2: ");
	puts(p2);
}
int main() {

	int table[2][4]= {
		{2,2,0,0},
		{0,0,1,1}
	};
	int i=0,j=0,k=0,count=0;
	int a1[2],a2[2],a3[2],a4[2];

	display_names();                                                             //display_names
	printf("             Player1\n");
	printf("             X      Y\n");
	printf("Player2  ");
	for(i=0; i<2; i++) {
		if(i==0) {
			printf("X  ");
		} else {
			printf("         Y  ");
		}
		for(j=0; j<4; j++) {
			printf("%d ",table[i][j]);
			if(j==1) {
				printf("  ");
			}
		}
		printf("\n");
	}


	printf("\nnash_equlibrium\n\n");
	printf("Case1:\n");
	printf("If player1 chooses X\n");
	printf("Player2 has two options X or Y\n");
	if(table[0][0]>table[1][0]) {
		printf("Player2 chooses X\n\n");
		a1[0]=0;
		a1[1]=0;
	} else {
		printf("Player2 chooses Y\n\n");
		a1[0]=1;
		a1[1]=0;
	}

	printf("If player1 chooses Y\n");
	printf("Player2 has two options X or Y\n");
	if(table[0][2]>table[1][2]) {
		printf("Player2 chooses X\n\n");
		a2[0]=0;
		a2[1]=2;
	} else {
		printf("Player2 chooses Y\n\n");
		a2[0]=1;
		a2[1]=2;
	}

	printf("Case2:\n");
	printf("If player2 chooses X\n");
	printf("Player1 has two options X or Y\n");
	if(table[0][1]>table[0][3]) {
		printf("Player1 chooses X\n\n");
		a3[0]=0;
		a3[1]=1;
	} else {
		printf("Player1 chooses Y\n\n");
		a3[0]=0;
		a3[1]=3;
	}

	printf("If player2 chooses Y\n");
	printf("Player1 has two options X or Y\n");
	if(table[1][1]>table[1][3]) {
		printf("Player1 chooses X\n\n");
		a4[0]=1;
		a4[1]=1;
	} else {
		printf("Player1 chooses Y\n\n");
		a4[0]=1;
		a4[1]=3;
	}

	printf("\nCalculating Nash Equilibrium\n");
	
	if(a1[0]==0 && a1[1]==0) {
		if(a3[0]==0 && a3[1]==1) {
			printf("Nash Equilibrium if both player chooses 'X':(X,X)\n");
			count++;
		}
	} else {
		if(a4[0]==1 && a4[1]==1) {
			printf("Nash Equilibrium if player1 chooses 'X' and player2 chooses 'Y':(X,Y)\n");
			count++;
		}
	}
	if(a2[0]==0 && a2[1]==2) {
		if(a3[0]==0 && a3[1]==3) {
			printf("Nash Equilibrium if player1 chooses 'Y' and player2 chooses 'X':(Y,X)\n");
			count++;
		}
	} else {
		if(a4[0]==1 && a4[1]==3) {
			printf("Nash Equilibrium if both player chooses 'Y':(Y,Y)\n");
			count++;
		}
	}
	if(count==0)
	{
		printf("There is no nash equlibrium");
	}
	else
	{
		printf("Hence, %d nash equilibrium",count);
	}
	

	return 0;
}




