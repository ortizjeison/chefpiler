#include "driver.h"
#include "parser.tab.hh"
#include <vector>


int compilador_driver::parse(const std::string& archivo)
{
  file = archivo;
  iniciarScanner();
  yy::compilador_parser parser(*this);
  parser.set_debug_level(false);
  //VARS
  std::vector<int> ings;
  std::vector<float> ops;
  float codigo = parser.parse();
  int sumA = parser.parse();
  int sumB = parser.parse();
  terminarScanner();
  return codigo;
}
