#include<iostream>	
#include<ctime>
#include<windows.h>
#include<fstream>
#include<sstream>	


using namespace std;


enum savestat { Auto, No_save, No_auth, Save_available };

class Stats {
public:
	int health = 5;
	int fullh = 5;
	int strength = 4;
	int sp;
	int spfull;
	int defense = 2;
	int xp;
	int lvl = 1;
	int levelup;
	int leveluprequirement;
	int oldrequirement;
	string name;

	void uplevel() {
		fullh += 3;
		strength += 3;
		defense += 1;
		spfull += 3;
		health = fullh;
		sp = spfull;
		lvl++;
		levelup++;
	}



};




savestat save = No_save;
Stats hero;
unsigned int integritychkskip = true;
bool gotostate = false;
bool nuke = false;
bool flee = true;
bool firstbattle = true;
bool storestat = false;
bool troll = true;
bool sound = true;
bool repeat = false;
bool statraise = false;
bool auth = false;
bool savepending = false;
string cheatcommand;
string item1read;
string item2read;
string item3read;
string item4read;
string item5read;
string cheatinvincibility = "off";
string twoturnsinrow = "off";
string monsterdoesnothing = "off";
string item5;
string item4;
string item3;
string item2;
string item1;
string action;
string errreport;
string actionmenu1 = "1)attack\n2)defend\n3)flee\n4)nothing\n5)view your current stats";
string actionmenu2 = "1)attack\n2)defend\n3)flee\n4)magic\n5)view your current stats";
string actionmenu3 = "1)attack\n2)defend\n3)flee\n4)magic\n5)view your current stats\n6)Items";
string actionmenu4 = "1)attack\n2)defend\n3)flee\n4)nothing\n5)view you current stats\n6)items";
string specialattackmenu1 = "1)back to basic moves menu\n2)nothing\n3)heal (2 hero.sp)\n";
string specialattackmenu2 = "1)back to basic moves menu\n2)nothing\n3)heal (2 hero.sp)\n4)fireball (4 hero.sp)\n";
string menuitems1;
string menuitems2;
string menuitems3;
string menuitems4;
string menuitems5;
string monstername;
unsigned int oldrequirement;
unsigned int leveluprequirement;
unsigned int weapon;
int errtype;
int monsterhealth;
int turncheat;
int damage;
int monsterfullh;
int monsterheal;
int monsterstrength;
int monsterdef;
int enemydamage;
unsigned int money;
unsigned int levelup;
int battle;
int cocoapuffs;
int rewardcoins;
unsigned int item1has;
unsigned int item2has;
unsigned int item3has;
unsigned int item4has;
unsigned int item5has;
unsigned int item1type;
unsigned int item2type;
unsigned int item3type;
unsigned int item4type;
unsigned int item5type;
unsigned int item1a;
unsigned int item2a;
unsigned int item3a;
unsigned int item4a;
unsigned int item5a;
unsigned int state;
int itemmenu;
int com;
int wrongpass;


















void faq() {
	system("cls");
	cout << "Scroll down to view all of the FAQs. Press any key to go back to the main menu.\n" << endl;
	cout << "To clear up some of the confusion, here are some frequently asked questions:" << endl;
	cout << endl;
	cout << "Q: Is there a version of this game with graphics?" << endl;
	cout << endl;
	cout << "No, unfortunately there isn't a version of COMPUTERDOOM with graphics. At least, not yet.\n\n" << endl;
	cout << "Q: Will there be a version of COMPUTERDOOM with graphics?" << endl;
	cout << endl;
	cout << "YES! As a result of popular request, and insults (I'm talking to you David Roman \"This game sucks\"), COMPUTERDOOM will have graphics!\n\n" << endl;
	cout << "Q: OMG I'M SO EXCITED, when will this new version of COMPUTERDOOM come out?" << endl;
	cout << endl;
	cout << "For now, the timeframe is unkown. Hopefully when I'm done all of my exams, I can poke around my new engine and start working on it.\n\n" << endl;
	cout << "Q: What will the new version of COMPUTERDOOM be like?" << endl;
	cout << endl;
	cout << "If all goes according to plan (joke's on you, I have no plan), the game should feature a GUI (graphical user interface), music, and (hopefully) a better save procedure.\n\n" << endl;
	cout << "Q: What are the system requirements for the new COMPUTERDOOM?" << endl;
	cout << endl;
	cout << "All you will need is a computer with a decent speed. You may or may not need to copy some DLL files in the same location as the game. I'm actively searching for a way around this.\nUPDATE: I have found a way to statically link the SFML library to the executable file, and now you will be able to run the file\n" << endl;
	cout << "Q: Will we be able to view your progress/latest compiled version as usual?" << endl;
	cout << endl;
	cout << "No. You will need to wait for me to make a latest stable version or tell me to send you the game.\n\n" << endl;
	cout << "Q: Why won't there be a version 1.0?" << endl;
	cout << endl;
	cout << "The addition of graphics is so big, I just had to bump up the major version number! It wouldn't make sense to have COMPUTERDOOM v1.0 beta 6 and add something as big as graphics." << endl;
	cout << endl;
	system("pause");





}










void endgame() {
	state = 0;
	integritychkskip = 1;
}


void coinreward(int chance) {
	rewardcoins = (rand() % chance + 1);
	money += rewardcoins;
	cout << rewardcoins << " coin(s)" << endl;

}














void refundhandler(int price) {
	int refund;
	int rewardchance;
	refund = (rand() % 100 + 1);
	rewardchance = (rand() % 200 + 1);
	switch (refund) {
	case 100 || 99:
		MessageBox(NULL, "Nice! You get a full refund!", "Lucky!", MB_ICONASTERISK);
		static_cast<int>(money += price);
		break;
	case 75:
	case 74:
	case 73:
		MessageBox(NULL, "Nice! You get a 75% refund!", "Lucky!", MB_ICONASTERISK);
		money += static_cast<int>(price*0.75);
		break;
	case 50:
	case 49:
	case 48:
	case 47:
		MessageBox(NULL, "Nice! You get a 50% refund!", "Lucky!", MB_ICONASTERISK);
		money += static_cast<int>(price*0.5);
		break;
	case 25:
	case 24:
	case 23:
	case 22:
	case 21:
		MessageBox(NULL, "Nice! You get a 25% refund!", "Lucky!", MB_ICONASTERISK);
		money += static_cast<int>(price*0.25);
		break;
	}
	switch (rewardchance) {
	case 50 || 49 || 48 || 47 || 46:
		MessageBox(NULL, "For being our number 1 customer, here is a reward of 50 COINS!!!!!!!!", "WINNER!!!", MB_ICONASTERISK);
		money += 50;
		break;
	case 100:
	case 99:
	case 98:
	case 97:
		MessageBox(NULL, "For being our number 1 customer, here is a reward of 100 COINS!!!!!!!!", "WINNER!!!", MB_ICONASTERISK);
		money += 100;
		break;
	case 150:
	case 149:
	case 148:
		MessageBox(NULL, "For being our number 1 customer, here is a reward of 150 COINS!!!!!!!!", "WINNER!!!", MB_ICONASTERISK);
		money += 150;
		break;
	case 200:
	case 199:
		MessageBox(NULL, "For being our number 1 customer, here is a reward of 200 COINS!!!!!!!!", "WINNER!!!", MB_ICONASTERISK);
		money += 200;
		break;
	}


}



void err() {
	stringstream error;
	if (errtype == 0) {

		if (hero.lvl > 3) {
			error << "hero.lvl is more than 3, ";
		}
		if (hero.fullh > 15) {
			error << "hero.fullh is more than 15, ";
		}
		if (hero.strength > 14) {
			error << "hero.strength is more than 14, ";
		}
		if (hero.defense > 6) {
			error << "hero.defense is more than 6, ";
		}
		if (hero.spfull > 11) {
			error << "hero.spfull is more than 11, ";
		}
		if (state > 3) {
			error << "state is more than 3, ";
		}
		if (money > 500) {
			error << "money is more than 500, ";
		}
		if (weapon > 1) {
			error << "weapon is more than 1, ";
		}
		if (hero.defense <= 0) {
			error << "hero.defense is less or equal to 0, ";
		}

		if (item1has > 1 || item2has > 1 || item3has > 1 || item4has > 1 || item5has > 1 || item1type > 2 || item2type > 2 || item3type > 2 || item4type > 2 || item5type > 2) {
			error << "The items are configured incorrectly on the save file.";
		}
		else if ((item1 == "Healing Potion" && item1type != 1) || (item1 == "Cocoa Puffs" && item1type != 2) || (item2 == "Healing Potion" && item2type != 1) || (item2 == "Cocoa Puffs" && item2type != 2)) {
			error << "The items are configured incorrectly on the save file.";
		}
		else if ((item1a > 0 && item1has == 0) || (item2a > 0 && item2has == 0) || (item1has == 1 && item1a == 0) || (item2has == 1 && item2a == 0)) {
			error << "The items are configured incorrectly on the save file.";
		}

	}
	errreport = error.str();
}






void item1type1() {
	system("cls");
	if (item1a > 0) {
		cout << hero.name << " is using a Healing Potion" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		hero.health = hero.fullh;
		cout << "\n" << hero.name << " now has " << hero.health << endl << endl;
		item1a = item1a - 1;
	}
	else if (item1a == 0) {
		MessageBox(NULL, "You don't have any more healing potions!", "You Cannot Use This Item!", MB_ICONWARNING | MB_OK);

		repeat = true;
	}
}


void item2type1() {
	system("cls");
	if (item2a > 0) {
		cout << hero.name << " is using a Healing Potion" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		hero.health = hero.fullh;
		cout << "\n" << hero.name << " now has " << hero.health << endl << endl;
		item2a = item2a - 1;
	}
	else if (item2a == 0) {
		MessageBox(NULL, "You don't have any more healing potions!", "You Cannot Use This Item!", MB_ICONWARNING | MB_OK);

		repeat = true;
	}
}

void item3type1() {
	system("cls");
	if (item3a > 0) {
		cout << hero.name << " is using a Healing Potion" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		hero.health = hero.fullh;
		cout << "\n" << hero.name << " now has " << hero.health << endl << endl;
		item3a = item3a - 1;
	}
	if (item3a == 0) {
		MessageBox(NULL, "You don't have any more healing potions!", "You Cannot Use This Item!", MB_ICONWARNING | MB_OK);

		repeat = true;
	}
}


void item4type1() {
	system("cls");
	if (item4a > 0) {
		cout << hero.name << " is using a Healing Potion" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		hero.health = hero.fullh;
		cout << "\n" << hero.name << " now has " << hero.health << endl << endl;
		item4a = item4a - 1;
	}
	else if (item4a == 0) {
		MessageBox(NULL, "You don't have any more healing potions!", "You Cannot Use This Item!", MB_ICONWARNING | MB_OK);

		repeat = true;
	}
}

