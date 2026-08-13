#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, flag = 1;

    printf("Enter string: ");
    gets(str);

   
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }

   
    i = 0;
    j = strlen(str) - 1;

    while(i < j) {
        if(str[i] == ' ') {
            i++;
        }
        else if(str[j] == ' ') {
            j--;
        }
        else if(str[i] != str[j]) {
            flag = 0;
            break;
        }
        else {
            i++;
            j--;
        }
    }

    if(flag == 1)
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}