//opdracht 0
#include <iostream>
#include <string>

using namespace std;

int main(){
string text;
int rot;
getline(cin,text);
cin >> rot;
for(int i = 0;i<text.size();i++){
cout << char(int(text[i]) + rot);
}
cout << endl;
}
