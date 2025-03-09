interface Depositable {
  void deposit(int amount);
}

class Account {
  String name;
  int accoutNo;
  int balance;
}

// Savings Account
class exp09_1 extends Account implements Depositable {
  exp09_1(String n, int accNo) {
    name = n;
    accoutNo = accNo;
  }

  public void deposit(int amount) {
    balance += amount;
  }

  public void display() {
    System.out.println("Name: " + name);
    System.out.println("Account No: " + accoutNo);
    System.out.println("Balance: " + balance);
  }

  public static void main(String args[]) {
    exp09_1 acc = new exp09_1("Student", 250);
    acc.deposit(5000);
    acc.deposit(2000);
    acc.display();
  }
}


