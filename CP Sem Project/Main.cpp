#include<iostream>
#include<string>
#include<time.h>
using namespace std;

void display_character_info(string character_name, string character_class, int character_health, int character_exp);
void character_creation(string& character_name, string& character_class);
void battle_system_mythical_creature_attack(int level);

//Main
int main()
{
	string character_name, character_class;
	int character_health = 100, character_exp=0,level;
	character_creation(character_name,character_class);
	display_character_info(character_name,character_class,character_health,character_exp);
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
void character_creation(string& character_name, string& character_class)
{
	string choice;
	cout << "Account Creation!" << endl;
	//Player Name
	cout << "Enter the player name: ";
	getline(cin, character_name);
	//Player Class
	cout << "Choose the player class " << endl
		<< "a) Warrior" << endl
		<< "b) Mage" << endl
		<< "c) Rogue" << endl
		<< "Choose";
	getline(cin, choice);
	if (choice == "a" || choice == "warrior")
		character_class = "Warrior";
	else if (choice == "b" || choice == "mage")
		character_class = "Mage";
	else if (choice == "c" || choice == "rogue")
		character_class = "Rogue";
}
//Battle System
void battle_system_mythical_creature_attack(int level)
{
	int attack;
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		attack = rand() % level;
		cout << attack<<endl;
	}
}