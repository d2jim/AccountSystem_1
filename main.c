#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
//program allows you to create an account
//has a login option if you have already created account
//validates if there is already username
void createAcct() { //function creates account
    char username1[30];
    char username2[30];
    char password1[30];
    char password2[30];
    bool decision1 = true;
    bool decision2 = true;
    system("cls");
    printf("***********Create An Account***********\n");
    FILE * fpun = fopen("username.txt", "a");
    FILE * fppw = fopen("password.txt", "a");
    while (decision1 == true) {
        printf("\nEnter username: ");
        scanf(" %s", username1);
        printf("Re-enter your username: ");
        scanf(" %s", username2);
        if (strcmp(username1, username2) == 0) {
            decision1 = false;
        }
        else {
            decision1 = true;
        }
    }
    while (decision2 == true) {
        printf("\nEnter password: ");
        scanf(" %s", password1);
        printf("Re-enter your password: ");
        scanf(" %s", password2);
        if (strcmp(password1, password2) == 0) {
            decision2 = false;
        }
        else {
            decision2 = true;
        }
    }
    if (checkAccounts(&username1, &password1) >= 1) {
        printf("~~~~~~~This username already exists.~~~~~~~\n\n");
        mainmenu();
    }
    else if ((decision1 == decision2)) {
        fprintf(fppw, "%s\n", password1);
        fprintf(fpun, "%s\n", username1);
        printf("Account Successfully Created!");
    }
    fclose(fpun);
    fclose(fppw);
    return 0;
}
void accountLogin() { //function begins account login
    int i;
    char username1[30];
    char password1[30];
    system("cls");
    printf("***********Account Login***********\n");
    for (i = 0; i < 5; i++) {
        printf("\nEnter Username: ");
        scanf("%s", username1);
        printf("Enter Password: ");
        scanf("%s", password1);
        if (2 == checkAccounts(&username1, &password1)) {
            printf("\n!! Login successful !! ");
        }
        else {
            printf("\n~~~~~~~Incorrect username or password.~~~~~~~ \n\n");
        }
    }
    return 0;
}
int checkAccounts(char* username1, char* password1) { //function looks for correct login credentials && prevents from creating duplicate accounts.
    int accountsuccess = 0;
    char username9[30];
    char password9[30];
    strcat(username1, "\n");
    strcat(password1, "\n");
    FILE * fpun = fopen("username.txt", "r");
    FILE * fppw = fopen("password.txt", "r");
    while ((fgets(username9, 256, fpun) != NULL)&&(fgets(password9, 256, fppw) != NULL)&&(accountsuccess == 0)) {
        if ((strcmp(username1, username9) == 0) && (strcmp(password1, password9) == 0)) {
            accountsuccess = 2;
        }
        else if (strcmp(username1, username9) == 0) {
            accountsuccess = 1;
        }
        else {
            accountsuccess = 0;
        }
    }
    fclose(fpun);
    fclose(fppw);
    return accountsuccess;
}

void mainmenu() {
    int userin;
    printf("What would you like to do today?\n0: Create an Account\n1: Account Login\n");
    scanf("%d", &userin);
    switch (userin) {
        case 0:
            createAcct();
            break;
        case 1:
            accountLogin();
            break;
        default:
            printf("Please select a listed option.\n");
        }

}
int main() {
    printf("Hello world! Welcome to the account system!\n");
    mainmenu();
}
