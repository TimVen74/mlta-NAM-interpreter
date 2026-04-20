#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::ifstream in1("input.txt");
std::ifstream in2("rules.txt");
std::ofstream out("output.txt");

int main() {
  std::string data;
  in1 >> data;

  std::vector<std::tuple<std::string, std::string, std::string>> rules;
  std::string A, sep, B;
  while (in2 >> A >> sep >> B) {
    rules.emplace_back(A, sep, B);
    if (sep != "->" and sep != "->.") {
      std::cerr << "Invalid rule: " << A << ' ' << sep << ' ' << B << '\n';
      exit(1);
    }
  }

  bool f = true;
  while (f) {
    f = false;
    for (auto [A, sep, B] : rules) {
      if (A == "@") A = "";
      if (B == "@") B = "";
      size_t pos = data.find(A);
      if (pos != std::string::npos) {
        data.replace(pos, A.size(), B);
        f = (sep == "->");
        break;
      }
    }
  }

  out << data << '\n';
}
