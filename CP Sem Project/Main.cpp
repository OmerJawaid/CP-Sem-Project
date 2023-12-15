#include<iostream>
#include<string>
#include<time.h>
using namespace std;

void display_character_info(string character_name, string character_class, int character_health, int character_exp);
void character_creation(string& character_name, string& character_class);
int battle_system_mythical_creature_attack(int attack_level);

//Main
int main()
{
	string character_name, character_class;
	int character_health = 100, character_exp=0,level,attack_level;
	//Character creation
	character_creation(character_name,character_class);
	//Character info
	display_character_info(character_name,character_class,character_health,character_exp);
	//Quest
	//Battle System
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
int battle_system_mythical_creature_attack(int attack_level)
{
	int attack;
	srand(time(0));
		attack = rand() % attack_level;
		cout << attack<<endl;
		return attack;
}