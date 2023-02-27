#include "bank.h"

#include <iostream>

bool Account::validate(int amount, std::string currency) {
  if (amount > this->amount_) {
    std::cerr << "No funds" << std::endl;
    return false;
  }
  if (currency != this->currency_) {
    std::cerr << "Wrong currency" << std::endl;
    return false;
  }
  return true;
}

void Account::print() {
  std::cout << this->name_ << " " << this->amount_ << " " << this->currency_
            << std::endl;
}
//-------------------------------------------------------/
Check* Account::take(int amount, std::string currency) {
  if (!validate(amount, currency)) {
    return 0;
  }
  this->amount_ -= amount;
  return new check(amount, currency, true);
}

bool Account::put(int amount, std::string currency, Check) {
  if (currency != this->currency_) {
    return false;
  }
  if(Check::check.flag == true;){
    this->amount_ += amount;
    Check::check.flag = false;
  }
  return true;
}
//--------------------------------------------------------------------------/
Account* Bank::create(std::string name) { return new RUBAccount(100, name); }

Account* Bank::createPremium(std::string name) {
  return new RUBAccountWithOverdraft(100, name, 50);
}

bool RUBAccountWithOverdraft::validate(int amount, std::string currency) {
  if (amount - this->amount_ > _limit) {
    std::cerr << "No funds" << std::endl;
    return false;
  }
  if (currency != this->currency_) {
    std::cerr << "Wrong currency" << std::endl;
    return false;
  }
  return true;
}