void item5type1() {
	system("cls");
	if (item5a > 0) {
		cout << hero.name << " is using a Healing Potion" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		hero.health = hero.fullh;
		cout << "\n" << hero.name << " now has " << hero.health << endl << endl;
		item5a = item5a - 1;

	}
	else if (item5a == 0) {
		MessageBox(NULL, "You don't have any more healing potions!", "You Cannot Use This Item!", MB_ICONWARNING | MB_OK);

		repeat = true;
	}
}



void item1type2() {
	system("cls");
	if (item1a > 0) {
		cout << hero.name << " is coocoo for cocoa puffs!" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		cocoapuffs = cocoapuffs + 3;
		item1a = item1a - 1;
	}
	else if (item1a == 0) {
		MessageBox(NULL, "You don't have any more cocoa puffs!", "You Cannot Use This Item!", MB_ICONWARNING | MB_OK);


		repeat = true;
	}
}

void item2type2() {
	system("cls");
	if (item2a > 0) {
		cout << hero.name << " is coocoo for cocoa puffs!" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		cocoapuffs = cocoapuffs + 3;
		item2a = item2a - 1;
	}
	else if (item2a == 0) {
		MessageBox(NULL, "You don't have any more cocoa puffs!", "You Cannot Use This Item!", MB_ICONWARNING | MB_OK);

		repeat = true;
	}
}

void item3type2() {
	system("cls");
	if (item3a > 0) {
		cout << hero.name << " is coocoo for cocoa puffs!" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		cocoapuffs = cocoapuffs + 3;
		item3a = item3a - 1;
	}
	else if (item3a == 0) {
		MessageBox(NULL, "You don't have any more cocoa puffs!", "You Cannot Use This Item!", MB_ICONWARNING | MB_OK);

		repeat = true;
	}
}

void item4type2() {
	system("cls");
	if (item4a > 0) {
		cout << hero.name << " is coocoo for cocoa puffs!" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		cocoapuffs = cocoapuffs + 3;
		item4a = item4a - 1;
	}
	else if (item4a == 0) {
		MessageBox(NULL, "You don't have any more cocoa puffs!", "You Cannot Use This Item!", MB_ICONWARNING | MB_OK);

		repeat = true;
	}
}

void item5type2() {
	system("cls");
	if (item5a > 0) {
		cout << hero.name << " is coocoo for cocoa puffs!" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		cocoapuffs = cocoapuffs + 3;
		item5a = item5a - 1;
	}
	else if (item5a == 0) {
		MessageBox(NULL, "You don't have any more cocoa puffs!", "You Cannot Use This Item!", MB_ICONWARNING | MB_OK);

		repeat = true;
	}
}

void item1type3() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code.This function merely acts as a placeholder.Everything that happens from this point on may be extra glitchy.The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n" << endl;
	if (sound == true) {

		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item1 == "Healing Potion") {
		item1type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item1 == "Cocoa Puffs") {
		item1type = 2;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);

	}
	repeat = true;
}
void item2type3() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item2 == "Healing Potion") {
		item2type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item2 == "Cocoa Puffs") {
		item2type = 2;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);

	}

	repeat = true;
}

void item3type3() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item3 == "Healing Potion") {
		item3type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item3 == "Cocoa Puffs") {
		item3type = 2;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);

	}

	repeat = true;
}

void item4type3() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item4 == "Healing Potion") {
		item4type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item4 == "Cocoa Puffs") {
		item4type = 2;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);
	}

	repeat = true;
}

void item5type3() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item5 == "Healing Potion") {
		item5type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item5 == "Cocoa Puffs") {
		item5type = 2;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);

	}
	repeat = true;

}

void item1type4() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item1 == "Healing Potion") {
		item1type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item1 == "Cocoa Puffs") {
		item1type = 2;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);

	}

	repeat = true;
}

void item2type4() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item2 == "Healing Potion") {
		item2type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item2 == "Cocoa Puffs") {
		item2type = 2;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);

	}
	repeat = true;
}

void item3type4() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item3 == "Healing Potion") {
		item3type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item3 == "Cocoa Puffs") {
		item3type = 2;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);

	}

	repeat = true;
}

void item4type4() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item4 == "Healing Potion") {
		item4type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item4 == "Cocoa Puffs") {
		item4type = 2;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);

	}
	repeat = true;
}

void item5type4() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item5 == "Healing Potion") {
		item5type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item5 == "Cocoa Puffs") {
		item5type = 2;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);

	}


	repeat = true;
}

void item1type5() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n \n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item1 == "Healing Potion") {
		item1type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item1 == "Cocoa Puffs") {
		item1type = 2;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);

	}

	repeat = true;
}

void item2type5() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item2 == "Healing Potion") {
		item2type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item2 == "Cocoa Puffs") {
		item2type = 2;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);

	}
	repeat = true;
}

void item3type5() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n \n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item3 == "Healing Potion") {
		item3type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item3 == "Cocoa Puffs") {
		item3type = 2;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);

	}
	repeat = true;
}

void item4type5() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	if (item4 == "Healing Potion") {
		item4type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item4 == "Cocoa Puffs") {
		if (sound == true) {
			Beep(800, 220);
		}
		item4type = 2;
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}


	repeat = true;
}

void item5type5() {
	system("cls");
	cerr << "Whoa! How did you get here!? This is an incomplete part of code. This function merely acts as a placeholder. Everything that happens from this point on may be extra glitchy. The likely cause of this error is a modified savegame. COMPUTERDOOM will now attempt to restore your item to a proper state.....\n\nPlease wait....\n\n\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	Sleep(1000);
	if (item5 == "Healing Potion") {
		item5type = 1;
		if (sound == true) {
			Beep(800, 220);
		}
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}

	else if (item5 == "Cocoa Puffs") {
		if (sound == true) {
			Beep(800, 220);
		}
		item5type = 2;
		MessageBox(NULL, "Successfully restored the item state!", "Success", MB_ICONASTERISK | MB_OK);
	}



	else {
		MessageBox(NULL, "Failed to repair the item! :(", "We All Have Bad Days", MB_ICONERROR | MB_OK);


	}

	repeat = true;
}


void itemmenuparse() {

	itemmenu = item1has + item2has + item3has + item4has + item5has;
	stringstream mi1, mi2, mi3, mi4, mi5;

	switch (itemmenu) {
	case 1:
		mi1 << "\n\n1) " << item1 << " (" << item1a << ")\n2)return to basic moves menu";
		menuitems1 = mi1.str();
		break;
	case 2:
		mi2 << "\n\n1) " << item1 << " (" << item1a << ")\n2) " << item2 << " (" << item2a << ")\n3)return to basic moves menu";
		menuitems2 = mi2.str();
		break;
	case 3:
		mi3 << "\n\n1) " << item1 << " (" << item1a << ")\n2) " << item2 << " (" << item2a << ")\n3) " << item3 << " (" << item3a << ")\n4)return to basic moves menu";
		menuitems3 = mi3.str();
		break;
	case 4:
		mi4 << "\n\n1) " << item1 << " (" << item1a << ")\n2) " << item2 << " (" << item2a << ")\n3) " << item3 << " (" << item3a << ")\n4) " << item4 << " (" << item4a << ")\n5)return to basic moves menu";
		menuitems4 = mi4.str();
		break;
	case 5:
		mi5 << "\n\n1) " << item1 << " (" << item1a << ")\n2) " << item2 << " (" << item2a << ")\n3) " << item3 << " (" << item3a << ")\n4) " << item4 << " (" << item4a << ")\n5) " << item5 << " (" << item5a << ")\n6)return to basic moves menu";
		menuitems5 = mi5.str();
		break;
	}


}






