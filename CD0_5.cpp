#include <bits/stdc++.h>
using namespace std;
string str;

bool isOperator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch=='/')
        return true ;
    
    return false ;
}

bool checkValidity(){

    int len = str.size();
    if(isOperator(str[len-1]))
        return 0;
    for(int i = 0 ; i  + 1 < len ; i++){
        if(isOperator(str[i]) && (str[i+1] == ')' || isOperator(str[i+1])))
            return 0;
        if(str[i]=='(' && (str[i+1]==')'|| isOperator(str[i+1])))
            return 0;
        if(str[i]==')' && (str[i+1]=='('|| isalpha(str[i+1]) || isdigit(str[i+1])))
            return 0;
    }
    return 1;
}

bool validParenthesis(){
    int brac = 0;
    for(int i = 0 ; i < str.size() ; i++){

        if(str[i] == '(')
            brac++;
        else if(str[i] == ')')
            brac--;
        if(brac < 0)
            return 0;

    }

    if(brac != 0)
        return 0;

    return 1;
}

bool hasOhterSybol(){
    for(int i = 0 ; i < str.size() ; i++){
        if(!isalpha(str[i]) || !isdigit(str[i]) || !isOperator(str[i]) ||
             str[i] != '(' || str[i] != ')')
                return 0;
    }
    return 1;
}

int main(){
    cin>>str;
    if(hasOhterSybol() || !validParenthesis() || !checkValidity())
        cout<<"Invalid"<<endl;
    else 
        cout<<"Valid"<<endl;

    return 0;
}