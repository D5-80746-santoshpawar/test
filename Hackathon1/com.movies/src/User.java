
import java.util.Date;
import java.util.Scanner;

public class User {
    private int userId;
    private String fName;
    private String lName;
    private String eMail;
    private String password;
    private String mobileNum;
    private Date birthDate;

    public User() {
    }

    public User(int userId, String fName, String lName, String eMail, String password, String mobileNum, Date birthDate) {
        this.userId = userId;
        this.fName = fName;
        this.lName = lName;
        this.eMail = eMail;
        this.password = password;
        this.mobileNum = mobileNum;
        this.birthDate = birthDate;
    }

    public int getUserId() {
        return userId;
    }

    public void setUserId(int userId) {
        this.userId = userId;
    }

    public String getfName() {
        return fName;
    }

    public void setfName(String fName) {
        this.fName = fName;
    }

    public String getlName() {
        return lName;
    }

    public void setlName(String lName) {
        this.lName = lName;
    }

    public String geteMail() {
        return eMail;
    }

    public void seteMail(String eMail) {
        this.eMail = eMail;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getMobileNum() {
        return mobileNum;
    }

    public void setMobileNum(String mobileNum) {
        this.mobileNum = mobileNum;
    }

    public Date getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(Date birthDate) {
        this.birthDate = birthDate;
    }

    @Override
    public String toString() {
        return "User{" +
                "userId=" + userId +
                ", fName='" + fName + '\'' +
                ", lName='" + lName + '\'' +
                ", eMail='" + eMail + '\'' +
                ", password='" + password + '\'' +
                ", mobileNum='" + mobileNum + '\'' +
                ", birthDate=" + birthDate +
                '}';
    }
   /* public void acceptData(Scanner sc){
        sc = new Scanner(System.in);
        System.out.println("Enter first name:");
        fName = sc.next();
        System.out.println("Enter last name:");
        lName = sc.next();
        System.out.println("Enter email:");
        fName = sc.next();



    }*/
}
