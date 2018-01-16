#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *fileRead, *fileWrite;
    char ch;
    if(argc != 3){
        printf("\nWrong number of arguments!\n");
        return 1;
    }
    fileRead = fopen(argv[1], "r");
    if(fileRead == NULL){
        printf("\nUnable to open file %s for reading!\n", argv[1]);
        return 2;
    }
    fileWrite = fopen(argv[2], "w");
    if(fileWrite == NULL){
        printf("\nUnable to open file %s for writing!\n", argv[2]);
        fclose(fileRead);
        return 2;
    }
    printf("\nCopy started..");
    while(!feof(fileRead)){
        fscanf(fileRead, "%c", &ch);
        fprintf(fileWrite, "%c", ch);
    }
    fclose(fileRead);
    fclose(fileWrite);
    printf("\nCopied contents of file '%s' to file '%s'..\n", argv[1], argv[2]);
    return 0;
}
