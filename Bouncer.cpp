#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;
//AllClass
class Character {
	
public:
	char Name[50];
	int Health;
	int Damage;
	int Money;
	void Character::MyCharacterBegin();
}MyCharacter;
void Character::MyCharacterBegin() {
	cout << "Welcome!\n"<< "What is your name ?\n"<< "Player name: ";
	cin  >> Name;
	Health = 7;
	Damage = 1;
	Money  = 0;
	system("cls");
	cout << Name << "? " << "Good name\n"
		<< Name << ", in this game you have such initial characteristics:\n"
		<< "Health -> " << Health << endl
		<< "Damage -> " << Damage << endl
		<< "Money  -> " << Money << endl;
	system("pause");
}

class Enemy {
	public:	
	char NameEnm[9][10] = {"Koleree","Tharitas","Zenil","Detheli","Xan","Fflersta","Ynanah","Dlilolany","Xyonireyn"};
	int Health;
	int Damage;
	char Name[10];
	void Enemy::CHEnemy(int num);
	}AllEnemy[9];
void Enemy::CHEnemy(int num) {
	strcpy(Name, NameEnm[num]); 
	Health = (num+num)+(4+num) ;
	Damage = (num + num) + 1;
	}

class Weapons {
private:
 const char HName[5][10] = {"HW 1","HW 2","HW 3","HW 4","HW 5"};
 const char DName[5][10] = {"DW 1","DW 2","DW 3","DW 4","DW 5"};
 const int Hint[5] = {3,6,8,11,16};
 const int Dint[5] = {2,4,6,8,10};
public:
 char Name[10];
 int WHealth;
 int WDamage;
 void Weapons::HF_Weapons(int Hnum);
 void Weapons::DF_Weapons(int Dnum);
}HWeapons[5], DWeapons[5];
void Weapons::HF_Weapons(int Hnum) {
	 strcpy(HWeapons[Hnum].Name, HName[Hnum]);
	 WHealth = Hint[Hnum];
}
void Weapons::DF_Weapons(int Dnum) {
	strcpy(DWeapons[Dnum].Name, DName[Dnum]);
	WDamage = Dint[Dnum];
}
//AllClass

//HUD
void HUD_Warning();
void HUD_Program        ();
void HUD_Main_Menu      (int NumLocation);
void HUD_Exit           ();
void HUD_Entry_Field    ();
void HUD_The_Battle     (int health, int damage, int HealthCh);
void HUD_Hunting        (int a);
void HUD_Shop_Menu_1    ();
void HUD_Shop_Menu_2    (int a);
void HUD_Location       (int NumLocation);
void HUD_end_batlle     ();
void HUD_off_end_batlle ();
void HUD_Shop_Yes();
void HUD_Shop_No();
//HUD

void Shop_B(int a, int b);
void Shop_B_H(int a, int b);
void Shop_B_D(int a, int b);

//global var;
char Location[3][10] = { "Gati","Stagrad","Traket" };

//global var;

