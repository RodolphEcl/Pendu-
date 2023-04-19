#include "header.h"


int main()
{

    // 1 if he wanna play more 0 if he dont want to play anymore
    int truee = 1;

    while(truee){
        FILE* folder = NULL ;
        // create a table with 100 words 20 char each and initialise it to 0


        folder = fopen("RODOLPH.txt", "r");

        if (folder != NULL){

            char *secretWord = generateWord(folder);
             int life = 10;

            char *wordDecrypted = decryptWord(secretWord);
            printf("Welcome to the Pendu Game \n ");

            while(life > 0 && strcmp(secretWord, wordDecrypted) != 0){
                char letterToFind;
                printf("You Still have %d lives to play \n What is you secret word ? ", life);
                printf("%s \n", wordDecrypted);
                printf("Guess a letter : ");
                letterToFind = readCaracter();
                printf("\n");


                char *letterIndex = strchr(secretWord, letterToFind);

                if(letterIndex != NULL){
                    int i = 0;
                    while(i <= strlen(secretWord))
                    {
                        if(secretWord[i] == letterToFind)
                        {
                            wordDecrypted[i] = letterToFind;
                        }
                    i++;
                    }

                }
                else


                life--;
            }

            if(life > 0 && strcmp(secretWord, wordDecrypted) == 0){
                printf("Congratulations You Won and you still had %d chances", life);
            }
            else if (life <= 0 && strcmp(secretWord, wordDecrypted) != 0){
                printf("You loose ! Hard Luck and try Again !");
            }



            fclose(folder);

        }

    printf("Wanna play more ? \n 1-Yes \n 0-No \n");
    scanf("%d", &truee);



    }



    return 0;
}






// Function that transforms the secretWord into *****
char *decryptWord(char word[]){

    int i = 0, wordLength = 0;
    static char dWord[100];
    wordLength = strlen(word);
    for(i = 0; i < wordLength; i++){
        dWord[i] = '*';
        }
    dWord[i] = '\0';

    return dWord;

}


//function that takes a character as input
char readCaracter(){
    char caractere = 0;
    caractere = getchar();
    caractere = toupper(caractere);

    while (getchar() != '\n'){}
    return caractere;
}

// function that generates a random number
int generateRandomNum(){
    int randomNum = 0;
    srand(time(NULL));
    randomNum = (rand() % (10 - 1 + 1)) + 1;
    return randomNum;


}

// Function that uses the generate random num function to generate a random word from a folder took as input
char *generateWord(FILE* f){

    int randomNum = 0;
    char listchaine[100][20] = {0};


    int i = 0, j = 0;
    //secretWord is the new word contains only * will be returned
    static char secretWord[100];
    randomNum = generateRandomNum();


    for(i = 0 ; i <= randomNum; i++ ){
        fscanf(f, "%s", &listchaine[i]);
    }

    strcpy(secretWord, listchaine[randomNum]);
    return secretWord;

}

