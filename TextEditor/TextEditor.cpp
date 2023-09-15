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

         
            break;

        case '4':
           

            break;
        case '5':
          

            break;
        case '6': {
           
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