int main() {
	int Health;
	int Damage;
	int NumLocation=1;
	int GameNum = 1;
	// Begin/
	HUD_Warning();
	MyCharacter.MyCharacterBegin(); //Begin Game
	for (int iEnemy = 0; iEnemy < 9; iEnemy++) { //Begin enemy
	AllEnemy[iEnemy].CHEnemy(iEnemy);
	}
	for (int iWeapons = 0; iWeapons < 9; iWeapons++) { //Begin Weapons
		HWeapons[iWeapons].HF_Weapons(iWeapons);
		DWeapons[iWeapons].DF_Weapons(iWeapons);
	}
	system("cls");
	// End/ 
	game:
	switch (GameNum)
	{
	case 1:
		//Main_Menu
	Menu:
		GameNum = 1;
		HUD_Program();
		HUD_Main_Menu(NumLocation);
		HUD_Exit();
		HUD_Entry_Field();
		cin >> GameNum;
		if (GameNum!=1&&GameNum != 2&&GameNum != 3&&GameNum!=9) { system("cls"); goto Menu; }
		if (GameNum==9) { return 0; }
		switch (GameNum)
		{
		case 1:
			GameNum = 5 ;
			break;
		case 2:
			GameNum = 6 ;
			break;
		case 3:
			GameNum = 2 ;
			break;
		}
		system("cls");
		goto game;
		break;

	case 2:
		//Shop1
	Shop1:
		C2:
		HUD_Program();
		HUD_Shop_Menu_1();
		HUD_Exit();
		HUD_Entry_Field();
		cin >> GameNum;
		if (GameNum != 1 && GameNum != 2 && GameNum != 3 && GameNum != 9) { system("cls"); goto C2; }
		if (GameNum == 9) { return 0; }
		if (GameNum == 3) { system("cls");	goto Menu; }
		system("cls"); 
		goto Shop2;
		break;

	case 3:
		//Shop2
	Shop2:
		int Num2;
		Num2 = GameNum;
		HUD_Program();
		HUD_Shop_Menu_2(Num2);
		HUD_Exit();
		HUD_Entry_Field();
		cin >> GameNum;
		if (GameNum != 1 && GameNum != 2 && GameNum != 3 && GameNum != 4 && GameNum != 5 && GameNum != 6 && GameNum != 9) { system("cls"); goto Shop2; }
		if (GameNum == 9) { return 0; }
		if (GameNum == 6) { system("cls"); goto Shop1; }
		Shop_B(Num2,GameNum);
		system("cls");
		goto Menu;
		break;

	case 4:
		//Battle
	batll:
		int HealthCh;
		HealthCh=MyCharacter.Health;
	batll2:
		C4:
		HUD_Program();
		HUD_The_Battle(Health,Damage, HealthCh);
		HUD_Exit();
		HUD_Entry_Field();
		cin >> GameNum;
		if (GameNum != 1 && GameNum != 2 && GameNum != 9) { system("cls"); goto C4; }
		if (GameNum == 9) { return 0; }
		if (GameNum == 2) { system("cls"); goto Menu; }
		if (GameNum == 1) {
			Health = Health - MyCharacter.Damage;			
		 	if (Health <= 0) {
				system("cls");
				HUD_Program();
				HUD_end_batlle();
				system("cls");
				goto Menu;
		} 
			HealthCh = HealthCh - Damage;
			if (HealthCh <= 0) {
				system("cls");
				HUD_Program();
				HUD_off_end_batlle();
				system("cls");
				goto Menu;
		}			
	} 
		system("cls");
		goto batll2;
		break;

	case 5:
		//Hunting
		C5:
		HUD_Program();
		HUD_Hunting(NumLocation);
		HUD_Exit();
		HUD_Entry_Field();
		cin >> GameNum;
		if (GameNum != 1 && GameNum != 2 && GameNum != 3 && GameNum != 4 && GameNum != 9) { system("cls"); goto C5; }
		if (GameNum == 9) { return 0; }
		if (GameNum == 4) { system("cls"); goto Menu; }
		switch (NumLocation)
		{
		case 1:
			if (GameNum == 1) { Health = AllEnemy[0].Health; Damage = AllEnemy[0].Damage; }
			if (GameNum == 2) { Health = AllEnemy[1].Health; Damage = AllEnemy[1].Damage; }
			if (GameNum == 3) { Health = AllEnemy[1].Health; Damage = AllEnemy[2].Damage; }
			break;
		case 2:
			if (GameNum == 1) { Health = AllEnemy[3].Health; Damage = AllEnemy[3].Damage; }
			if (GameNum == 2) { Health = AllEnemy[4].Health; Damage = AllEnemy[4].Damage; }
			if (GameNum == 3) { Health = AllEnemy[5].Health; Damage = AllEnemy[5].Damage; }
			break;
		case 3:
			if (GameNum == 1) { Health = AllEnemy[6].Health; Damage = AllEnemy[6].Damage; }
			if (GameNum == 2) { Health = AllEnemy[7].Health; Damage = AllEnemy[7].Damage; }
			if (GameNum == 3) { Health = AllEnemy[8].Health; Damage = AllEnemy[8].Damage; }
			break;
		}
		system("cls");
		goto batll;
		break;

	case 6:
		//location
		C6:
		HUD_Program();
		HUD_Location(NumLocation);
		HUD_Exit();
		HUD_Entry_Field();
		cin >> GameNum;
		if (GameNum != 1 && GameNum != 2 && GameNum != 3 && GameNum != 9) { system("cls"); goto C6; }
		if (GameNum == 9) { return 0; }
		if (GameNum == 3) { system("cls"); goto Menu; }
		switch (NumLocation)
		{
		case 1:
			if (GameNum == 1) { NumLocation = 2; }
			if (GameNum == 2) { NumLocation = 3; }
			break;
		case 2:
			if (GameNum == 1) { NumLocation = 1; }
			if (GameNum == 2) { NumLocation = 3; }
			break;
		case 3:
			if (GameNum == 1) { NumLocation = 1; }
			if (GameNum == 2) { NumLocation = 2; }
			break;
		}

		system("cls");
		goto Menu;
		break;

	}
	system("pause");
	ExitGame:
	return 0;
}

