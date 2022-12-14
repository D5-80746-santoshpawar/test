package com.moviereview;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Date;


public class UsersDao extends Dao{
	
	protected UsersDao() throws Exception {
		super();
		// TODO Auto-generated constructor stub
	}
	
	public int save(Users u) throws Exception {
		String sql = "INSERT INTO users VALUES(default, ?, ?, ?, ?, ?, ?)";
		try(PreparedStatement stmt = con.prepareStatement(sql)) {
		stmt.setString(1, u.getFirst_name());
		stmt.setString(2, u.getLast_name());
		stmt.setString(3, u.getEmail());
		stmt.setString(4, u.getPassword());
		stmt.setString(5, u.getMobile());
		stmt.setDate(6, DateUtil.utilToSqlDate(u.getBirth()));
		int count = stmt.executeUpdate();
		return count;
		} //stmt.close();
		}


		public Users findByEmail(String email) throws Exception {
		String sql = "SELECT * FROM users WHERE email=?";
		try(PreparedStatement stmt = con.prepareStatement(sql)) {
		stmt.setString(1, email);
		try(ResultSet rs = stmt.executeQuery()) {
		while(rs.next()) {
		int id = rs.getInt("user_id");
		String fname = rs.getString("first_name");
		String lname = rs.getString("last_name");
		String emails = rs.getString("email");
		String password = rs.getString("password");
		String mobile = rs.getString("mobile");
		Date birth = DateUtil.sqlToUtilDate(rs.getDate("birth"));
		return new Users(id, fname, lname, emails, password, mobile, birth);
		}
		} // rs.close();
		} // stmt.close();
		return null;
		}

		public int editProfile(int userid, String firstname, String lastame, String email, String mobile, Date birth) throws Exception {
		String sql = "UPDATE users SET first_name=?, last_name=?, email=?, mobile=?, birth=? WHERE user_id=?";
		try(PreparedStatement stmt = con.prepareStatement(sql)) {
		stmt.setString(1, firstname);
		stmt.setString(2, lastame);
		stmt.setString(3, email);
		//stmt.setString(4, password);
		stmt.setString(4, mobile);
		stmt.setDate(5, (java.sql.Date) birth);
		stmt.setInt(6, userid);
		int count = stmt.executeUpdate();
		return count;
		} //stmt.close();
		}

		public int changePassword(int userid, String pass) throws Exception {
		String sql = "UPDATE users SET password=? WHERE user_id=?";
		try(PreparedStatement stmt = con.prepareStatement(sql)) {
		
		stmt.setString(1, pass);
		stmt.setInt(2, userid);
		int count = stmt.executeUpdate();
		return count;
		} //stmt.close();
		}
		
	
}
	

