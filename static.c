#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processInput(char *input) {
    char buffer[10];
    strcpy(buffer, input);  

    if (input) {
        printf("Input: %s\n", input);
    }

    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
    
        printf("Failed to open file\n");
        return; 
    }
    fclose(file);
}

int main() {
    char *userInput = NULL;
    userInput = (char *)malloc(50 * sizeof(char)); 
    strcpy(userInput, "This is a very long input that exceeds the buffer!");
    processInput(userInput);
    if (userInput) {
        free(userInput); 
    }
    return 0;
}