//HUD
void HUD_Warning() {
	cout << "A warning!\n" << "1. If the input from 0 to 9 is erroneous, then the program will crash and your computer will break.\n"
		<< "2. The alias must be without spaces.\n";
	system("pause");
	system("cls");
	cout << "And the alias should be no more than 50 characters :3\n";
	system("pause");
	system("cls");
}
void HUD_Program     () {
	cout << "-**** Ver.1                      -\n"
		 << "-*** Game: FS_G_Bouncer          -\n"
		 << "-** Programming language: C++    -\n"
		 << "-* Author: FromSi                -\n"
	     << "----------------------------------\n\n";

}
void HUD_Main_Menu   (int NumLocation){
	cout << "----------------------------------\n"
		 << "- Name:     " << MyCharacter.Name   << endl
		 << "- Health:   " << MyCharacter.Health << endl
	     << "- Damage:   " << MyCharacter.Damage << endl
		 << "- Money:    " << MyCharacter.Money  << endl
		 << "----------------------------------\n"
		 << "- Location: " << Location[NumLocation-1] << endl
		 << "----------------------------------\n"
		 << "- [1] Hunting\n"
		 << "- [2] Change of location\n"
		 << "- [3] Shop\n"
		 << "----------------------------------\n";
}
void HUD_Exit        () {
	cout << "- [9] Exit\n"
		 << "----------------------------------\n";
}
void HUD_Entry_Field () {
		cout << "----------------------------------\n"
			 << "- Entry field:  ";
}
void HUD_The_Battle(int health, int damage, int HealthCh) {
	cout << "----------------------------------\n"
		 << "- Name:    " << MyCharacter.Name << endl
		 << "- Health:  " << HealthCh << endl
		 << "- Damage:  " << MyCharacter.Damage << endl
		 << "---------------------------------\n"
		 << "---------------------------------\n"
		 << "- Enemy    " << endl
		 << "- Health:  " << health << endl
		 << "- Damage:  " << damage << endl
		 << "---------------------------------\n"
		 << "---------------------------------\n"
		 << "- [1] Make damage\n"
		 << "- [2] Return to main menu\n"
		 << "---------------------------------\n";
}
void HUD_Hunting     (int a) {
	cout << "---------------------------------\n";
	cout << "- [1] ";
	switch (a)
	{
	case 1:
	   
		cout << AllEnemy[0].NameEnm[0] 
			<< "   " 
			<< "Health: " 
			<< AllEnemy[0].Health 
			<< " " 
			<< "Damage:" 
			<< AllEnemy[0].Damage 
			<< endl;
		break;
	case 2:
	   cout << AllEnemy[3].NameEnm[3] 
			<< "  " 
			<< "Health: " 
			<< AllEnemy[3].Health 
			<< " " 
			<< "Damage:" 
			<< AllEnemy[3].Damage 
			<< endl;
		break;
	case 3:
	   cout << AllEnemy[6].NameEnm[6] 
			<< "    " 
			<< "Health: " 
			<< AllEnemy[6].Health 
			<< " " 
			<< "Damage:" 
			<< AllEnemy[6].Damage 
			<< endl;
		break;
	}
	cout << "- [2] ";
	switch (a)
	{
	case 1:
	   cout << AllEnemy[1].NameEnm[1] 
			<< "  " 
			<< "Health: " 
			<< AllEnemy[1].Health 
			<< " " 
			<< "Damage:" 
			<< AllEnemy[1].Damage 
			<< endl;
		break;
	case 2:
       cout << AllEnemy[4].NameEnm[4] 
			<< "      " 
			<< "Health: " 
			<< AllEnemy[4].Health 
			<< " " 
			<< "Damage:" 
			<< AllEnemy[4].Damage 
			<< endl;
		break;
	case 3:
	   cout << AllEnemy[7].NameEnm[7] 
			<< " " 
			<< "Health: " 
			<< AllEnemy[7].Health 
			<< " " 
			<< "Damage:" 
			<< AllEnemy[7].Damage 
			<< endl;
		break;
	}
	cout << "- [3] ";
	switch (a)
	{
	case 1:
	   cout << AllEnemy[2].NameEnm[2] 
			<< "     " 
			<< "Health: " 
			<< AllEnemy[1].Health 
			<< " " 
			<< "Damage:" 
			<< AllEnemy[2].Damage 
			<< endl;
		break;
	case 2:
	   cout << AllEnemy[5].NameEnm[5] 
			<< " " 
			<< "Health: " 
			<< AllEnemy[5].Health 
			<< " " 
			<< "Damage:" 
			<< AllEnemy[5].Damage 
			<< endl;
		break;
	case 3:
	   cout << AllEnemy[8].NameEnm[8] 
			<< " " 
			<< "Health: " 
			<< AllEnemy[8].Health 
			<< " " 
			<< "Damage:" 
			<< AllEnemy[8].Damage 
			<< endl;
		break;
	}
	cout << "---------------------------------\n"
		<< "- [4] Return to main menu\n";

}
void HUD_Shop_Menu_1 () {
    cout << "----------------------------------\n"
  		 << "- Shop\n"
		 << "- Money:   " << MyCharacter.Money << endl
		 << "---------------------------------\n"
		 << "- [1] Health\n"
		 << "- [2] Damage\n"
		 << "---------------------------------\n"
		 << "- [3] Return to main menu\n"
		 << "---------------------------------\n";

}
void HUD_Shop_Menu_2 (int a) {
	const char NameW[2][10] = { "Health","Damage" };
	const int Money[5] = { 1,2,4,6,8 };
	const int HD[5] = {3,6,9,14,20};
	char ShopName[10][10] = { "H_Dr1","H_Dr2","H_Dr3","H_Dr4","H_Dr5","D_Dr1","D_Dr2","D_Dr3","D_Dr4","D_Dr5" };
	cout << "----------------------------------\n"
		 << "- Shop\n"
		 << "- Money:    " 
		<< MyCharacter.Money 
		<< endl
		 << "---------------------------------\n"
		 << "- [1] Name: " << ShopName[1*a]                               << endl
		 << "- "           << NameW[a-1]		 <<":   " << HD[0]        << endl
		 << "- Cost:     " << Money[0]                                    << endl
	     << "---------------------------------\n"
		 << "- [2] Name: " << ShopName[2*a]								  << endl
		 << "- "           << NameW[a - 1]		 <<":   " << HD[1]		  << endl
		 << "- Cost:     " << Money[1]								      << endl
		 << "---------------------------------\n"
		 << "- [3] Name: " << ShopName[3*a]								  << endl
		 << "- "           << NameW[a - 1]		 <<":   " << HD[2]        << endl
		 << "- Cost:     " << Money[2]									  << endl
		 << "---------------------------------\n"
		 << "- [4] Name: " << ShopName[4*a]								  << endl
		 <<	"- "           << NameW[a - 1]       <<":   " << HD[3]        << endl
		 << "- Cost:     " << Money[3]									  << endl
		 << "---------------------------------\n"
		 << "- [5] Name: " << ShopName[5*a]								  << endl
		 << "- "           << NameW[a - 1]       <<":   " << HD[4]	      << endl
		 << "- Cost:     " << Money[4]								      << endl
		 << "---------------------------------\n"
		 << "---------------------------------\n"
		 << "- [6] Back\n"
		 << "---------------------------------\n";
}
void HUD_Location    (int NumLocation) {
	int num[3];
	switch (NumLocation)
	{
	case 1:
		num[0] = 1;
		num[1] = 2;
		num[2] = 0;
		break;
	case 2:
		num[0] = 0;
		num[1] = 2;
		num[2] = 1;
		break;
	case 3:
		num[0] = 0;
		num[1] = 1;
		num[2] = 2;
		break;
	}
	cout << "- Location: " << Location[num[2]] << endl
		 << "----------------------------------\n"
		 << "- [1] " << Location[num[0]] << endl
		 << "- [2] " << Location[num[1]] << endl
		 << "----------------------------------\n"
		 << "- [3] Return to main menu\n";
}
void HUD_end_batlle  () {
	cout << "----------------------------------\n"
		<< "- You killed the enemy\n"
		<< "- Money +1\n"
		<< "-----------------------------------\n";
	MyCharacter.Money++;
	system("pause");
}
void HUD_off_end_batlle() {
	cout << "----------------------------------\n"
		<< "- You lose!\n"
		<< "-----------------------------------\n";
	system("pause");
}
void HUD_Shop_Yes() {
	cout << "----------------------------------\n"
		<< "- Successful purchase\n"
		<< "----------------------------------\n";
	system("pause");
}
void HUD_Shop_No() {
	cout << "----------------------------------\n"
		<< "- Not enough money\n"
		<< "----------------------------------\n";
	system("pause");
}
//HUD

