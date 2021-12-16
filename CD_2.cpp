#include <bits/stdc++.h>
using namespace std;

string str;

bool is_valid(int start , int end){
    for(int i = start ; i <= end ; i++){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i] <='9'))
            continue;
        return 0;
    }
    return 1;
}

bool is_allDigit(){
    for(auto i : str){
        if(i>='0' && i<='9')
            continue;
        return 0;
    }
    return 1;
}

int isFloat(){
    int i , cnt = 0, len = str.size() , j;
    
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

bool isBinary(){
    for(auto i : str){
        if(i != '0' || i != '1')
            return 0;
    }
    return 1;
}

int main(){
    int n , i , j , len;

    while(cin>>str){

        len = str.size();
        if(len > 3 && str[0] == 'c' && str[1] == 'h' && str[2] == '_' && is_valid(3,len-1))
            cout<<"Character Variable"<<endl;
        else if(len > 3 && str[0] == 'b' && str[1] == 'n' && str[2] == '_' && is_valid(3,len-1))
            cout<<"Binary Variable"<<endl;
        else if(len >= 2 && isBinary() && str[0] == '0')
            cout<<"Binary Number"<<endl;
        else if(isFloat() == 2)
            cout<<"Float Number"<<endl;
        else if(isFloat() >= 3)
            cout<<"Double Number"<<endl; 
        else if(!is_valid(0,len-1))
            cout<<"Undefined"<<endl;
        else if((str[0]>='i' && str[0]<='n') || (str[0]>='I' && str[0]<='N'))
            cout<<"Integer variable"<<endl;
        else if(len <= 4 && is_allDigit() && (str[0]>='1' && str[0]<='9'))
            cout<<"ShortInt Number"<<endl;
        else if(is_allDigit() && (str[0]>='1' && str[0]<='9'))
            cout<<"LongInt Number"<<endl;
        else if((str[0]>='a'&&str[0]<='h')||(str[0]>='A'&&str[0]<='H')||(str[0]>='o'&&str[0]<='z')||(str[0]>='O'&&str[0]<='Z'))
            cout<<"Float Variable"<<endl;
        
        else 
            cout<<"Invalid Input"<<endl;
        
    }
}