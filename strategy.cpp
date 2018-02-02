#include <iostream>
using namespace std;

class WeaponBehavior
{
public:
	void virtual useWeapon() = 0;
};

class AK47:public WeaponBehavior
{
public:
	void useWeapon()
	{
		cout << "Use AK47 to shoot!" << endl;
	}
};

class Knife:public WeaponBehavior
{
public:
	void useWeapon()
	{
		cout << "Use Knife to kill!" << endl;
	}
};

class Character
{
public:
	Character()
	{
		weapon = 0;
	}
	void setWeapon(WeaponBehavior &w)//引用或指针实现多态,这里用的引用
	{
		this->weapon = w;
	}
	void virtual fight() = 0;
protected:
	WeaponBehavior *weapon;
};

class King:public Character
{
public:
	void fight()
	{
		cout << "The king:" ;
		if ( this->weapon == NULL)
		{
			cout << "You don't have a weapon! Please Set Weapon!" << endl;
		}
		else
		{ 
			weapon->useWeapon();
		}
	}
};
int main()
{    
	AK47  ak47 ;
	Knife knife;     

	Character *kin = new King();      

	kin->fight();   
	cout << endl; 

	kin->setWeapon(ak47);
	kin->fight();
	cout << endl;

	kin->setWeapon(knife);
	kin->fight();

	return 0;
}
