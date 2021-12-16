#include <bits/stdc++.h>
using namespace std;


bool Operator(char x){

    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        return true;
    else 
        return false;
}

int Precedence(char ch){
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else 
        return 1;
}


int main(){
    int i , j , n , cnt=0 , len , tc;
    char ch;
    string str,res;
    stack < char > st;
    res = "";
    getline(cin,str);
    str.insert(0,"("),str.push_back(')');
    len = str.size();
    cout<<str<<endl;
    for(i=0;i<len;i++){

        ch = str[i];
         if(ch == '(')
            st.push(ch);

        else if(Operator(ch)){
            while(Operator(st.top()) && Precedence(ch) <= Precedence(st.top()) ){
                res += st.top();
                st.pop();
            }
            st.push(ch);
        }
        else if(ch == ')'){
            while(st.top() !='('){
                res +=st.top();
                st.pop();
            }
            st.pop();
        }
       else res +=ch;

   }
    cout<<res<<endl;

    return 0;

}

