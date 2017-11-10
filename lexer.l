%{
# include <cerrno>
#include <stdio.h>
#include <string>
#include "driver.h"
#include "parser.tab.hh"
#undef yywrap
#define yywrap() 1
static yy::location loc;
%}

%option noyywrap nounput batch debug noinput
%option outfile="scanner.cpp"

ws [ \t\n]+
digit [0-9]
integer {digit}+

%%

{ws}  {}
{integer} {return yy::compilador_parser::make_INT(strtol (yytext, NULL, 10),loc);}

"+"		{return yy::compilador_parser::make_PLUS(loc);}
"-"		{return yy::compilador_parser::make_MINUS(loc);}
"*"		{return yy::compilador_parser::make_TIMES(loc);}
"/"		{return yy::compilador_parser::make_DIV(loc);}

<<EOF>>		{return yy::compilador_parser::make_FIN(loc);}

%%
void compilador_driver::iniciarScanner(){
  yy_flex_debug = false;
  if(file.empty() || file == "-"){
    printf("No se encuentra el archivo de entrada");
    exit(1);
  }else{
    yyin = fopen (file.c_str (), "r");
  }
}
void compilador_driver::terminarScanner(){
  fclose(yyin);
}
