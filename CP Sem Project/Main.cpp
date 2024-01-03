#include<iostream>
#include<time.h>
#include<string>

//Styling
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define RESET_COLOR "\033[0m"

using namespace std;

struct {
	string name[5];
}chapter;

struct {
	string name;
	int health, combo, attack[5];
}king;

struct {
	string name, category;
	int health, exp, level, attack,score;
}character;

struct {
	string name;
	int health, attack[3], combo;
}creature[5];

struct {
	string name;
}quest_without_fight[9];

struct {
	string name;
	string difficulty[3];
	int attack_level[3];
}quest_battle[5];

struct {
	string armour_name[3];
	string sword_name[3];
}Inventory_under_Vanguard;

struct {
	string name="";
	int number=0;
}inventory_storage[10];

void display_character_info();
void character_creation();
inline int mythical_creature_attack(int attack_level, int characternumber);
inline int character_attack(int character_attack_level, int creatures_attack, int creature_number, int& creature_health, int& total_character_attack);
bool battle_system(int creaturenumber, int guard_number, int difficulty);
int choice_quest_difficulty(int creature_number);
void creature_initialization();
void quest_initialization_without_fight();
void quest_battle_initialization();
inline int king_battle();
inline int character_attack_King(int character_attack_level, int creatures_attack, int& total_character_attack);
void scoring(int totalattack);
void leveling_up();
void gameover();
void inventory_king();
void inventory_display();

