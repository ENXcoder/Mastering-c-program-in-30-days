//number guessing game
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int attempts=0;
int n; //guessed number
int choice;
void tolowercase(char *str){
    
    while (*str)
    {
        *str=tolower(*str);
        str++;

    }
    
}
int main(){
    srand(time(0));
    char again[100];
    
    int kezhap=0,guessnum;
    
    do{ 
        guessnum=rand()%100+1;
        printf("Lets start the game\n");
        printf("You can  guess upto 10times!!");
        redo:
        printf("I choosed a number between 1  to 100\n");
        re:
        printf("Enter your guess:");
        scanf("%d",&n);
        if(n<=0 || n>100){
            kezhap++;
             if(kezhap>=5){
            printf("Retry limit exceeded!!");
            break;
             }else{
            printf("You can guess numbers from 1 to 99 only!! \n");
            goto redo;
        }
           
        }else{ 
             if(n>guessnum){
                printf("Your guess is too high!\n");
                attempts++;
                if(attempts==5){
                    printf("Do you want continue or quit the game??\n[+]1\n[+2]\n");
                    printf(">>");
                    scanf("%d",&choice);
                    if(choice==1){
                        goto re;
                    }else if(choice==2){
                    printf("Exiting program...");
                    break;}
                }else if(attempts==10){
                    printf("Guessing limit reached!!");
                    break;}
                else{
                    goto re;
                }

            }else if(n<guessnum){
                printf("Your guess is too low!\n");
                attempts++;
                if(attempts==5){
                    printf("Do you want continue or quit the game??\n[+]1\n[+2]\n");
                    printf(">>");
                    scanf("%d",&choice);
                    if(choice==1){
                        goto re;
                    }else if(choice==2){
                    printf("Exiting program...");
                    break;}
                }else if(attempts==10){
                    printf("Guessing limit reached!!");
                    break;}
                else{
                    goto re;
                }
            }else{
                attempts++;
                printf("Congratulation you guessed the correct number in  %d attempt!\n",attempts);
            }

            }
        attempts=0;
        printf("Do you want to play again:");
        scanf(" %s",again);
        tolowercase(again);
        
    }while(strcmp(again,"yes")==0 || strcmp(again,"y")==0);
    
    printf("Program exited!!");
    

}