void itemhandler() {
	system("cls");
	itemmenuparse();
	if (itemmenu == 5) {
		cout << "Items:\n\n" << menuitems5 << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		cin >> action;

		if (action == "6") {
			repeat = true;
			return;
		}

		else if (action == "1") {
			switch (item1type) {
			case 1:
				item1type1();
				break;
			case 2:
				item1type2();
				break;
			case 3:
				item1type3();
				break;
			case 4:
				item1type4();
				break;
			case 5:
				item1type5();
				break;
			default:
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;

			}
		}

		else if (action == "2") {
			switch (item2type) {
			case 1:
				item2type1();
				break;
			case 2:
				item2type2();
				break;
			case 3:
				item2type3();
				break;
			case 4:
				item2type4();
				break;
			case 5:
				item2type5();
				break;
			default:
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;

			}
		}

		else if (action == "3") {
			switch (item3type) {
			case 1:
				item3type1();
				break;
			case 2:
				item3type2();
				break;
			case 3:
				item3type3();
				break;
			case 4:
				item3type4();
				break;
			case 5:
				item3type5();
				break;
			default:
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;
			}
		}
		else if (action == "4") {
			switch (item4type) {
			case 1:
				item4type1();
				break;
			case 2:
				item4type2();
				break;
			case 3:
				item4type3();
				break;
			case 4:
				item4type4();
				break;
			case 5:
				item4type5();
				break;
			default:
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;
			}
		}

		else if (action == "5") {
			switch (item5type) {
			case 1:
				item5type1();
				break;
			case 2:
				item5type2();
				break;
			case 3:
				item5type3();
				break;
			case 4:
				item5type4();
				break;
			case 5:
				item5type5();
				break;
			default:
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;
			}
		}

		else {
			system("cls");
			cout << "Invalid Input\n\n" << endl;
			if (sound == true) {
				Beep(800, 220);
				Beep(800, 220);
			}
			system("pause");
			itemhandler();
		}

	}

	else if (itemmenu == 1) {
		cout << "Items:\n\n" << menuitems1 << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		cin >> action;

		if (action == "1") {
			switch (item1type) {
			case 1:
				item1type1();
				break;
			case 2:
				item1type2();
				break;
			case 3:
				item1type3();
				break;
			case 4:
				item1type4();
				break;
			case 5:
				item1type5();
				break;
			default:
				system("cls");
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;

			}
		}
		else if (action == "2") {
			repeat = true;
			return;
		}

		else {
			system("cls");
			cout << "Invalid Input\n" << endl;
			if (sound == true) {
				Beep(800, 220);
				Beep(800, 220);
			}
			system("pause");
			itemhandler();
		}

	}

	else if (itemmenu == 2) {
		cout << "Items:\n\n" << menuitems2 << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		cin >> action;

		if (action == "3") {
			repeat = true;
			return;
		}

		else if (action == "1") {
			switch (item1type) {
			case 1:
				item1type1();
				break;
			case 2:
				item1type2();
				break;
			case 3:
				item1type3();
				break;
			case 4:
				item1type4();
				break;
			case 5:
				item1type5();
				break;
			default:
				system("cls");

				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);

				break;
			}
		}

		else if (action == "2") {
			switch (item2type) {
			case 1:
				item2type1();
				break;
			case 2:
				item2type2();
				break;
			case 3:
				item2type3();
				break;
			case 4:
				item2type4();
				break;
			case 5:
				item2type5();
				break;
			default:
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;
			}
		}

		else {
			system("cls");
			cout << "Invalid Input\n" << endl;
			if (sound == true) {
				Beep(800, 220);
				Beep(800, 220);
			}
			system("pause");
			itemhandler();
		}

	}

	else if (itemmenu == 3) {
		cout << "Items:\n\n" << menuitems3 << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		cin >> action;

		if (action == "4") {
			repeat = true;
			return;
		}

		else if (action == "1") {
			switch (item1type) {
			case 1:
				item1type1();
				break;
			case 2:
				item1type2();
				break;
			case 3:
				item1type3();
				break;
			case 4:
				item1type4();
				break;
			case 5:
				item1type5();
				break;
			default:
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;
			}
		}
		else if (action == "2") {
			switch (item2type) {
			case 1:
				item2type1();
				break;
			case 2:
				item2type2();
				break;
			case 3:
				item2type3();
				break;
			case 4:
				item2type4();
				break;
			case 5:
				item2type5();
				break;
			default:
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;
			}
		}

		else if (action == "3") {
			switch (item3type) {
			case 1:
				item3type1();
				break;
			case 2:
				item3type2();
				break;
			case 3:
				item3type3();
				break;
			case 4:
				item3type4();
				break;
			case 5:
				item3type5();
				break;
			default:
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;
			}
		}

		else {
			system("cls");
			cout << "Invalid Input\n" << endl;
			if (sound == true) {
				Beep(800, 220);
				Beep(800, 220);
			}
			system("pause");
			itemhandler();
		}

	}
	else if (itemmenu == 4) {
		cout << "Items:\n\n" << menuitems4 << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		cin >> action;

		if (action == "5") {
			repeat = true;
			return;
		}

		else if (action == "1") {
			switch (item1type) {
			case 1:
				item1type1();
				break;
			case 2:
				item1type2();
				break;
			case 3:
				item1type3();
				break;
			case 4:
				item1type4();
				break;
			case 5:
				item1type5();
				break;
			default:
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;
			}
		}

		else if (action == "2") {
			switch (item2type) {
			case 1:
				item2type1();
				break;
			case 2:
				item2type2();
				break;
			case 3:
				item2type3();
				break;
			case 4:
				item2type4();
				break;
			case 5:
				item2type5();
				break;
			default:
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;
			}
		}

		else if (action == "3") {
			switch (item3type) {
			case 1:
				item3type1();
				break;
			case 2:
				item3type2();
				break;
			case 3:
				item3type3();
				break;
			case 4:
				item3type4();
				break;
			case 5:
				item3type5();
				break;
			default:
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;
			}
		}
		else if (action == "4") {
			switch (item4type) {
			case 1:
				item4type1();
				break;
			case 2:
				item4type2();
				break;
			case 3:
				item4type3();
				break;
			case 4:
				item4type4();
				break;
			case 5:
				item4type5();
				break;
			default:
				system("cls");
				MessageBox(NULL, "An error occured when attempting to use this item. Be sure that the name of the selected item was valid. This is most likely caused by a corrupted savegame. If this continues to cause problems, please delete the corrupted savegame.", "Item Not Valid", MB_OK | MB_ICONERROR);
				break;
			}
		}

		else {
			system("cls");
			cout << "Invalid Input\n" << endl;
			if (sound == true) {
				Beep(800, 220);
				Beep(800, 220);
			}
			system("pause");
			itemhandler();
		}
	}
	else {
		system("cls");
		MessageBox(NULL, "An error has occured while loading the items menu. This could either be because you don't have any items, and you were accidentally redirected to the items menu, or there was an error processing an earlier purchase of items.", "Loading Item Menu", MB_OK | MB_ICONERROR);

	}


	return;
}



void chkinventorysob() {


	if (weapon == 0) {
		NULL;
	}

	else if (weapon == 1) {
		hero.strength = hero.strength + 5;
	}
	else if (weapon == 2) {
		hero.strength = hero.strength + 10;
	}

	else {
		system("cls");
		MessageBox(NULL, "An error occured when performing pre-battle weapon checks. The cause of this may be a corrupted savegame. Your weapon may malfunction, or not function at all during battle.", "Loading Battle", MB_ICONERROR | MB_OK);

	}

	itemmenu = item1has + item2has + item3has + item4has + item5has;

}

void chkinventoryeob() {

	if (weapon == 0) {
		NULL;
	}

	else if (weapon == 1) {
		hero.strength = hero.strength - 5;
	}
	else if (weapon == 2) {
		hero.strength = hero.strength - 10;
	}

	else {
		system("cls");
		MessageBox(NULL, "Aw snap! Couldn't wrap things up with the weapons. The problem could be a corrupted savegame.", "Ending Battle", MB_ICONERROR | MB_OK);

	}

	if (item1a == 0) {
		item1 = item2;
		item1a = item2a;
		item1has = item2has;
		item1type = item2type;
	}
	if (item2a == 0) {
		item2 = item3;
		item2a = item3a;
		item2has = item3has;
		item2type = item3type;
	}

	if (item3a == 0) {
		item3 = item4;
		item3a = item4a;
		item3has = item4has;
		item3type = item4type;

	}
	if (item4a == 0) {
		item4 = item5;
		item4a = item5a;
		item4has = item5has;
		item4type = item5type;

	}
	if (item5a == 0) {
		item5has = 0;
		item5 = "";
		item5type = 0;
	}
	if (item1a == 0) {
		item1 = item2;
		item1a = item2a;
		item1has = item2has;
		item1type = item2type;

	}


}




void itemstore() {
	int alert;
	storestat = true;
	srand(unsigned(time(0)));
	cin.ignore(256, '\n');
	while (action != "5") {
		system("cls");
		system("color a");
		cout << "You have " << money << " coins\n\n" << endl;
		if (troll == true) {
			cout << "Welcome to the shop! See something you like? Buy it! If you don't, then be sure to check back as the store will be updated to dihero.splay new stuff as you advance through the game. Type about before the number to learn more. For example, \"about 1\":\n\n\n1)Iron Sword (150 coins)\n2)Healing potion (50 coins each)\n3)THE PASSWORD FOR TOTAL DOMINATION!!! (1 coin)\n4)Cocoa puffs (75 coins)\n5)exit" << endl;
		}
		else if (troll == false) {
			cout << "Welcome to the shop! See something you like? Buy it! If you don't, then be sure to check back as the store will be updated to dihero.splay new stuff as you advance through the game. Type about before the number to learn more. For example, \"about 1\":\n\n\n1)Iron Sword (150 coins)\n2)Healing potion (50 coins each)\n3)THE PASSWORD FOR TOTAL DOMINATION!!! (10000000000000 coins)\n4)Cocoa puffs (75 coins)\n5)exit" << endl;
		}
		if (sound == true) {
			Beep(800, 220);
		}
		getline(cin, action);
		if (action == "1" && money < 150 && weapon != 1)
			MessageBox(NULL, "You don't have enough coins to buy this item!", "Not Enough Coins!", MB_ICONERROR);


		if (action == "1" && weapon == 1)
			MessageBox(NULL, "You already have this item", "Don't Be Greedy!", MB_ICONERROR);

		if (action == "1" && money >= 150 && weapon != 1) {
			alert = MessageBox(NULL, "Do you want to buy the Iron Sword, for 150 coins?", "Confirm Purchase", MB_ICONQUESTION | MB_YESNO);

			if (alert == IDNO)
				continue;

			MessageBox(NULL, "You got the Iron Sword!", "Item Purchased!", MB_ICONASTERISK);

			refundhandler(150);


			money = money - 150;
			weapon = 1;
		}



		if (action == "about 1" || action == "About 1" || action == "ABOUT 1") {
			system("cls");
			MessageBox(NULL, "The iron sword will increase your strength by 5. That should help you PWN those monsters!", "Iron Sword Info", MB_ICONASTERISK);
		}
		if (action == "about 2" || action == "About 2" || action == "ABOUT 2") {
			system("cls");
			MessageBox(NULL, "This will fully replenish your health during battle!", "Healing Potion Info", MB_ICONASTERISK);
		}

		if (action == "about 3" || action == "About 3" || action == "ABOUT 3") {
			system("cls");
			MessageBox(NULL, "This is the password to the cheat menu and to authenticate modified savegames (password will only be useful in beta version of COMPUTERDOOM).", "About This *cough* Item :)", MB_ICONASTERISK);
		}

		if (action == "about 4" || action == "About 4" || action == "ABOUT 4") {
			system("cls");
			MessageBox(NULL, "This will make you COOCOO FOR COCOA PUFFS, allowing you to go so fast, that you will be able to have 3 turns in a row!", "About Cocoa Puffs", MB_ICONASTERISK);
		}


		if (action == "3") {
			system("cls");
			troll = false;
			MessageBox(NULL, "You might want to take a closer look at the price", "Ooooh, You Wanna Buy THAT?", MB_ICONWARNING);
		}

		if (action == "2" && money < 50) {
			system("cls");
			MessageBox(NULL, "Sorry, you don't have enough coins to buy this item...", "Cannot Purchase Item", MB_ICONERROR);
		}

		if (action == "4" && money < 75) {
			system("cls");
			MessageBox(NULL, "Sorry, you don't have enough coins to buy this item...", "Cannot Purchase Item", MB_ICONERROR);
		}

		if (action == "4" && money >= 75) {
			system("cls");
			alert = MessageBox(NULL, "Confirm your purchase of Cocoa Puffs for 75 coins?", "Confirm Purchase", MB_YESNO | MB_ICONQUESTION);

			if (alert == IDNO)
				continue;

			MessageBox(NULL, "Thank you for your purchase! We'll use your contributions to add more goodies to the store!", "Item Purchased!", MB_ICONASTERISK);
			money = money - 75;
			if (item1 == "Cocoa Puffs" || item1 == "" || item1 == "0") {
				item1 = "Cocoa Puffs";
				item1has = 1;
				item1type = 2;
				item1a++;
				refundhandler(75);
			}
			else if (item2 == "Cocoa Puffs" || item2 == "" || item2 == "0") {
				item2 = "Cocoa Puffs";
				item2type = 2;
				item2has = 1;
				item2a++;
				refundhandler(75);
			}
			else if (item3 == "Cocoa Puffs" || item3 == "" || item3 == "0") {
				item3 = "Cocoa Puffs";
				item3type = 2;
				item3has = 1;
				item3a++;
				refundhandler(75);
			}
			else if (item4 == "Cocoa Puffs" || item4 == "" || item4 == "0") {
				item4 = "Cocoa Puffs";
				item4type = 2;
				item4has = 1;
				item4a++;
				refundhandler(75);
			}
			else if (item5 == "Cocoa Puffs" || item5 == "" || item5 == "0") {
				item5 = "Cocoa Puffs";
				item5type = 2;
				item5has = 1;
				item5a++;
				refundhandler(75);
			}

			else {
				MessageBox(NULL, "An error has occured when completing your purchase. The likely cause of this could be a modified savegame, or an invalid modification in the cheat menu", "We All Have Bad Days", MB_ICONERROR);
				money = money + 75;
				cout << "\nYou will now receive a full refund for your coins. You now have " << money << " coins." << endl << endl;
				if (sound == true) {
					Beep(800, 220);
					Beep(800, 220);
				}
				system("pause");
			}


		}

		if (action == "2" && money >= 50) {
			system("cls");
			alert = MessageBox(NULL, "Confirm your purchase of a healing potion for 50 coins?", "Confirm Purchase", MB_YESNO | MB_ICONQUESTION);

			if (alert == IDNO)
				continue;

			MessageBox(NULL, "Thank you for your purchase! We'll use your contributions to add more goodies to the store!", "Item Purchased!", MB_ICONASTERISK);

			money = money - 50;
			if (item1 == "Healing Potion" || item1 == "" || item1 == "0") {
				item1 = "Healing Potion";
				item1has = 1;
				item1type = 1;
				item1a++;
				refundhandler(50);
			}
			else if (item2 == "Healing Potion" || item2 == "" || item2 == "0") {
				item2 = "Healing Potion";
				item2type = 1;
				item2has = 1;
				item2a++;
				refundhandler(50);
			}
			else if (item3 == "Healing Potion" || item3 == "" || item3 == "0") {
				item3 = "Healing Potion";
				item3type = 1;
				item3has = 1;
				item3a++;
				refundhandler(50);
			}
			else if (item4 == "Healing Potion" || item4 == "" || item4 == "0") {
				item4 = "Healing Potion";
				item4type = 1;
				item4has = 1;
				item4a++;
				refundhandler(50);
			}
			else if (item5 == "Healing Potion" || item5 == "" || item5 == "0") {
				item5 = "Healing Potion";
				item5type = 1;
				item5has = 1;
				item5a++;
				refundhandler(50);
			}

			else {
				MessageBox(NULL, "An error has occured when completing your purchase. The likely cause of this could be a modified savegame, or an invalid modification in the cheat menu", "We All Have Bad Days", MB_ICONERROR);
				money = money + 50;
				cout << "\nYou will now get a full refund of your coins. You have " << money << " coins." << endl << endl;
				if (sound == true) {
					Beep(800, 220);
					Beep(800, 220);
				}
				system("pause");
			}


		}

		else if (action != "1" && action != "2" && action != "3" && action != "4" && action != "5" && action != "about 1"  && action != "about 2" && action != "about 3" && action != "about 4")
		{
			MessageBox(NULL, "Please enter a valid option", "Invalid Input", MB_ICONWARNING);
			system("cls");
		}



	}
	system("cls");
	system("color 07");
	return;
}





