#include <stdio.h>
#include <string.h>

int isValidArithmeticOperator(char *str){

    if(strcmp(str,"+") == 0 || strcmp(str,"-") == 0 || strcmp(str,"*") == 0|| 
        strcmp(str,"/") == 0 ||strcmp(str,"^") == 0 || strcmp(str,"=") == 0)
        return 1;
    return 0;
}

int isValidRelationalOperator(char *str){
    if(strcmp(str,"<") == 0 || strcmp(str,">") == 0 || strcmp(str,"!=") == 0||
        strcmp(str,"==") == 0 || strcmp(str,"<=") == 0 || strcmp(str,">=") == 0)
        return 1;

    return 0;
}
int isValidIdentifier(char ch){

    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
        return 1;

    return 0;
}


int isFloat(char *str){
    int i , cnt = 0, len = strlen(str) , j;
    
    for(i = 0;i < len; i++){
        if(str[i] == '.'){

            for(j = 0 ; j < len ; j++){
                if(j != i && (str[j] < '0' || str[j] > '9'))
                    return 0;
            }

            if(str[0] == '0' && str[1] != '.')
                return 0;

            return len - i - 1;
        }
    }
    return 0;
}

int isInteger(char *str){
    int i , len = strlen(str);
    for(i = 0; i < len ; i++){
        if(str[i] >='0' && str[i] <='9')
            continue;
        return 0;
    }
    return 1;
}

int isValidKeyword(char* str) {

    if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") ||    !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int")
    || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str,    "char") || !strcmp(str, "case") || !strcmp(str, "char")
    || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned")
    || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return 1;
    return 0;
}

int main(){
    char str[100];
    int len;
    while(scanf("%s",str) != EOF){

        len = strlen(str);

        if(isValidArithmeticOperator(str))
            puts("Arithmetic Operator");
        else if(isValidRelationalOperator(str))
            puts("Relational Operator");
        else if(isValidKeyword(str))
            puts("Keyword");
        else if(isValidIdentifier(str[0]))
            puts("Identifier");
        else if(isFloat(str))
            puts("Float");
        else if(isInteger(str))
            puts("Integer");
        else
            puts("Unknown");
    }
    return 0;
}