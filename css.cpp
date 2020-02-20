#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int c=0;
	fstream f("css.txt", ios::in);

  if (!f.is_open()) {
   cout<<"Cant open file\n";
   return 0;
   }

  string contents;
  contents.reserve(10000); 
  char ch;
  while (f.get(ch)) {
    c++;
    if (ch == ';' ){
    	contents.push_back(ch);
      contents.push_back('\n');
	}
  else if(ch=='.'||ch=='@' ){
  	contents.push_back('\n');
  		contents.push_back(ch);
  }else{	contents.push_back(ch);
  	
  }
  }

  f.close();
  
  f.open("css.txt", ios::out);
  if (!f.is_open()) {
   cout<<"Cant open file\n";
   return 0;
  
  }
  f << contents;
  f.close();
  cout<<"Initial size="<<c;
  return 0;
}
