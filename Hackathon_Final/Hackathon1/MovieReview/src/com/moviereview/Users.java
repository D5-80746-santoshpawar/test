package com.moviereview;

import java.util.*;
import java.util.Objects;

public class Users {
	
	

	int user_id;
	String first_name;
	String last_name;
	String email;
	String password;
	String mobile;
	Date birth;
	
	
	public Users() {
		// TODO Auto-generated constructor stub
	}
	
	public Users(int id, String first_name, String last_name, String email, String password, String mobile,
			Date birth) {
		super();
		this.user_id = id;
		this.first_name = first_name;
		this.last_name = last_name;
		this.email = email;
		this.password = password;
		this.mobile = mobile;
		this.birth = birth;
	}

	
	public int getUser_id() {
		return user_id;
	}

	public void setUser_id(int user_id) {
		this.user_id = user_id;
	}

	public String getFirst_name() {
		return first_name;
	}
	public void setFirst_name(String first_name) {
		this.first_name = first_name;
	}
	public String getLast_name() {
		return last_name;
	}
	public void setLast_name(String last_name) {
		this.last_name = last_name;
	}
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public String getMobile() {
		return mobile;
	}
	public void setMobile(String mobile) {
		this.mobile = mobile;
	}
	public Date getBirth() {
		return birth;
	}
	public void setBirth(Date birth) {
		this.birth = birth;
	}

	
//	@Override
//	public String toString() {
//		return "Users [user_id=" + user_id + ", first_name=" + first_name + ", last_name=" + last_name + ", email="
//				+ email + ", password=" + password + ", mobile=" + mobile + ", birth=" + birth + "]";
//	}

	@Override
	public int hashCode() {
		return Objects.hash(birth, email, first_name, user_id, last_name, mobile, password);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Users other = (Users) obj;
		return Objects.equals(birth, other.birth) && Objects.equals(email, other.email)
				&& Objects.equals(first_name, other.first_name) && user_id == other.user_id
				&& Objects.equals(last_name, other.last_name) && Objects.equals(mobile, other.mobile)
				&& Objects.equals(password, other.password);
	}

	@Override
	public String toString() {
		return String.format(
				"Users [user_id=%s, first_name=%s, last_name=%s, email=%s, password=%s, mobile=%s, birth=%s]\n", user_id,
				first_name, last_name, email, password, mobile, birth);
	}

	
	
	
	
}
