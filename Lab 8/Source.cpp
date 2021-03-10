#include "Header.h"

int main()
{
	int i=0;
	//declaraing the structure
	Counter x("x");
	Counter os("os");
	Counter cpu("cpu");
	Counter disk("disk");
	Counter cache("cache");

	//asking the user the number of threads
	while (i < 6)
	{
		cout << "Enter number of threads" << endl;
		cin >> i;
		cin.ignore();
		if (i < 6)
		{
			cout << "Don't do that" << endl;
		}
	}
	int num_thread = (i - 1) / 5;
	for (int iterator = 0; iterator < num_thread; iterator++)
	{
		starting_point.push_back(iterator * (250000000 / num_thread));
		starting_point.push_back(iterator * (250000000 / num_thread));
		starting_point.push_back(iterator * (250000000 / num_thread));
		starting_point.push_back(iterator * (250000000 / num_thread));
		starting_point.push_back(iterator * (250000000 / num_thread));
	}

	pthread_t tiddie[i];
	
	//reading the characters at the beginning of the threads
	x.read_characters = 250000000 / num_thread;
	os.read_characters = 250000000 / num_thread;
	cpu.read_characters = 250000000 / num_thread;
	disk.read_characters = 250000000 / num_thread;
	cache.read_characters = 250000000 / num_thread;

	pthread_create(&tiddie[0],NULL,WriteFile,NULL); //creating the thread
	pthread_join(tiddie[0], NULL); //joining the thread
	
	for (int q = 1; q < i; q+=5)
	{
		x.id_thread = q-1;
		os.id_thread = q;
		cpu.id_thread = q + 1;
		disk.id_thread = q + 2;
		cache.id_thread = q + 3;
		pthread_create(&tiddie[q], NULL, SearchFile, &x);//reading the thread
		pthread_create(&tiddie[q+1], NULL, SearchFile, &os);
		pthread_create(&tiddie[q+2], NULL, SearchFile, &cpu);
		pthread_create(&tiddie[q+3], NULL, SearchFile, &disk);
		pthread_create(&tiddie[q+4], NULL, SearchFile, &cache);
	}
	for (int q = 1; q < i; q++) //Joining the thread
	{
		pthread_join(tiddie[q], NULL);
	}
	
	x.print();
	os.print();
	cpu.print();
	disk.print();
	cache.print();
	return 0;
}