//Logical functions
void Shop_B(int a, int b) {
	if (a==1) {
		switch (b)
		{
		case 1:
			if (MyCharacter.Money >= 1) {
				Shop_B_H(3,1);
				system("cls");
				HUD_Program();
				HUD_Shop_Yes();
			}
			else { system("cls"); HUD_Program(); HUD_Shop_No(); }
			break;
		case 2:
			if (MyCharacter.Money >= 2) {
				Shop_B_H(6,2);
				system("cls");
				HUD_Program();
				HUD_Shop_Yes();
		}
	else { system("cls"); HUD_Program(); HUD_Shop_No(); }
			break;
		case 3:
			if (MyCharacter.Money >= 4) {
				Shop_B_H(9,4);
				system("cls");
				HUD_Program();
				HUD_Shop_Yes();
	}
	else { system("cls"); HUD_Program(); HUD_Shop_No(); }
			break;
		case 4:
			if (MyCharacter.Money >= 6) {
				Shop_B_H(14,6);
				system("cls");
				HUD_Program();
				HUD_Shop_Yes();
}
			else { system("cls"); HUD_Program(); HUD_Shop_No(); }
			break;
		case 5:
			if (MyCharacter.Money >= 8) {
				Shop_B_H(20,8);
				system("cls");
				HUD_Program();
				HUD_Shop_Yes();
						}
			else { system("cls"); HUD_Program(); HUD_Shop_No(); }
			break;
		}
	}
	if (a == 2) {
		switch (b)
		{
		case 1:
			if (MyCharacter.Money >= 1) {
				Shop_B_D(3,1);
				system("cls");
				HUD_Program();
				HUD_Shop_Yes();
		}
	else { system("cls"); HUD_Program(); HUD_Shop_No(); }
			break;
		case 2:
			if (MyCharacter.Money >= 2) {
				Shop_B_D(6,2);
				system("cls");
				HUD_Program();
				HUD_Shop_Yes();
	}
	else { system("cls"); HUD_Program(); HUD_Shop_No(); }
			break;
		case 3:
			if (MyCharacter.Money >= 4) {
				Shop_B_D(9,4);
				system("cls");
				HUD_Program();
				HUD_Shop_Yes();
						}
			else { system("cls"); HUD_Program(); HUD_Shop_No(); }
			break;
		case 4:
			if (MyCharacter.Money >= 6) {
				Shop_B_D(14,6);
				system("cls");
				HUD_Program();
				HUD_Shop_Yes();
						}
			else { system("cls"); HUD_Program(); HUD_Shop_No(); }
			break;
		case 5:
			if (MyCharacter.Money >= 8) {
				Shop_B_D(20,8);
				system("cls");
				HUD_Program();
				HUD_Shop_Yes();
						}
			else { system("cls"); HUD_Program(); HUD_Shop_No(); }
			break;
		}
	}
}
void Shop_B_H (int a, int b) {
	MyCharacter.Health = 7;
	MyCharacter.Health = MyCharacter.Health + a;
	MyCharacter.Money = MyCharacter.Money - b;
	system("cls");
}
void Shop_B_D(int a, int b) {
	MyCharacter.Damage = 1;
	MyCharacter.Damage = MyCharacter.Damage + a;
	MyCharacter.Money = MyCharacter.Money - b;
	system("cls");
}