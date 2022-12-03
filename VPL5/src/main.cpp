#include <iostream>
#include <vector>

using namespace std;
int main() {
   
    vector<vector<int>> matriz1;
    vector<vector<int>> matriz2;
    vector<int> linha;
    int l1;
    int l2;
    int c2;

    cin >> l1;
    cin >> l2;
    cin >> c2;
    int valor;

    for(int i =0; i <l1; i++){
        for(int j =0; j < l2; j++){
            cin >> valor;
            linha.push_back(valor);
        }
        matriz1.push_back(linha);
        linha.clear();
    }

    for(int i =0; i <l2; i++){
        for(int j =0; j < c2; j++){
            cin >> valor;
            linha.push_back(valor);
        }
        matriz2.push_back(linha);
        linha.clear();
    }
    int cont = 0;
    
    for(int i =0;i <= c2; i++){
        valor = 0;
         if(i == c2){
            cont++;
            if(cont == l1){
                break;
            }
            i = 0;
            cout << endl;
        }else {
            if(i> 0){
                cout << " ";
            }
        }
        for(int j =0; j<l2; j++){
            valor+= matriz1[cont][j] * matriz2[j][i];
            
        }
        cout << valor;
        
    }

}