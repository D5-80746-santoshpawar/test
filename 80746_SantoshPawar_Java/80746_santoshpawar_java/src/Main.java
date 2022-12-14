
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        AccountHolderDetailsDAO accountHolderDetailsDAO = new AccountHolderDetailsDAO();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Menu:");
            System.out.println("1. Add new Account Holder Details");
            System.out.println("2. Display all Account Holder Details");
            System.out.println("3. Edit name and birthdate");
            System.out.println("4. Display Account Holder Details for given account type");
            System.out.println("5. Delete Account Holder Details for given account number");
            System.out.println("6. Display account type wise total number of Account Holders");
            System.out.println("7. Sort by Account balance");
            System.out.println("8. Exit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline character

            switch (choice) {
                case 1:
                    // Add new Account Holder Details
                    System.out.print("Enter name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter email: ");
                    String email = scanner.nextLine();
                    System.out.print("Enter birthdate (yyyy-mm-dd): ");
                    String birthdate = scanner.nextLine();
                    System.out.print("Enter balance: ");
                    double balance = scanner.nextDouble();
                    System.out.print("Enter account type ID: ");
                    int accTypeId = scanner.nextInt();

                    AccountHolderDetails newAccountHolder = new AccountHolderDetails(name, email, birthdate, balance, accTypeId);
                    accountHolderDetailsDAO.addAccountHolder(newAccountHolder);
                    System.out.println("Account Holder Details added successfully.");
                    break;

                case 2:
                    // Display all Account Holder Details
                    List<AccountHolderDetails> accountHolders = accountHolderDetailsDAO.getAllAccountHolders();
                    for (AccountHolderDetails accountHolder : accountHolders) {
                        System.out.println(accountHolder);
                    }
                    break;

                case 3:
                    // Edit name and birthdate
                    System.out.print("Enter account number to edit: ");
                    int accNo = scanner.nextInt();
                    scanner.nextLine(); // Consume newline character
                    System.out.print("Enter new name: ");
                    String newName = scanner.nextLine();
                    System.out.print("Enter new birthdate (yyyy-mm-dd): ");
                    String newBirthdate = scanner.nextLine();
                    accountHolderDetailsDAO.editAccountHolder(accNo, newName, newBirthdate);
                    System.out.println("Account Holder Details updated successfully.");
                    break;

                case 4:
                    // Display Account Holder Details for given account type
                    System.out.print("Enter account type ID: ");
                    int typeId = scanner.nextInt();
                    List<AccountHolderDetails> accountHoldersByType = accountHolderDetailsDAO.getAccountHoldersByType(typeId);
                    for (AccountHolderDetails accountHolder : accountHoldersByType) {
                        System.out.println(accountHolder);
                    }
                    break;

                case 5:
                    // Delete Account Holder Details for given account number
                    System.out.print("Enter account number to delete: ");
                    int deleteAccNo = scanner.nextInt();
                    accountHolderDetailsDAO.deleteAccountHolder(deleteAccNo);
                    System.out.println("Account Holder Details deleted successfully.");
                    break;

                case 6:
                    // Display account type wise total number of Account Holders
                    accountHolderDetailsDAO.displayAccountTypeWiseCount();
                    break;

                case 7:
                    // Sort by Account balance
                    accountHolderDetailsDAO.sortAccountHoldersByBalance();
                    break;

                case 8:
                    // Exit the program
                    System.out.println("Exiting program...");
                    System.exit(0);
                    break;

                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
