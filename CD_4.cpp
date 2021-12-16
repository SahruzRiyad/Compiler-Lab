#include<bits/stdc++.h>
using namespace std;

string grammar[] = {"E+E","E-E","E*E","E/E","(E)","a","b","c"};


int Operator(char ch){
    switch (ch)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '(':
        return 4;
    default:
        return -1;
    }
}


int main(){
    int i , j , len , index;
    string str , ans , tmp;
    cin>>str;
    len = str.size();
    ans = "E";
    cout<<ans<<endl;
    
    for(i = 0 ; i < len ; i++){

        index = Operator(str[i]);
        if(index != -1){
            ans.pop_back();
            ans += grammar[index];
            cout<<ans<<endl;
        }
    }
    
    for(i = 0 ; i < ans.size() ; i++){
        if(ans[i] == 'E'){
            ans[i] = str[i];
            cout<<ans<<endl;
        }
    }

    return 0;
}