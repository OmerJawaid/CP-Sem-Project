#include<iostream>
#include<string>
#include<time.h>
using namespace std;

void display_character_info(string character_name, string character_class, int character_health, int character_exp);
void character_creation(string& character_name, string& character_class, int& character_exp , int& level);
int battle_system_mythical_creature_attack(int attack_level);
void quest();
//structure for character creation
struct {
	string character_name, character_class;
	int character_health = 1000, character_exp=0, level=0;
}character_1;

//Main
int main()
{
	
	{
		
		char choice;
		do {
			//Main Page for start and quit
			cout << "Welcome to the mythical land of Eldoria" << endl
				<< "a) Start" << endl
				<< "b) Quit" << endl
				<< "What do you want to do (a/b)?" << endl;
			cin >> choice;

			if (choice == 'a')
			{
				//Storyline
				cout << "On a calm winter day, Eldoria Kingdom got hit by a surprise snowstorm. Everything turned white as snow covered the kingdom. But then, weird creatures from the nearby jungle showed up and attacked Eldoria. They took the people hostage and took control of the kingdom." << endl;
				system("pause");
				cout << "There was a small  village nestled beside Eldoria, There were three renowned warriors known for their exceptional fighting skills lived in that village. When they came to know that Eldoria is being attacked by some mythical creatures they decided to help the Eldoria kingdom and set them free from the hands of powerful magical mythical creatures" << endl;
				//Character Creation with its verification
				char choice;
				do {
					//Character creation
					character_creation(character_1.character_name, character_1.character_class, character_1.character_exp, character_1.level);
					//Character info
					display_character_info(character_1.character_name, character_1.character_class, character_1.character_health, character_1.character_exp);
					cout << "Is the above information correct?(Y/N)";
					cin >> choice;
					if (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y')
						cout << "Choose th corrent option.";
						continue;
				} while (choice=='N'|| choice == 'n');
				//Contiune the story



			}
			else if (choice == 'b')
				exit(1);
			else
				cout << "Choose the correct option";
		} while (choice != 'a' && choice != 'b');
	}
}

//Character Information
void display_character_info(string character_name, string character_class, int character_health, int character_exp)
{
	cout << "Character Information" << endl
		<< "Character Name: " << character_name << endl
		<< "Character Class: " << character_class << endl
		<< "Health: " << character_health << endl
		<< "Experience Points: " << character_exp << endl;
}
//Character creation
void character_creation(string& character_name, string& character_class, int &character_exp, int &level)
{
	string choice;
	bool flag=true;
	cout << "\nAccount Creation!" << endl;
	//Player Name
	cout << "Enter the player name: ";
	cin>>character_1.character_name;
	//Player Class
	do {
		cout << "Choose the player class " << endl
			<< "a) Warrior" << endl
			<< "b) Mage" << endl
			<< "c) Rogue" << endl
			<< "Choose: ";
		cin >> choice;
		choice[0] = tolower(choice[0]);
		if (choice == "a" || choice == "warrior" || choice == "Warrior")
			character_1.character_class = "Warrior";
		else if (choice == "b" || choice == "mage" || choice == "Mage")
			character_1.character_class = "Mage";
		else if (choice == "c" || choice == "rogue" || choice == "Rogue")
			character_1.character_class = "Rogue";
		else
		{
			cout << "Incorrect" << endl
				<< "Try Again!";
			flag = false;
		}
	} while (flag == false);
	character_exp = 0;
	level = 0;
}
//Battle System
int battle_system_mythical_creature_attack(int attack_level)
{
	int attack;
	srand(time(0));
		attack = rand() % attack_level;
		cout << attack<<endl;
		return attack;
}
//Quest Building
void quest()
{
	//Quest Options
	cout << "Quest: " << endl
		<<"Beginner"<<endl
		<<"Intermediate"<<endl
		<<"Advanced"<<endl
		<<"Choice: ";
}