void defaults() {
	hero.health = 5;
	hero.lvl = 1;
	hero.defense = 2;
	hero.strength = 4;
	hero.fullh = 5;
	hero.sp = 0;
	hero.spfull = 0;
	state = 0;
	levelup = 0;
	hero.xp = 0;
	money = 0;
	weapon = 0;
	leveluprequirement = 0;
	oldrequirement = 0;
	save = No_save;
	flee = true;
	item1 = "";
	item2 = "";
	item3 = "";
	item4 = "";
	item5 = "";
	item1has = 0;
	item2has = 0;
	item3has = 0;
	item4has = 0;
	item5has = 0;
	item1type = 0;
	item2type = 0;
	item3type = 0;
	item4type = 0;
	item5type = 0;
	item1a = 0;
	item2a = 0;
	item3a = 0;
	item4a = 0;
	item5a = 0;
	nuke = true;


}





void leveluphandler() {
	bool recheck = false;
	bool preplannedlevelup = false;


	if (battle > 1) {
		leveluprequirement = oldrequirement + levelup * 100 + 50;
		oldrequirement = leveluprequirement;
	}



	if (battle == 1) {
		leveluprequirement = 50;
		oldrequirement = 50;
	}

	if (battle == 1) {
		cout << "Reward(s): 50 exp\n" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		hero.xp = hero.xp + 50;


		system("PAUSE");
	}

	if (battle == 2) {
		cout << "Reward(s): 100 exp\n" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		hero.xp = hero.xp + 100;
		system("PAUSE");
	}

	if (battle == 3) {
		cout << "Reward(s): 400 exp\n" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		hero.xp = hero.xp + 400;
		coinreward(battle * 25);

	}



	if (hero.xp >= 50 && levelup == 0) {
		preplannedlevelup = true;
		levelup++;
		hero.lvl++;
		statraise = true;
		hero.fullh = hero.fullh + 3;
		hero.strength = hero.strength + 3;
		hero.defense = hero.defense + 1;
		hero.spfull = 4;
		cout << "YOU LEVELED UP!!!!!!!!!!!!! \n You can now use magic! Note that the \"nothing\" command, has been moved to the magic moves menu.\n" << endl;
		if (sound == true) {
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
		}
		system("PAUSE");
		MessageBox(NULL, "You unlocked heal! Look for it in the magic menu!\n", "YOU LEVELED UP!", MB_ICONASTERISK);
		system("cls");
		action = "nothing";


	}

	if (hero.xp >= 150 && levelup == 1) {
		preplannedlevelup = true;
		hero.lvl++;
		levelup++;
		statraise = true;
		hero.fullh = hero.fullh + 3;
		hero.strength = hero.strength + 3;
		hero.defense = hero.defense + 1;
		hero.spfull = hero.spfull + 3;
		cout << "YOU LEVELED UP!!!!!!!!!\nYou learned a new move! Fireball! Look for it in the magic moves menu!\n\n" << endl;
		if (sound == true) {
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
		}
		system("PAUSE");

	}





checkagain:
	if (recheck == true) {
		oldrequirement = leveluprequirement;
		leveluprequirement = oldrequirement + levelup * 100 + 50;
		recheck = false;
	}

	if (hero.xp >= leveluprequirement && preplannedlevelup == false) {
		recheck = true;
		hero.lvl++;
		levelup++;
		statraise = true;
		hero.fullh = hero.fullh + 3;
		hero.strength = hero.strength + 3;
		hero.defense = hero.defense + 1;
		hero.spfull = hero.spfull + 3;
		MessageBox(NULL, "YOU LEVELED UP!!!!", "Level Up", MB_ICONASTERISK);

	}

	while (statraise == true) {
		cout << "Select a stat to raise by 2:\n\n1)Health\n2)defense (will only be raised by 1)\n3)power\n4)hero.sp\n\n" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		cin >> action;





		if (action == "1") {
			hero.fullh = hero.fullh + 2;
			statraise = false;
		}

		else if (action == "2") {
			hero.defense = hero.defense + 1;
			statraise = false;

		}

		else if (action == "3") {
			hero.strength = hero.strength + 2;
			statraise = false;
		}

		else if (action == "4") {
			hero.spfull = hero.spfull + 2;
			statraise = false;

		}

		else {
			system("cls");
			MessageBox(NULL, "Please enter a valid option", "Invalid Input", MB_ICONWARNING);
		}

	}

	if (recheck == true) {
		goto checkagain;
	}

	statraise = false;
	return;
}

void battleend() {
	system("cls");
	if (hero.health <= 0) {
		exit(0);
	}
	system("color f0");
	cout << "congratulations! You beat " << monstername << "\n*****************************************\nSTATS:\n\n" << endl;
	system("color 07");
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	system("PAUSE");



	if (monsterhealth > 0)
		MessageBox(NULL, "No experience has been earned because you fled. Try not to flee next time because you may not be strong enough for the next enemy. If you flee you cannot earn experience to level up. Good luck!", "Results", MB_ICONASTERISK);


	if (monsterhealth <= 0) {

		leveluphandler();

		cout << "Here are your stats:\nlvl " << hero.lvl << "\n\n Health: " << hero.fullh << "\n defense: " << hero.defense << "\n power: " << hero.strength << "\n sp: " << hero.spfull << "\nExperience: " << hero.xp << endl << endl << endl;
		system("PAUSE");
		return;
	}
	return;
}















