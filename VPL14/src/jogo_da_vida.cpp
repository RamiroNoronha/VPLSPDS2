#include "jogo_da_vida.h"
#include<iostream>
JogoDaVida::JogoDaVida(int l, int c){
    
    for(int i =0; i < l; i++){
        std::vector<bool> coluna;
        for(int j = 0; j < c; j++){
            coluna.push_back(false);
        }
        vivas_.push_back(coluna);
    }
}


bool JogoDaVida::viva(int i, int j){
    if(i < 0 || i >= linhas() || j < 0 || j >= colunas()){
        ExcecaoCelulaInvalida celula;
        celula.linha = i;
        celula.coluna = j;
        throw celula;
    }
    
        return vivas_[i][j];
    
}

void JogoDaVida::Matar(int i, int j){
    if(i < 0 || i >= linhas() || j < 0 || j >= colunas()){
        ExcecaoCelulaInvalida celula;
        celula.linha = i;
        celula.coluna = j;
        throw celula;
    }
    vivas_[i][j] = false;
}

void JogoDaVida::Reviver(int i, int j){
    if(i < 0 || i >= linhas() || j < 0 || j >= colunas()){
        ExcecaoCelulaInvalida celula;
        celula.linha = i;
        celula.coluna = j;
        throw celula;
    }
    vivas_[i][j] = true;
}


void JogoDaVida::ExecutarProximaIteracao(){
    std::vector<int> l;
    std::vector<int> c;
    std::vector<int> lr;
    std::vector<int> cr;

        for(int i =0; i < linhas(); i++){
        for(int j =0; j < colunas(); j++){
            //std::cout << "Entrou ate a iteracao de j :" << j << " E i: " << i <<std::endl;
            if(vivas_[i][j]){
                if(NumeroDeVizinhasVivas(i, j) == 0 || NumeroDeVizinhasVivas(i,j) == 1 || NumeroDeVizinhasVivas(i,j) >3 ){
                    //guardar as que vou matar aqui
                    l.push_back(i);
                    c.push_back(j);
                }
            }
        }
    }
     // dar vida
    for(int i =0; i < linhas(); i++){
        for(int j =0; j < colunas(); j++){
                if(NumeroDeVizinhasVivas(i,j) == 3){
                    lr.push_back(i);
                    cr.push_back(j);
                }
            
        }
    }
        //Matar
    for(int i =0; i < l.size(); i++){
        Matar(l[i], c[i]);
    }
    //reviver
    for(int i =0; i < lr.size(); i++){
        Reviver(lr[i], cr[i]);
    }

    


    l.clear();
    c.clear();
    lr.clear();
    cr.clear();
}

int JogoDaVida::NumeroDeVizinhasVivas(int i, int j){
      int cont = 0;
    int lvp;
    int lva;
    int cvp;
    int cva;
    


    //Situações 
    // A B C
    // D E F
    // G H I
    // A -> i = 0 && j = 0                      / 
    // B -> i = 0                               /
    // C -> i = 0 && j = colunas() -1           /
    // D -> j = 0                               /
    // E sem restrições                         /
    // F -> j = colunas() -1                    /
    // G -> i = linhas()-1 && j = 0             /
    // H -> i = linhas()-1                      /
    // I -> i = linhas()-1 && j = colunas() -1  /


    //CASO A
    if(i ==0 && j == 0){
        lvp = i+ 1;
        lva = linhas() -1;
        cvp = j+ 1;
        cva = colunas() - 1;
    }
    //CASO B
    else if(i == 0 && j > 0 && j < colunas() -1){
        lvp = i +1;
        lva = linhas() -1;
        cvp = j+1;
        cva = j -1;
    }
    //CASO C
    else if(i == 0 && j == colunas() -1){
        lvp = i + 1;
        lva = linhas() - 1;
        cvp = 0;
        cva = j -1;
    }
    //CASO D
    else if(i > 0 && i < linhas() -1 && j == 0){
        lvp = i + 1;
        lva = i -1;
        cvp = j+ 1;
        cva = colunas() - 1;
    }
    //CASO F
    else if(j == colunas() -1 && i > 0 && i < linhas() -1){
        lvp = i + 1;
        lva = i - 1;
        cvp = 0;
        cva = j - 1; 
    }
    //CASO G
    else if(i == linhas() -1 && j==0){
        lvp = 0;
        lva = i -1;
        cvp = j+ 1;
        cva = colunas() - 1;
    }
    //CASO H
    else if (i == linhas() -1 && j > 0 && j < colunas() -1){
        lvp = 0;
        lva = i -1;
        cvp = j+1;
        cva = j -1;
    }
    //CASO I
    else if(i == linhas() -1 && j == colunas() -1){
        lvp = 0;
        lva = i -1;
        cvp = 0;
        cva = j -1;
    }
    //CASO E
    else {
        lvp = i + 1;
        lva = i - 1;
        cvp = j+1;
        cva = j -1;

    }
    
    if(vivas_[lva][cva]){
        cont++;
    }
    if(vivas_[lva][j]){
        cont++;
    }
    if(vivas_[lva][cvp]){
        cont++;
    }
    if(vivas_[i][cva]){
        cont++;
    }
    if(vivas_[i][cvp]){
        cont++;
    }
    if(vivas_[lvp][cva]){
        cont++;
    }
    if(vivas_[lvp][j]){
        cont++;
    }
    if(vivas_[lvp][cvp]){
        cont++;
    }
    
    return cont;
}