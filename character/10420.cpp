#include <string>
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
  int n; scanf("%d", &n);
	map<string, int> answer;
	while (n--) {
		string country, name;
		cin >> country;
		cin.ignore();
		getline(cin, name);
		//cout<<"name"<<name<<endl;
		//name = "dkkd";
		answer[country]++;
	}
	for (map<string, int>::iterator it = answer.begin(); it != answer.end(); it++)
		cout << it->first << " " << it->second << endl;
		
	return 0;

}
