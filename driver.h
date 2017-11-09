#ifndef DRIVER
# define DRIVER
# include <string>
# include "parser.tab.hh"
#define YY_DECL \
  yy::compilador_parser::symbol_type yylex (compilador_driver& driver)
YY_DECL;

class compilador_driver
{
public:
  float resultado;
  void iniciarScanner();
  void terminarScanner();

  int parse(const std::string& archivo);

  std::string file;
};
#endif
