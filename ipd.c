#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int computer_move(int comp_move)
{
    srand((unsigned int)time(0));
    if(rand()%2 == 0)
        comp_move=1;
    else
        comp_move=2;
    
    return comp_move;
};

int update_score_p1(int p1_move, int p2_move){
    int score_p1=0,score_p2=0;
    if (p1_move==1 && p2_move==1)
    {
        score_p1=3;
        score_p2=3;
    }
    if (p1_move==1 && p2_move==2)
    {
        score_p1=0;
        score_p2=5;
        
    }
    if (p1_move==2 && p2_move==1)
    {
        score_p1=5;
        score_p2=0;
         
    }
    if (p1_move==2 && p2_move==2)
    {
        score_p1=1;
        score_p2=1;
        
    }
    
    return score_p1;
};

int update_score_p2(int p1_move, int p2_move){
    int score_p1=0,score_p2=0;
    if (p1_move==1 && p2_move==1) {
        score_p1=3;
        score_p2=3;
    }
    if (p1_move==1 && p2_move==2) {
        score_p1=0;
        score_p2=5;
        
    }
    if (p1_move==2 && p2_move==1) {
        score_p1=5;
        score_p2=0;
         
    }
    if (p1_move==2 && p2_move==2) {
        score_p1=1;
        score_p2=1;
        
    }
    
    return score_p2;
};


int comp_move;

int main(){
    int score_p1,score_p2;
    int rounds;
    printf("Enter Number Of Rounds:");
    scanf("%d",&rounds);
    if (rounds==0) {
        printf("\n\nError!!! Rounds shall be 1 or more than 1!!!\n\n");
    }
    int final_p1[rounds],final_p2[rounds];
    
    for (int i=0; i<rounds; i++) {
        printf("\n\nROUND %d",i+1);
        int p1_move;
        
        printf("\n\nEnter 1 to Cooperate, 2 to Defect, 0 to Quit\n");
        scanf("%d",&p1_move);
        int p2_move=computer_move(comp_move);
        
            if (p1_move==1 || p1_move==2) {
                printf("Player 1's move is:%d & Player 2's move is:%d",p1_move,p2_move);
            score_p1=update_score_p1(p1_move, p2_move);
            score_p2=update_score_p2(p1_move, p2_move);
                final_p1[i]=score_p1;
                final_p2[i]=score_p2;
            printf("\nPlayer 1's Score:%d\n",score_p1);
            printf("\nPlayer 2's Score:%d\n",score_p2);
            }
            
            else if (p1_move==0){
                printf("\nExiting Game!!!\n\n");
                exit(0);
            }
           
            else
                printf("\nWrong Input!!! Try Again!!!");
    }
    int sum1=0,sum2=0;
    for (int j=0; j<rounds; j++) {
        sum1+=final_p1[j];
        sum2+=final_p2[j];
    }
    printf("\n\n\nFinal Score Of Player 1: %d",sum1);
    printf("\n\n\nFinal Score Of Player 2: %d",sum2);
    
    if (sum1>sum2) {
        printf("\n\n\nPlayer 1 Wins!!!\n");
    }
    
    if (sum1<sum2) {
        printf("\n\n\nPlayer 2 Wins!!!\n");
    }
    
    if (sum1==sum2) {
        printf("\n\n\nIt's A DRAW!!!\n");
    }
    
    return 0;
}
