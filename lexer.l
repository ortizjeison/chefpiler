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
if (if)
elsif (elsif)
else (else)
and (and)
or (or)
not (not)
xor (xor)

%%
/*espacio? nada*/
{ws}  {}
/*entero? devuelvalo*/
{integer} {return yy::compilador_parser::make_NUMERO(strtol (yytext, NULL, 10),loc);}
/*{IDENTIFICADOR}	{return yy::compilador_parser::make_IDENTIFICADOR(yytext,loc);}*/

/*Operadores*/
"+"		{return yy::compilador_parser::make_PLUS(loc);}
"-"		{return yy::compilador_parser::make_MINUS(loc);}
"*"		{return yy::compilador_parser::make_TIMES(loc);}
"/"		{return yy::compilador_parser::make_DIV(loc);}

/*condicionales*/
{if} {return yy::compilador_parser::make_IF(loc);}
{elsif} {return yy::compilador_parser::make_ELSIF(loc);}
{else} {return yy::compilador_parser::make_PLUS(loc);}

/*Operadores lógicos*/
{and} {return yy::compilador_parser::make_AND(loc);}
{or} {return yy::compilador_parser::make_OR(loc);}
{not} {return yy::compilador_parser::make_NOT(loc);}
{xor} {return yy::compilador_parser::make_XOR(loc);}

.     {//printf("ERROR LEXICO %s\n",yytext);}
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
