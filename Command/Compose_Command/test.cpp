#include <Command.h>

int main() {
  BankAccount xiaoMing{}, daMing{};
  BankAccountCommand bigBroWithdraw(daMing, BankAccountCommand::Action::kWithdraw, 100);
  BankAccountCommand littleBroDeposit(xiaoMing, BankAccountCommand::Action::kDeposit, 100);
  //bigBroWithdraw.call();
  //littleBroDeposit.call();
  //哥哥大明给弟弟小明一百块，如果哥哥给小明600就不行了，最多允许透支500
  ComposeBankAccountCommand transfer({bigBroWithdraw, littleBroDeposit});
  transfer.call();
  return 0;
}
