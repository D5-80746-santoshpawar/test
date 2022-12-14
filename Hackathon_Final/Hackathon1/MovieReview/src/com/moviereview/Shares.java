package com.moviereview;

import java.util.Objects;

public class Shares {
	
	int review_id;
	int user_id;
	
	public Shares() {
		// TODO Auto-generated constructor stub
	}
	
	public Shares(int review_id, int user_id) {
		super();
		this.review_id = review_id;
		this.user_id = user_id;
	}
	
	public int getReview_id() {
		return review_id;
	}
	public void setReview_id(int review_id) {
		this.review_id = review_id;
	}
	public int getUser_id() {
		return user_id;
	}
	public void setUser_id(int user_id) {
		this.user_id = user_id;
	}
	
	@Override
	public int hashCode() {
		return Objects.hash(review_id, user_id);
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Shares other = (Shares) obj;
		return review_id == other.review_id && user_id == other.user_id;
	}

	@Override
	public String toString() {
		return String.format("Shares [review_id=%s, user_id=%s]\n", review_id, user_id);
	}

//	@Override
//	public String toString() {
//		return "Shares [review_id=" + review_id + ", user_id=" + user_id + "]";
//	}
	
	
	
}
