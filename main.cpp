#include <stdio.h>
#include "driver.h"
#include <sstream>
#include "iostream"
#include <bits/stdc++.h>

using namespace std;

template <typename T>
string toString(T num){
  stringstream ss;
  ss<<num;
  return ss.str();
}


//Método addIngredients


//Standar Strings:
string header = "New Tasty Algorithm. \nComments. \nIngredients.\n";
string endcode = "Pour contents of the 1st mixing bowl into the baking dish.\n\nServes 1.";
string method = "Method.\nPut zero into the 1st mixing bowl.\n";
string ingredients = "0 zero\n";

int main(){
  float codigo = 0.0;
  compilador_driver driver;
  if(driver.parse("entrada.txt")){
    //printf("La entrada es incorrecta\n");
  }else{
    //printf("La entrada es correcta\n");
    printf("resultado = %f\n",driver.codigo);

    for(int i =0;i<driver.ings.size();i++){
      ingredients += toString(driver.ings[i]) + " ingredient"+toString(i)+'\n';
    }
    ingredients+='\n';

    method += "Add a into the 1st mixing bowl.\n";
    method += "Add b into the 1st mixing bowl.\n";
    cout<<header + ingredients+ method + endcode<<endl;
  }

  return 0;
}
