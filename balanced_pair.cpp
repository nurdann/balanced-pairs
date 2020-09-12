#include <stack>
#include <iostream>
#include <algorithm>
#include <map> 

bool isBalanced(std::string exp, std::map<char, char>& p) {
  std::stack<char> s;
  for(auto& c: exp) {
	if(p.find(c) != p.end()) {
	  s.push(c);
	} else if(!s.empty() && (p.find(s.top())->second == c)) {
	  s.pop();
	} else if(std::find_if(p.begin(), p.end(), [&, c] (std::pair<char, char> allowed_pair) {
	  return allowed_pair.second == c;
	}) != p.end()) {
	  return false;
	}
  }
  return s.empty();
}

int main(int argc, char* argv[]) {
  std::string input = argv[1];
  std::string pairs;
  if(argc > 2)
	pairs = argv[2];

  std::map<char, char> enclosingPairs;
  enclosingPairs['('] = ')'; // default pairs
  
  for(std::string::iterator it = pairs.begin(); it < pairs.end(); ++it) {
	char first = *it;
	char second = *(++it);
	enclosingPairs[first] = second;
  }
  
  std::cout << isBalanced(input, enclosingPairs) << std::endl;
  
  return 0;
}
