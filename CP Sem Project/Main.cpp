#include<iostream>
#include<string>
#include<time.h>
using namespace std;

//structure for character creation
struct {
	string name, catagory;
	int health = 400, exp = 0, level = 1,attack;
}character;

struct {
	string name;
	int health, attack[2], combo;
}creature[5];

void display_character_info();
void character_creation();
inline int mythical_creature_attack(int attack_level, int characterattack, int characternumber);
inline int character_attack(int character_attack_level, int creatures_attack, int creature_number);

//Main
int main()
{
	//Creatures
	{
		{
			creature[0].name = "Frostbane Guard";
			creature[0].health = 100;
			creature[0].attack[0] = 15;
		}
		{
			creature[1].name = "Frostbite Yeti";
			creature[1].health = 300;
			creature[1].attack[0] = 50;
			creature[1].attack[1] = 57;
			creature[1].attack[2] = 35;
			creature[1].combo=150;
		}
		{
			creature[2].name = "Blizzard Golem";
			creature[2].health = 250;
			creature[2].attack[0] = 15;
			creature[2].attack[1] = 57;
			creature[2].attack[2] = 35;
			creature[2].combo = 135;
		}
		{
			creature[3].name = "Snow Shriken Ninja";
			creature[3].health = 350;
			creature[3].attack[0] = 15;
			creature[3].attack[1] = 57;
			creature[3].attack[2] = 35;
			creature[3].combo= 160;
		}
		{
			creature[4].name = "Glacius Frostend";
			creature[4].health = 500;
			creature[4].attack[0] = 15;
			creature[4].attack[1] = 57;
			creature[4].attack[2] = 35;
			creature[4].combo=300;
		}
		{
			creature[5].name = "King of Mythical Creatures";
			creature[5].health = 1000;
			creature[5].attack[0] = 15;
			creature[5].attack[1] = 57;
			creature[5].attack[2] = 35;
			creature[5].combo = 400;
		}
	}
	{
		string choice;
		do {
			//Main Page for start and quit
			cout << "Welcome to the mythical land of Eldoria" << endl
				<< "a) Start" << endl
				<< "b) Quit" << endl
				<< "What do you want to do (a/b)?" << endl;
			cin >> choice;

			if (choice == "a")
			{
				//Storyline
				cout << "On a calm winter day, Eldoria Kingdom got hit by a surprise snowstorm. Everything turned white as snow covered the kingdom. But then, weird creatures from the nearby jungle showed up and attacked Eldoria. They took the people hostage and took control of the kingdom." << endl;
				system("pause");
				cout << "There was a small village nestled beside Eldoria, There were three renowned warriors known for their exceptional fighting skills lived in that village. When they came to know that Eldoria is being attacked by some mythical creatures they decided to help the Eldoria kingdom and set them free from the hands of powerful magical mythical creatures" << endl;
				//Character Creation with its verification
				string choice_creation;
				do {
					//Character creation
					character_creation();
					//Character info
					display_character_info();
					cout << "Is the above information correct?(Y/N)";
					cin >> choice_creation;
					if (choice_creation != "N" && choice_creation != "n" && choice_creation != "Y" && choice_creation != "y")
						cout << "Choose th corrent option.";
						continue;
				} while (choice_creation == "N" || choice_creation == "n");

				//Contiune the story
				{
					string entrancechoice;
					cout << character.name << " inched closer to the kingdom, blending into the snowy bushes for cover. As he observed the kingdom," << character.name << "  spotted three potential paths to infiltrate.";
					//Quest
					do {
						cout << "a) The first option caught Jake's eye – the main gate.(Hard)" << endl
							<< "b) Turning his attention to the second path, Jake discovered a watchtower (Medium)" << endl
							<< "c) His gaze then shifted to the third option – a tower on the opposite side (Easy)" << endl
							<< "Choose your path: ";
						cin >> entrancechoice;
						entrancechoice=tolower(entrancechoice[0]);
						//Path 1
						if (entrancechoice == "a")
						{
							cout << "He came out of the bushes and moved slowly towards the main gate of the kingdom" << endl
								<<system("pause")
								<< creature[0].name << ": Who are you ? Go away otherwise you will have to face the circumstances!" << endl
								<< character.name << ": Lets face the circumstances." << endl;
							system("pause");
							//Battle with all 5 guards
							for (int i = 1; i <= 5; i++)
							{
								int characterattack = 0, creature_attack = 0;
								cout << "Guard " << i << endl;
								creature[0].health = 100;
								do{
										creature_attack = mythical_creature_attack(creature[0].attack[0], characterattack, 0);
										characterattack = character_attack(25, creature_attack,0);
										if (creature[0].health < 1 || character.health < 1)
										{
											break;
										}
								}while (creature[0].health  >0|| character.health >0);
								character.exp += 10;
								if (character.exp == 50)
									character.level++;
							}
							cout << "He moves on to the first gate of kingdom by hiding himself from the mythical creatures guarding the endure. Once the player reaches the kingdom’s first gate" << endl;
						}
						//Path 2
						else if (entrancechoice == "b")
						{
							cout << "He came out of the bushes and moved slowly towards the watchtower of the kingdom." << endl;
							system("pause");
							cout << "There were 3 guards guarding the watchtower. The players check his inventory, he gets a rope out of his inventory and climbs the watch tower. He gets on top of the watchtower and pulls out one guard. " << endl;
							for (int i = 1; i <= 2; i++)
							{
								int characterattack = 0, creature_attack = 0;
								cout << "Guard" << i << endl;
								creature[0].health = 100;
								do {
									creature_attack = mythical_creature_attack(creature[0].attack[0], characterattack, 0);
									characterattack = character_attack(25, creature_attack,0);
									if (creature[0].health < 1 || character.health < 1)
									{
										break;
									}
								} while (creature[0].health > 0 || character.health > 0);
								character.exp += 10;
								if (character.exp == 50)
									character.level++;
							}
							cout << "He goes through the wall top and while fighting the guard on top reaches the kingdom’s first gate. ";
						}
						else if (entrancechoice == "c")
						{
							cout << "He came out of the bushes and moved slowly towards the main gate of the kingdom.\nThere was 1 guard guarding the watchtower." << endl;
							system("pause");
							cout << "The player took the rope out of his inventory and climbed the watchtower. The guard watched him and started attacking";
							int characterattack = 0, creature_attack = 0;
							cout << "Guard" << 1 << endl;
							creature[0].health = 100;
							do {
								creature_attack = mythical_creature_attack(creature[0].attack[0], characterattack, 0);
								characterattack = character_attack(25, creature_attack,0);
								if (creature[0].health < 1 || character.health < 1)
								{
									break;
								}
							} while (creature[0].health > 0 || character.health > 0);
							character.exp += 10;
							if (character.exp == 50)
								character.level++;
						}
						else
							cout << "Choose correct option.";
					} while (entrancechoice != "a" && entrancechoice != "b" && entrancechoice != "c");
				}
			}
			else if (choice == "b")
				exit(1);
			else
				cout << "Choose the correct option";
		} while (choice != "a" && choice != "b");
	}
}

