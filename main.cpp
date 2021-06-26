/**
* @file main.cpp
*/
#include <iostream>
#include <math.h>
#include <ctime>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <ham8.h>
#include <iomanip>

using namespace std;


char askCodeDecode (string question)
{
    char response;
    do {
        cout<<question<<"(c/d/e):";
        cin>>response;
    } while(response!='c' && response!='d' && response!='e');
    return response;
}
char askYesNo (string question)
{
    char response;
    do {
        cout<<question<<"(y/n):";
        cin>>response;
    } while(response!='y' && response!='n');
    return response;
}

int main()
{
    try {
    cout<<setw(35)<<"Hamming8"<<endl;
    char g;
    vector<int> code;
    Hamming8 obj;
    do {
        char p='n';
        g = askCodeDecode("Кодирование, декодирование или выход?");
        string text = " ";
        if(g=='c') {
            cout << "Введите слово: ";
            cin>>text;
            while(p=='n') {
                p=askYesNo("Текст введён верно?");
                if (p=='y') {
                    vector<int> code = obj.encode(text);
                    cout << "Закодированный текст:" << endl;
                    obj.print_vec(code);

                } else {
                    cout << "Введите слово: ";
                    cin>>text;
                }
            }
        } else {
                if(g=='d')
                {
                    cout << "Введите код(Допустимые символы 0 и 1)" << endl;
                    cin >> text;
                    while(p=='n') {
                        p=askYesNo("Код введён верно?");
                        if (p=='y') {
                            code = obj.stringToVec(text);
                
                            text = obj.decode(code);
                            cout << "Декодированное слово: " << endl;
                            cout << text << endl;
                        }  else {
                            cout << "Введите код(Допустимые символы 0 и 1)"<<endl;
                            cin>>text;
                        }
                    }
                }
                }
    } while(g!='e');
     } catch (const error_hamming & e) {
        cerr << "Error: " << e.what() << endl;
    }
}