void cheatcommandmenu() {
	int herofullhnew = hero.fullh;
	int herodefnew = hero.defense;
	int statenew = state;
	int spfullnew = hero.spfull;
	int moneynew = money;
	int herostrengthnew = hero.strength;
	int lvlnew = hero.lvl;
	string cheatinvincibilitynew = cheatinvincibility;
	string monsterdoesnothingnew = monsterdoesnothing;
	string twoturnsinrownew = twoturnsinrow;
	system("color b0");
	system("cls");
	cout << "Cheat Menu v1.7 (For testing purposes only)" << endl;
	cout << "\n\n\nENTER ADMINISTRATOR PASSWORD OR TYPE \"exit\":\n" << endl;
	if (sound == true) {
		Beep(800, 220);
	}
	cin >> cheatcommand;
	if (cheatcommand == "exit") {
		system("color 07");
		system("cls");
		return;
	}


	while (cheatcommand != "password") {
		cout << "\nah ah ah! You didn't say PLEASE!!':\n" << endl;
		if (sound == true) {
			Beep(800, 220);
			Beep(800, 220);
		}
		cin >> cheatcommand;
		if (cheatcommand == "exit") {
			system("color 07");
			system("cls");
			return;
		}
	}

	while (cheatcommand != "9") {
		system("cls");
		if (hero.fullh != herofullhnew || hero.strength != herostrengthnew || hero.lvl != lvlnew || hero.defense != herodefnew || money != moneynew || state != statenew || hero.spfull != spfullnew || cheatinvincibility != cheatinvincibilitynew || monsterdoesnothing != monsterdoesnothingnew || twoturnsinrow != twoturnsinrownew) {
			cout << "\nPlease input a number:\n\n1)change player's health\n2)change the player's power\n3)change the player's defense\n4)change the player''s level\n5)cheat menu\n6)change the player's sp\n7)Change how many coins you have\n8)Go to a certain part of the game\n9)exit discarding changes\n10)exit saving changes" << endl;
		}
		else {
			cout << "\nPlease input a number:\n\n1)change player's health\n2)change the player's power\n3)change the player's defense\n4)change the player''s level\n5)cheat menu\n6)change the player's hero.sp\n7)Change how many coins you have\n8)Go to a certain part of the game\n9)exit discarding changes\n" << endl;
		}
		if (sound == true) {
			Beep(800, 220);
		}
		cin >> cheatcommand;


		if (cheatcommand == "1") {
			system("cls");
			cout << "Please input a number for the amount of health." << endl;
			if (sound == true) {
				Beep(800, 220);
			}
			cin >> herofullhnew;
			if (!cin) {
				cin.clear();
				cin.ignore(100, '\n');
				MessageBox(NULL, "Please enter a valid number.", "Incorrect Configuration", MB_ICONEXCLAMATION);
				herofullhnew = hero.fullh;
			}

		}

		if (cheatcommand == "2") {
			system("cls");
			cout << "Please input a number for the player's power" << endl;
			if (sound == true) {
				Beep(800, 220);
			}
			cin >> herostrengthnew;
			if (!cin) {
				cin.clear();
				cin.ignore(100, '\n');
				MessageBox(NULL, "Please enter a valid number.", "Incorrect Configuration", MB_ICONEXCLAMATION);
				herofullhnew = hero.fullh;
			}


		}
		if (cheatcommand == "3") {
			system("cls");
			cout << "Please input the player's defense" << endl;
			if (sound == true) {
				Beep(800, 220);
			}
			cin >> herodefnew;

			if (!cin) {
				cin.clear();
				cin.ignore(100, '\n');
				MessageBox(NULL, "Please enter a valid number.", "Incorrect Configuration", MB_ICONEXCLAMATION);
				herodefnew = hero.defense;
			}


		}
		if (cheatcommand == "4") {
			system("cls");
			cout << "Please enter the player's new level" << endl;
			if (sound == true) {
				Beep(800, 220);
			}
			cin >> lvlnew;

			if (!cin) {
				cin.clear();
				cin.ignore(100, '\n');
				MessageBox(NULL, "Please enter a valid number.", "Incorrect Configuration", MB_ICONEXCLAMATION);
				lvlnew = hero.lvl;
			}

		}
		if (cheatcommand == "5") {
			system("cls");
			cout << "Input a number to toggle cheats:\n\n\n1)invincibility: " << cheatinvincibilitynew << "\n2)Two turns in a row: " << twoturnsinrownew << "\n3)Enemies always do nothing: " << monsterdoesnothingnew << "\n4)exit" << endl;
			if (sound == true) {
				Beep(800, 220);
			}
			cin >> cheatcommand;

			if (cheatcommand == "1") {
				system("cls");
				if (cheatinvincibilitynew == "off") {
					cheatinvincibilitynew = "on";
					MessageBox(NULL, "Invincibility has been turned on", "Changes Applied", MB_ICONASTERISK);
					system("cls");
				}

				else if (cheatinvincibilitynew == "on") {
					cheatinvincibilitynew = "off";
					MessageBox(NULL, "Invincibility has been turned off", "Changes Applied", MB_ICONASTERISK);
					system("cls");


				}

			}

			if (cheatcommand == "2") {
				system("cls");
				if (twoturnsinrownew == "off") {
					twoturnsinrownew = "on";
					MessageBox(NULL, "Two turns in a row has been turned on", "Changes Applied", MB_ICONASTERISK);
					system("cls");
				}

				else if (twoturnsinrownew == "on") {
					twoturnsinrownew = "off";
					MessageBox(NULL, "Two turns in a row has been turned off", "Changes Applied", MB_ICONASTERISK);
					system("cls");


				}

			}

			if (cheatcommand == "3") {
				system("cls");
				if (monsterdoesnothingnew == "off") {
					monsterdoesnothingnew = "on";
					MessageBox(NULL, "Enemy does nothing has been turned on", "Changes Applied", MB_ICONASTERISK);
					system("cls");
				}

				else if (monsterdoesnothingnew == "on") {
					monsterdoesnothingnew = "off";
					MessageBox(NULL, "Enemy does nothing has been turned oFF", "Changes Applied", MB_ICONASTERISK);
					system("cls");


				}

			}
			if (cheatcommand == "4") {
				continue;
			}
		}

		if (cheatcommand == "6") {
			system("cls");
			cout << "Please input a number for the player's hero.sp:" << endl;
			if (sound == true) {
				Beep(800, 220);
			}
			cin >> spfullnew;

			if (!cin) {
				cin.clear();
				cin.ignore(100, '\n');
				MessageBox(NULL, "Please enter a valid number.", "Incorrect Configuration", MB_ICONEXCLAMATION);
				spfullnew = hero.spfull;
			}
		}

		if (cheatcommand == "7") {
			system("cls");
			cout << "Bring on the cashflow! Input a number for how many coins you want!" << endl;
			if (sound == true) {
				Beep(800, 220);
			}
			cin >> moneynew;

			if (!cin) {
				cin.clear();
				cin.ignore(100, '\n');
				MessageBox(NULL, "Please enter a valid number.", "Incorrect Configuration", MB_ICONEXCLAMATION);
				moneynew = money;
			}

		}

		if (cheatcommand == "8") {
			system("cls");
			cout << "Enter number for variable \"state\" (this will cause errors if an invalid number is entered)" << endl;
			if (sound == true) {
				Beep(800, 220);
			}
			cin >> statenew;

			if (!cin) {
				cin.clear();
				cin.ignore(100, '\n');
				MessageBox(NULL, "Please enter a valid number.", "Incorrect Configuration", MB_ICONEXCLAMATION);
				statenew = state;
			}
		}



		if (cheatcommand == "10") {
			if (hero.fullh != herofullhnew || hero.strength != herostrengthnew || hero.lvl != lvlnew || hero.defense != herodefnew || money != moneynew || state != statenew || hero.spfull != spfullnew || cheatinvincibility != cheatinvincibilitynew || monsterdoesnothing != monsterdoesnothingnew || twoturnsinrow != twoturnsinrownew) {
				system("cls");
				cout << "\nOkay, these are your new stats:\n\n level: " << lvlnew << "\nHealth: " << herofullhnew << "\nPower: " << herostrengthnew << "\nDefense: " << herodefnew << "\nhero.sp: " << spfullnew << "\nCoins: " << moneynew << "\nState: " << statenew << endl;
				cout << "\n\n\nThese are your current cheat settings:\n\ninvincibility: " << cheatinvincibilitynew << "\nTwo turns in a row: " << twoturnsinrownew << "\nEnemies always do nothing: " << monsterdoesnothingnew << endl;
				cout << "\nDo you wish to proceed? (y/n)" << endl;
				if (sound == true) {
					Beep(800, 220);
				}
				cin >> cheatcommand;


				if (cheatcommand == "y" || cheatcommand == "Y") {
					hero.fullh = herofullhnew;
					hero.strength = herostrengthnew;
					hero.lvl = lvlnew;
					hero.defense = herodefnew;
					money = moneynew;
					state = statenew;
					hero.spfull = spfullnew;
					cheatinvincibility = cheatinvincibilitynew;
					monsterdoesnothing = monsterdoesnothingnew;
					twoturnsinrow = twoturnsinrownew;
					gotostate = true;
					break;
				}
				else if (cheatcommand == "n" || cheatcommand == "N") {
					continue;
				}

			}
		}
	}
	system("cls");
	hero.health = hero.fullh;
	hero.sp = hero.spfull;
	system("color 07");
	return;
}





void mainmenu() {

	while (action != "1" || action != "2" || action != "3" || action != "4") {
		system("cls");
		if (sound == true) {
			Beep(800, 220);
		}
		if (save != Save_available) {
			cout << "Main menu:\n\nInput a number and press enter:\n\n\n1)Start/resume game\n2)Delete savegame\n3)Cheat menu\n4)Settings\n5)FAQs\n6)Exit\n" << endl;
		}
		if (save == Save_available) {
			cout << "Main menu:\n\nInput a number and press enter:\n\n\n1)Start/resume game\n2)Delete savegame\n3)Cheat menu\n4)Settings\n5)Save game\n6)FAQs\n7)Exit" << endl;
		}
		cin >> action;





		if (action == "1") {
			system("cls");
			return;
		}

		else if (action == "2") {
			system("cls");
			int alert = MessageBox(NULL, "This will erase your progress, proceed?", "Delete Savegame?",
				MB_YESNO | MB_ICONEXCLAMATION);

			if (alert == IDNO)
				continue;


			do {
				if (remove("gamesave.dat") != 0) {
					alert = MessageBox(NULL, "Error removing gamesave.dat.", "Delete Savegame", MB_RETRYCANCEL | MB_ICONERROR);

				}


				else {
					defaults();
					MessageBox(NULL, "File Successfully deleted!", "Success", MB_ICONASTERISK | MB_OK);
					system("cls");
				}
			} while (alert == IDRETRY);
		}

		else if (action == "3")
			cheatcommandmenu();

		else if (action == "5" && save != Save_available)
			faq();

		else if (action == "6" && save != Save_available) {
			exit(0);
		}

		else if (action == "6" && save == Save_available)
			faq();

		else if (action == "7" && save == Save_available) {
			exit(0);
		}

		else if (action == "5" && save == Save_available) {
			savepending = true;
			return;
			system("cls");

		}

		else if (action == "4") {
			while (action != "3") {
				system("cls");
				cout << "\nInput a number to toggle the settings:\n\n\n1)Toggle sound: ";
				if (sound == true) {
					cout << "on" << endl;
				}
				else if (sound == false) {
					cout << "off" << endl;
				}
				else {
					cout << sound << endl;
				}
				cout << "2)Save automatically: ";
				if (save == Auto) {
					cout << "on" << endl;
				}
				else if (save == Save_available) {
					cout << "off" << endl;
				}
				else if (save == No_auth) {
					cout << "You cannot change this option because a modified savegame was detected" << endl;
				}
				else if (save == No_save) {
					cout << "You cannot change this option because no savegame is loaded yet" << endl;
				}
				else {
					cout << save << endl;
				}
				cout << "3)exit" << endl;

				cin >> action;

				if (action == "1" && sound == true) {
					system("cls");
					sound = false;
					MessageBox(NULL, "Beeping sounds have been turned off (alert messages like this one don't count)", "Change Applied", MB_OK | MB_ICONASTERISK);

				}
				else if (action == "1" && sound == false) {
					system("cls");
					sound = true;
					MessageBox(NULL, "Beeping sounds have been turned on!", "Change Applied", MB_OK | MB_ICONASTERISK);
				}

				else if (action == "2" && save == No_save) {
					system("cls");
					MessageBox(NULL, "You cannot change this option because no savegame is loaded yet!", "Option Unavailable", MB_OK | MB_ICONEXCLAMATION);

				}
				else if (action == "2" && save == No_auth) {
					system("cls");
					MessageBox(NULL, "You cannot change this option because a modified savegame was detected!", "Option Unavailable", MB_OK | MB_ICONEXCLAMATION);
				}

				else if (action == "2" && save == Auto) {
					system("cls");
					save = Save_available;
					MessageBox(NULL, "Automatic saving off. From now on, you will need to go to the main menu to save your game.", "Change Applied", MB_OK | MB_ICONASTERISK);
				}
				else if (action == "2" && save == Save_available) {
					system("cls");
					save = Auto;
					MessageBox(NULL, "Game will now be saved automatically", "Change Applied", MB_ICONASTERISK | MB_OK);
				}

				else if (action == "3") {
					NULL;
				}

				else {
					MessageBox(NULL, "Please enter a valid option", "Invalid Input", MB_ICONWARNING);
				}
			}
		}



		else {
			MessageBox(NULL, "Please enter a valid option", "Invalid Input", MB_ICONWARNING);
		}
	}
	system("cls");
	return;

}



