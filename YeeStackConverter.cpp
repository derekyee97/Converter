// YeeStackConverter.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <stdio.h>
#include<iostream>
#include<string>
#include <math.h>
using namespace std;
void menu(int &number,  int &base, int &otherBase, int &difNumBase,string &hexRef);
//@class: Yee_Stack_Converter
// implementation of a stack, used for number based conversion.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Yee_Stack_Converter
{
public:
	int numOfElements = 0;
	//@method: push
	//place element onto top of the "stack" following LIFO
	//======================================================================================================================================
	bool push(int *pointer, int array[], int element)
	{
		if (numOfElements == 100) //if full, cant add to stack so going to exit (essentially check_full())
		{
			cout << "The stack is full. Can not compute, exiting..." << endl;
			exit(1);
		}
		else
		{
			*(pointer) = element;       //access address to next available splot
			numOfElements++;

			return true;
		}
		return false;
	}
	//======================================================================================================================================
	//@method: pop
	//will return the top of the stack
	//======================================================================================================================================
	int pop(int *pointer, int array[])
	{
		if (numOfElements == 0)            //essentially check_empty()
		{
			return -1;                             //return negative value if stack empty 
		}
		int temp = *(pointer);
		numOfElements--;
		return temp;
	}
	//======================================================================================================================================
	//#method: check_full
	//return boolean value true if the stack is full.
	//======================================================================================================================================
	bool check_full()
	{
		if (numOfElements != 100)
		{
			return false;
		}
		return true;
	}
	//======================================================================================================================================
	//@method: check_empty
	//will return bool value of true if the stack is empty
	//======================================================================================================================================
	bool check_empty()
	{
		if (numOfElements == 0)
		{
			return true;
		}
		return false;
	}
	//======================================================================================================================================
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//@main: 
//will run the desired conversions.
//===============================================================================================================================
int convertToDecimal(int& base, int &number, Yee_Stack_Converter holder,int* pointer, int array[],string hexString);
void convertFromDecimal(int &input, int &base, int remainder,int* pointer, Yee_Stack_Converter &holder,int array[]);
int main()
{
	//declaration of variables needed, and their references
	int input = 0, base = 0, remainder = 0, temp = 0, otherBase = 0,difNumBase=0, &inputRef = input, &baseRef = base, &otherBaseRef=otherBase,&difNumBaseRef=difNumBase;
	const int max = 100;
	int array[max];
	string hexString = " "; //used when the user wants to enter a hex value
	int *pointer = array;
	Yee_Stack_Converter stack;          // when converting, holds the remainders...
	Yee_Stack_Converter &holder = stack;
	while (true) //run menu infintely 
	{
		menu(inputRef, baseRef, otherBaseRef, difNumBaseRef,hexString);
		if (input != -2)  //converting decimal to whatever base.
		{
			remainder = 0;
			convertFromDecimal(input, base, remainder, pointer,holder,array);
			cout << endl;
		}
		else  //converting from another base to decimal, hex, octal ,or binary
		{
			cout << "Converting from base: " << otherBase << " to " << base << endl;
			int temp = convertToDecimal(otherBase, difNumBaseRef,holder, pointer, array,hexString);  //no matter what, convert to decimal first.
			if (base == 10)   //if want from another base to decimal, just print out result
			{
				cout << "The decimal conversion is: " << temp << endl;
			}
			else
			{
				convertFromDecimal(temp, base, remainder, pointer, holder, array);   //otherwise use previously implemented method to convert decimal to any other base.
				cout<<endl;
			}

		}
	}
}
//===============================================================================================================================
//@function: menu
// Will print out options for the user to choose from. 
//===============================================================================================================================
void menu(int &number, int &base, int &otherBase, int &difNumBaseRef,string &hexRef)
{
	cout << "Please enter the base you would like to convert to, or enter -1 to quit: ";
	cin >> base;
	if (base == -1)
	{
		cout << "selected to quit: " << endl;
		exit(0);
	}
	cout << "\nPlease enter the positive number you would like to convert to in decimal, if not in decimal please type -2: ";
	cin >> number;
	if (number == -2)             //selecting to enter number from different base 
	{
		cout << "Please enter the base you would like to convert FROM: 2,8, or 16: ";
		cin >> otherBase;
		if (otherBase == 2 || otherBase == 8 || otherBase == 16)
		{
			if (otherBase != 16)
			{
				cout << "\nPlease enter the NUMBER in the base you want to convert from: ";
				cin >> difNumBaseRef;
			}
			else
			{
				cout << "Please enter the hex value you would like to convert." << endl;
				cin >> hexRef;
				
			}
		}
		else
		{
			cout << "invalid base to convert from." << endl;
			return;
		}
	}
}
//===============================================================================================================================
//@function: convertFromDecimal
// will take a decimal number, and convert it to the specified base
//===============================================================================================================================
void convertFromDecimal(int &input, int &base, int remainder,int* pointer,Yee_Stack_Converter &holder,int array[])
{
	int temp = 0;
	cout << "selected to convert to base: " << base << " from the number: " << input << endl;
	cout << "The answer is: " << endl;
	while (input > 0)
	{
		remainder = input%base;
		input = input / base;
		holder.push(pointer, array, remainder);
		pointer++;
	}
	while (!holder.check_empty())
	{
		pointer--;
		temp = holder.pop(pointer, array);
		if (base == 16)                   //if base 16, need to print out appropriate characters that represent numbers from 10-15
		{
			if (temp == 10)
				cout << 'A';
			else if (temp == 11)
			{
				cout << 'B';
			}
			else if (temp == 12)
			{
				cout << 'C';
			}
			else if (temp == 13)
			{
				cout << 'D';
			}
			else if (temp == 14)
			{
				cout << 'E';
			}
			else if (temp == 15)
			{
				cout << 'F';
			}
			else
			{
				cout << temp;
			}
		}
		else
		{
			cout << temp;
		}
	}

}
//===============================================================================================================================
//@function: convertToDecimal
//will take a binary, hex, or octal number and convert it to decimal
//===============================================================================================================================

int convertToDecimal(int& base, int &number, Yee_Stack_Converter holder,int* pointer, int array[],string hexString)
{
	int counter = 0;  //keeps track of power
	int remainder = 0;
	int result = 0;
	int temp = 0;
	if (base != 16)   //not checking for letters 
	{
		while (number > 0)
		{
			remainder = number % 10;
			result += remainder*(int)pow(base, counter);  //equation to convert to decimal
			number = number / 10;
			counter++;
		}
	}
	else
	{
		result = std::stoi(hexString, nullptr, 16);

	}
	return result;
}
//===============================================================================================================================