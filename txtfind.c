#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30

int substring( char * str1, char * str2)
{
    int len1 = strlen(str1);
    int len2= strlen(str2);
    int i=0,j=0,index=0;
    if (len2>len1)
    {
       return 0;
    }   
    while (i<len1 && j<len2)
    {
        if (str1[i]==str2[j])
        {
            i++;
            j++;
        }
        else
        {
            i=index;
            j=0;
        }       
        if (str2[j] == '\0')
        {
            return 1;
        }
        index++;      
    }
    return 0;
}
int similar (char *s, char *t, int n)
{
    int len1 = strlen(s);
    int len2 = strlen(t);
    int count = 0, i=0, j=0;
    if ((len1 - len2) != n)
    {
        return 0;
    }
    while (i<len1 && j<len2)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
            count++;
        }
        if (t[j]=='\0' && count==n)
        {
           return 1;
        }   
    }
    return 0;    
}
// print the lines that contain the string -- IF CHOSEN BY THE USER "a"
void print_lines(char *str)
{
    char line[LINE];
    while (fgets(line, LINE, stdin) != NULL)
    {
        if (substring(line, str) == 1)
        {
            char *token = strtok(line, "\r\n");
            printf("%s\n", token);
        }
    }
}
// void print_similar_words(char *str) {
//     char line[LINE];
//     while (fgets(line, LINE, stdin) != NULL) {
//         // Iterate through the line one character at a time
//         for (int i = 0; line[i] != '\0'; i++) {
//             // If the character is not a space, tab, newline, or null terminator, it is part of a word
//             if (line[i] != ' ' && line[i] != '\t' && line[i] != '\r' && line[i] != '\n' && line[i] != '\0') {
//                 // Save the start index of the word
//                 int start = i;
//                 // Iterate until the end of the word is reached
//                 while (line[i] != ' ' && line[i] != '\t' && line[i] != '\r' && line[i] != '\n' && line[i] != '\0') {
//                     i++;
//                 }
//                 // Save the end index of the word
//                 int end = i - 1;
//                 // Calculate the length of the word
//                 int length = end - start + 1;
//                 // Create a buffer to hold a copy of the word
//                 char word[length + 1];
//                 // Copy the word from the line into the buffer
//                 for (int j = 0; j < length; j++) {
//                     word[j] = line[start + j];
//                 }
//                 // Add a null terminator to the end of the word
//                 word[length] = '\0';
//                 // Check if the word is similar to the input string
//                 if (similar(word, str, 1) == 1) {
//                     printf("%s\n", word);
//                 }
//             }
//         }
//     }
// }
void print_similar_words(char *str)
{
    char line[LINE];
    while (fgets(line, LINE, stdin) != NULL)
    {
        char *word =strtok(line, " \t\r\n\v\f");
        for (; word != NULL; word = strtok(NULL, " \t\r\n\v\f"))
        {
            if (similar(word, str, 1) == 1)
            {
                printf("%s\n", word);
            }
        }
    }
}

int main()
{
    char line[LINE];
    fgets(line, LINE , stdin);
    char *tok = strtok(line, " ");   // token is the first string
    char *tok2 = strtok(NULL, " "); // token is the second string - the char
    char ch = tok2[0];              // finding the char at the end of the string
    if (ch == 'a')
    {
        print_lines(tok);
    }
    else if (ch == 'b')
    {
        print_similar_words(tok);
    }
    return 0;
}