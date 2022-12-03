#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    vector<string> palavras;
    int cont = 0;
    string entrada;
    map<string, int> mapaQuantidade;
    string entradaFinal;
    int entradas = 0;
    getline(cin, entrada);
    do{
        
        if(entradas > 0){
            entradaFinal = entradaFinal + ' ' + entrada;
        } else{
            entradaFinal = entrada;
        }
        for(int i =0; i <= entrada.size(); i++){
            
            if(entrada[i] == ' ' || entrada[i] == '\n' || entrada[i] == '\0' || i == entrada.size() ){
                
                palavras.push_back(entrada.substr(cont, i-cont));
                cont = i+1;
            }
        }
        for(string palavra : palavras){
            mapaQuantidade[palavra] = mapaQuantidade[palavra] + 1;
        }
        entrada.clear();
        getline(cin, entrada);
        entradas++;
        cont = 0;
    }while(entrada != "");
    
    string resultado;
    int maior = 0;
    for(string palavra : palavras){
        if(maior < mapaQuantidade[palavra]){
            maior = mapaQuantidade[palavra];
            resultado = palavra;
        }
    }

    cout << '\"' << entradaFinal << '\"' << ":[" << resultado << ']' << endl;
}