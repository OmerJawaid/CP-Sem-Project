#include<iostream>
#include<string>
#include<time.h>
using namespace std;

//structure for character creation
struct {
	string name, catagory;
	int health = 400, exp = 0, level = 1,attack=25;
}character;

struct {
	string name;
	int health, attack[2], combo;
}creature[5];

struct {
	string name;
	
}quest[16];

void display_character_info();
void character_creation();
inline int mythical_creature_attack(int attack_level, int characterattack, int characternumber);
inline int character_attack(int character_attack_level, int creatures_attack, int creature_number);

//Main
int main()
{
	string loop_choice;
	do {
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
				creature[1].combo = 150;
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
				creature[3].combo = 160;
			}
			{
				creature[4].name = "Glacius Frostend";
				creature[4].health = 500;
				creature[4].attack[0] = 15;
				creature[4].attack[1] = 57;
				creature[4].attack[2] = 35;
				creature[4].combo = 300;
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
						{
							cout << "Choose the correct option.";
							continue;
						}
					} while (choice_creation == "N" || choice_creation == "n");
					//CHAPTER 1: Paths to Eldoria
				{
					//Contiune the story
					{
						string entrancechoice;
						cout << character.name << " inched closer to the kingdom, blending into the snowy bushes for cover. As he observed the kingdom," << character.name << "  spotted three potential paths to infiltrate." << endl;
						//Quest 1
						do {
							cout << "\ta) The first option caught Jake's eye – the main gate.(Hard)" << endl
								<< "\tb) Turning his attention to the second path, Jake discovered a watchtower (Medium)" << endl
								<< "\tc) His gaze then shifted to the third option – a tower on the opposite side (Easy)" << endl
								<< "Choose your path: ";
							cin >> entrancechoice;
							entrancechoice = tolower(entrancechoice[0]);
							//Path 1
							if (entrancechoice == "a")
							{
								cout << "He came out of the bushes and moved slowly towards the main gate of the kingdom" << endl
									<< system("pause")
									<< creature[0].name << ": Who are you ? Go away otherwise you will have to face the circumstances!" << endl
									<< character.name << ": Lets face the circumstances." << endl;
								system("pause");
								//Battle with all 5 guards
								for (int i = 1; i <= 5; i++)
								{
									int characterattack = 0, creature_attack = 0;
									cout << "Guard " << i << endl;
									creature[0].health = 100;
									do {
										creature_attack = mythical_creature_attack(creature[0].attack[0], characterattack, 0);
										characterattack = character_attack(25, creature_attack, 0);
										if (character.health < 1)
										{
											cout << "Game Over";
											goto loop;
										}

									} while (creature[0].health > 0 && character.health > 0);//&&
									character.exp += 10;
									if (character.exp == 50)
									{
										character.level++;
										character.exp - 50;
									}
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
										characterattack = character_attack(25, creature_attack, 0);
										if (character.health < 1)
										{
											cout << "Game Over";
											goto loop;
										}
									} while (creature[0].health > 0 && character.health > 0);
									character.exp += 10;
									if (character.exp == 50)
									{
										character.level++;
										character.exp - 50;
									}
								}
								cout << "He goes through the wall top and while fighting the guard on top reaches the kingdom’s first gate. ";
							}
							//Path 3
							else if (entrancechoice == "c")
							{
								cout << "He came out of the bushes and moved slowly towards the main gate of the kingdom.\nThere was 1 guard guarding the watchtower." << endl;
								system("pause");
								cout << "The player took the rope out of his inventory and climbed the watchtower. The guard watched him and started attacking" << endl;
								int characterattack = 0, creature_attack = 0;
								cout << "Guard" << 1 << endl;
								creature[0].health = 100;
								do {
									creature_attack = mythical_creature_attack(creature[0].attack[0], characterattack, 0);
									characterattack = character_attack(25, creature_attack, 0);
									if (character.health < 1)
									{
										cout << "Game Over";
										goto loop;
									}
								} while (creature[0].health > 0 && character.health > 0);
								character.exp += 10;
								if (character.exp == 50)
									character.level++;
							}
							else
								cout << "Choose correct option.";
						} while (entrancechoice != "a" && entrancechoice != "b" && entrancechoice != "c");
					}
					//End of Quest 1


					//Quest 2:Continue the story
					{
						cout << character.name << "Moves to the kingdom second gate while stealth and saving himself from other gueard. \nHe opens the gate and suddenly he sees guards standing and now he had to take the fight." << endl
							<< creature[0].name << ": Who are you? How did you get in?" << endl
							<< "Another " << creature[0].name << ": He is an introdure kill him!" << endl;
						for (int i = 1; i <= 6; i++)
						{
							int characterattack = 0, creature_attack = 0;
							cout << "\nGuard " << i << endl;
							creature[0].health = 100;
							do {
								creature_attack = mythical_creature_attack(creature[0].attack[0], characterattack, 0);
								characterattack = character_attack(25, creature_attack, 0);
								if (character.health < 1)
								{
									cout << "Game Over";
									goto loop;
								}
							} while (creature[0].health > 0 && character.health > 0);
						}
						cout << character.name << " listens to a scary Noice coming from a corner ask him to come towards him. He steadily moves towards him but when he reaches" << endl
							<< "Informer: Saviour! Saviour!" << endl
							<< character.name << " understands that the guy wants some help, he stands by him and starts listening to him." << endl;
						system("pause");
						cout << "Informer: Saviour you are here the people in the prison were hoping you to come to save them you need to access the reach the business market in order to get this info." << endl
							<< character.name << " gets hesitant after listening the word Saviour. He honors the informer and gratitude and asks him to send his message to the villagers"

							<< character.name << ": Message(Your Saviour is here) " << endl
							<< character.name << ": I will make sure that you will get a reward for helping in this mission." << endl;
						cout << "\n HERE " << character.name << " WEARS SUIT OF GUARDS AND CHANGES HIS GETUP" << endl;
					}
					//Quest 2 Ends
				}
				//End of CHapter 1
					
					//CHAPTER 2: Infiltrate the Market
					{
						string chap2_st_choice;
						do {
							cout <<character.name<< " now had gathered the information required and fixed his path to the market he started moving towards the market but on the way, he encountered multiple ways to reach the market. " << endl
								<< "Bussiness Market Paths: " << endl
								<< "\ta) Guards guarding and have to fight.		(Hard)" << endl
								<< "\tb) Through hub of huts.					(Easy)" << endl;
							cin >> chap2_st_choice;
							if (chap2_st_choice == "a" || chap2_st_choice == "A")
							{
								cout << character.name << " moves towards the snowy street inclining him towards the market but unfortunately the 2 guards due to not following the code of instruction set by their management captures him to be intruder" << endl
									<< creature[0].name<<": Where is you badge"<<endl
									<<character.name<<" Does not replys"<<endl
									<<creature[0].name<<": Hello sir I am talking to you."<<endl;

								//Fight with the gurads
								for (int i = 1; i <= 2; i++)
								{
									int characterattack = 0, creature_attack = 0;
									cout << creature[0].name << i << endl;
									creature[0].health = 100;
									do {
										creature_attack = mythical_creature_attack(creature[0].attack[0], characterattack, 0);
										characterattack = character_attack(25, creature_attack, 0);
										if (character.health < 1)
										{
											cout << "Game Over";
											goto loop;
										}
									} while (creature[0].health > 0 && character.health > 0);
									character.exp += 10;
									if (character.exp == 50)
									{
										character.level++;
										character.exp - 50;
									}
								}
								cout << character.name << " successfully defends their attacks and destroys them but just when they got finished asked them about the pathway of the market." << endl;
								//Quest 3: Go to the business market for the information and get out 
								{
									cout << "The player goes to the business market while the guards watch him going in. In the business market the player gets a map of the Eldoria kingdom where the villagers were captured. \nWhen the player was coming out of the business market he was surrounded by the guards. "<<endl;
									cout << creature[0].name << ": You are surrounded! Put your weapons down.";
								}
								//End of quest 3
								//Quest 4: Embark Quest: Go to the villagers
								{
									string quest4_path_choice;
									do {
										cout << "HERE " << character.name << " GETS 2 PATHS: " << endl
											<< "\ta) Fight all 10 Guards and run" << endl
											<< "\tb) Throws his weapon and gets arrested." << endl
											<< "\t Enter your CHOICE: ";
											cin >> quest4_path_choice;
										if (quest4_path_choice == "a" || quest4_path_choice == "A")
										{
											cout << character.name << " push the guards in front and start to run but suddenly 3 Frostbane guards came across"<<endl
												<<creature[0].name<<": Hey you come here! Bloody Intruder!"<<endl
												<<endl<<character.name<<"Started to fight"<<endl;
											//Fight with the guards and arrest remaining
											for (int i = 1; i <= 13; i++)
											{
												int characterattack = 0, creature_attack = 0;
												cout << creature[0].name << i << endl;
												creature[0].health = 100;
												if (character.health < 50 / 100 * 400)
												{
													cout << character.name << " GOT ARRESTED!" << endl
														<<"He gets cuffed and one of the Frostbane Guards hit his gun on his head and he gets unconscious.";
													goto Gail;//goto arrest in path 2
												}
												do {
													creature_attack = mythical_creature_attack(creature[0].attack[0], characterattack, 0);
													characterattack = character_attack(25, creature_attack, 0);
													if (character.health < 1)
													{
														cout << "Game Over";
														goto loop;
													}
												} while (creature[0].health > 0 && character.health > 0);
												character.exp += 10;
												if (character.exp == 50)
												{
													character.level++;
													character.exp - 50;
												}
											}
											cout << character.name << " escapes and starts to move towards the villagers but in the middle of the pathway.";
										}
										else if (quest4_path_choice == "b" || quest4_path_choice=="B")
										{
											cout << "The player throws his weapons and surrenders." << endl
												<< creature[0].name << ": Get down to your knees and backoff." << endl
												<< creature[0].name << " took him to Eldora's prison" << endl
												<< "When he get on his knees one of the guards hit is gun on " << character.name << " head and he gets unconscious." << endl;
											//Beating in prison
											Gail:
											cout << "When " << character.name << " gets into his sences. The " << creature[0].name << "s where beating him and asking: " << endl
												<< creature[0].name << ": Who are you?" << endl
												<< creature[0].name << ": Who send you?" << endl
												<< character.name << " again gets unconscious." << endl;
											//In gail informer
											cout << "When he came into his sences. He looked around, he was in ball and chain." << endl
												<< "HE Waited..." << endl
												<< "After sometime informer came and frees him from the gail, ball and chain." << endl
												<< "Informer: We have to Hurry up" << endl
												<< character.name << ": You are here we go again." << endl
												<< "Informer: Frostbite Yeti is looking for you. Come on hurry up." << endl
												<< character.name << "Who is this Frostbite Yeti?" << endl
												<< "The informer did not reply, and they both started running." << endl;
											//Quest 5: Follow the informer
											{

											}
										}
										else
											cout << "Wrong path. TRY AGAIN";
									} while (quest4_path_choice != "A" || quest4_path_choice != "a" || quest4_path_choice != "B" || quest4_path_choice != "b");
								}

							}
							else if (chap2_st_choice == "b" || chap2_st_choice == "B")
							{

							}
							else
								cout << "Incorrect Path! TRY AGAIN";
						} while (chap2_st_choice != "a"&& chap2_st_choice != "b"&& chap2_st_choice != "A" && chap2_st_choice != "B");
					}
					//End of Chapter 2
				}
				else if (choice == "b")
					exit(1);
				else
					cout << "Choose the correct option" << endl;
			} while (choice != "a" && choice != "b");
		}
		loop:
		do {
			cout << "Do you want to play again?(Y/N): ";
			cin >> loop_choice;
			if (loop_choice != "y" || loop_choice != "Y" || loop_choice != "N" || loop_choice != "n")
				cout << "Choose correct option.";
		} while (loop_choice != "y" || loop_choice != "Y" || loop_choice != "N" || loop_choice != "n");
	}while (loop_choice=="y"|| loop_choice == "Y");
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
		{
			character.catagory = "Warrior";
			flag = true;
		}
		else if (choice == "b" || choice == "B")
		{
			character.catagory = "Mage";
			flag = true;
		}
		else if (choice == "c" || choice == "C")
		{
			character.catagory = "Rogue";
			flag = true;
		}
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
	string attack_choice;//string
	do {
		
		cout << "\nCreature Health" << creature[creature_number].health << endl;
		cout << "Attack Options: " << endl
			<< "a) Attack" << endl
			<< "b) Defend" << endl
			<< "c) Healing" << endl
			<< "Choice: ";
		cin >> attack_choice;
		if (attack_choice == "a" || attack_choice == "A")
		{
			character.health = character.health - creatures_attack;
			int attack;
			srand(time(0));
			attack = rand() % character_attack_level;
			cout <<"Attack: " << attack << endl;
			creature[creature_number].health = creature[creature_number].health - attack;
			return attack;
		}
		else if (attack_choice == "b" || attack_choice == "B")
		{
			cout << "Defended: " << creatures_attack<<endl;
		}
		else if (attack_choice == "c" || attack_choice == "C")
		{
			character.health = character.health + 40;
			character.health = character.health - creatures_attack;
			if (character.health > 400)
				character.health = 400;
		}
		else
		{
			cout << "Invalid input " << endl;
		}
	} while (attack_choice != "a" && attack_choice != "b" && attack_choice != "c");
}