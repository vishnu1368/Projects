#include<stdio.h>
int bat(int,int,int);
int bowl(int,int,int);
int opp_score,score_b;
void main()
{
    int i,m,n,toss,score1=0,batt=0;
    char choice;
	printf("***************\nWelcome to Hand Cricket\n*****************\n");
    printf("***************\nselect the number of overs to be played\n*************\n");
    scanf("%d",&n);
    n=n*6;

    printf("now,it's a time for toss \n*******************\nput 0 for head and 1 for tail\n****************\n");
    scanf("\n%d",&toss);

    toss=rand()%2;
    
	
    if(toss==1){
        printf("you've won the toss\n*******************\nput b for batting and f for fielding\n*******************\n");
        scanf("\n%c",&choice);

		if(choice=='b'){
		        score_b= bat(n,score1,batt);
		        printf("\n***********\nyour score is %d\n*************\n",score_b);
			    printf("\n************\nNow,you're bowling\n**************\n");
		        score1=score_b;
		        batt=batt+1;
		        opp_score=bowl(n,score1,batt);
		        printf("\n***************************\nyour opponent score is %d\n**********************\n",opp_score);
		        if(score_b>opp_score)
		            printf("you have won the match\n");
		        else if(score_b<opp_score)
		            printf("you have lost the match\n");
		            else if(score_b==opp_score)
		            printf("the match ends in draw\n");           
        }

        else if(choice=='f'){
                opp_score=bowl(n,score1,batt);
                printf("\n******************\nyour opponent score is %d\n************\n",opp_score);
                printf("\n****************\n Now you're batting\n*************\n");
				score1=opp_score;
                batt=batt+1;
                score_b=bat(n,score1,batt);
                printf("\n********************\nyour score is %d\n*****************\n",score_b);
                    if(score_b>opp_score)
                        printf("you have won the match\n");
                    else if(score_b<opp_score)
                        printf("you have lost the match\n");
                    else if(score_b==opp_score)
                        printf("the match ends in draw\n");

        }
    }
    
    else{
        printf("Opponent  have  Won the toss");
        toss=rand()%2;
        
        if(toss==0){
            printf(" and opponent have elected to bat first\n");
            opp_score=bowl(n,score1,batt);
            printf("\n******************\nyour opponent score is %d\n************\n",opp_score);
            printf("\n****************\n Now you're batting\n*************\n");
            score1=score_b;
            batt=batt+1;
            score_b=bat(n,score1,batt);
            printf("\n********************\nyour score is %d\n*****************\n",score_b);
            if(score_b>opp_score)
                    printf("you have won the match\n");
            else if(score_b<opp_score)
                    printf("you have lost the match\n");
            else if(score_b==opp_score)
                    printf("the match ends in draw\n");
        }
        
        else{
            printf("  and opponent elected to bowl first\n");
            score_b= bat(n,score1,batt);
            //printf("your  score is %d\n",score_b);
            printf("\n***********\nyour score is %d\n*************\n",score_b);
			printf("\n************\nNow,you're bowling\n**************\n");
            score1=score_b;
            batt=batt+1;
            opp_score=bowl(n,score1,batt);
            printf("\n***************************\nyour opponent score is %d\n**********************\n",opp_score);
            //printf("computer score is %d\n",opp_score);
            if(score_b>opp_score)
                printf("you have won the match\n");
            else if(score_b<opp_score)
                printf("you have lost the match\n");
            else if(score_b==opp_score)
                printf("the match ends in draw\n");
        }
	}
}

int bat(int n,int score1,int batt)
{
    int score=0,bowl,bating,i;
    while(n!=0){
        printf("enter a number b/w 1 to 6\n");
        scanf("%d",&bating);
        printf("\n\n");
        bowl=rand()%6+1;
        printf("%d is  bowled by compuer\n",bowl);
		n--;

        if(bating!=bowl){
	        score=score+bating;
    	    printf("****************\nyour score is %d\n****************\n",score);
		
        	if(batt==1){
        		if(opp_score<score)
        			return(score);
            	
				printf("\n*************\nNeed to get %d runs from %d balls\n*************\n",opp_score-score+1,n);
            }
            printf("%d balls remaining\n",n);
            continue;
        }
        
        else if(bating==bowl){
            printf("you are out\n");
            break;
    	}
        printf("the score is %d\n",score);
    }
        return(score);
}

int bowl(int n,int score1,int batt)
{
    int score=0,bowl,bating,i;
    while(n!=0){
        printf("enter a number b/w 1 to 6 to bowl\n");
        scanf("%d",&bating);
        printf("\n\n");
	    bowl=rand()%6+1;
        printf("%d scored by computer\n",bowl);
        n--;

        if(bating!=bowl){
       		 score=score+bowl;
             if(batt==1){
             	if(score>score_b)
        			return(score);
              
			  	printf("\n*************\nNeed to get %d runs from %d balls\n*************\n",score_b-score+1,n);
            }

		printf("%d balls remaining\n",n);
        printf("\n****************\n%d is computer  score\n****************\n",score);
        continue;
        }
        
        else if(bating==bowl){
            printf("computer  is out now!!\n");
            break;
    	}
   }
            return(score);
}

