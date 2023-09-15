#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    bool loop = true;
    int r = 15;
    int c = 20;
    char** text = (char**)malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        text[i] = (char*)malloc(c * sizeof(char));
        text[i][0] = '\0';  // initialize each row to empty string
    }
    int curRow = 0;
    printf("1-Append in the end, 2-Start new line, 3-Save to file, 4-load from file, 5-print to console, 6-Insert text by indexes, 7-search, 8-clear\n");
    while (loop == true) {
        char str;
        scanf_s("%c", &str);
        while ((getchar()) != '\n');
        printf("The entered int is: %c\n", str);
        switch (str)
        {
        case '1':
        {


            printf("Append  the end\n");
            int appendTextSize = 20;
            char* appendText = (char*)malloc(appendTextSize * sizeof(char));

            fgets(appendText, appendTextSize, stdin);

            size_t len = strlen(appendText);
            if (len > 0 && appendText[len - 1] == '\n') {
                appendText[len - 1] = '\0';

            }
            size_t ROWLEN = strlen(text[curRow]);
            while (len == appendTextSize - 1) {
                appendTextSize = appendTextSize * 2;
                appendText = (char*)realloc(appendText, appendTextSize * sizeof(char));
                fgets(appendText + len, appendTextSize - len, stdin);
                len = strlen(appendText);
            }
            while (ROWLEN + len + 1 > c) {
                c *= 2;  // double the row capacity
                text[curRow] = (char*)realloc(text[curRow], c * sizeof(char));
                ROWLEN = strlen(text[curRow]);
            }
            strcat_s(text[curRow], c, appendText);
            printf("The entered text is: %s\n", text[curRow]);
            break;
        }
        case '2':
            printf("Start new line\n");
            strcat_s(text[curRow], c, "\n");
            curRow++;
            if (curRow == r) {
                r *= 2;  // double the number of rows
                text = (char**)realloc(text, r * sizeof(char*));
                for (int i = curRow; i < r; i++) {
                    text[i] = (char*)malloc(c * sizeof(char));
                    text[i][0] = '\0';  // initialize each new row to empty string
                }
            }
            break;

        case '3':

            printf("Save to file\n");
            FILE* file;
            file = fopen("myFile.txt", "w");
            if (file != NULL)
            {
                for (int i = 0; i < r; i++) {
                    if (text[i][0] != '\0') {

                        fputs(text[i], file);
                    }
                }
                fclose(file);
            }
            else {
                printf("Null\n");
            }
            break;

        case '4':
            printf("load from file\n");
            FILE* fileLoad;
            char mystring[900];
            file = fopen("myFile.txt", "r");
            if (file == NULL)
            {
                printf("Error opening file");
            }
            else
            {
                while (fgets(mystring, 900, file) != NULL)
                {
                    printf("%s", mystring);
                }
                fclose(file);
            }


            break;
        case '5':
            printf("print to console\n");
            for (int i = 0; i < r; i++) {
                if (text[i][0] != '\0') {
                    printf("%d %s", i, text[i]);
                }
                
            }

            break;
        case '6': {
            int row;
            int Place;
            char insert[500];


            int BufferSize = 20;
            char* BufferText = (char*)malloc(BufferSize * sizeof(char));



            printf("Insert text by indexes\n");
            scanf_s("%d", &row);
            while ((getchar()) != '\n');
            scanf_s("%d", &Place);
            while ((getchar()) != '\n');
            fgets(insert, sizeof(insert), stdin);
            size_t len2 = strlen(insert);
            if (len2 > 0 && insert[len2 - 1] == '\n') {
                insert[len2 - 1] = '\0'; // replace newline with null terminator
            }
            while (strlen(text[row]) + strlen(insert) + 1 > c) {
                c *= 2;  // double the row capacity
                text[row] = (char*)realloc(text[row], c * sizeof(char));
            }
            while (BufferSize <= strlen(insert) + strlen(text[row]) + 1) {
                BufferSize = BufferSize * 2;
                BufferText = (char*)realloc(BufferText, BufferSize * sizeof(char));


            }
            int i = 0;
            int j = 0;
            for (i = 0, j = 0; i < strlen(text[row]); i++) {
                if (i == Place) {
                    strcpy(BufferText + j, insert);
                    j += strlen(insert);
                }
                BufferText[j++] = text[row][i];
            }

            if (i == Place) {
                strcpy(BufferText + j, insert);
                j += strlen(insert);
            }

            BufferText[j] = '\0';

            strcpy(text[row], BufferText);

            break;
        }
        case '7': {
            

            break;
        }
        case '8':
         
            break;


        default:
            printf("Error! operator is not correct\n");
        }

    }

    return 0;
}


