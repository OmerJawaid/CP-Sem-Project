#include<iostream>
#include<string>
#include<time.h>
using namespace std;

void display_character_info(string character_name, string character_class, int character_health, int character_exp);
void character_creation();
int battle_system_mythical_creature_attack(int attack_level);
void quest();
//structure for character creation
struct {
	string character_name, character_class;
	int character_health = 400, character_exp=0, level=1;
	string inventory[15];
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
					character_creation();
					//Character info
					display_character_info(character_1.character_name, character_1.character_class, character_1.character_health, character_1.character_exp);
					cout << "Is the above information correct?(Y/N)";
					cin >> choice;
					if (choice != 'N' && choice != 'n' && choice != 'Y' && choice != 'y')
						cout << "Choose th corrent option.";
						continue;
				} while (choice=='N'|| choice == 'n');

				character_1.inventory[0] = "Rope";
				character_1.inventory[1] = "Health potion";

				//Contiune the story
				{
					char entrancechoice;
					cout << character_1.character_name << " inched closer to the kingdom, blending into the snowy bushes for cover. As he observed the kingdom," << character_1.character_name << "  spotted three potential paths to infiltrate.";
					//Quest
					do {
						cout << "a) The first option caught Jake's eye – the main gate.(Hard)" << endl
							<< "b) Turning his attention to the second path, Jake discovered a watchtower (Medium)" << endl
							<< "c) His gaze then shifted to the third option – a tower on the opposite side (Easy)" << endl
							<< "Choose your path: ";
						cin >> entrancechoice;
						entrancechoice=tolower(entrancechoice);
						if (entrancechoice == 'a')
						{
							cout << "He came out of the bushes and moved slowly towards the main gate of the kingdom" << endl
								<< "Guards: Who are you? Go away otherwise you will have to face the circumstances!" << endl
								<< character_1.character_name << ": Lets face the circumstances." << endl;

						}
						else if (entrancechoice == 'b')
						{

						}
						else if (entrancechoice == 'c')
						{
							
						}
						else
							cout << "Choose correct option.";
					} while (entrancechoice != 'a' && entrancechoice != 'b' && entrancechoice != 'c');
				}


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
void character_creation()
{
	string choice,name;
	bool flag=true;
	cout << "\nAccount Creation!" << endl;
	//Player Name
	cout << "Enter the player name: ";
	cin >> character_1.character_name;
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
	character_1.character_exp = 0;
	character_1.level = 0;
}
//Battle System
int battle_system_mythical_creature_attack(int attack_level)
{
	int attack;
	srand(time(0));
		attack = rand() % attack_level;
		cout << attack <<endl;
		return attack;
}
int character_attack(int character_attack_level, int creatures_attack)
{
	char attack_choice;
	do {
		cout << "Attack Options: " << endl
			<< "a) Attack" << endl
			<< "b) Defend" << endl
			<< "c) Healing" << endl
			<< "Choice: ";
		cin >> attack_choice;
		attack_choice = tolower(attack_choice);
		if (attack_choice == 'a')
		{
			character_1.character_health = character_1.character_health - creatures_attack;
			int attack;
			srand(time(0));
			attack = rand() % character_attack_level;
			cout <<"Attack: " << attack << endl;
			return attack;
		}
		else if (attack_choice == 'b')
		{
			cout << "Defended: " << creatures_attack;
		}
		else if (attack_choice == 'c')
		{
			character_1.character_health = character_1.character_health + 40;
			character_1.character_health = character_1.character_health - creatures_attack;
		}
		else
		{
			cout << "Invalid input ";
		}
	}while(attack_choice!='a' && attack_choice != 'b'&& attack_choice != 'c');
}
//Quest Building
void quest1()
{
	//Quest Options
	cout << "Quest: " << endl
		<<"Beginner"<<endl
		<<"Intermediate"<<endl
		<<"Advanced"<<endl
		<<"Choice: ";
}