//Main
int main()
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
					quest_battle_initialization();
					creature_initialization();
					quest_initialization_without_fight();
					
					//Chapters
					{
						chapter.name[0] = "Chapter 1: Paths to Eldoria";
						chapter.name[1] = "Chapter 2: Infiltrate the Market ";
						chapter.name[2] = "Chapter 3: The Bosses - Yeti's Challenge - Blizzard Golem - Snow Shuriken Ninja ";
						chapter.name[3] = "Chapter 4: Vanguard's Stand ";
						chapter.name[4] = "Chapter 5: The last Act";
					}
					
					//Storyline
					cout << "On a calm winter day, Eldoria Kingdom got hit by a surprise snowstorm. Everything turned white as snow covered the kingdom. But then, weird creatures from the nearby jungle showed up and attacked Eldoria. They took the people hostage and took control of the kingdom." << endl;
					system("pause");
					cout << "There was a small village nestled beside Eldoria, There were three renowned warriors known for their exceptional fighting skills lived in that village. When they came to know that Eldoria is being attacked by some mythical creatures they decided to help the Eldoria kingdom and set them free from the hands of powerful magical mythical creatures" << endl;
					
					//Character Creation with its verification
					string choice_creation;
					do {
						//Character creation
						character_creation();
						
						//Character info
						display_character_info();
						do {
							cout << "Is the above information correct?(Y/N)";
							cin >> choice_creation;
							if (choice_creation != "N" && choice_creation != "n" && choice_creation != "Y" && choice_creation != "y")
							{
								cout << "Choose the correct option.";
								continue;
							}
						} while (choice_creation != "N" && choice_creation != "n" && choice_creation != "Y" && choice_creation != "y");
					} while (choice_creation == "n" || choice_creation == "N");
					
					//CHAPTER 1
					cout << RED_TEXT << chapter.name[0]<< RESET_COLOR <<endl;
					{
						{
							string entrancechoice;
							cout << character.name << " inched closer to the kingdom, blending into the snowy bushes for cover. As he observed the kingdom," << character.name << "  spotted three potential paths to infiltrate." << endl;
							
							//Quest1
							cout <<endl<<GREEN_TEXT<< quest_without_fight[0].name<< RESET_COLOR<<endl;
							do {
								cout << "\ta) The first option caught " << character.name << " eye - The Main Gate. " << quest_battle[0].difficulty[2] << endl
									<< "\tb) Turning his attention to the second path, " << character.name << " discovered a watchtower. " << quest_battle[0].difficulty[1] << endl
									<< "\tc) He gaze then shifted to the third option a tower on the opposite side. "<< quest_battle[0].difficulty[0] << endl
									<< "Choose your path: ";
								cin >> entrancechoice;
								//Path 1
								if(entrancechoice=="a"|| entrancechoice == "A")
								{
									cout << "Path 1 : Selected" << endl;
									cout << "He came out of the bushes and moved slowly towards the main gate of the kingdom" << endl;
										system("pause");
									cout<< creature[0].name << ": Who are you ? Go away otherwise you will have to face the circumstances!" << endl
										<< character.name << ": Lets face the circumstances." << endl;
									system("pause");
									//Battle with all 5 guards
									int difficulty;
									difficulty = choice_quest_difficulty(0);
									for (int i = 1; i <= 5; i++)
									{
										bool flag = false;
										flag = battle_system(0, i, difficulty);
										if (flag == true)
										{
											gameover();
										}
										inventory_storage[0].name = "Starlight Elixir";
										inventory_storage[0].number += 10;
										inventory_display();
									}
									cout << "He moves on to the first gate of kingdom by hiding himself from the mythical creatures guarding the endure. Once the player reaches the kingdom�s first gate" << endl;
									break;
								}
								/*Path 2:*/
								else if(entrancechoice=="b"|| entrancechoice == "B")
								{
									cout << "Path 2 : Selected" << endl;
									cout << "He came out of the bushes and moved slowly towards the watchtower of the kingdom." << endl;
									system("pause");
									cout << "There were 3 guards guarding the watchtower. The players check his inventory, he gets a rope out of his inventory and climbs the watch tower. He gets on top of the watchtower and pulls out one guard. " << endl;
									int difficulty;
									difficulty = choice_quest_difficulty(0);
									for (int i = 1; i <= 2; i++)
									{
										bool flag = false;
										flag = battle_system(0, i,difficulty);
										if (flag == true)
										{
											gameover();
										}
										inventory_storage[0].name = "Starlight Elixir";
										inventory_storage[0].number += 10;
										inventory_display();
									}
									cout << "He goes through the wall top and while fighting the guard on top reaches the kingdom�s first gate. ";
								}
								/*Path 3:*/
								else if(entrancechoice == "C"|| entrancechoice == "c")
								{
									cout << "Path 3 : Selected" << endl;
									cout << "He came out of the bushes and moved slowly towards the main gate of the kingdom.\nThere was 1 guard guarding the watchtower." << endl;
									system("pause");
									cout << "The player took the rope out of his inventory and climbed the watchtower. The guard watched him and started attacking" << endl;
									int difficulty;
									difficulty = choice_quest_difficulty(0);
									bool flag = false;
									flag = battle_system(0, 1,difficulty);
									if (flag == true)
									{
										gameover();
									}
									inventory_storage[0].name = "Starlight Elixir";
									inventory_storage[0].number += 10;
									inventory_display();
								}
								else
								{
									cout << "Choose correct option.";
								}
						} while (entrancechoice != "a" && entrancechoice != "b" && entrancechoice != "c");
							
							cout <<GREEN_TEXT<< "Quest 1 End" <<RESET_COLOR<< endl;
						}
						//End of Quest 1


						//Quest 2:Continue the story
						cout <<endl<<GREEN_TEXT<< quest_without_fight[1].name <<RESET_COLOR<< endl;
						{
							cout << character.name << " moves to the kingdom second gate while stealth and saving himself from other guard. \nHe opens the gate and suddenly he sees guards standing and now he had to take the fight." << endl
								<< creature[0].name << ": Who are you? How did you get in?" << endl
								<< "Another " << creature[0].name << ": He is an intruder kill him!" << endl;
							
							//Fight 6 guards
							int difficulty;
							difficulty = choice_quest_difficulty(0);
							for (int i = 1; i <= 6; i++)
							{
								bool flag = false;
								flag = battle_system(0, i,difficulty);
								if (flag == true)
								{
									gameover();
								}
								inventory_storage[0].name = "Starlight Elixir";
								inventory_storage[0].number += 10;
								inventory_display();
							}
							//End Fight

							cout << character.name << " listens to a scary Noice coming from a corner ask him to come towards him. He steadily moves towards him but when he reaches" << endl
								<< "Informer: Saviour! Saviour!" << endl
								<< character.name << " understands that the guy wants some help, he stands by him and starts listening to him." << endl;
							system("pause");
							cout << "Informer: Saviour you are here the people in the prison were hoping you to come to save them you need to access the reach the business market in order to get this info." << endl
								<< character.name << " gets hesitant after listening the word Saviour. He honors the informer and gratitude and asks him to send his message to the villagers"

								<< character.name << ": Message(Your Saviour is here) " << endl
								<< character.name << ": I will make sure that you will get a reward for helping in this mission." << endl;
							cout << "\n HERE " << character.name << " WEARS SUIT OF GUARDS AND CHANGES HIS GETUP" << endl;
							
							cout <<GREEN_TEXT<< "Quest 2 End" <<RESET_COLOR<< endl;
						}
						
						//Quest 2 Ends
					}
					cout <<RED_TEXT<< "End of Chapter 1" << RESET_COLOR << endl;
					system("pause");
					system("cls");
					//End of CHapter 1

					//CHAPTER 2: Infiltrate the Market
					cout << RED_TEXT<<chapter.name[1] << RESET_COLOR<<endl;
					char chap2_st_choice;
					do {
						cout <<endl<< character.name << " now had gathered the information required and fixed his path to the market he started moving towards the market but on the way, he encountered multiple ways to reach the market. " << endl
							<< "Business Market Paths: " << endl
							<< "\ta) Guards guarding and have to fight.		(Hard)" << endl
							<< "\tb) Through hub of huts.				(Easy)" << endl;
						cin >> chap2_st_choice;

						switch (chap2_st_choice)
						{
							//Path 1
						case'A':
						case'a':
						{
							cout << character.name << " moves towards the snowy street inclining him towards the market but unfortunately the 2 guards due to not following the code of instruction set by their management captures him to be intruder" << endl
								<< creature[0].name << ": Where is you badge" << endl
								<< character.name << " Does not replies" << endl
								<< creature[0].name << ": Hello sir I am talking to you." << endl;

							//Fight with the gurads
							int difficulty;
							difficulty = choice_quest_difficulty(0);
							for (int i = 1; i <= 2; i++)
							{
								bool flag = false;
								flag = battle_system(0, i, difficulty);
								if (flag == true)
								{
									gameover();
								}
								inventory_storage[0].name = "Starlight Elixir";
								inventory_storage[0].number += 10;
								inventory_display();
							}
							cout << character.name << " successfully defends their attacks and destroys them but just when they got finished asked them about the pathway of the market." << endl;

							//Quest 3: Go to the business market for the information and get out
							cout << GREEN_TEXT << quest_without_fight[2].name << RESET_COLOR << endl;
							{
								cout << "The player goes to the business market while the guards watch him going in. In the business market the player gets a map of the Eldoria kingdom where the villagers were captured. \nWhen the player was coming out of the business market he was surrounded by the guards. " << endl;
								cout << creature[0].name << ": You are surrounded! Put your weapons down."<<endl;
							}
							cout << GREEN_TEXT << "Quest 3 End" << RESET_COLOR << endl;
							//End of quest 3

							//Quest 4: Embark Quest: Go to the villagers
							cout << GREEN_TEXT << quest_without_fight[3].name << RESET_COLOR << endl;
							{
								string quest4_path_choice;
								do {
									cout << "HERE " << character.name << " GETS 2 PATHS: " << endl
										<< "\ta) Fight all 13 Guards and run" << endl
										<< "\tb) Throws his weapon and gets arrested." << endl
										<< "\t Enter your CHOICE: ";
									cin >> quest4_path_choice;
									//Path 1
									if (quest4_path_choice == "a" || quest4_path_choice == "A")
									{
										cout << character.name << " push the guards in front and start to run but suddenly 3 Frostbane guards came across" << endl
											<< creature[0].name << ": Hey you come here! Bloody Intruder!" << endl
											<< endl << character.name << "Started to fight" << endl;
										//Fight with the guards and arrest remaining
										for (int i = 1; i <= 13; i++)
										{

											int characterattack = 0, creature_attack = 0, health = creature[0].health, total_character_attack = 0;
											cout << creature[0].name << i << endl;
											if (character.health < 50 / 100 * 400)
											{
												cout << character.name << " GOT ARRESTED!" << endl
													<< "He gets cuffed and one of the Frostbane Guards hit his gun on his head and he gets unconscious.";
												goto Jail;//goto arrest in path 2 line 361
											}
											do {
												creature_attack = mythical_creature_attack(creature[0].attack[0], 0);
												characterattack = character_attack(character.attack, creature_attack, 0, health, total_character_attack);
												if (character.health < 1)
												{
													cout << "Game Over";
													gameover();
												}
											} while (health > 0 && character.health > 0);

											scoring(total_character_attack);
											leveling_up();
											inventory_storage[0].name = "Starlight Elixir";
											inventory_storage[0].number += 10;
											inventory_display();
										}
										cout << character.name << " escapes and starts to move towards the villagers but in the middle of the pathway." << endl;
										cout << UNDERLINE << "HERE FROSTBITE YETI COMES AND TAKES THE PLAYER TO HIS MOUNTAIN USING THE ZIPLINE FROM ELDORIA TO HIS MOUNTAIN." << CLOSEUNDERLINE << endl;
										cout << creature[1].name << ": Oh Hello! You are the savior." << endl
											<< character.name << "Oh yes! I am" << endl;
									}
									//Path 1 Ends

									//Path 2
									else if (quest4_path_choice == "b" || quest4_path_choice == "B")
									{
										cout << "The player throws his weapons and surrenders." << endl
											<< creature[0].name << ": Get down to your knees and backoff." << endl
											<< creature[0].name << " took him to Eldoria's prison" << endl
											<< "When he get on his knees one of the guards hit is gun on " << character.name << " head and he gets unconscious." << endl;
										//Beating in prison
									Jail:
										cout << "When " << character.name << " gets into his senses. The " << creature[0].name << "s where beating him and asking: " << endl
											<< creature[0].name << ": Who are you?" << endl
											<< creature[0].name << ": Who send you?" << endl
											<< character.name << " again gets unconscious." << endl;
										//In jail informer
										cout << "When he came into his senses. He looked around, he was in ball and chain." << endl
											<< "HE Waited..." << endl
											<< "After sometime informer came and frees him from the jail, ball and chain." << endl
											<< "Informer: We have to Hurry up" << endl
											<< character.name << ": You are here we go again." << endl
											<< "Informer: Frostbite Yeti is looking for you. Come on hurry up." << endl
											<< character.name << "Who is this Frostbite Yeti?" << endl
											<< "The informer did not reply, and they both started running." << endl;

										//Quest 5: Follow the informer
										cout << GREEN_TEXT << quest_without_fight[4].name << RESET_COLOR << endl;
										cout << "They both go through the underground tunnels." << endl
											<< character.name << ": Where the hell are we?" << endl
											<< "Through the tunnels they both came out in open.But Frostbite Yeti saw both of them from the mountain top." << endl;
										cout << UNDERLINE << "HERE FROSTBITE YETI COMES AND TAKES THE PLAYER TO HIS MOUNTAIN USING THE ZIPLINE FROM ELDORIA TO HIS MOUNTAIN." << CLOSEUNDERLINE << endl;
										cout << creature[1].name << ": Oh Hello! You are the savior." << endl
											<< character.name << "Oh yes! I am" << endl;
										//Quest 5 End
										cout << GREEN_TEXT << "Quest 5 End" << RESET_COLOR << endl;

									}
									//Path 2 Ends 
									else
										cout << "Wrong path. TRY AGAIN";
								} while (quest4_path_choice != "A" && quest4_path_choice != "a" && quest4_path_choice != "B" && quest4_path_choice != "b");
								cout << RED_TEXT << " Chapter 2 ends " << RESET_COLOR << endl;
								system("cls");




								//Chapter 3:  The Bosses - Yeti's Challenge - Blizzard Golem - Snow Shuriken Ninja
								cout << RED_TEXT << chapter.name[2] << RESET_COLOR << endl;
								system("pause");

								//Quest 6: Kill Frostbite Yeti
								cout << GREEN_TEXT << quest_battle[0].name << RESET_COLOR << endl;
								{
									cout << "Here Frostbite Yeti comes into anger and attacks the player, the player dodges the attack, and the fight begins." << endl;
									//Frostbite yeti Fight
									int difficulty;
									difficulty = choice_quest_difficulty(0);
									bool flag = false;
									flag = battle_system(1, 0, difficulty);
									if (flag == true)
									{
										gameover();
									}

									//Fight Ends
									cout << creature[1].name << " fells and " << character.name << " puts his sword on his neck and asks: " << endl
										<< character.name << ": What is happening here? Who are you and what are you doing here?" << endl
										<< creature[1].name << ": You don't know anything what is happening here. He will kill you." << endl
										<< character.name << " wipes his neck off";
									//Inventory drops
									inventory_storage[1].name = "Stormcaller Staff ";
									inventory_storage[1].number = 1;
									inventory_storage[2].name = "Nightshade Potion (Invisibility Potion)";
									inventory_storage[2].number = 3;
									inventory_storage[3].name = "Phoenix Feather Talisman (Talisman)";
									inventory_storage[3].number = 1;
									inventory_display();
								}
								cout << GREEN_TEXT << "Quest 6 End" << RESET_COLOR << endl;
								//Quest 6 Ends

								cout << character.name << " starts to walk for the zipline but in fog the player ends up going toward the Bilzzard Golem (The Second Boss of Mythical creatures). " << endl
									<< character.name << " asks the same : " << "What is happening here? Who are you and what are you doing here?";

								//Quest 7: Embark Quest: Kill Bilzzard Golem
								cout << GREEN_TEXT << quest_battle[1].name << RESET_COLOR << endl;
								{
									cout << creature[2].name << " did not reply and came to attack the player but this time the player got hit badly." << endl;
									//Player health drops to 50% as he got hit by Bilzzard Golem 
									character.health = character.health * 0.5;
									cout << creature[3].name << ": This was the man whom everyone feared (with a scary laugh to the saviour)." << endl
										<< character.name << " gets angry, stood up and ran for the fight.";
									//Billzard Fight
									int difficulty;
									difficulty = choice_quest_difficulty(0);
									bool flag = false;
									flag = battle_system(2, 0, difficulty);
									if (flag == true)
									{
										gameover();
									}
									inventory_storage[4].name = "Frostbane Blade";
									inventory_storage[4].number = 1;
									inventory_storage[5].name = "Whispering Dagger";
									inventory_storage[5].number = 1;
									inventory_storage[0].name = "Starlight Elixir";
									inventory_storage[0].number += 40;
									inventory_display();
									//Billzard Fight Ends and drops inventory
								}
								//Quest 7 Ends
								cout << GREEN_TEXT << "Quest 7 End" << RESET_COLOR << endl;

								cout << "The player then again goes for the zipline but this time he got path. He takes that path and comes back to the Eldoria Kingdom." << endl
									<< "Again starts the search of villagers and he reaches them" << endl;
							}
							cout << GREEN_TEXT << "Quest 4 End" << RESET_COLOR << endl;
							//Quest 4 ends

							cout << character.name << ": Oh! you are here." << endl
								<< "Villager: Thankgod you are here to help us." << endl
								<< character.name << ": You are not all, where are the remaining people ?" << endl
								<< "Villager: We have no idea where they would be." << endl
								<< character.name << ": All of you guys just stay here I will come and set you free." << endl;
							system("pause");
							cout << "Meanwhile the informer came, and he talked what to do next and how to set them free." << endl
								<< "Informer: Come follow me!" << endl
								<< character.name << ": So now where are we heading towards?" << endl
								<< "Informer: To your king. " << endl
								<< character.name << ": Let's go." << endl;
							system("pause");
							cout << "The informer and " << character.name << " headed towards the palace meanwhile the Mythical creature " << creature[3].name << " watched them on the top of mountain. " << creature[3].name << " Jumped from the mountain and attacked both. The informed got a huge injury and " << character.name << " also got hit" << endl;
							character.health = character.health - character.health * 0.25;
							//Quest 8: Kill Snow Shuriken Ninja
							cout << GREEN_TEXT << quest_battle[2].name << RESET_COLOR << endl;
							{
								//Fight with SNOW Shuriken Ninja
								int difficulty;
								difficulty = choice_quest_difficulty(0);
								bool flag = false;
								flag = battle_system(3, 0, difficulty);
								if (flag == true)
								{
									gameover();
								}
								inventory_storage[6].name = "Enchanted Grappling Hook (Upgraded)";
								inventory_storage[6].number = 1;
								inventory_storage[7].name = "Moonstone Key (Enhanced)";
								inventory_storage[7].number = 1;
								inventory_storage[8].name = "Rune-infused Gauntlets (Upgraded)";
								inventory_storage[8].number = 1;
								inventory_display();
								//Fight ends
								cout << character.name << " killed " << creature[3].name << "But the informer was hit and due to his hit, he was getting poisoned and was killed gradually." << endl
									<< "Before he gets kill, he tells the player how to get to the palace. " << endl;
							}
							cout << GREEN_TEXT << "Quest 8 End" << RESET_COLOR << endl;

							//Quest 8 ends

							//Chapter 3 ends
							cout << RED_TEXT << "Chapter 3 End" << RESET_COLOR << endl;
							system("cls");
							break;
						}
						//End of path 1

						//Path 2
						case 'B':
						case'b':
						{
							cout << character.name << " follow the bushes and sneakily try to enter the hub of houses" << endl
								<< character.name << " entered the house... " << endl
								<< "He searches the house"//Player gets some inventory
								<< "He finds a map to reach crew of villagers" << endl;
							cout << RED_TEXT "Chapter 2 End" << RESET_COLOR << endl;
							system("cls");
							//Chapter 2 Ends

							//Chapter 3: The Bosses - Yeti's Challenge - Blizzard Golem - Snow Shuriken Ninja
							cout << RED_TEXT << chapter.name[2] << RESET_COLOR << endl;
							{
								cout << character.name << " followed the map but in the middle of the map he was following he got attacked by first mythical creature's boss Snow Shuriken Ninja. " << endl << endl
									<< "He took " << character.name << " to his cave on the mountain top. When Snow Shuriken Ninja attack he got unconscious." << endl;
								//Quest 9: Get out of the Cave.
								cout << GREEN_TEXT << quest_without_fight[4].name << RESET_COLOR << endl;
								{
									cout << "When he came back in senses, he was covered in blood and Snow Shuriken Ninja was not there and was tied up with chains. After a while the informer sneakily comes in." << endl
										<< "Informer: I knew this would happen." << endl
										<< character.name << ": Who was this?" << endl
										<< "Informer: He is the right hand of the king of Mythical Creatures. But I am shocked he did not kill you. " << endl
										<< character.name << ": I want to know about your King." << endl
										<< "Informer: Not a right time. Let's go, we have to leave. " << endl
										<< "The informer set him free. " << endl
										<< "Informer: Follow me." << endl;
									system("pause");
									cout << character.name << " and the informer were going out of the cave of the Snow Shuriken Ninja but at the cave�s mouth, he got to know about both of them and he roared. The informer went out of the cave, but the player was stuck in the cave as the mouth got closed by the rocks fallen from the roar." << endl;
								}
								cout << GREEN_TEXT << "Quest 9 End" << RESET_COLOR << endl;
								//Quest 9 Ends

								//Quest 10: Kill the Snow Shuriken Ninja
								cout << GREEN_TEXT << quest_battle[2].name << RESET_COLOR << endl;
								{
									cout << creature[3].name << ": Oh poor saviour. You are going to hell." << endl
										<< character.name << ": Well I guess you should visit it first." << endl
										<< "Snow Shuriken Ninja get in anger and starts!" << endl;
									//Fight with Snow Shuriken Ninja
									{
										int difficulty;
										difficulty = choice_quest_difficulty(0);
										bool flag = false;
										flag = battle_system(3, 0, difficulty);
										if (flag == true)
										{
											gameover();
										}
										inventory_storage[6].name = "Enchanted Grappling Hook (Upgraded)";
										inventory_storage[6].number = 1;
										inventory_storage[7].name = "Moonstone Key (Enhanced)";
										inventory_storage[7].number = 1;
										inventory_storage[8].name = "Rune-infused Gauntlets (Upgraded)";
										inventory_storage[8].number = 1;
										inventory_display();
									}
									//Fight ends
									//Inventory Drop
									cout << "After the Snow Shuriken Ninja is killed, the informer manages to open the caves mouth and both of them get out." << endl;
								}
								cout << GREEN_TEXT "Quest 10 End" << RESET_COLOR << endl;
								//Quest 10 Ends

								//Quest 11: Go to the zipline with Quest 12 Yeti killing
								cout << GREEN_TEXT << quest_without_fight[5].name << RESET_COLOR << endl;
								{
									cout << "Informer: Hurry up! Let's go." << endl
										<< character.name << ": Is this the right hand of your King you were talking about?" << endl
										<< "Informer: Yes! Indeed he was.\tLet's go! Hurry up." << endl;
									system("pause");
									cout << "They both went further to the other mountain to catch the zipline but on the way they encounter the Second Boss Mythical Creature FROSTBITE YETI" << endl;
									system("pause");
									cout << character.name << ": Now who the hell is he?" << endl
										<< "Informer: He is yeti.He got a strong eye on you and now it is." << endl
										<< character.name << ": What do you mean by strong eye." << endl;
									cout << character.name << " slides and saves him from the attack of Frostbite Yeti. The informer got hit and fell down." << endl
										<< creature[1].name << ": So, you are the Saviour." << endl
										<< character.name << ": Yes, I am the savior." << endl
										<< creature[1].name << ": Let's see what you have. " << endl
										<< "In order to save himself and to take the revenge, he have to take a fight.";
									//Quest 12: Kill The Frostbite Yeti  
									cout << GREEN_TEXT << quest_battle[0].name << RESET_COLOR << endl;
									{
										int difficulty;
										difficulty = choice_quest_difficulty(0);
										bool flag = false;
										flag = battle_system(1, 0, difficulty);
										if (flag == true)
										{
											gameover();
										}
										cout << character.name << " killed Frostbite Yeti but he was confused why everyone is calling him a saviour." << endl;
										inventory_storage[1].name = "Stormcaller Staff ";
										inventory_storage[1].number = 1;
										inventory_storage[2].name = "Nightshade Potion (Invisibility Potion)";
										inventory_storage[2].number = 3;
										inventory_storage[3].name = "Phoenix Feather Talisman (Talisman)";
										inventory_storage[3].number = 1;
										inventory_display();
									}
									cout << GREEN_TEXT << "Quest 12 End" << RESET_COLOR << endl;
									//Quest 12 Ends
									cout << "He saw the informer was hardly hit. He took him on his back and started running towards the zipline. He took the zipline and came down with the informer at his back." << endl;
								}
								cout << GREEN_TEXT << "Quest 11 End" << RESET_COLOR << endl;
								//Quest 11 Ends

								cout << "He came down back to the kingdom and started moving towards the villagers. He met the villagers, but they were not all of them." << endl
									<< character.name << ": Oh! you are here." << endl
									<< "Villager: Thankgod you are here to help us." << endl
									<< character.name << ": You are not all, where are the remaining people ?" << endl
									<< "Villager: We have no idea where they would be." << endl
									<< character.name << ": All of you guys just stay here I will come and set you free." << endl;
								system("pause");
								cout << character.name << " then moves towards the king with the informer but in the way to the palace " << character.name << " meets a another Boss Mythical Creature Blizzard Golem. He without giving any gesture start attacking. " << character.name << "Got hit and loses his health." << endl;
								//Character health decreses due to attack by 50%
								character.health = character.health * 0.5;

								//Quest 13: Kills the Blizzard Golem 
								cout << GREEN_TEXT << quest_battle[1].name << RESET_COLOR << endl;
								{
									//Fight with the Billzard Golem
									{
										int characterattack = 0, creature_attack = 0, informer_output = 0, health = creature[2].health, difficulty, total_character_attack = 0;
										cout << creature[2].name << endl;
										difficulty = choice_quest_difficulty(1);
										do {
											informer_output++;
											creature_attack = mythical_creature_attack(creature[2].attack[difficulty], 2);
											characterattack = character_attack(character.attack, creature_attack, 2, health, total_character_attack);
											if (informer_output == 5)
											{
												cout << "The Informer tried to help him but due to a massive hit by creature lose his life." << endl
													<< "and now " << character.name << " fights with more dedication" << endl;
											}
											if (character.health < 1)
											{
												cout << "Game Over";
												gameover();
											}
										} while (health > 0 && character.health > 0);

										scoring(total_character_attack);
										leveling_up();
										inventory_storage[4].name = "Frostbane Blade";
										inventory_storage[4].number = 1;
										inventory_storage[5].name = "Whispering Dagger";
										inventory_storage[5].number = 1;
										inventory_storage[0].name = "Starlight Elixir";
										inventory_storage[0].number += 40;
										inventory_display();
										//Billzard Fight Ends and drops inventory
									}
									//Fight ends
									cout << "Now " << character.name << " started moving towards the palace to save his king." << endl;
								}
								cout << GREEN_TEXT << "Quest 13 End" << RESET_COLOR << endl;
								//Quest 13 Ends
							}
							//End of Chapter 3

							cout << RED_TEXT << "Chapter 3 End" << RESET_COLOR << endl;
							system("cls");
						}
						//Path 2 ends

						default:
							cout << "Incorrect Path! TRY AGAIN";
						}
					} while (chap2_st_choice != 'a' && chap2_st_choice != 'b' && chap2_st_choice != 'A' && chap2_st_choice != 'B');

						//Chapter 4:  Vanguard's Stand 
						cout << RED_TEXT << chapter.name[3] << RESET_COLOR << endl;
						{
							cout << character.name << " reaches to the palace. As he enters the inner sanctum of the palace, a chilling presence announces the arrival of " << creature[4].name << " (Frozen Vanguard)" << endl
								<< "A formidable creature with mastery over frost and ice. Glacius Frostend is the chief commander of the Frostbane guards and a key enforcer for the mythical creatures." << endl;

							//Quest 14: Vangurad's plan
							cout << GREEN_TEXT << quest_without_fight[6].name << RESET_COLOR << endl;
							{
								cout << "As " << character.name << " enters the battle. Vanguard deceives him with the aim of weakening him shows his father tide into rope covered with bloods and doing heavy breathes." << endl;
								cout << character.name << ": Father!!" << endl
									<< character.name << " takes a step forward." << endl
									<< creature[4].name << " Oh no you don't" << endl
									<< creature[4].name << " hits his father." << endl
									<< character.name << " gets angry and started to run towards him and " << character.name << " fell in a hole." << endl
									<< creature[4].name << " successful pass in his plan" << character.name << endl;
								system("pause");
								cout << character.name << " stood up and went more deeper where the key people of the kingdom were kept." << endl;
							}
							//Quest 14 Ends
							cout << GREEN_TEXT << "Quest 14 End" << RESET_COLOR << endl;

							cout << character.name << "  finally met his king, and he saw the player with the glimpse of hope and King smiled." << endl
								<< "The kIng: My child you are here." << endl
								<< character.name << ": I have no time for this. He is coming after me I need resources." << endl
								<< "King: Who?" << endl
								<< character.name << ": A Vanguard" << endl
								<< "king: You mean Glacius Frostend?" << endl
								<< character.name << ": Indeed he is. Now where can I find resources to fight him?" << endl
								<< "King: Beneath the kingdom there is a room which has the inventory to defeat the king and his frozen vanguard you need to access that for killing I made it when I saw them coming from escape world, but things gotten out my hand." << endl;

							//Quest 15: Suit Yourself Up Inventory Remaining
							cout << GREEN_TEXT << quest_without_fight[7].name << RESET_COLOR << endl;
							{
								cout << character.name << " starts running to the inventory room�and jumps into it for accessing the room under the kingdom, " << creature[4].name << " follows him but he pulled the lever and blocked the access which gives extra time to access and get the killing weapons to kill the king and the vanguard." << endl
									<< character.name << " saw a glimpse of inventory packed in an old architecture shinning to the sky. He sees and his eyes glimpses up with a satisfaction felt by wounds and now he opens the inventory it attracts him as it was meant for him" << endl;
								system("pause");
								//Here player have to choose his inventory and have craft healings etc
								//Inventory
								inventory_king();
								cout << character.name << " feet got up the surface and he came in the fullest potential." << endl;
							}
							cout << GREEN_TEXT << "Quest 15 End" << RESET_COLOR << endl;
							//Quest 15 Ends

							cout << "Suddenly the Vanguard enters the room by smashing the door and " << character.name << " defend the door coming to him in the air. Vanguard went to his main move to crush him, but " << character.name << " defends with ease shocking the vanguard and showing his intense move and putting maximum disadvantage to the Vanguard." << endl;
							creature[4].health = creature[4].health - 100;

							//Quest 16: Kill the Vanguard
							cout << GREEN_TEXT << quest_battle[3].name << RESET_COLOR << endl;
							{
								cout << "And fight starts" << endl;
								//Vanguard Fight Starts
								{
									int difficulty;
									difficulty = choice_quest_difficulty(0);
									bool flag = false;
									flag = battle_system(4, 0, difficulty);
									if (flag == true)
									{
										gameover();
									}
									inventory_storage[9].name = "Frostwind Amulet (Empowered)";
									inventory_storage[9].number = 1;
									inventory_storage[1].name = "Stormcaller Staff (Empowered)";
									inventory_storage[1].number += 1;
									inventory_storage[10].name = "Frostbite Arrows (Empowered)";
									inventory_storage[10].number += 30;
									inventory_display();
								}
								//Vanguard Fight ends
								//Inventory Drops
							}
							cout << GREEN_TEXT << "Quest 16 End" << RESET_COLOR << endl;
							//Quest 16 Ends

							cout << "The defeat of Vanguard felt by the king through magic alerting him that his biggest opponent is here and gears up for the battle." << endl
								<< character.name << " now feels the sense of maintaining the truth in the kingdom saving the people of the kingdom." << endl
								<< character.name << " goes through the hole to meet the real king of kingdom, but he was not in the place they met before. Then he ran out from the hole to save his father, but both the King and his father were captured by the king of mythical creature." << endl
								<< "But The king dropped a note for the him. Which tells him to reach the king without fighting the major chunk of Forestbane Guard." << endl;
						}
						cout << RED_TEXT << "Chapter 4 End" << RESET_COLOR << endl;
						//Chapter 4 Ends
						system("cls");

						//Chapter 5: The last Act
						cout << RED_TEXT << chapter.name[4] << RESET_COLOR << endl;
						{
							{
								king.name = "King of mythical creature";
								king.health = 1000;
								king.attack[0] = 140;
								king.attack[1] = 180;
								king.attack[2] = 200;
								king.attack[3] = 195;
								king.attack[4] = 210;
								king.combo = 400;
							}

							cout << character.name << " runs�towards the place." << endl
								<< character.name << " sneakily enters the place. Enter the room of throne and followed the path by climbing up which took him to the room of king and successfully found the door where king was." << endl;
							system("pause");

							//Quest 17: The final battle with king, giants forestbane and mythical king story
							cout << GREEN_TEXT << quest_without_fight[8].name << RESET_COLOR << endl;
							{
								//3 attack system Remaining
								int difficulty;
								difficulty = choice_quest_difficulty(0);
								for (int i = 1; i <= 8; i++)
								{
									bool flag = false;
									flag = battle_system(0, i, difficulty);
									if (flag == true)
									{
										gameover();
									}
								}
								system("pause");
								cout << "\n------------------------------------------------------------" << endl
									<< "\nThe King\n" << endl
									<< "------------------------------------------------------------" << endl;
								cout << character.name << "meets the king of mythical creatures. After battling hard with all the creatures of his land. Facing the King was a relief for him, with the hope of getting the kingdom and pride in the village and life of people." << endl
									<< character.name << " senses defeating the king of mythical creatures. The king flies in the air pushes him and comes to the ground of the kingdom." << endl
									<< character.name << "'s father was on the ground of the kingdom. His hands were tied up, the king of the mythical creature came, put the sword on his neck and told: " << endl;

								cout << "\n\nBackstory of King" << endl;
								cout << "Long ago the King had 2 children and the King gave the kingdom to the elder one. The younger prince got jealous and killed his father and ran to the village he took help from the player's father. He enchanted the younger brother, now the mythical creature king, granting him power but sealing his fate. He helped him to form an army but once the player�s father got to know his mind he ran away. \nYou were born with natural magical resistance, inherits the title of the savior. The elder brother, driven by newfound darkness, unwittingly fulfills the prophecy by imprisoning the rightful king. Now, you must unravel the enchantments, break the curse, and confront their own kin to restore Eldoria's rightful ruler and save the kingdom from the grips of dark magic.\n" << endl
									<< character.name << "'s Father tells his side of the story about how he can defeat the king of a mythical creature and due to this the king kills the " << character.name << "father" << endl
									<< character.name << " become shocked to see such reality and his father dying in front of his eyes he begins to fight with king with the aim to save the kingdom and take revenge of his father." << endl;

								//King fight
								cout << king.name << endl;
								int characterattack = 0, creature_attack = 0, total_character_attack = 0;
								do {
									creature_attack = king_battle();
									characterattack = character_attack_King(character.attack, creature_attack, total_character_attack);
									if (character.health < 1)
									{
										cout << "Game Over";
										gameover();
									}
								} while (creature[0].health > 0 && character.health > 0);

								scoring(total_character_attack);
								leveling_up();
								//Fight Ends
								cout << character.name << " conquered the battle with his fullest aims and won the battle and bow the king of mythical creature on the foot� and finally ended the oppressed and lustful era of the� mythical king� the player sense the pride of the victory taking revenge of his father and saving the kingdom and raising the pride of village where he belongs to and where his father too.The player finally met with the king and handed his power to him, and the king thanked and gave him some huge rewards as a sign of thankfulness" << endl;
							}
							cout << GREEN_TEXT << "Quest 17 End" << RESET_COLOR << endl;
							//Quest 17 Ends

						}
						cout << RED_TEXT << "Chapter 5 End" << RESET_COLOR << endl;
						system("cls");
						//Chapter 5 Ends
				}
				else if (choice == "b")
					exit(1);
				else
					cout << "Choose the correct option" << endl;
			} while (choice != "a" && choice != "b");
			gameover();
}

