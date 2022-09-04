#pragma warning(disable:4996)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

/*
    Source by GeeksForGeeks (https://www.geeksforgeeks.org)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main() {
    if (fork() == 0) {
        FILE* h = fopen("file.txt", "a");
        char* line = "gggggggggggggggggggggggggggggggggggggggggggggggg\n";
        
        for (int i = 0; i < 1000; i++) {
            if (fwrite(line, 1, strlen(line), h) != strlen(line)) {
                perror("Could not append line to file");
                exit(1);
            }
        }
        
        if (fclose(h) != 0) {
            perror("Could not close file");
            exit(1);
        }
    } else {
        FILE* h = fopen("file.txt", "a");
        char* line = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb\n";

        for (int i = 0; i < 1000; i++) {
            if (fwrite(line, 1, strlen(line), h) != strlen(line)) {
                perror("Could not append line to file");
                exit(1);
            }
        }

        if (fclose(h) != 0) {
            perror("Could not close file");
            exit(1);
        }
    }

    _getch();
    return 0;
}