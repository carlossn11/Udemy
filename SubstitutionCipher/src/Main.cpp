#include <iostream>
#include <string>

int main()
{
   std::string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
   std::string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

   std::string SecretMessageInput;

   std::cout << "Enter a secret message\n" << " : ";
   std::getline(std::cin, SecretMessageInput);

   std::string CipherMessage {SecretMessageInput};
   std::string DecipherMessage;

   for(size_t i = 0; i < CipherMessage.length(); i++)
   {
       if(CipherMessage.at(i) != ' ')
       {
           char CharTemp {CipherMessage.at(i)};
           int TempPos {static_cast<int>(alphabet.find(CharTemp))};
           CipherMessage.at(i) = key.at(TempPos);
        //    Now decipher of it
           DecipherMessage.push_back(CipherMessage.at(i));
           DecipherMessage.at(i) = alphabet.at(TempPos);
       }else {
           DecipherMessage.push_back(CipherMessage.at(i));
       }
   }
   std::cout << CipherMessage << "\n" << DecipherMessage << "\n";
}