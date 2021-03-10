#include <iostream>
#include <string>
#include <pthread.h>
#include <fstream>
#include <cctype>
#include <stdexcept>
#include <cstring> //c string manipulator
#include <sstream>
#include <vector>
#include <unistd.h>
using namespace std;

pthread_mutex_t moo;

vector<int> starting_point;

class Counter 
{
	public:
		Counter(string c) : str(c) {}
		string str;
		int read_characters;
		int i;
		int id_thread;
		void increment();
		void print();
		
};
void Counter :: print()
{
	cout << this->str << " has " << i << " in big.txt\n";
}
void Counter :: increment()
{
	this->i++;
}


void* WriteFile(void* parameter)
{
	ofstream create; //creating a new file big.txt
	create.open("big.txt");
	char a;
	
	if (!create.is_open()) //output the warning sign if the file isn't opened
	{
		cout << "Fail to open big.txt file" << endl;
	}

	pthread_mutex_lock(&moo);
	for (int i = 0; i < 250000000; i++) //writing file
	{
		if (rand() % 2 == 1) // writing random lower case letter
		{
			a = 'a' + rand() % 26;
		}
		else // writing random upper case letter
		{
			a = 'A' + rand() % 26;
		}
		create << a;
	}
	create.close();
	pthread_mutex_unlock(&moo);
	pthread_exit(NULL);
}

void* SearchFile(void* C)
{
	Counter* pointer = static_cast<Counter*>(C); // casting the pointer
	ifstream read;
	read.open("big.txt");
	char a; //get characters
	string character;
	int j = 0;

	for (int i = 0; i < 250000000; i++)
	{
		read.get(a); // Get characters from the file
		
		if (i >= starting_point[pointer->id_thread])
		{
			if (i == pointer->read_characters)
			{
				break;
			}
			character += a; // Characters into string
			if (isupper(character[j]))
			{
				character[j] = tolower(character[j]);
			}

			if (character[j] == pointer->str[j])
			{
				j++;
				if (character.size() == pointer->str.size())
				{
					pthread_mutex_lock(&moo);
					pointer->increment();
					pthread_mutex_unlock(&moo);
					character.clear();
					j = 0;
				}
			}
			else
			{
				character.clear();
				j=0;
			}

		}
	}
	pthread_exit(NULL);
}
