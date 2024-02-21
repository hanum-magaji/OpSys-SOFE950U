/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

question questions[NUM_QUESTIONS] = {

{
    "Math",
    "What letter is used for imaginary constants",
    "i",
    100,
    false  
},

{
    "Programming",
    "What programmin language does JVM support",
    "Java",
    200,
    false
},

{
    "Soccer",
    "Give the first name of the soccer player who has the most goals(Hint: Starts with R)",
    "Ronaldo",
    300,
    false
}
};


// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    printf("Welcome to the jeopardy game. \n");
    printf("Here are the rules: \n");
    printf("1. To select a question, type the category and the value .\n");
    printf("2. Answer in all caps, in 'WHO IS' or 'WHAT IS'. We don't care which.\n");
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    printf("We have\n");
    for (int i = 0; i < NUM_CATEGORIES; i++)
    {
            printf ("%-5s %-5s\t", categories[i], " ");
 
                for (int j = 0; j < 4; j++)
                {
                    if (quest[i*4 + j].answered == false)
                    {
                        printf("%-2d \t", quest[i*4 +j].value);
                    }
			        else printf("%-2s\t", " ");
                }
        
        printf("\n"); 
    }
    
    printf("Pick your question: ");
    
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for (int i=0; i<NUM_QUESTIONS; i++)
    {
        if ( ( strcmp(quest[i].category, category) == 0 ) && (quest[i].value == value) )
        {
        printf("\033[1;34m\t\t%s\033[0m\n", quest[i].question);
        quest[i].answered = true;
        break;
        }
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
     int test = 0;
    if (answer[strlen(answer)-1] == '\n') { answer[strlen(answer)-1] = '\0'; } //remove newline     
    for (int i=0; i<strlen(answer); i++)
    {
        if (answer[i] == ' ')
        {
            test++;
        }
    }

    if (! (test == 2) ) return false;
  	char *p = strtok(answer, " ");
    if ( !(strcmp(&p, "WHO") || strcmp(&p, "WHAT") ) ) return false; 
    if (p != NULL)  p = strtok(NULL, " ");
    if ( !strcmp(&p, "IS") ) return false;
    if (p != NULL)  p = strtok(NULL, " ");
    strcpy(answer, p);


    for (int i=0; i<NUM_QUESTIONS; i++)
    {
        if ( ( strcmp(quest[i].category, category) == 0 ) && (quest[i].value == value) )
        {
            if ( strcmp(quest[i].answer, answer) == 0 ) 
            {
                return true;
            }
            else { return false; }
        }
    }
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
      for (int i=0; i<NUM_QUESTIONS; i++)
    {
        if ( ( strcmp(quest[i].category, category) == 0 ) && (quest[i].value == value) )
        {
            if ( quest[i].answered == false ) 
            {
                return false;
            }
            else { return true; }
        }
    }

}
