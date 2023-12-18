#include<iostream>
#include<string>
#include<time.h>
using namespace std;

void display_character_info(string character_name, string character_class, int character_health, int character_exp);
void character_creation(string& character_name, string& character_class, int& character_exp , int& level);
int battle_system_mythical_creature_attack(int attack_level);

struct character {
	string character_name, character_class;
	int character_health = 1000, character_exp, level;
};

//Main
int main()
{
	//Structure copy
	struct character character_1;
	//Character creation
	character_creation(character_1.character_name, character_1.character_class, character_1.character_exp, character_1.level);
	//Character info
	display_character_info(character_1.character_name, character_1.character_class, character_1.character_health, character_1.character_exp);
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
void character_creation(string& character_name, string& character_class, int &character_exp, int &level)
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