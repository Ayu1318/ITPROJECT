#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct inputer {
    char inputname[100];
    char inputpass[100];
};
typedef struct inputer data;

struct Game{
    int userChoice;
    int computerChoice;
    char username[100];
};
typedef struct Game gaym;


int getComputerChoice() {
    return rand() % 3; // Returns a random number between 0 and 2 which will give us the output for rock,paper and scissors
}

// This Function is to determine the winner 
void determineWinner(int userChoice, int computerChoice,char* name) {
    if (userChoice == computerChoice) {
        printf("It'S A TIE , TRY AGAIN!\n");
    } 
    else if ((userChoice == 0 && computerChoice == 2) || // Rock beats Scissors
               (userChoice == 1 && computerChoice == 0) || // Paper beats Rock
               (userChoice == 2 && computerChoice == 1)) { // Scissors beats Paper
        printf("%s CONGRATS! YOU HAVE WON AGAINST THE COMPUTER. NOW GO TOUCH SOME GRASS! \n", name);
    } 
    else {
        printf("UGHH BROTHER YOU LOST UGHHHH!\n");
    }
}

int main() {  
    data inp;
    FILE *file;
    char copy1[100];
    char copy2[100];
    file = fopen("project.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    if (fgets(copy1, sizeof(copy1), file) != NULL) {
        strcpy(copy2, copy1);
    } 
    else {
        printf("Error reading from file.\n");
    }



    int i = 0, k = 0;
    char password[100], Name[100];
    char *p;

    for (int l = 4; l >= 1; l--) {
        printf("Enter your username: \n");
        scanf("%s", inp.inputname);
        printf("Enter your password: \n");
        scanf("%s", inp.inputpass);
        p = strstr(copy1, inp.inputname);
        if (p) {
            printf("Name found\n");
            while (*(p + i) != ':') { 
                Name[i] = *(p + i);
                i++;
            }
            Name[i] = '\0';
            i++;
            while (*(p + i) != '\\') {
                password[k] = *(p + i);
                i++;
                k++;
            }
            password[k] = '\0';
           
        } 
        else {
            printf("Name not found in database\n");
        }
        i = 0; k = 0;
        if (!(strcmp(password, inp.inputpass)) && !(strcmp(Name, inp.inputname))) {
            printf("user exist \n");
            
            gaym changer;
            printf("Enter your name");
            fgets(changer.username,100,stdin);

    
            srand(time(NULL));

    // Now, lets display the game options.
            printf("Rock, Paper, Scissors Game\n");
            printf("Enter 0 for Rock, 1 for Paper, 2 for Scissors: ");
            scanf("%d", &changer.userChoice);

    
            if (changer.userChoice < 0 || changer.userChoice > 2) {
                printf("Invalid choice. Please enter 0, 1, or 2.\n");
                return 1; 
                // Exit if invalid input
            }

    //This will get us the computer's choice
    changer.computerChoice = getComputerChoice();

    // Display the choices
            printf("You chose: ");
            if (changer.userChoice == 0) {
                printf("Rock\n");
    } 
            else if (changer.userChoice == 1) {
                     printf("Paper\n");
    } 
            else {
                  printf("Scissors\n");
    }

            printf("Computer chose: ");
            if (changer.computerChoice == 0) {
                printf("Rock\n");
    } 
            else if (changer.computerChoice == 1) {
                     printf("Paper\n");
    } 
            else {
                  printf("Scissors\n");
    }

        // This determines the winner and displays it in the terminal.
        determineWinner(changer.userChoice, changer.computerChoice,inp.inputname);
        fclose(file);
            return 2;
        } 
        else {
            printf("Either password or username is wrong\n");
            printf("%d attempts left\n", l - 1);
        }
    }
    printf("try again after sometime");
    fclose(file);
    return 0;
}