void noauth() {
	int alert;
	system("color c0");
	system("cls");
	if (wrongpass < 4) {
		MessageBox(NULL, "COMPUTERDOOM found a problem with the contents of this file. If you wish to ignore this error and proceed with the game, you will need to enter the password to authenticate this invalid file.", "File Integrity Check Complete", MB_ICONERROR);
		cout << "enter the password:" << endl;
	password:
		cin >> action;
	}

	if (action != "password")
		wrongpass++;


	while (action != "password") {
		save = No_auth;
		system("cls");
		cout << "ACCESS DENIED! Your savegame will now be deleted, unless you can find a way to save it! Here are your options:\n\n\n1)Poke around the main menu\n2)Delete my savegame\n3)Attempt the password again\n4)Why am I seeing this?\n" << endl;
		if (sound == true) {
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
		}
		cin >> action;

		if (action == "password")
			action = "0";

		if (action == "1") { mainmenu(); }
		else if (action == "2") {
			do {
				if (remove("gamesave.dat") != 0) {
					alert = MessageBox(NULL, "Error deleting gamesave.dat", "Deleting Savegame", MB_ICONERROR | MB_RETRYCANCEL);
					system("cls");

				}
				else {
					MessageBox(NULL, "File successfully deleted!", "SUCCESS", MB_ICONASTERISK | MB_OK);
					system("cls");
					save = No_save;
					defaults();
					system("color 07");
					return;
				}
			} while (alert == IDRETRY);
		}


		else if (action == "3") {
			if (wrongpass > 3) {
				MessageBox(NULL, "You've already attempted the password too many times!", "You Can't Retry!", MB_ICONERROR | MB_OK);
				return;
			}
			system("cls");
			cout << "Enter the password" << endl;
			if (sound == true) {
				Beep(800, 220);
			}
			goto password;

		}

		else if (action == "4") {
			system("cls");
			Beep(800, 220);
			err();
			cerr << "Errors:\n\n" << errreport << endl;
			system("PAUSE");
		}

		else { system("cls"); MessageBox(NULL, "Please enter a valid option!", "Invalid input", MB_ICONWARNING); system("cls"); }

	}



	if (action == "password") {
		auth = true;
		system("cls");
		system("color 07");
		return;
	}
}







void integritycheck() {
	system("cls");
	cout << "Verifying integrity of file..." << endl;
	if (hero.lvl > 5 || hero.fullh > 25 || hero.strength > 24 || hero.defense > 10 || hero.defense <= 0 || hero.spfull > 21 || state > 3 || money > 1000 || weapon > 1 || integritychkskip > 1 || item1has > 1 || item2has > 1 || item3has > 0 || item4has > 0 || item5has > 0 || item1type > 2 || item2type > 2 || item3type > 2 || item4type > 2 || item5type > 2) {
		if (auth == true) {
			cout << "\nModification authenticated, skipping....." << endl;
		}

		if (auth == false) {
			noauth();
		}
	}

	if ((item1 == "Healing Potion" && item1type != 1) || (item1 == "Cocoa Puffs" && item1type != 2) || (item2 == "Healing Potion" && item2type != 1) || (item2 == "Cocoa Puffs" && item2type != 2)) {
		if (auth == true) {
			cout << "\nModification authenticated, skipping........." << endl;
		}
		if (auth == false) {
			noauth();
		}
	}
	if ((item1a > 0 && item1has == 0) || (item2a > 0 && item2has == 0) || (item1has == 1 && item1a == 0) || (item2has == 1 && item2a == 0)) {
		if (auth == true) {
			cout << "Modification authenticated, skipping.........." << endl;

		}
		if (auth == false) {


			noauth();
		}
	}

	system("cls");
}














void gamesavehandler() {
	int alert;
	if (save == Auto || save == Save_available) {
		ofstream writesave;
		writesave.open("gamesave.dat");
		switch (itemmenu) {
		case 1:
			writesave << integritychkskip << endl << leveluprequirement << endl << oldrequirement << endl << hero.lvl << endl << hero.spfull << endl << hero.defense << endl << hero.strength << endl << hero.fullh << endl << hero.xp << endl << levelup << endl << hero.name << endl << state << endl << money << endl << weapon << endl << item1 << endl << item1a << endl << item1has << endl << item1type << endl;
			break;
		case 2:
			writesave << integritychkskip << endl << leveluprequirement << endl << oldrequirement << endl << hero.lvl << endl << hero.spfull << endl << hero.defense << endl << hero.strength << endl << hero.fullh << endl << hero.xp << endl << levelup << endl << hero.name << endl << state << endl << money << endl << weapon << endl << item1 << endl << item1a << endl << item1has << endl << item1type << endl << item2 << endl << item2a << endl << item2has << endl << item2type << endl;
			break;
		case 3:
			writesave << integritychkskip << endl << leveluprequirement << endl << oldrequirement << endl << hero.lvl << endl << hero.spfull << endl << hero.defense << endl << hero.strength << endl << hero.fullh << endl << hero.xp << endl << levelup << endl << hero.name << endl << state << endl << money << endl << weapon << endl << item1 << endl << item1a << endl << item1has << endl << item1type << endl << item2 << endl << item2a << endl << item2has << endl << item2type << endl << item3 << endl << item3a << endl << item3has << endl << item3type << endl;
			break;
		case 4:
			writesave << integritychkskip << endl << leveluprequirement << endl << oldrequirement << endl << hero.lvl << endl << hero.spfull << endl << hero.defense << endl << hero.strength << endl << hero.fullh << endl << hero.xp << endl << levelup << endl << hero.name << endl << state << endl << money << endl << weapon << endl << item1 << endl << item1a << endl << item1has << endl << item1type << endl << item2 << endl << item2a << endl << item2has << endl << item2type << endl << item3 << endl << item3a << endl << item3has << endl << item3type << endl << item4 << endl << item4a << endl << item4has << endl << item4type << endl;
			break;
		case 5:
			writesave << integritychkskip << endl << leveluprequirement << endl << oldrequirement << endl << hero.lvl << endl << hero.spfull << endl << hero.defense << endl << hero.strength << endl << hero.fullh << endl << hero.xp << endl << levelup << endl << hero.name << endl << state << endl << money << endl << weapon << endl << item1 << endl << item1a << endl << item1has << endl << item1type << endl << item2 << endl << item2a << endl << item2has << endl << item2type << endl << item3 << endl << item3a << endl << item3has << endl << item3type << endl << item4 << endl << item4a << endl << item4has << endl << item4type << endl << item5 << endl << item5a << endl << item5has << endl << item5type << endl;
			break;
		default:

			writesave << integritychkskip << endl << leveluprequirement << endl << oldrequirement << endl << hero.lvl << endl << hero.spfull << endl << hero.defense << endl << hero.strength << endl << hero.fullh << endl << hero.xp << endl << levelup << endl << hero.name << endl << state << endl << money << endl << weapon << endl;
			break;
		}
		writesave.close();
		system("cls");
		MessageBox(NULL, "Game saved successfully!", "Game save", MB_OK | MB_ICONASTERISK);
		return;
	}

	cout << "Loading gamesave....\n\n";
	ifstream readsave;
	readsave.open("gamesave.dat");

	if (readsave.fail()) {
		while (true) {
			alert = MessageBox(NULL, "Could not read from save file. It may be corrupted, or doesn't exist.\n\nWould you like to create a gamesave now? (this creates \"gamesave.dat\" in the location of the game)", "Error loading savegame", MB_ICONERROR | MB_YESNO);


			if (alert == IDYES) {
				system("cls");
				cout << "Creating save data..." << endl;
				readsave.close();
				ofstream writesave;
				writesave.open("gamesave.dat");
				writesave << integritychkskip << endl << leveluprequirement << endl << oldrequirement << endl << hero.lvl << endl << hero.spfull << endl << hero.defense << endl << hero.strength << endl << hero.fullh << endl << hero.xp << endl << levelup << endl << hero.name << endl << state << endl << money << endl;
				if (sound == true) {
					Beep(800, 220);
				}
				MessageBox(NULL, "The save data was created", "Success!", MB_OK | MB_ICONASTERISK);
				writesave.close();
				save = Auto;
				system("cls");
				return;

			}

			if (alert == IDNO) {
				system("cls");
				alert = MessageBox(NULL, "You will not be able to save your game or create a save file in the future (until you quit, that is). Are you sure you would like to proceed with playing without a save?", "Play Unsaved Game", MB_YESNO | MB_ICONQUESTION);

				if (alert == IDNO) {
					system("cls");
					continue;
				}
				else if (alert == IDYES)
					NULL;

				save = No_save;
				system("cls");
				return;
			}

			system("cls");


		}
	}

	readsave >> integritychkskip >> leveluprequirement >> oldrequirement >> hero.lvl >> hero.spfull >> hero.defense >> hero.strength >> hero.fullh >> hero.xp >> levelup >> hero.name >> state >> money >> weapon >> item1 >> item1read >> item1a >> item1has >> item1type >> item2 >> item2read >> item2a >> item2has >> item2type >> item3 >> item3read >> item3a >> item3has >> item3type >> item4 >> item4read >> item4a >> item4has >> item4type >> item5 >> item5read >> item5a >> item5has >> item5type;

	system("cls");
	cout << "The following savegame was found:\n\n" << hero.name << " level " << hero.lvl << "\n\nHealth: " << hero.fullh << "\nPower: " << hero.strength << "\nDefense: " << hero.defense << "\nhero.sp: " << hero.spfull << "\nExperience: " << hero.xp << "\nCoins: " << money << endl << endl << "\nInventory;\n\n" << endl;
	if (item1has == 1) {
		stringstream saveitem1;
		saveitem1 << item1 << " " << item1read;
		item1 = saveitem1.str();
		item1read = "";
		cout << item1 << " (" << item1a << ")" << endl;

	}
	if (item2has == 1) {
		stringstream saveitem2;
		saveitem2 << item2 << " " << item2read;
		item2 = saveitem2.str();
		item2read = "";
		cout << item2 << " (" << item2a << ")" << endl;
	}
	if (item3has == 1) {
		stringstream saveitem3;
		saveitem3 << item3 << " " << item3read;
		item3 = saveitem3.str();
		item3read = "";
		cout << item3 << " (" << item3a << ")" << endl;
	}
	if (item4has == 1) {
		stringstream saveitem4;
		saveitem4 << item4 << " " << item4read;
		item4 = saveitem4.str();
		item4read = "";
		cout << item4 << " (" << item4a << ")" << endl;
	}
	if (item5has == 1) {
		stringstream saveitem5;
		saveitem5 << item5 << " " << item5read;
		item5 = saveitem5.str();
		item5read = "";
		cout << item5 << " (" << item5a << ")" << endl;
	}

	if (weapon == 1) {
		cout << "\nIron Sword\n\n" << endl;
	}
	if (weapon == 2) {
		cout << "\nBronze Sword\n\n" << endl;
	}

	system("PAUSE");
	save = Auto;
	readsave.close();
	if (integritychkskip == 0)
		integritycheck();



	system("cls");
	readsave.close();


	return;
}

























