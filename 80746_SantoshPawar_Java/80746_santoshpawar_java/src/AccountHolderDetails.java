


public class AccountHolderDetails {
    private int accNo;
    private String name;
    private String email;
    private String birthdate;
    private double balance;
    private int accTypeId;

    // Constructors
    public AccountHolderDetails() {
    }

    public AccountHolderDetails(String name, String email, String birthdate, double balance, int accTypeId) {
        this.name = name;
        this.email = email;
        this.birthdate = birthdate;
        this.balance = balance;
        this.accTypeId = accTypeId;
    }

    // Getters and setters
    public int getAccNo() {
        return accNo;
    }

    public void setAccNo(int accNo) {
        this.accNo = accNo;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getBirthdate() {
        return birthdate;
    }

    public void setBirthdate(String birthdate) {
        this.birthdate = birthdate;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public int getAccTypeId() {
        return accTypeId;
    }

    public void setAccTypeId(int accTypeId) {
        this.accTypeId = accTypeId;
    }

    // toString() method for object representation
    @Override
    public String toString() {
        return "AccountHolderDetails{" +
                "accNo=" + accNo +
                ", name='" + name + '\'' +
                ", email='" + email + '\'' +
                ", birthdate='" + birthdate + '\'' +
                ", balance=" + balance +
                ", accTypeId=" + accTypeId +
                '}';
    }
}

