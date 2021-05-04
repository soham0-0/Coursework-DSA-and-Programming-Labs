public class p1_minimum_balance_exception {
    public static void main(String[] args) {
        BankAccount account_1 = new BankAccount("Account1");
        try {
            account_1.showBalance();
            account_1.withdraw(100);
        } catch (LessThanMinumumException e) {
            System.out.println("Error: " + e);
        } finally {
            account_1.showBalance();
        }

        System.out.println();
        BankAccount account_2 = new BankAccount("Account2");
        try {
            account_2.showBalance();
            account_2.withdraw(5000);
        } catch (LessThanMinumumException e) {
            System.out.println("Error: " + e);
        } finally {
            account_2.showBalance();
        }
    }
}

class LessThanMinumumException extends Exception {
    public String toString() {
        return "Remaining balance less than Rs. 1000/-";
    }
}

class BankAccount {
    private double balance;
    private String holdername;

    BankAccount(String name) {
        this.holdername = name;
        this.balance = (Math.random() * 2500) + 1000;
    }

    void showBalance() {
        System.out.println(this.holdername + " Bank Balance: " + this.balance);
    }

    void withdraw(double amount) throws LessThanMinumumException {
        if (this.balance - amount < 1000) {
            throw new LessThanMinumumException();
        } else {
            this.balance -= amount;
            System.out.println("Withdrawn " + amount);
        }
    }
}
