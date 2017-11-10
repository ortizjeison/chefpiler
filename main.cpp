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


//Method find token index
int find(int n, std::vector<int> v){
  for(int i=0;i<v.size();i++){
    if(v[i]==n){
      return i;
    }
  }
}


//Standar Strings:
string header = "New Tasty Algorithm. \nComments. \nIngredients.\n";
string endcode = "Pour contents of the 1st mixing bowl into the baking dish.\n\nServes 1.";
string method = "Method.\n";
string ingredients="0 zero\n1 one\n";

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

    //Building the method in chef.
    //Para los tokens 1 y 2:
    int posA=find(driver.ops[0],driver.ings); //Posición del primer token
    int posB=find(driver.ops[2],driver.ings);
    //Check operator

/* 5544 sum, 4455 res, 7788 mult, 8877 div */

    //cout<<"A = "<<posA<<" / B = "<<posB<<endl;
    if(driver.ops[1]==5544){
      //"Add " + "ingredient"+toString(driver.ings[posA])+" into the 1st mixing bowl.\n";
      method += "Put zero into the 1st mixing bowl.\n";
      method += "Add " + std::string("ingredient"+toString(posA)+" into the 1st mixing bowl.\n");
      method += "Add " + std::string("ingredient"+toString(posB)+" into the 1st mixing bowl.\n");
    }else if (driver.ops[1]==4455) {
      method += "Put zero into the 1st mixing bowl.\n";
      method += "Remove " + std::string("ingredient"+toString(posA)+" into the 1st mixing bowl.\n");
      method += "Remove " + std::string("ingredient"+toString(posB)+" into the 1st mixing bowl.\n");
    }else if(driver.ops[1]==7788){
      method += "Put one into the 1st mixing bowl.\n";
      method += "Combine " + std::string("ingredient"+toString(posA)+" into the 1st mixing bowl.\n");
      method += "Combine " + std::string("ingredient"+toString(posB)+" into the 1st mixing bowl.\n");
    }else if(driver.ops[1]==8877){
      method += "Put one into the 1st mixing bowl.\n";
      method += "Divide " + std::string("ingredient"+toString(posB)+" into the 1st mixing bowl.\n");
      method += "Divide " + std::string("ingredient"+toString(posB)+" into the 1st mixing bowl.\n");
    }

    //Para el resto de tokens

    for(int i=3;i<driver.ops.size()-2;i++){
      if(driver.ops[i+1]==5544){
        int index=find(driver.ops[i+2],driver.ings);
        method += "Add " + std::string("ingredient"+toString(index)+" into the 1st mixing bowl.\n");
        cout<<"sumando"<<endl;
        cout<<"driver.ops[i+1] = "<<driver.ops[i+1]<<endl<<"toString(i+2) = "<<i+2<<endl;
      }else if (driver.ops[i+1]==4455) {
        method += "Remove " + std::string("ingredient"+toString(i+2)+" into the 1st mixing bowl.\n");
        cout<<"restando"<<endl;
      }else if(driver.ops[i+1]==7788){
        method += "Combine " + std::string("ingredient"+toString(i+2)+" into the 1st mixing bowl.\n");
        cout<<"mult"<<endl;
      }else if(driver.ops[1]==8877){
        method += "Divide " + std::string("ingredient"+toString(i+2)+" into the 1st mixing bowl.\n");
        cout<<"div"<<endl;
      }
    }

    cout<<header + ingredients+ method + endcode<<endl;
  }

  return 0;
}
