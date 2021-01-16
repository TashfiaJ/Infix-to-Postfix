#include<bits/stdc++.h>
using namespace std;

#define stack_max 100

int top=-1;

char my_stack[stack_max];

int my_result[stack_max];

int head=-1;

void push(char i){

    my_stack[++top]=i;

    }
char pop(){

    return my_stack[top--];

}

int precedence(char ch){

    if(ch=='('|| ch==')')
        return 1;

    else if(ch=='^')
        return 4;

    else if(ch=='*' || ch=='/')
        return 3;

    else if(ch=='+' || ch=='-')
        return 2;
    }

string numToStr(int x){

    string str="";

    int k;

    while(x!=0){
        k=x%10;
        str+=k+'0'; //converting from int to character
        x/=10;

    }

    reverse(str.begin(),str.end());

    return str;
    }

int operation(int a,char c,int b){

    int result=0;

    if(c=='+')
        return a+b;

    else if(c=='-')
        return a-b;

    else if(c=='*')
        return a*b;

    else if(c=='/')
        return a/b;

    else if(c=='^')
        return pow(a,b);
    }

int evaluation(string s){

    int op1,op2,result=0,number=0;

    for(int i=0;s[i]!='\0';i++){

        if(s[i]==' ')continue;

        else if (isalnum(s[i])){

            if(!(isalnum(s[i-1])))number=0;

            number=number*10+s[i]-'0';

            if(!(isalnum(s[i+1]))){

                my_result[++head]=number;
            }

        }

        else{

            op2=my_result[head--];

            op1=my_result[head--];

            result=operation(op1,s[i],op2);

            my_result[++head]=result;

        }
    }
    return result;}

int main()
{
    string s,postfix="";

    int number=0;

    getline(cin, s);

    cout<<"Postfix expression: ";

    for(int i=0;i<s.size();i++){

        if(isalnum(s[i])){

           if(!(isalnum(s[i-1])))number=0;

           number=number*10+s[i]-'0';

           if(!(isalnum(s[i+1]))){

            cout<<number<<", ";

                postfix+=numToStr(number);

            postfix+=' ';
            }}

        else if(s[i]==' ')continue;

        else if(s[i]=='(')
            push(s[i]);

        else if(s[i]==')'){

            while(my_stack[top]!='('){

                    postfix+=my_stack[top];

                    postfix+=' ';

                    cout<<pop();

                    if(top>=-1 &&i!=s.size()-1)cout<<", ";
                  }
                  pop();
        }
        else{
                while((precedence(s[i])<precedence(my_stack[top])) || ((precedence(s[i])==precedence(my_stack[top]))&&(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'))){

                    postfix+=my_stack[top];

                    postfix+=' ';

                    cout<<pop();

                    if(top>=-1 && i!=s.size()-1)cout<<", ";

                }

                push(s[i]);

        }}

        while(top!=-1){

            postfix+=my_stack[top];

            postfix+=' ';

            cout<<pop();

            if(top>=0)cout<<", ";}

            cout<<"\n"<<"Value: "<<evaluation(postfix);
}






