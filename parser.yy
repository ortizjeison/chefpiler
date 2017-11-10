%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.4"
%defines
%define parser_class_name {compilador_parser}
%define api.token.constructor
%define api.namespace {yy}
%define api.value.type variant
%define parse.assert
%code requires
{
#include <string>
#include <stdio.h>
class compilador_driver;
}

%param { compilador_driver & driver }
%locations
%define parse.trace
%define parse.error verbose
%code
{
#include "driver.h"
#include <iostream>
}
%define api.token.prefix {TOK_}

//Listado de Terminales
%token PLUS "+"
%token <int> INT "int"
%token MINUS "-"
%token TIMES "*"
%token DIV "/"
%token FIN 0 "eof"

//Listado de No Terminales
%type <float> E
%type <float> T
%type <float> F

%printer { yyoutput << $$; } <*>;

%%
%start INICIO;

INICIO : E {driver.codigo= $1;};

E : E "+" T {$$=$1+$3; driver.sumA= $1; driver.sumB=$3;}
   |E "-" T {$$=$1-$3;};
   |T       {$$=$1;};

T : T "*" F {$$=$1*$3;}
   |T "/" F {$$=$1/$3;}
   |F       {$$=$1;};

F : "int"   {$$=$1; driver.ings.push_back($1);};

%%
void yy::compilador_parser::error(const location_type& lugar, const std::string& lexema)
{
  std::cout << "####ERROR#####" << lexema << std::endl;
}