//Character Information
void display_character_info()
{
	cout << "\nCharacter Information" << endl
		<< "Character Name: " << character.name << endl
		<< "Character category: " << character.category << endl
		<< "Health: " << character.health << endl
		<< "Experience Points: " << character.exp << endl
		<<"Level: "<<character.level<<endl
		<<"Attack: "<<character.attack<<endl
		<<"Score: "<<character.score<<endl;
}

//Character creation
void character_creation()
{
	string name,choice;
	int character_category_number;
	bool flag = true;
	cout << "\nAccount Creation!" << endl;
	//Player Name
	cout << "Enter the player name: ";
	cin.ignore();
	getline(cin, character.name);

	//Player category
	do {
		cout << "Choose the player category " << endl
			<< "a) Warrior" << endl
			<< "b) Mage" << endl
			<< "c) Rogue" << endl
			<< "Choose: ";
		cin >> choice;
		if (choice == "a" || choice == "A")
		{
			character.category = "Warrior";
			flag = true;
			character_category_number = 0;
			character.health = 600;
			character.attack = 50;
		}
		else if (choice == "b" || choice == "B")
		{
			character.category = "Mage";
			flag = true;
			character_category_number = 1;
			character.health = 450;
			character.attack = 30;
		}
		else if (choice == "c" || choice == "C")
		{
			character.category = "Rogue";
			flag = true;
			character_category_number = 2;
			character.health = 500;
			character.attack = 60;
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
int mythical_creature_attack(int creature_attack_level, int creature_number)
{
	cout <<character.name<<" " << "\nHealth: " << character.health << endl;
	int attack;
	srand(time(0));
	attack = rand() % creature_attack_level;
	cout << creature[creature_number].name<< " Attack : " << attack << endl;
	return attack;
}
//Character Attacking
inline int character_attack(int character_attack_level, int creatures_attack, int creature_number,int &creature_health, int &total_character_attack)
{
	string attack_choice;//string
	do {

		cout << "\nCreature Health: " << creature_health << endl;
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
			cout <<character.name<< "'s Attack: " << attack << endl;
			creature_health = creature_health - attack;
			total_character_attack += attack;
			return attack;
		}
		else if (attack_choice == "b" || attack_choice == "B")
		{
			cout << "Defended: " << creatures_attack << endl;
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
	} while (attack_choice != "a" && attack_choice != "A" && attack_choice != "b" && attack_choice != "B" && attack_choice != "c" && attack_choice != "C");
}
//Main battle function

bool battle_system(int creaturenumber,int guard_number, int difficulty)
{	
		int health = creature[creaturenumber].health;
		int characterattack = 0, creature_attack = 0,total_character_attack=0;
		bool flag = false;
		
		cout << "-------------------------------------------------------------------" << endl;
		cout <<endl<< creature[creaturenumber].name << " "<< guard_number<< endl;
		do {
			creature_attack = mythical_creature_attack(creature[creaturenumber].attack[difficulty], creaturenumber);
			characterattack = character_attack(character.attack, creature_attack, creaturenumber,health, total_character_attack);
			if (character.health < 1)
			{
				cout << "Game Over";
				flag = true;
				return flag;
			}
			else {
				flag = false;
			}
		} while (health > 0 && character.health > 0);
		scoring(total_character_attack);
		if(character.exp >=200)
		{
		leveling_up();
		}
		return flag;
}

int choice_quest_difficulty(int creature_number)
{
	string choice;
	string difficulty_level;
	do {
		cout << "How hard would you like to fight: " << endl
			<< "\ta) " << quest_battle[creature_number].difficulty[0] << endl
			<< "\tb) " << quest_battle[creature_number].difficulty[1]<< endl
			<< "\tc) " << quest_battle[creature_number].difficulty[2] << endl
			<< "Enter your choice: " << endl;
		cin >> choice;
		if (choice != "a" && choice != "A" && choice != "b"&& choice != "B" && choice != "c" && choice != "C")
				cout << "You Entered Wrong Input. Try Again!"<<endl;
	} while (choice != "a" && choice != "A" && choice != "b" && choice != "B" && choice != "c" && choice != "C");
	
	if(choice=="a"|| choice == "A")
	{
			cout << "Easy Selected"<<endl;
			return 0;
		}
	else if (choice == "b" || choice == "B")
		{
			cout << "Medium Selected" << endl;
			return 1;
		}
	else if (choice == "C" || choice == "c")
		{
			cout << "Hard Selected" << endl;
			return 2;
		}
	else
			cout << "Try Again!";
}
void quest_battle_initialization()
{
	{
		quest_battle[0].name = "Kill Frostbite Yeti";
		quest_battle[0].difficulty[0] = "Easy";
		quest_battle[0].difficulty[1] = "Medium";
		quest_battle[0].difficulty[2] = "Hard";
	}
	{
		quest_battle[1].name = "Kill Bilzzard Golem";
		quest_battle[1].difficulty[0] = "Easy";
		quest_battle[1].difficulty[1] = "Medium";
		quest_battle[1].difficulty[2] = "Hard";
	}
	{
		quest_battle[2].name = "Kill Snow Shuriken Ninja";
		quest_battle[2].difficulty[0] = "Easy";
		quest_battle[2].difficulty[1] = "Medium";
		quest_battle[2].difficulty[2] = "Hard";
	}
	{
		quest_battle[3].name = "Kill the Vanguard";
		quest_battle[3].difficulty[0] = "Easy";
		quest_battle[3].difficulty[1] = "Medium";
		quest_battle[3].difficulty[2] = "Hard";
	}
	{
		quest_battle[4].name = "Kill The King";
		quest_battle[4].difficulty[0] = "Easy";
		quest_battle[4].difficulty[1] = "Medium";
		quest_battle[4].difficulty[2] = "Hard";
	}
}
void quest_initialization_without_fight()
{
	quest_without_fight[0].name = "Find a way to Enter the Kingdom";
	quest_without_fight[1].name = "Go meet the Informer.";
	quest_without_fight[2].name = "Go to the business market for the information and get out ";
	quest_without_fight[3].name = "Go to the villagers ";
	quest_without_fight[4].name = "Follow the informer";
	quest_without_fight[5].name = "Get out of the Cave.";
	quest_without_fight[6].name = "Go to the zipline ";
	quest_without_fight[7].name = "Leveling up";
	quest_without_fight[8].name = "-The final battle with king, giants forestbane and mythical king story ";
}

void creature_initialization()
{
	{
		creature[0].name = "Frostbane Guard";
		creature[0].health = 100;
		creature[0].attack[0] = 15;
		creature[0].attack[1] = 20;
		creature[0].attack[2] = 25;
	}
	{
		creature[1].name = "Frostbite Yeti";
		creature[1].health = 300;
		creature[1].attack[0] = 30;
		creature[1].attack[1] = 50;
		creature[1].attack[2] = 75;
	}
	{
		creature[2].name = "Blizzard Golem";
		creature[2].health = 250;
		creature[2].attack[0] = 30;
		creature[2].attack[1] = 40;
		creature[2].attack[2] = 65;
	}
	{
		creature[3].name = "Snow Shuriken Ninja";
		creature[3].health = 350;
		creature[3].attack[0] = 45;
		creature[3].attack[1] = 60;
		creature[3].attack[2] = 85;
	}
	{
		creature[4].name = "Glacius Frostend";
		creature[4].health = 500;
		creature[4].attack[0] = 80;
		creature[4].attack[1] = 90;
		creature[4].attack[2] = 100;
	}
}

inline int king_battle()
{
	cout << "Character Health: " << character.health;
	int attack_choice;
	srand(time(0));
	attack_choice = rand() % 4;
	cout << attack_choice << endl;

	if (attack_choice == 0)
	{
		int attack_power;
		srand(time(0));
		attack_power = rand() % king.attack[0];
		cout << "The X-SNOW ATTACK: " << attack_power << endl;
		return attack_power;
	}
	else if (attack_choice == 1)
	{
		int attack_power;
		srand(time(0));
		attack_power = rand() % king.attack[1];
		cout << "The physiological attack: " << attack_power << endl;
		return attack_power;
	}
	else if (attack_choice == 2)
	{
		int attack_power;
		srand(time(0));
		attack_power = rand() % king.attack[2];
		cout << "Getting player dizzy effect to forward punch: " << attack_power << endl;
		return attack_power;
	}
	else if (attack_choice == 3)
	{
		int attack_power;
		srand(time(0));
		attack_power = rand() % king.attack[3];
		cout << "The lock attack: " << attack_power << endl;
		return attack_power;
	}
	else
	{
		int attack_power;
		srand(time(0));
		attack_power = rand() % king.attack[4];
		cout << "The combo effect: " << attack_power << endl;
		return attack_power;
	}
}
inline int character_attack_King(int character_attack_level, int creatures_attack,int& total_character_attack)
{
	string attack_choice;//string
	do {

		cout << "\nCreature Health: " << king.health << endl;
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
			cout << "Attack: " << attack << endl;
			king.health = king.health - attack;
			total_character_attack += attack;
			return attack;
		}
		else if (attack_choice == "b" || attack_choice == "B")
		{
			cout << "Defended: " << creatures_attack << endl;
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

void scoring(int totalattack)
{
	character.score = rand() % totalattack;
	cout << "Score: " << character.score;
	character.exp = totalattack - character.score;
}
void leveling_up()
{

		string choice;
		do
		{
			cout << "Your experience points reaches 200. Do you want to level up(y/n) : ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				character.level++;
				character.health += 100;
				character.attack += 5;
				character.exp = character.exp - 200;
				break;
			}
			else if(choice=="n"||choice=="N")
				break;
			else
				cout << "Invalid input Try Again!" << endl;
		} while (choice != "y" && choice != "Y" && choice != "N" && choice != "n");
}

void gameover()
{
	string loop_choice;
	do {
		cout << "Do you want to play again?(Y/N): ";
		cin >> loop_choice;
		if (loop_choice == "y" || loop_choice == "Y")
			main();
		else if (loop_choice == "n" || loop_choice == "N")
			exit(1);
		if (loop_choice != "y" && loop_choice != "Y" && loop_choice != "N" && loop_choice != "n")
			cout << "Choose correct option.";
	} while (loop_choice != "y" && loop_choice != "Y" && loop_choice != "N" && loop_choice != "n");
}

void inventory_king()
{
	string armour_selection;
	Inventory_under_Vanguard.armour_name[0] = "Icicle Vanguard Gear    (1100)";
	Inventory_under_Vanguard.armour_name[1] = "Winter's Embrace Armor  (800)";
	Inventory_under_Vanguard.armour_name[2] = "Crystal Frostplate Set  (1000)";
	do {
		cout << "Select your Armour." << endl
			<< "\ta) " << Inventory_under_Vanguard.armour_name[0] << endl
			<< "\tb) " << Inventory_under_Vanguard.armour_name[1] << endl
			<< "\tc) " << Inventory_under_Vanguard.armour_name[2] << endl
			<< "Select the Armour Set: ";
		cin >> armour_selection;
		if (armour_selection == "a"|| armour_selection == "A")
		{
			cout << Inventory_under_Vanguard.armour_name[0] << "\tSelected!";
			character.health = 1100;
		}
		else if (armour_selection == "b"||armour_selection == "B")
		{
			cout << Inventory_under_Vanguard.armour_name[1] << "\tSelected!";
			character.health = 800;
		}
		else if (armour_selection == "c"|| armour_selection == "C")
		{
			cout << Inventory_under_Vanguard.armour_name[2] << "\tSelected!";
			character.health = 1000;
		}
		else
			cout << "Wrong Selection Try Again!" << endl;
	} while (armour_selection != "a" && armour_selection != "A" && armour_selection != "b" && armour_selection != "B" && armour_selection != "c" && armour_selection != "C");

	Inventory_under_Vanguard.sword_name[0] = "Abyssal Frostblade (100)";
	Inventory_under_Vanguard.sword_name[1] = "Chillwind Scimitar (150)";
	Inventory_under_Vanguard.sword_name[2] = "Frozen Phoenix Slicer (110)";

	string sword_selection;
	do {
		cout << "Select your Sword." << endl
			<< "\ta) " << Inventory_under_Vanguard.sword_name[0] << endl
			<< "\tb) " << Inventory_under_Vanguard.sword_name[1] << endl
			<< "\tc) " << Inventory_under_Vanguard.sword_name[2] << endl
			<< "Select the Sword Set: ";
		cin >> sword_selection;
		if (sword_selection == "a" || sword_selection == "A")
		{
			cout << Inventory_under_Vanguard.sword_name[0] << "\tSelected!";
			character.attack = 100;
		}
		else if (sword_selection == "b" || sword_selection == "B")
		{
			cout << Inventory_under_Vanguard.sword_name[1] << "\tSelected!";
			character.attack =150 ;
		}
		else if (sword_selection == "c" || sword_selection == "C")
		{
			cout << Inventory_under_Vanguard.sword_name[2] << "\tSelected!";
			character.attack = 110;
		}
		else
			cout << "Wrong Selection Try Again!" << endl;
	} while (sword_selection != "a" && sword_selection != "A" && sword_selection != "b" && sword_selection != "B" && sword_selection != "c" && sword_selection != "C");
}

void inventory_display()
{
	cout << "Inventory: " << endl;
	for (int i = 0; i < 10; i++)
		cout<<i+1 <<" " << inventory_storage[i].name<< inventory_storage[i].number<<endl;
}