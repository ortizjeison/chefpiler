#ifndef DRIVER
# define DRIVER
# include <string>
# include "parser.tab.hh"
#include <stdio.h>
#include "driver.h"
#include <sstream>
#include "iostream"
#include <bits/stdc++.h>
#define YY_DECL \
  yy::compilador_parser::symbol_type yylex (compilador_driver& driver)
YY_DECL;

class compilador_driver
{
public:

  float codigo;
  int sumA;
  int sumB;
  std::vector<int> ings;
  std::vector<float> ops;
  void iniciarScanner();
  void terminarScanner();

  int parse(const std::string& archivo);

  std::string file;
};
#endif
