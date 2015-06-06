//
//  main.cpp
//  Converter
//
//  Created by Ashley Muller on 5/29/15.
//  Copyright (c) 2015 Ashley Muller. All rights reserved.
//
 
#include <iostream>
#include <cmath>
using namespace std;
int getNum();
void dec_Bin(int number);
int bin_Dec(int size);
void dec_Hex(int);
void octal_Bin();
void hex_Bin();
int main() {
 
    //int num = getNum();
    //dec_Bin(num);
    //cout << endl;
    //int num2 = bin_Dec(8);
    //cout << num2;
   // dec_Hex(num);
    hex_Bin();
    cout << endl;
    octal_Bin();
    return 0;
}
 
 
 
 
 
int getNum()
{
    int number;
    do{
        cout << "Please enter a number between 0 and 255: ";
        cin >> number;
    }while(number > 255 || number < 0);
    return number;
}
 
void dec_Bin(int number)
{
    int index = 0;
    const int SIZE = 8;
    int binArray[SIZE] = {};
    
    for(int i = SIZE - 1; i >= 0; i--)
    {
        binArray[i] = number%2;
        number = number/2;
    }
    for (int i = 0; i < SIZE; i++){
    
        if (binArray[i] != 0)
        {
            index = i;
            break; //exits the loop on first instance of a non zero number
        }
           
        
    }
    for (int i = index; i < SIZE; i++)
    {
        cout << binArray[i];
    }
}
 
/*void dec_Bin(int number) {
    const int SIZE = sizeof(number) * 8;
    
    bool not_trailing = false;
    for (int i = 0; i < SIZE; i++) {
        cout << (number < 0 ? "1" : not_trailing ? "0" : "");
        not_trailing = number < 0;
        number = number << 1;
    }
}*/
 
 
int bin_Dec(int size)
{
    int myArray[8] = {1,0,1,0,1,1,0,1};
    int num = 0;
    int index =0;
    for(int i = size - 1; i >= 0;i--)
    {
        num +=  myArray[i]*(pow(2,index));
        index++;
    }
    return num;
}
void dec_Hex(int number)
{
  
    const int SIZE = 8;
    char character;
    int binArray[SIZE] = {};
    
    for(int i = SIZE - 1; i >= 0; i--)
    {
        binArray[i] = number%16;
        number = number/16;
    }
    for (int i = 0; i < SIZE; i++)
    {
        if(binArray[i] > 9)
        {
            character = binArray[i] + 55; //offset for ASCII character. 65 = A
            cout << character;
        }
        else
        cout << binArray[i];
        
    }
 
 
}
 
void hex_Bin()
{
    string hex = "4A";
    int hexArray[hex.length()];
    for(int i = hex.length() - 1; i >= 0; i--)
    {
        hexArray[i] = hex[i];
    }
 
    for (int i = 0; i < hex.length(); i++)
    {
        if(hexArray[i] >= 65) //ASCII A starts at 65
            hexArray[i] = int(hexArray[i]-55); //convert to decimal equivalent
        if(hexArray[i] >= 48 && hexArray[i] < 65)//ASCII numbers and decimal are different
            hexArray[i] = int(hexArray[i]- 48);//Convert ASCII number to its decimal equivalent
        
    }
 
    for(int i = 0; i < hex.length();i++)
    {
        dec_Bin(hexArray[i]); //convert decimal to binary for each number
    }
    
}
 
 
void octal_Bin()
{
    string octal = "22";
    
    int octalArray[octal.length()];
    for(int i = octal.length() - 1; i >= 0; i--)
    {
        octalArray[i] = octal[i];
    }
    
    for (int i = 0; i < octal.length(); i++)
    {
        
        octalArray[i] = int(octalArray[i]- 48);//Convert ASCII number to its decimal equivalent
        
    }
    
    for(int i = 0; i < octal.length();i++)
    {
        dec_Bin(octalArray[i]); //convert decimal to binary for each number
    }
 
    
}