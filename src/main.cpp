#include "interpreter.cpp"

std::ifstream in1("input.txt");
std::ifstream in2("rules.txt");
std::ofstream out("output.txt");

int main() {
  std::string data;
  in1 >> data;
  out << RunMarkovAlgorithm(data, in2) << '\n';
}