void midwaymenu() {
	if (nuke == true) {
		return;
	}

	if (storestat != true) {
		cout << "*************************************************\n\n What would you like to do next?:\n1)Fight next monster\n2)Go to main menu\n3)Quit (your progress will be saved if a savegame was previously loaded)\n\n" << endl;
	}
	else if (storestat == true) {
		cout << "*************************************************\n\n What would you like to do next?:\n1)Fight next monster\n2)Go to main menu\n3)Go to the store\n4)Quit (your progress will be saved if a savegame was previously loaded)\n\n" << endl;
	}
	if (gotostate == true) {
		return;
	}
	cin >> action;

	if (action == "1") {
		return;
	}

	else if (action == "2") {
		do {
			savepending = false;
			mainmenu();
			if (savepending == true)
				gamesavehandler();
		} while (savepending == true);
	}
	else if (action == "3" && storestat == false) {
		system("cls");
		cout << "Goodbye!\n" << endl;
		if (sound == true) {
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
		}
		system("pause");
		exit(0);
	}
	else if (action == "3" && storestat == true) {
		itemstore();
	}

	else {
		system("cls");
		MessageBox(NULL, "Please enter a valid option.", "Invalid Input", MB_ICONEXCLAMATION);
		midwaymenu();

	}
	midwaymenu();
}




void sphandler() {
	if (hero.lvl == 2) {
		cout << "You have " << hero.sp << " hero.sp\n\n" << specialattackmenu1 << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		cin >> action;
	}

	if (hero.lvl > 2) {
		cout << "You have " << hero.sp << " hero.sp\n\n" << specialattackmenu2 << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		cin >> action;
	}
	if (action == "3" && hero.sp >= 2) {

		hero.health = hero.fullh;
		hero.sp = hero.sp - 2;
		system("color f0");
		cout << hero.name << " is healing!\n\n" << hero.name << " now has " << hero.health << " health!\n\n" << endl;
		if (sound == true) {
			Beep(800, 220);
		}

	}

	else if (action == "3" && hero.sp <2) {
		cout << hero.name << " is attempting to heal, but failed because there is insufficient hero.sp!\n\n" << endl;
		if (sound == true) {
			Beep(800, 220);
			Beep(800, 220);
		}
	}

	else if (action == "1") {
		return;
	}

	else if (action == "2") {
		cout << hero.name << " did nothing\n" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
	}
	else if (action == "4" && hero.sp >= 4 && hero.lvl > 2) {
		hero.sp = hero.sp - 4;
		monsterhealth = monsterhealth - (damage * 2);
		system("color c");
		cout << hero.name << " is using a fireball!\n\n" << hero.name << " did " << damage << " damage\n\n" << monstername << "  now has " << monsterhealth << " left\n\n" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
	}

	else if (action == "4" && hero.lvl > 2 && hero.sp < 4) {
		cout << hero.name << " is attempting to use a fireball, but failed because there is insufficient hero.sp!\n\n" << endl;
		if (sound == true) {
			Beep(800, 220);
			Beep(800, 220);
		}
	}

	else {
		cout << "\n\nInvalid Input\n\n" << endl;
		if (sound == true) {
			Beep(800, 220);
			Beep(800, 220);
		}
		system("PAUSE");
		system("cls");
		sphandler();
	}





	return;
}


































void fightbasicmonster1() {
	int alert;
	enemydamage = monsterstrength / hero.defense;
	damage = hero.strength / monsterdef;
	turncheat = 1;
	while (hero.health > 0 && monsterhealth > 0) {
		enemydamage = monsterstrength / hero.defense;

		if (cocoapuffs > 0) {
			cout << "\n\nCoocoo for Cocoa Puffs for " << cocoapuffs << " extra turn(s); \n\n" << endl;

		}
		if (hero.lvl == 1 && itemmenu > 0) {
			cout << hero.name << ", what will you do?\n" << actionmenu4 << endl;
			if (sound == true) {
				Beep(800, 220);
			}
		}


		else if (hero.lvl == 1) {

			cout << hero.name << ", what will you do?\n" << actionmenu1 << endl;
			if (sound == true) {
				Beep(800, 220);
			}
		}



		else if (itemmenu > 0 && hero.lvl > 1) {
			cout << hero.name << ", what will you do?\n" << actionmenu3 << endl;
			if (sound == true) {
				Beep(800, 220);
			}
		}


		else if (hero.lvl > 1) {
			cout << hero.name << ", what will you do?\n" << actionmenu2 << endl;
			if (sound == true) {
				Beep(800, 220);
			}
		}

		cin >> action;
		system("cls");

		if (action == "3") {

			alert = MessageBox(NULL, "Are you sure you want to flee? If you do, you will gain no experience!", "Chickening out?", MB_YESNO | MB_ICONQUESTION);


			if (alert == IDYES && flee == true) {
				cout << hero.name << " is fleeing!\n\n The battle has ended.\n" << endl;
				if (sound == true) {
					Beep(800, 220);
					Beep(800, 220);
				}
				system("PAUSE");
				break;
			}

			else if (alert == IDYES && flee == false) {
				MessageBox(NULL, "Cannot flee from this battle :(", "Chickening out?", MB_OK | MB_ICONEXCLAMATION);
				continue;
			}

			else if (alert == IDNO) {
				continue;
			}



		}

		if (action == "1") {

			monsterhealth = monsterhealth - damage;

			if (monsterhealth >= 0) {
				cout << "You did " << damage << "!\n" << monstername << " now has " << monsterhealth << " health left\n" << endl;
			}
			else if (monsterhealth < 0) {
				cout << "You did " << damage << "!\n" << monstername << " now has 0 health left\n" << endl;
			}

			system("color fc");
			if (sound == true) {
				Beep(800, 220);
			}
			if (monsterhealth <= 0) {
				break;
			}
		}

		if (action == "2") {
			enemydamage = enemydamage / 2;
			system("color 9");
			cout << hero.name << " is defending!" << endl;
			if (sound == true) {
				Beep(800, 220);
			}
		}

		if (action == "4" && hero.lvl == 1) {

			cout << hero.name << " did nothing!\n" << endl;
			if (sound == true) {
				Beep(800, 220);
			}
			system("color 07");
		}


		if (action == "5") {
			cout << "\n************************************************************\n" << endl;
			if (sound == true) {
				Beep(800, 220);
			}
			cout << "STATS: \n\n" << hero.name << " level " << hero.lvl << "\n\nHealth: " << hero.health << "\nPower : " << hero.strength << "\nDefense : " << hero.defense << "\nhero.sp : " << hero.sp << "\nExperience : " << hero.xp << "\nCoins : " << money << endl << endl << "\nInventory; \n\n" << endl;
			if (item1has == 1) {
				cout << item1 << " (" << item1a << ")" << endl;
			}
			if (item2has == 1) {
				cout << item2 << " (" << item2a << ")" << endl;
			}
			if (item3has == 1) {
				cout << item3 << " (" << item3a << ")" << endl;
			}
			if (item4has == 1) {
				cout << item4 << " (" << item4a << ")" << endl;
			}
			if (item5has == 1) {
				cout << item5 << " (" << item5a << ")" << endl;
			}

			if (weapon == 1) {
				cout << "\nIron Sword (+5 power)" << endl;
			}
			if (weapon == 2) {
				cout << "\nBronze Sword (+10 power)" << endl;
			}
			cout << "\n\n" << endl;
			system("PAUSE");
			continue;
		}

		if (action == "4" && hero.lvl > 1) {
			sphandler();
			if (action == "1") {
				continue;
			}

		}
		if (action == "6" && itemmenu > 0) {
			itemhandler();
		}


		if ((action != "1" && action != "2" && action != "3" && action != "4" && action != "5" && itemmenu == 0) || (action != "1" && action != "2" && action != "3" && action != "4" && action != "5" && action != " 6" && itemmenu > 0))
		{
			system("cls");
			MessageBox(NULL, "Please enter a valid option!", "Invalid Input", MB_ICONWARNING);
			continue;
		}



		if (repeat == true) {
			repeat = false;
			continue;
		}
		if (twoturnsinrow == "on" && turncheat == 1) {
			turncheat = turncheat - 1;
			continue;
		}

		if (cocoapuffs > 0) {
			cocoapuffs = cocoapuffs - 1;
			continue;
		}


		srand((unsigned)time(0));
		com = (rand() % 6 + 1);

		turncheat = 1;
		damage = hero.strength / monsterdef;

		if (monsterheal == 0 || monsterhealth == monsterfullh) {
			com = (rand() % 5 + 1);
		}

		if (monsterdoesnothing == "on") {
			com = 3;
		}

		if (com == 1 || com == 2 || com == 3) {

			if (cheatinvincibility == "off") {

				hero.health = hero.health - enemydamage;
			}
			if (cheatinvincibility == "on") { enemydamage = 0; }
			if (hero.health >= 0) {
				cout << monstername << " is attacking\n " << monstername << " did " << enemydamage << "!\n You now have " << hero.health << " left" << endl;
			}
			else if (hero.health < 0) {
				cout << monstername << " is attacking\n" << monstername << " did " << enemydamage << "!\n You now have 0 left" << endl;
			}
			system("color c");


		}

		if (com == 4) {
			damage = damage / 2;
			cout << monstername << " is defending\n" << endl;
		}
		if (com == 5) {

			cout << monstername << " did nothing\n" << endl;
		}

		if (com == 6 && monsterheal >0 && monsterhealth < monsterfullh) {

			monsterhealth = monsterfullh;
			monsterheal = monsterheal - 1;
			cout << monstername << " is healing!\n" << monstername << " now has " << monsterhealth << "\n" << endl;
			system("color f0");
		}

	}



	if (hero.health <= 0) {
		system("color c0");
		cout << "You ran out of health!\n**********************************\n GAME OVER....\n**********************************************\n Please input anything or just close the game because you lost bro!" << endl;
		if (sound == true) {
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
			Beep(800, 220);
		}
		system("PAUSE");

	}
}














