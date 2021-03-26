#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> symbols = {"!=", "(", ")", "*", "+", ",", "-", "/", ";", "<", "<=", "=", "==", ">", ">=", "[", "]", "{", "}"};
vector<string> keys = {"else", "if", "int", "return", "void", "while"};
void printToken(int line, string token, string &s){
    cout << "(" << line << "," << token << "," << "\"" << s << "\")" << endl;
}
bool isLetter(char x){
    return (x >= 'a' and x <= 'z') or (x >= 'A' and x <= 'Z');
}
bool isDigit(char x){
    return (x >= '0' and x <= '9');
}
void checksymbol(int &line, string &s){
    if(binary_search(symbols.begin(), symbols.end(), s)){
        printToken(line, "SYM", s);
    }
    else{
        printToken(line, "ERROR", s);
    }
}
void checkid(int &line, string &s){
    if(binary_search(keys.begin(), keys.end(), s)){
        printToken(line, "KEY", s);
    }
    else
        printToken(line, "ID", s);
}
void checknum(int &line, string &s){
        printToken(line, "NUM", s);
}
int32_t main() {
	string s;
    bool id, num, sy;
    id = num = sy = false;
    int line = 0;
    while(getline(cin, s)){
        line++;
        s+=' ';
        if(s[0] == s[1] and s[0] == '/')
            continue;
        string aux = "";
        int pos = 0;
        for(auto &i : s){
            if(i == '/' and s[pos+1] == '/' ) break;
            if(i == ' '){
                if(aux.empty()) continue;
                if(sy) checksymbol(line, aux);
                if(id) checkid(line, aux);
                if(num) checknum(line, aux);
                aux = "";
                id = num = sy = false;
            }
            else{
                if(sy){
                    if(isLetter(i)){
                        checksymbol(line, aux);
                        aux = i;
                        sy = false;
                        id = true;
                    }
                    else if(isDigit(i)){
                        checksymbol(line, aux);
                        aux = i;
                        sy = false;
                        num = true;
                    }
                    else{
                        if((aux == "!" or aux == "=" or aux == ">" or aux == "<") and i == '='){
                            aux += i;
                        }
                        else{
                            checksymbol(line,aux);
                            aux = i;
                        }
                    }
                }
                else if(num){
                    if(isLetter(i)){
                        checknum(line, aux);
                        aux = i;
                        num = false;
                        id = true;
                    }
                    else if(isDigit(i)){
                        aux += i;
                    }
                    else{
                        checknum(line, aux);
                        aux = i;
                        num = false;
                        sy = true;
                    }
                }
                else if(id){
                    if(isLetter(i) or isDigit(i)){
                        aux += i;
                    }
                    else{
                        checkid(line, aux);
                        aux = i;
                        id = false;
                        sy = true;
                    }
                }
                else{
                    aux+=i;
                    if(isLetter(i)){
                        id = true;
                    }
                    else if(isDigit(i)){
                        num = true;
                    }
                    else{
                        sy = true;
                    }
                }
            }
            pos++;
        }
    }
}