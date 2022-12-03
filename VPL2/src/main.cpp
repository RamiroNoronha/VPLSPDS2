#include <iostream>
#include <map>

using namespace std;

int main() {
    cout << "Digite a palavra: " << endl;
    string palavra;
    cin >> palavra;
    map<char, int> vogais;

    for(int i =0; i < palavra.size(); i++){
        bool isVogal = palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u';
        if(isVogal){
            char vogal = palavra[i];
            vogais[vogal] = vogais[vogal] + 1;
        }
    }

    string todasVogais = "aeiou";
    for(int i =0; i < todasVogais.size(); i++){
        char vogal = todasVogais[i];
        if(vogais[vogal] > 0){
            cout << vogal << " " << vogais[vogal] << endl;
        }
    }
}