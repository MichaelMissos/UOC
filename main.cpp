# Final CPP

#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <math.h> 

class BankAccount{
private:
	std::string name;
	std::string surname;
  double balance;
public:
  BankAccount(std::string name , std::string surname, double balance):name (name),surname(surname),balance(0) {}
  
  
	double getBalance() { return balance; }

  virtual void deposit(double x)  { balance += x; }
  bool transfer(BankAccount & bankaccount, double x)  { if (x>balance){
    return false;
  }
    balance-=x;
    bankaccount.balance+=x;
    return true;
    }
};

class BonusAccount : public BankAccount{
private:
	std::string name;
	std::string surname;
  double balance;
  double bonus;
public:
  BonusAccount(std::string name , std::string surname, double balance, float bonus): BankAccount(name , surname, balance), bonus(bonus) {}
	double getBalance() { return balance; }

  virtual  void deposit(double x)  { BankAccount::deposit(x);
    printf("%lf",bonus);//get the deposit of a normal account
		balance= balance+bonus*x;				//also get the bonusaccount bonus
	}

  bool transfer(BonusAccount & bonusaccount, double x)  { if (x>balance){
    return false;
  }
    balance-=x;
    bonusaccount.balance+=x;
    return true;
    }


};

int main() {
	BankAccount bankaccount1("Giorgos", "Papadakis", 0), bankaccount2("Maria", "Markaki", 0);
	BonusAccount bonusaccount("Manos", "Papadopoulos", 0, 0.5);
	BankAccount* accounts[3] = {&bankaccount1, &bankaccount2, &bonusaccount};

	for (int i = 0; i < 3; ++i) {
		printf("Account[%d] balance before deposit: ", i);
		printf("%lf",accounts[i]->getBalance());
		printf("\n");
		accounts[i]->deposit(100);	//100 deposit
		printf("Personel[%d] after deposit: ", i);
		printf("%lf",accounts[i]->getBalance());
		printf("\n");
    accounts[i]->transfer(*accounts[i],50);
    printf("Money now?");
    printf("%lf",accounts[i]->getBalance());
		printf("\n");
	}
	
	return 0;
}

