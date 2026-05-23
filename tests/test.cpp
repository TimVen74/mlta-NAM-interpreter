#include <gtest/gtest.h>
#include <algorithm>
#include <random>
#include "../src/interpreter.cpp"

std::ifstream rules_invert("../examples/example1_rules.txt");
std::ifstream rules_sort("../examples/example2_rules.txt");
std::ifstream rules_double("../examples/example3_rules.txt");

std::string Invert(std::string s) {
  std::string ans = s;
  for (int i = 0; i < (int)ans.size(); ++i) {
    if (s[i] == '0') ans[i] = '1';
    else ans[i] = '0';
  }
  return ans;
}

std::string Sort(std::string s) {
  std::string ans = s;
  std::sort(ans.begin(), ans.end());
  return ans;
}

std::string Double(std::string s) {
  std::string ans = s + s;
  return ans;
}

std::mt19937 rnd(67);
const int LEN_SMALL = 10;
const int CNT_SMALL = 1000;
const int LEN_BIG = 500;
const int CNT_BIG = 5;

TEST(InvertTests, Small) {
  for (int i = 0; i < CNT_SMALL; ++i) {
    std::string s;
    for (int j = 0; j < LEN_SMALL; ++j) {
      s += (char)('0' + (rnd() % 2));
    }
    EXPECT_EQ(RunMarkovAlgorithm(s, rules_invert), Invert(s));
    rules_invert.clear();
    rules_invert.seekg(0);
  }
}

TEST(InvertTests, Big) {
  for (int i = 0; i < CNT_BIG; ++i) {
    std::string s;
    for (int j = 0; j < LEN_BIG; ++j) {
      s += (char)('0' + (rnd() % 2));
    }
    EXPECT_EQ(RunMarkovAlgorithm(s, rules_invert), Invert(s));
    rules_invert.clear();
    rules_invert.seekg(0);
  }
}

TEST(SortTests, Small) {
  for (int i = 0; i < CNT_SMALL; ++i) {
    std::string s;
    for (int j = 0; j < LEN_SMALL; ++j) {
      s += (char)('0' + (rnd() % 2));
    }
    EXPECT_EQ(RunMarkovAlgorithm(s, rules_sort), Sort(s));
    rules_sort.clear();
    rules_sort.seekg(0);
  }
}

TEST(SortTests, Big) {
  for (int i = 0; i < CNT_BIG; ++i) {
    std::string s;
    for (int j = 0; j < LEN_BIG; ++j) {
      s += (char)('0' + (rnd() % 2));
    }
    EXPECT_EQ(RunMarkovAlgorithm(s, rules_sort), Sort(s));
    rules_sort.clear();
    rules_sort.seekg(0);
  }
}

TEST(DoubleTests, Small) {
  for (int i = 0; i < CNT_SMALL; ++i) {
    std::string s;
    for (int j = 0; j < LEN_SMALL; ++j) {
      s += (char)('0' + (rnd() % 2));
    }
    EXPECT_EQ(RunMarkovAlgorithm(s, rules_double), Double(s));
    rules_double.clear();
    rules_double.seekg(0);
  }
}

TEST(DoubleTests, Big) {
  for (int i = 0; i < CNT_BIG; ++i) {
    std::string s;
    for (int j = 0; j < LEN_BIG; ++j) {
      s += (char)('0' + (rnd() % 2));
    }
    EXPECT_EQ(RunMarkovAlgorithm(s, rules_double), Double(s));
    rules_double.clear();
    rules_double.seekg(0);
  }
}
