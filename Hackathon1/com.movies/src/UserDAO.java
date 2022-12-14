import java.sql.*;
import java.util.*;
public class UserDAO extends DAO{
    public UserDAO() throws Exception{
    }

    public int saveUser(User u) throws Exception{
        String sql = "INSERT INTO users VALUES(default, ?, ?, ?, ?, ?, ?)";
        try(PreparedStatement stmt = con.prepareStatement(sql)) {
            stmt.setString(1, u.getfName());
            stmt.setString(2, u.getlName());
            stmt.setString(3, u.geteMail());
            stmt.setString(4, u.getPassword());
            stmt.setString(3, u.getMobileNum());
            stmt.setDate(5, DateUtil.utilToSqlDate(u.getBirthDate()));
            int count = stmt.executeUpdate();
            return count;
        }

    }

    public int updateUser(User u) throws Exception{
        Scanner sc = new Scanner(System.in);
        String sql = "UPDATE users SET first_name = ?, last_name = ?, email = ?" +
                "mobile = ?, birth = ? WHERE id = ?";
        try(PreparedStatement stmt = con.prepareStatement(sql)){
            stmt.setString(1, u.getfName());
            stmt.setString(2,u.getlName());
            stmt.setString(3, u.geteMail());
            stmt.setString(4, u.getMobileNum());
            stmt.setDate(5, DateUtil.utilToSqlDate(u.getBirthDate()));
            int count =
        }
    }




}
