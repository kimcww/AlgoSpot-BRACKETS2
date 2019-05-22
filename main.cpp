#include<iostream>
#include<string.h>
#include<list>

using namespace std;
char dataNum[101];
char Buffer[10001];
string Data;

int main()
{

    cin.getline(dataNum, sizeof(dataNum));

    list<char> Stack;
    for(int i = 0; i < atoi(dataNum) ; i++){
        unsigned long long count = 0;
        memset(Buffer,0,sizeof(Buffer));
        int end = 1;
        Stack.clear();

        cin>>Data;

        strcpy(Buffer,Data.c_str());

        while(end){
            switch (Buffer[count]){
                case '{' : {
                    Stack.push_back(Buffer[count]);
                    break;
                }
                case '(' : {
                    Stack.push_back(Buffer[count]);
                    break;
                }
                case '[' : {
                    Stack.push_back(Buffer[count]);
                    break;
                }
                case ')' : {
                if( Stack.back() == '('){
                    Stack.pop_back();
                    break;
                } else {
                    cout<<"NO"<<endl;
                    end = 0;
                    break;
                }
                }
                case '}' : {
                if( Stack.back() == '{'){
                    Stack.pop_back();
                    break;
                } else{
                    cout<<"NO"<<endl;
                    end = 0;
                    break;
                }
            }
                case ']' : {
                    if( Stack.back() == '['){
                        Stack.pop_back();
                        break;
                    } else {
                        cout<<"NO"<<endl;
                        end = 0;
                        break;
                    }

                }
            }
            if( count == Data.size()){
                if( Stack.empty() == true){
                    cout<<"YES"<<endl;
                    memset(Buffer,0,sizeof(Buffer));
                    end =0;
                    Stack.clear();
                } else {
                    cout<<"NO"<<endl;
                    end = 0;
                }
            } else{
                count++;
            }
        }
        }
    return 0;
}
