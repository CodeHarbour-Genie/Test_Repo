#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processInput(char *userInput_Name, char *userInput_Gender, int *userInput_Age) {
    char buffer_Name[5];
    char buffer_Gender[5];
    int buffer_Age[5];
    
    strcpy(buffer_Name, userInput_Name);  
    strcpy(buffer_Name, userInput_Gender);  
    strcpy(buffer_Name, userInput_Age);  

    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
    
        printf("Failed to open file\n");
        return; 
    }
    else {

        if (userInput_Name) {
       
    fprintf(file, "Name: %s", userInput_Name);
    fprintf(file, "Gender: %s\n", userInput_Gender);
    fprintf(file, "Age: %d\n", userInput_Age);
    }

    }
    fclose(file);
}

int main() {
    char *userInput_Name, *userInput_Gender = NULL;
    int *userInput_Age = NULL;
    userInput_Name = (char *)malloc(10 * sizeof(char)); 
    userInput_Gender = (char *)malloc(10 * sizeof(char)); 
    userInput_Age = (int *)malloc(10 * sizeof(int)); 
    strcpy(userInput_Name, "Vaishali Jain");
    strcpy(userInput_Gender, "Female");
    strcpy(userInput_Age, "25");

    processInput(userInput_Name, userInput_Gender, userInput_Age);
    if (userInput_Name) {
        free(userInput_Name); 
        free(userInput_Gender); 
        free(userInput_Age); 
    }
    return 0;
}