void tutorial() {
	system("cls");
	while (true) {
		system("cls");
		cout << "This game automatically saves all of your stats and progress. If you see a file called \"gamesave.dat\", this is your gamesave file. You probably won't be able to change the savegame, but don't try to cheat because I WILL FIND OUT! This program tracks where you live!" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		system("PAUSE");
		cout << "\nLOL just kidding, I don't know where you live, but this game can still detect a modified save file so DON'T THINK I'M STUPID JUST 'CAUSE I'M A COMPUTER, THAT'S RACIST!" << endl;
		if (sound == true) {
			Beep(800, 220);
		}
		system("pause");
		system("cls");
		if (sound == true) {
			Beep(800, 220);
		}
		cout << "When you get an action menu, input only the number, not the word. For example:\n**********************************************************************************\n You encountered practice!\n" << hero.name << ",what will you do?" << endl;
		cout << actionmenu1 << endl;
		cin >> action;
		if (action == "1" || action == "2" || action == "3" || action == "4" || action == "5") {
			cout << "Very good\n\n" << endl;
		}

		else {
			cout << "Try again. Type in a number from the list and press enter\n\n" << endl;
			if (sound == true) {
				Beep(800, 220);
				Beep(800, 220);
			}
			system("PAUSE");
			continue;

		}
		if (sound == true) {
			Beep(800, 220);
		}
		cout << "Occasionally, you will be asked yes or no questions (the way you were asked to do a tuturial) remember, do NOT type \"yes\" or \"no\". All yes or no questions will have \"y/n\" at the end. \nThis is the end of the tutorial. Would you like to repeat it? y/n" << endl;
		cin >> action;

		if (action == "n" || action == "N") {
			break;
			system("cls");
		}
	}
	cout << "You are ready!\n********************************" << endl; Beep(800, 220); system("PAUSE"); system("cls"); return;
}































































































int main() {
	system("title COMPUTERDOOM v1.0 beta 6");
	int alert;
	alert = MessageBox(NULL, "This will be the last iteration of COMPUTERDOOM betas on version 1.0. Version 1.0 will not be happening due to an exciting change. See \"FAQs\" in the main menu for more details.",
		"No more COMPUTERDOOM v1.0", MB_ICONASTERISK);

	MessageBox(NULL, "Sorry, I've given up on this game forever. Enjoy the memories from my Grade 8/Grade 9 coding times! :)", "No more new versions of COMPUTERDOOM", MB_ICONINFORMATION);

	if (alert == IDNO)
		exit(0);

start:
	mainmenu();
	if (savepending == true) {
		gamesavehandler();
		savepending = false;
		goto start;
	}
	gamesavehandler();
	if (save == No_auth) { goto start; }

	if (state == 0) {
		NULL;
	}

	else if (state == 1)
		goto state1;

	else if (state == 2)
		goto state2;

	else if (state == 3)
		goto state3;


	else {
		do {
			system("cls");
			alert = MessageBox(NULL, "An error occured while trying to configure checkpoints. This could be because of an invalid entry in the cheat menu or a corrupted savegame. The variable must be reset to 0 in order to avoid problems. You have the following options now:\n\nYou can abort loading the game and return to the main menu.\n\nYou can attempt to load this variable again.\n\nUnderstanding the risks (losing savegame, game glitching, etc.), you can ignore this error without fixing the problem (may cause unstability and bugs)", "We All Have Bad Days", MB_ICONERROR | MB_ABORTRETRYIGNORE);

			if (alert == IDABORT)
				goto start;

		} while (alert == IDRETRY);
	}
	if (sound == true) {
		Beep(800, 220);
	}
	cout << "Welcome brave hero! The computer world is in danger and has been invaded by many threats! You are the chosen one who can help us. Good luck!\n\n\n\n\n" << endl;
	cout << "What is your name hero?" << endl;
	cin.ignore(256, '\n');
	getline(cin, hero.name);

	if (save == Auto) {
		gamesavehandler();
	}

	cout << "\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
	}
	cout << "These are your current stats:\n\n" << hero.name << ": \n1vl " << hero.lvl << "\nhealth: " << hero.health << "\n defense: " << hero.defense << "\n power: " << hero.strength << "\n*******************************" << endl;
	system("PAUSE");
	alert = MessageBox(NULL, "Go through some important info about the game?", "Orientation", MB_ICONQUESTION | MB_YESNO);

	if (alert == IDYES) {
		tutorial();
	}


	monstername = "POPUPAD";
	action = "nothing";
	monsterfullh = 6;
	monsterdef = 2;
	monsterstrength = 4;
	monsterheal = 1;
	monsterhealth = monsterfullh;
	hero.health = hero.fullh;
	hero.sp = hero.spfull;

	system("cls");
	battle = 1;
	cout << "You encountered a POPUPAD!\n" << endl;
	if (sound == true) {
		Beep(800, 220);
	}
	system("PAUSE");

	chkinventorysob();
	fightbasicmonster1();
	chkinventoryeob();
	if (hero.health <= 0) {
		return 0;
	}
	system("cls");
	system("color f0");
	cout << "congratgulations! You've won your first battle\n*****************************************\nSTATS:\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
	}
	system("PAUSE");
	system("color 07");

	if (monsterhealth > 0)
		MessageBox(NULL, "No experience has been earned because you fled. Try not to flee next time because you may not be strong enough for the next enemy. If you flee you cannot earn experience to level up. Good luck!", "Results", MB_ICONASTERISK);


	if (monsterhealth <= 0) {
		leveluphandler();

		cout << "Here are your stats:\nlvl " << hero.lvl << "\n\n Health: " << hero.fullh << "\n defense: " << hero.defense << "\n power: " << hero.strength << "\n hero.sp: " << hero.spfull << "\nExperience: " << hero.xp << endl << endl << endl;
		system("PAUSE");

	}
	state = 1;

	if (save == Auto) {
		gamesavehandler();
	}

state1:

	midwaymenu();
	if (nuke == true) {
		nuke = false;
		goto start;
	}

	if (gotostate == true) {
		gotostate = false;
		goto start;

	}
	if (savepending == true) {
		gamesavehandler();
		savepending = false;
	}

	action == "nothing";
	monsterfullh = 11;
	monsterdef = 3;
	monsterstrength = 8;
	monsterheal = 3;
	monsterhealth = monsterfullh;
	hero.health = hero.fullh;
	hero.sp = hero.spfull;
	battle = 2;
	monstername = "EXCEPTION";
	cout << "You encountered an EXCEPTION" << endl;
	Beep(800, 220);
	chkinventorysob();
	fightbasicmonster1();
	chkinventoryeob();

	battleend();
	state = 2;
	if (save == Auto) {
		gamesavehandler();
	}
state2:
	system("cls");
	cout << "Careful! The next enemy will be way too difficult for you to beat. If only........ what the-?\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
	}
	system("PAUSE");
	cout << "\n\n\nLook! " << monstername << " dropped about 100 coins. If only there was a place where we could buy something to help us. Look over there! A shop!\n\n" << endl;
	if (sound == true) {
		Beep(800, 220);
	}
	system("pause");
	cout << "\nYou got 100 coins!\n" << endl;
	if (sound == true) {
		Beep(800, 220);
		Beep(800, 220);
		Beep(800, 220);
	}
	system("PAUSE");
	money = money + 100;
	itemstore();
	itemmenuparse();
	state = 3;
	if (save == Auto) {
		gamesavehandler();
	}
state3:
	midwaymenu();
	if (gotostate == true) {
		gotostate = false;
		goto start;
	}
	if (savepending == true) {
		gamesavehandler();
		savepending = false;
	}
	if (nuke == true) {
		nuke = false;
		goto start;
	}


	monstername = "BSoD";
	monsterhealth = 16;
	monsterfullh = 16;
	monsterstrength = 15;
	monsterdef = 4;
	monsterheal = 5;
	hero.health = hero.fullh;
	hero.sp = hero.spfull;
	flee = false;
	system("cls");
	battle = 3;
	cout << "You encountered a BSoD!\n" << endl;
	if (sound == true) {
		Beep(800, 220);
	}
	system("PAUSE");
	chkinventorysob();
	fightbasicmonster1();
	chkinventoryeob();
	battleend();
	system("cls");
	if (save == Auto) {
		gamesavehandler();
	}
	midwaymenu();
	if (gotostate == true) {
		gotostate = false;
		goto start;
	}
	if (nuke == true) {
		nuke = false;
		goto start;
	}
	system("cls");
	cout << "Uh Oh! This next enemy is going to be even harder than any enemy you've ever faced so far! This is it. The threat and annoyance that has been haunting humanity and the computer world for generations!\n" << endl;
	system("pause");
	cout << "\nThis is going to be difficult, so take 200 coins. I've served my purpose, you're on your own " << hero.name << " .Good luck!\n" << endl;
	system("pause");
	alert = MessageBox(NULL, "This is going to be intense! Would you like to go to the store to hero.spend your coins?", "You're gonna need more firepower", MB_YESNO | MB_ICONQUESTION);

	if (alert == IDYES) {
		itemstore();
	}

	monstername = "OSXYOSEMITE";
	monsterhealth = 25;
	monsterfullh = 25;
	monsterstrength = 20;
	monsterdef = 6;
	monsterheal = 6;
	hero.health = hero.fullh;
	hero.sp = hero.spfull;
	system("cls");
	cout << "You encountered OSXYOSEMITE" << endl;
	system("pause");
	chkinventorysob();
	fightbasicmonster1();
	chkinventoryeob();
	battleend();
	system("cls");
	endgame();
	if (save == Auto) {
		gamesavehandler();
	}
	midwaymenu();
	if (gotostate == true) {
		gotostate = false;
		goto start;
	}
	if (nuke == true) {
		nuke = false;
		goto start;
	}

	cout << "to be continued....\n\n\nYou can play the game from the beginning with your new stats, items, and magic just for fun!" << endl;
	if (sound == true)
		Beep(800, 220);

	system("pause");
}
