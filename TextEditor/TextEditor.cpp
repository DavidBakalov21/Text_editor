#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    bool loop = true;
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



            break;
      
        }
        case '2':
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


