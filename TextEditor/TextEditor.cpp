#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
bool loop = true;
int r = 20;
int c = 20;
char** text;
int curRow = 0;
void Clear() {
    system("cls");
    printf("clear\n");
    printf("1-Append in the end, 2-Start new line, 3-Save to file, 4-load from file, 5-print to console, 6-Insert text by indexes, 7-search, 8-clear\n");
}
void CaseOne() {

    int appendTextSize = 20;
    char* appendText = (char*)malloc(appendTextSize * sizeof(char));

    fgets(appendText, appendTextSize, stdin);

    size_t len = strlen(appendText);

    /* 1*/
    if (appendText[len - 1] == '\n') {
        appendText[len - 1] = '\0';
    }
    /* 1*/

    size_t ROWLEN = strlen(text[curRow]);
    /*2*/

    while (len == appendTextSize - 1) {
        appendTextSize = appendTextSize * 3;
        appendText = (char*)realloc(appendText, appendTextSize * sizeof(char));
        fgets(appendText + len, appendTextSize - len, stdin);
        len = strlen(appendText);
    }
    /*2*/

    /*3*/
    while (ROWLEN + len + 1 > c) {
        c *= 3;  
        text[curRow] = (char*)realloc(text[curRow], c * sizeof(char));
        ROWLEN = strlen(text[curRow]);
    }
    /*3*/

    /*4*/
    strcat(text[curRow], appendText);
    printf("The entered text is: %s\n", text[curRow]);
    /*4*/
}

void CaseTwo() {
    printf("Start new line\n");

   
    if (strlen(text[curRow]) + 2 > c) {
        c *= 3; 
        text[curRow] = (char*)realloc(text[curRow], c * sizeof(char));
    }

    strcat(text[curRow], "\n");
    curRow++;

    if (curRow == r) {
        r *= 3;  
        text = (char**)realloc(text, r * sizeof(char*));
        for (int i = curRow; i < r; i++) {
            text[i] = (char*)malloc(c * sizeof(char));
            text[i][0] = '\0';  
        }
    }
}



void CaseThree() {
    FILE* file;
    printf("Save to file\n");

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
}


void CaseFour() {
    printf("load from file\n");
    FILE* fileLoad;
    char mystring[900];
    fileLoad = fopen("myFile.txt", "r");
    if (fileLoad == NULL)
    {
        printf("Error opening file");
    }
    else
    {
        while (fgets(mystring, 900, fileLoad) != NULL)
        {
            if (mystring[0] != '\0') {
                printf("%s", mystring);
            }
        }
        fclose(fileLoad);
    }
}


void CaseFive() {
    printf("print to console\n");
    for (int i = 0; i < r; i++) {
        if (text[i][0] != '\0') {
            printf("%d %s", i, text[i]);
        }

    }
}
void CaseSix() {
    int row;
    int Place;
    char insert[500];
   

    int BufferSize = 700;
    char* BufferText = (char*)malloc(BufferSize * sizeof(char));

    printf("Insert text by indexes\n");
    scanf("%d", &row);
    while ((getchar()) != '\n');  
    scanf("%d", &Place);
    while ((getchar()) != '\n');  

    fgets(insert, sizeof(insert), stdin);
    size_t len2 = strlen(insert);
    if (insert[len2 - 1] == '\n') {
        insert[len2 - 1] = '\0'; 
    }

    while (strlen(text[row]) + strlen(insert) + 1 > c) {
        c *= 3;  
        text[row] = (char*)realloc(text[row], c * sizeof(char));
    }

    while (BufferSize <= strlen(insert) + strlen(text[row]) + 1) {
        BufferSize = BufferSize * 2;
        BufferText = (char*)realloc(BufferText, BufferSize * sizeof(char));
    }

    int i = 0;
    int BP = 0;
    for (i; i < strlen(text[row])+1; i++) {
        if (i == Place) {
            for (int j = 0; j < strlen(insert); j++) {
                BufferText[BP] = insert[j];
                BP++;
            }
        }

        if (i < strlen(text[row])) {
            BufferText[BP] = text[row][i];
            BP++;
        }

        
        printf("%d\n", i);
    }
    BufferText[BP] = '\0';
    strcpy(text[row], BufferText);
}

void CaseSeven() {
    int SearchRow = 0;
    int SearchPlace = 0;
    printf("search\n");
    FILE* fileSearch;
    char mystring[900];
    char Searchstr[200];
    fgets(Searchstr, sizeof(Searchstr), stdin);
    size_t len = strlen(Searchstr);
    if (Searchstr[len - 1] == '\n') {
        Searchstr[len - 1] = '\0';
    }
    fileSearch = fopen("myFile.txt", "r");
    if (fileSearch == NULL)
    {
        printf("Error opening file");
    }
    else
    {
        while (fgets(mystring, 900, fileSearch) != NULL)
        {
            size_t mystring_len = strlen(mystring);
            if (mystring[mystring_len - 1] == '\n') {
                mystring[mystring_len - 1] = '\0';
            }

            if (strstr(mystring, Searchstr)) {
                char copyText[900];
                strcpy(copyText, mystring);
                char* Firsttoken = strtok(copyText, " ");
                while (Firsttoken != NULL) {
                    if (strcmp(Firsttoken, Searchstr) == 0)
                    {
                        printf("The coordinates: %d , %d\n", SearchRow, SearchPlace);
                    }
                    Firsttoken = strtok(NULL, " ");
                    SearchPlace += 1;

                }
                SearchPlace = 0;
            }
            SearchRow += 1;
        }
        fclose(fileSearch);
    }
}




int main()
{
    text = (char**)malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        text[i] = (char*)malloc(c * sizeof(char));
        text[i][0] = '\0';  
    }

    printf("1-append in the end, 2-Start new line, 3-Save to file, 4-load from file, 5-print to console, 6-Insert text by indexes, 7-search, 8-clear\n");
    while (loop == true) {
        char str;
        scanf("%c", &str);
        while ((getchar()) != '\n');
        printf("ThP entered int is: %c\n", str);
        switch (str)
        {
        case '1':
        {

            CaseOne();
            printf("Append  the end\n");

            break;
        }
        case '2':
            CaseTwo();
            break;

        case '3':
            CaseThree();
            break;

        case '4':
            CaseFour();


            break;
        case '5':

            CaseFive();
            break;
        case '6': {
            CaseSix();
            break;
        }
        case '7': {

            CaseSeven();
            break;
        }
        case '8':
            Clear();
            break;


        default:
            printf("Error! operator is not correct\n");
        }

    }

    return 0;
}


