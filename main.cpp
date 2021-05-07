#include <iostream>
#include <map>
#include <string>
#include <regex>

using namespace std;


 map < char, int > EncryptionMap;
 map <  int,char > DecryptionMap;


void Decryption (string &str)
{
  bool contains_non_alpha
    = !std::regex_match(str, std::regex("^[A-Za-z]+$"));
   if(!contains_non_alpha){


    int value = 0;

    for (char letter = 'a'; letter <= 'z'; ++letter)
    {
      EncryptionMap.insert (make_pair (letter, value++));

    }

    int valu = 0;
    for (char letter = 'a'; letter <= 'z'; ++letter)
    {
      DecryptionMap.insert (make_pair (valu++,letter));
    }

     string s="";
     for (auto i:str){
         int key= (5- EncryptionMap[i])%26;

         char value=DecryptionMap[abs(key)];
         s+=value;

    }

   cout <<"clear text: "  <<s<< endl;
    cout << endl;
   }else{
      cout <<"invalid characters in your message"<< endl;
      cout << endl;
    }
}


void Encryption (string &str)
{
  bool contains_non_alpha
    = !std::regex_match(str, std::regex("^[A-Za-z]+$"));
   if(!contains_non_alpha){
    int value = 0;

    for (char letter = 'a'; letter <= 'z'; ++letter)
    {
      EncryptionMap.insert (make_pair (letter, value++));

    }

    int valu = 0;
    for (char letter = 'a'; letter <= 'z'; ++letter)
    {
      DecryptionMap.insert (make_pair (valu++,letter));
    }

    string s="";
    for (auto i:str){
         auto key= (5 + EncryptionMap[i])%26;
         char value=DecryptionMap[key];
         s+=value;
    }
        cout <<"cipher text: "  <<s<< endl;
        cout << endl;
    }else{
      cout <<"invalid characters in your message"<< endl;
      cout << endl;
    }
}

main ()
{
  cout << "MENU" << endl;
  cout << "Encryption = 1" << endl;
  cout << "Decryption = 2" << endl;
  cout << "Exit = 3" << endl;
  int n;
  bool stop=false;
  while(!stop){
      cout << "pick a value from the menu (1-3)" << endl;

      cin>>n;
      if(!cin.good()){
          cout << "invalid input value  "<<n << endl;
         break;
      }
      if(n!=1 && n!=2&& n!=3){
          cout << "invalid input value  "<<n << endl;
          break;
      }
      else{
        if(n==1){
               cout << endl;
               cout << "Encrypt your message into cipher text" << endl;
               cout << "Enter your message:";
               string s;
               cin >>s;
                transform(s.begin(), s.end(), s.begin(), ::tolower);
               Encryption (s);

          }
          else if(n==2){
               cout << endl;
               cout << "Decrypt your  message into clear text" << endl;
               cout << "Enter your message:";
               string s;
               cin >>s;
               transform(s.begin(), s.end(), s.begin(), ::tolower);
               Decryption (s);
          }
         else  if(n==3){
              stop=true;
              cout << "exiting..." << endl;

          }
      }
  }



  return 0;

}

