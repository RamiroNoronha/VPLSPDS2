#include <iostream>

int main() {
    int primeiro = 10;
    int* ponteiro;
    ponteiro = nullptr;
    int vetor[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::cout << &primeiro << std::endl;
    std::cout << primeiro << std::endl;
    std::cout << &ponteiro << std::endl;
    std::cout << ponteiro << std::endl;
    std::cout << vetor << std::endl;
    std::cout << &vetor[0] << std::endl;
    std::cout << vetor[0] << std::endl;
    ponteiro = &primeiro;
    std::cout << ponteiro << std::endl;
    std::cout << *ponteiro << std::endl;
    std:: cout << (&primeiro == ponteiro) << std::endl;
    *ponteiro = 5;
    std::cout << primeiro << std::endl;
    *ponteiro =vetor[0];
    std::cout << ponteiro << std::endl;
    std::cout << *ponteiro << std::endl;
    ponteiro = vetor;
    std::cout << ponteiro << std::endl;
    std::cout << *ponteiro<< std::endl;
    for(int i =0; i < 10; i++){
        std::cout << vetor[i];
        if(i != 9){
            std::cout << " ";
        } else{
            std::cout << std::endl;
        }
    }
    for(int i =0; i < 10; i++){
        std::cout << *(vetor + i);
        if(i != 9){
            std::cout << " ";
        } else{
            std::cout << std::endl;
        }
    }

}