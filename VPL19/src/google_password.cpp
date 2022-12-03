#include "google_password.h"

#include <iostream>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {

    if(!validPassword(password)){
        return;
    }
    if(passwords_.find(url) != passwords_.end()){
    return;
  }
    Usuario u;
    u.login = login;
    u.password = password;
    passwords_[url] = u;

    
}

void GooglePassword::remove(const std::string& url) {
  // TODO: Implemente este metodo
    if(passwords_.find(url) == passwords_.end()){
    return;
  }
  passwords_.erase(url);
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  // TODO: Implemente este metodo
  /**
   * Este metodo nao pode inserir novas credenciais, apenas atualizar as
   * ja existentes. Alem disso, o login e/ou senha do usuario so podem ser
   * atualizados se a senha armazenada no sistema for igual a old_password.
   * Nao esqueca de verificar se o novo password tambem e valido.
   */
  if(passwords_.find(url) == passwords_.end()){
    return;
  }
  if(old_password != passwords_[url].password){
    return;
  }
  if(!validPassword(new_password)){
        return;
  }
  Usuario u;
  u.login = login;
  u.password = new_password;
  passwords_[url]= u;
}

void GooglePassword::printPasswords() {
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * 3
   * aaa.site.com: login and password
   * www.site.com: login and password
   * zzz.site.com: login and password
   *
   */
  std::cout << passwords_.size() << std::endl;
  for(auto item : passwords_){
    std::cout << item.first << ": " << item.second.login << " and " << item.second.password << std::endl; 
  }
}

bool GooglePassword::validPassword(const std::string& password) const {
      if(password.length() < 6 || password.length() > 50){
        return;
    }
    if(password.find(' ') != string::npos){
        return;
    }
    if(password.find("123456") != string::npos){
        return;
    }
}

