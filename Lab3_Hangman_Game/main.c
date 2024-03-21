#include <stdio.h>
#include <stdlib.h>
#include "english_words.h"
#include <time.h>
#include <string.h>

#define Max_Trial 10

void line()
{
    printf("\n----------------------------------------\n");
}

int Check_guessed_char(char *correct_word,char *hidden_word,char guessed_char)
{
    int flag=0;
    int word_length = strlen(correct_word);
    int i;
    for(i=0;i<word_length;i++)
    {
        if(correct_word[i]==guessed_char)
        {
            flag++;
            hidden_word[i]=guessed_char;
        }
    }
    return flag;
}

int Trial(int *trial,char *correct_word,char *hidden_word)
{
    printf("You Trials = %d\n",*trial);
    printf("The Word is %s\n",hidden_word);
    char guessed_char;
    printf("Guess and Type the char here : ");
    scanf(" %c",&guessed_char);
    if(Check_guessed_char(correct_word,hidden_word,guessed_char))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Check_Hidden_Word(char *hidden_word)
{
    int word_len=strlen(hidden_word);
    int i=0;
    for(i=0;i<word_len;i++)
    {
        if(hidden_word[i]=='_')
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int i;
    printf("Developer Name : Ayman Mohamed Nabil\n");
    printf("Hangman Game Project");
    line();

    int trials=Max_Trial; // Your trials

    char correct_word[20];
    srand((unsigned int)time(NULL));
    int x = rand() % (sizeof(englishWords)/sizeof(englishWords[i]));

    strcpy(correct_word,englishWords[x]);

    int num_word = strlen(englishWords[x]);

    char hidden_word[num_word];

    for(i=0;i<num_word;i++)
    {
        hidden_word[i]='_';
    }
    hidden_word[i]='\0';

    while(trials)
    {
        if(!Trial(&trials,correct_word,hidden_word))
        {
            trials--;
        }
        if(!Check_Hidden_Word(hidden_word))
        {
            break;
        }
    }
    if(trials==0)
    {
        line();
        printf("Oops , Man is Executed");
        printf("\nThe Word was %s",correct_word);
        line();
    }
    else
    {
        line();
        printf("WIIIIIN");
        printf("\nThe Word was %s",correct_word);
        line();
    }



    return 0;
}
