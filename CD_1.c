#include <stdio.h>
#include <string.h>

int isValidDelimiter(char ch) {
    if (ch == ' ' || ch == '+'  || ch == '*' ||
    ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
    ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
    ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (1);

   return (0);
}

int isValidLetter(char ch){
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        return 1;
    return 0;
}

int isValidDigits(char ch){
    if(ch >= '0' && ch <= '9')
        return 1;
    return 0;
}

int isVowel(char ch){
    if(ch >= 'A' && ch <= 'Z')
        ch = ch - 'A' + 'a';
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return 1;
    return 0;
}

void aNo(char str[]){
    printf("A\n");
    int len = strlen(str) , i , j , words = 1 , letter = 0 , digits = 0 , other = 0;
    for(i = 0 ; i < len ; i++){
        if(str[i] == ' ' && str[i+1] != ' ')
            words++;
        if(isValidLetter(str[i]))
            letter++;
        else if(isValidDigits(str[i]))
            digits++;
        else if(str[i] != ' ')
            other++;
    }
    printf("Number of Words = %d, letters = %d, digits = %d and others = %d\n",words,letter,digits,other);
}

void bNo(char str[]){
    printf("B\n");

    int len = strlen(str) , i , j= 0 , k = 0 , l = 0;
    char letter[50] , digit[50] , other[50];
    for(i = 0 ; i < len ; i++){
        if(isValidLetter(str[i]))
            letter[j++] = str[i];
        else if(isValidDigits(str[i]))
            digit[k++] = str[i];
        else if(str[i] != ' ') 
            other[l++] = str[i];
    }
    letter[j] = digit[k] = other[l] = '\0';
    printf("Letters: %s\nDigits: %s\nOthers: %s\n",letter,digit,other);
}

void cNo(char str[]){
    printf("C\n");

    int len = strlen(str) , vowel = 0 , consonant = 0 , i;
    for(i = 0 ; i < len ; i++){
        if(!isValidLetter(str[i]))
            continue;
        if(isVowel(str[i]))
            vowel++;
        else 
            consonant++;
    }
    printf("Number of Vowel: %d and Consonant: %d\n",vowel,consonant);
}

int mark[30];

void dNo(char str[]){
    printf("D\n");
    
    int len = strlen(str), i , j = 0 , k = 0;
    char vowel[50] , consonant[50]  , ch;
    for(i = 0 ; i < len ; i++){
        if(!isValidLetter(str[i]))
            continue;
        ch = str[i];
        if(ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';
        if(isVowel(ch) && mark[ch-'a'] == 0){
            vowel[j++] = str[i];
            mark[ch-'a'] = 1;
        }
        else if(mark[ch-'a'] == 0){
            consonant[k++] = str[i];
            mark[ch-'a'] = 1;
        }
    }
    vowel[j] = consonant[k] = '\0';
    printf("Vowel: %s and Consonant: %s\n",vowel,consonant);
}

void eNo(char str[]){
    printf("E\n");

    int len = strlen(str), i , j = 0 , k = 1 , v[50] , vw= 0 , cs = 0;
    char vowel[10] , consonant[30];
    v[0] = 0;
    for(i = 1 ; i < len ; i++){
        if(str[i] == ' ' && i + 1 < len)
            v[k++] = i + 1;
    }
    for(i = 0 ; i < k ; i++){
        if(isVowel(str[v[i]])){
            vowel[vw++] = str[v[i]];
            j = v[i] + 1;
            while(j < len && str[j] != ' ')
                vowel[vw++] = str[j++];
        }
    }
    vowel[vw] = '\0';
    for(i = 0 ; i < k ; i++){
        if(!isVowel(str[v[i]]) && !isValidDigits(str[v[i]])){
            consonant[cs++] = str[v[i]];
            j = v[i] + 1;
            while(j < len && !isValidDelimiter(str[j]))
                consonant[cs++] = str[j++];
            consonant[cs++] = ' ';
            
        }
    }
    consonant[cs] = '\0';
    puts("Starting with vowel");
    puts(vowel);
    puts("Starting with consonant");
    puts(consonant);
}

int main(){
    char str[100] = "Md. Tareq Zaman, Part-3, 2011";
    aNo(str);
    bNo(str);
    cNo(str);
    dNo(str);
    eNo(str);
    return 0;
}