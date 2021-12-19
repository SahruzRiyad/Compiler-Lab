#include <bits/stdc++.h>
using namespace std;

/*  Here 
    E' = R
    epsilon = #
    T' = Y
    id = i                            
*/

string grammar[] = {"E->TR","R->+TR","T->FY","Y->*FY","F->(E)","R->#","Y->#","F->i"};
string FIRST[] = {"i(","+","i(","*","(","#","#","i"};
string FOLLOW[10];
bool mark[500] , vis[50];
map<char,vector<string>>table;
char str[50];
vector<char>terminal;

string calc_FirstFollow(char ch , int c1 , int c2){
    int i , j;
    string ans= "";
    for(i = 0 ; i < 8; i++){
        if(ch == grammar[i][0]){
            
            for(j = 0 ; j < FIRST[i].size() ; j++){

                if(FIRST[i][j] != '#')
                     ans += FIRST[i][j];
                else{
                    
                    if(grammar[c1][c2+1] == '\0')
                        ans += FOLLOW[c1];
                    else if(grammar[c1][c2+1] < 'A' || grammar[c1][c2+1] > 'Z')
                        ans += grammar[c1][c2+1];
                    else 
                        ans += calc_FirstFollow(grammar[c1][c2+2],c1,c2+1);
                }
            }
        }
    }
    return ans;
}

void calc_FOLLOW(){
    int i , j , k;

    for(i = 0; i < 8; i++){

        if(FOLLOW[0].size() == 0)
            FOLLOW[i] += '$';
        
        for(j = 0 ; j < 8 ; j++){

            for(k = 3 ; k < grammar[j].size() ; k++){
                
                if(grammar[j][k] == grammar[i][0]){

                    if(grammar[j][k+1] == '\0')
                        FOLLOW[i] += FOLLOW[j];
                    
                    else if(grammar[j][k+1]>='A' && grammar[j][k+1] <= 'Z')
                        FOLLOW[i] += calc_FirstFollow(grammar[j][k+1],j,k+1);
                    
                    else 
                        FOLLOW[i] += grammar[j][k+1];
                }
            }

        }
    }
    cout<<"FOLLOW Set:"<<endl;
    for(i = 0 ; i < 8 ; i++){
       
        string tmp = "";
        for(j = 0 ; j < FOLLOW[i].size() ; j++){
            if(!mark[FOLLOW[i][j]])
                tmp += FOLLOW[i][j];
            mark[FOLLOW[i][j]] = 1;
        }
        FOLLOW[i] = tmp;
        memset(mark,0,sizeof(mark));
        if(!vis[grammar[i][0] - 'A']){
            cout<<grammar[i][0]<<"="<<'{';
            for(j = 0 ; j < FOLLOW[i].size() ; j++){
                cout<<FOLLOW[i][j];
                if(j != FOLLOW[i].size()-1)
                    cout<<',';
                
            }
            cout<<'}'<<endl;
        }
        vis[grammar[i][0] - 'A'] = 1;
    }

}

void cpy_str(string &s){
    int i = 0;
    for(i = 0 ; i < s.size() ; i++)
        str[i] = s[i];
    str[i] = '\0';

    printf("%-10s",str);
}
void calc_LLParsingTable(){
    int i , j;
    printf("\n");
    printf("\n\t**************** LL(1) PARSING TABLE *******************\n");
    printf("\t--------------------------------------------------------\n");
    printf("%-10s", "");
    mark['#'] = 1;
    for(i = 0 ; i < 8 ; i++){
        for(j = 0 ; j < FIRST[i].size() ; j++){
            if(!mark[FIRST[i][j]])
                terminal.push_back(FIRST[i][j]);
            mark[FIRST[i][j]] = 1;
        }
        for(j = 0 ; j < FOLLOW[i].size() ; j++){
            if(!mark[FOLLOW[i][j]])
                terminal.push_back(FOLLOW[i][j]);
            mark[FOLLOW[i][j]] = 1;
        }
    }
    for(i = 0 ; i < terminal.size() ; i++){
        printf("%-10c",terminal[i]);
    }
    printf("\n");
    printf("\n");
    
    for(i = 0 ; i < 8 ; i++){
        
        for(j = 0 ; j < FIRST[i].size() ; j++){
            if(FIRST[i][j] != '#')
                table[FIRST[i][j]].push_back(grammar[i]);
            else{
                for(int k = 0 ; k < FOLLOW[i].size() ; k++){
                    table[FOLLOW[i][k]].push_back(grammar[i]);
                   
                }
            }
        } 
    }
 
    for(i = 0 ; i < 5 ; i++){
        char ch = grammar[i][0];
        printf("%-10c",ch);
        for(j = 0 ; j < terminal.size(); j++){
            char ter = terminal[j];
            for(int k = 0 ; k < table[ter].size() ; k++){
                if(table[ter][k][0] == ch){
                    cpy_str(table[ter][k]);
                    //table[ter][k][0] = '-';
                    goto br;
                    
                }
            }
            
            printf("%-10s","");
            br:;
        }
        printf("\n");
    }
    cout<<endl;
}

int main(){
  
    calc_FOLLOW();
    calc_LLParsingTable();
    return 0;
}