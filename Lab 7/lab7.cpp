#include <iostream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;
class Message
{
private:
	string input; // User input
public:
	Message() { getline(cin, input); } // Empty constructor
	Message(string text) : input(text) {} // parametric constructor
	~Message() {} //destructor 
	string getinput();
	void print();
};
class MorseCode
{
private:
	string morse; // To store Morse code message
public:
	void translate(string);
	void print();
	string getMorse(); // this function is to get Morsecode
};
class stack
{
private:
	string memo;
	vector <string> v;
public:
	stack(string directive) : memo(directive) {}
	void push();
	void pop();
	void print();
	void set(string message);
};
string Message::getinput()
{
	return input;
}

void Message::print() //accessing private variable through the function
{
	cout << input << endl;
	return;
}
void MorseCode::translate(string msg)
{
	string morse[] = { ".-","-...","-.-.","-..",".","..-.",
					  "--.","....","..",".---","-.-",".-..",
					  "--","-.","---",".--.","--.-",".-.",
					  "...","-","..-","...-",".--","-..-",
					  "-.--","--..","-----",".----",
					  "..---","...--","....-",".....","-....",
					  "--...","---..","----.",".-.-.-","--..--" }; // MorseCode in alphebets and number in order
	string alphabets[] = { "A","B","C","D","E","F","G",
						  "H","I","J","K","L","M","N",
						  "O","P","Q","R","S","T","U",
						  "V","W","X","Y","Z","0","1",
						  "2","3","4","5","6","7","8",
						  "9",".","," };

	string morse_code;

	for (int i = 0; i < msg.size(); i++)
	{
		if (islower(msg[i])) // if the user types in upper case, this will switch all the uppercase into lowercase
		{
			msg[i] = toupper(msg[i]);
		}
		for (int j = 0; j < 38; j++) // intializing all the morsecode in alphebets and number in order
		{
			if (msg[i] == ' ') // include space if the user uses space
			{
				morse_code += ' ';
				break;
			}
			if (msg[i] == alphabets[j][0])
			{
				morse_code += morse[j];
				break;
			}
		}

	}
	this->morse = morse_code;
	return;
}
void MorseCode::print() // trying to get access the variables from private
{
	cout << morse << endl;
	return;
}
void stack::push() // pushing the memo
{
	v.push_back(memo);
	return;
}

void stack::pop() // Pop function
{
	if (v.empty())
	{
		cout << "Cannot pop! Stack is Empty." << endl;
	}
	else
	{
		v.pop_back();
	}
	return;
}

void stack::print() // printing the stack
{
	if (v.empty()) //check to see if the stack is empty
	{
		cout << "Stack is empty!!!" << endl;
	}
	else
	{
		for (int i = 0; i < v.size(); i++) // printing the stack
		{
			cout << v[i] << endl;
		}
	}
	return;
}
void stack::set(string message)
{
	this->memo = message; //setting message into memo
	return;
}

string MorseCode::getMorse()
{
	return this->morse;
}

int main()
{
	int num = 0;
	char x = 'a';
	stack messages("");
	while (num != 4)
	{
		cout << "Choose your option" << endl << endl
			<< "1. Enter Text" << endl
			<< "2. Print Stack" << endl
			<< "3. Pop" << endl
			<< "4. Exit" << endl;
		cin >> num;
		cin.ignore();
		switch (num)
		{
		case 1: // Read text from the user
		{
			Message txt;
			while (x != 'y' || x != 'n') // Loop till the user gives right output
			{
				cout << "Do you want to translate or not?" << endl;
				cout << "Enter y for yes, n for no" << endl;
				cin >> x;
				if (x == 'y' || x == 'n') // if the user gives the right output it will stop the loop
				{
					break;
				}
			}
			if (x == 'y')
			{
				MorseCode translate;
				translate.translate(txt.getinput()); // calling a function from class
				messages.set(translate.getMorse()); // carry the user's input text and translate it 
				messages.push(); // push the translated text into the stack
			}
			else
			{
				messages.set(txt.getinput()); // it will just keep the text without translating it
				messages.push(); // push the text into the stack
				break;
			}
		}

		case 2: // Printing all the elements in the stack
		{
			messages.print(); // print the stack
			break;
		}

		case 3: // Pop the latest message element from the stack
		{
			messages.pop(); // pop the stack
			break;
		}

		case 4: // Quiting the program
		{
			break;
		}
		}
	}
	return 0;
}