//Character Information
void display_character_info()
{
	cout << "Character Information" << endl
		<< "Character Name: " << character.name << endl
		<< "Character catagory: " << character.catagory << endl
		<< "Health: " << character.health << endl
		<< "Experience Points: " << character.exp << endl;
}

//Character creation
void character_creation()
{
	string name;
		string choice;
	bool flag=true;
	cout << "\nAccount Creation!" << endl;
	
	//Player Name
	cout << "Enter the player name: ";
	cin.ignore();
	getline(cin,character.name);
	
	//Player catagory
	do {
		cout << "Choose the player catagory " << endl
			<< "a) Warrior" << endl
			<< "b) Mage" << endl
			<< "c) Rogue" << endl
			<< "Choose: ";
		cin >> choice;
		if (choice == "a" || choice == "A")
			character.catagory = "Warrior";
		else if (choice == "b" || choice == "B")
			character.catagory = "Mage";
		else if (choice == "c" || choice ==  "C")
			character.catagory = "Rogue";
		else
		{
			cout << "Incorrect" << endl
				<< "Try Again!";
			flag = false;
		}
	} while (flag == false);
	character.exp = 0;
	character.level = 0;
}



//Battle System

//Creatures Attacks
int mythical_creature_attack(int creature_attack_level, int characterattack,int creature_number)
{
	
	cout << "\nHealth: " << character.health<<endl;
	int attack;
	srand(time(0));
		attack = rand() % creature_attack_level;
		cout <<creature[creature_number].name <<": " << attack << endl;
		return attack;
}


//ATTACK CHOICES FOR BOSSES
int attack_choice()
{
	int attack_number;
	srand(time(0));
	attack_number = rand() % 3;
	return attack_number;
}


//Character Attacking
inline int character_attack(int character_attack_level, int creatures_attack,int creature_number)
{
	char attack_choice;
	do {
		
		cout << "\nCreature Health" << creature[creature_number].health << endl;
		cout << "Attack Options: " << endl
			<< "a) Attack" << endl
			<< "b) Defend" << endl
			<< "c) Healing" << endl
			<< "Choice: ";


cin >> attack_choice;
		attack_choice = tolower(attack_choice);
		if (attack_choice == 'a')
		{
			character.health = character.health - creatures_attack;
			int attack;
			srand(time(0));
			attack = rand() % character_attack_level;
			cout <<"Attack: " << attack << endl;
			creature[creature_number].health = creature[creature_number].health - attack;
			return attack;
		}
		else if (attack_choice == 'b')
		{
			cout << "Defended: " << creatures_attack<<endl;
		}
		else if (attack_choice == 'c')
		{
			character.health = character.health + 40;
			character.health = character.health - creatures_attack;
		}
		else
		{
			cout << "Invalid input " << endl;
		}
	}while(attack_choice!='a' && attack_choice != 'b'&& attack_choice != 'c');
}