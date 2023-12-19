#include<iostream>
#include<string>
#include<time.h>
using namespace std;

void display_character_info(string character_name, string character_class, int character_health, int character_exp);
void character_creation(string& character_name, string& character_class, int& character_exp , int& level);
int battle_system_mythical_creature_attack(int attack_level);
void quest();
//structure for character creation
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
	bool flag=true;
	cout << "Account Creation!" << endl;
	//Player Name
	cout << "Enter the player name: ";
	getline(cin, character_name);
	//Player Class
	do {
		cout << "Choose the player class " << endl
			<< "a) Warrior" << endl
			<< "b) Mage" << endl
			<< "c) Rogue" << endl
			<< "Choose";
		cin >> choice;
		choice[0] = tolower(choice[0]);
		if (choice == "a" || choice == "warrior")
			character_class = "Warrior";
		else if (choice == "b" || choice == "mage")
			character_class = "Mage";
		else if (choice == "c" || choice == "rogue")
			character_class = "Rogue";
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