#include <map>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  std::map<string,size_t> wordcount;
  for(string word;cin>>word;++wordcount[word]);
  for(auto it=wordcount.begin();it!=wordcount.end();++it)
    cout << it->first << " " << it->second << endl;
}
