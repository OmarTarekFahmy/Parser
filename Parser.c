#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 64
#define MAX_LINE_TOKENS 16
#define MAX_TOKEN_SIZE 16


char*** parse_file(char* filepath){

    FILE* file = fopen(filepath, "r");

    if(file == NULL){
        perror("Unable to open file\n");
    }else{
        printf("File opened successfully\n");
    }

    
    
    char*** file_tokens = (char***)malloc(sizeof(char**) * MAX_LINES);
    char* line_buffer = (char*)malloc(MAX_LINE_TOKENS * MAX_TOKEN_SIZE);
    int line = 0;
    
    while(fgets(line_buffer, MAX_LINE_TOKENS * MAX_TOKEN_SIZE, file)){
        
        char* token = malloc(MAX_TOKEN_SIZE);
        int token_number = 0;
        line_buffer[strcspn(line_buffer, "\n")] = 0;
        token = strtok(line_buffer, " ");
        char** line_tokens = (char**)malloc(sizeof(char*) * MAX_LINE_TOKENS);
        while(token != NULL){
            line_tokens[token_number] = strdup(token);
            token_number++;
            token = strtok(NULL, " ");
        }
        line_tokens[token_number] = NULL;
        file_tokens[line] = line_tokens;
        line++;
    }
    file_tokens[line] = NULL;

    return file_tokens;
}


int main(){
    char*** file_tokens = parse_file("textfile");

    int line_num = 0;
    int token_num = 0;

    char** line = file_tokens[line_num];
    char* token = line[token_num];

    while(line != NULL){
        token_num = 0; 
        token = line[token_num];
        printf("Line %d: ", line_num+1);
        while(token != NULL){
            printf("*%s* ", token); 
            token_num++;
            token = line[token_num];
        }
        printf("\n");
        line_num++;
        line = file_tokens[line_num];
    }
    

}