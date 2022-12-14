package com.moviereview;

import java.sql.Timestamp;
import java.text.SimpleDateFormat;
import java.util.Objects;

public class Reviews {
	
	int review_id;
	int movie_id;
	String review;
	int rating;
	int user_id;
	Timestamp modified;
	
	public Reviews() {
		// TODO Auto-generated constructor stub
	}
	
	public Reviews(int review_id, int movie_id, String review, int rating, int user_id, Timestamp modified) {
		super();
		this.review_id = review_id;
		this.movie_id = movie_id;
		this.review = review;
		this.rating = rating;
		this.user_id = user_id;
		this.modified = new Timestamp(review_id);
		
	}
	
	

	public int getReview_id() {
		return review_id;
	}

	public void setReview_id(int review_id) {
		this.review_id = review_id;
	}

	public int getMovie_id() {
		return movie_id;
	}

	public void setMovie_id(int movie_id) {
		this.movie_id = movie_id;
	}

	public String getReview() {
		return review;
	}

	public void setReview(String review) {
		this.review = review;
	}

	public int getRating() {
		return rating;
	}

	public void setRating(int rating) {
		this.rating = rating;
	}

	public int getUser_id() {
		return user_id;
	}

	public void setUser_id(int user_id) {
		this.user_id = user_id;
	}

	public Timestamp getModified() {
		return modified;
	}

	public void setModified(Timestamp modified) {
		this.modified = modified;
	}

	@Override
	public int hashCode() {
		return Objects.hash(review_id, modified, movie_id, rating, review, user_id);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Reviews other = (Reviews) obj;
		return review_id == other.review_id && Objects.equals(modified, other.modified) && movie_id == other.movie_id
				&& rating == other.rating && Objects.equals(review, other.review) && user_id == other.user_id;
	}

	@Override
	public String toString() {
		return String.format("Reviews [review_id=%s, movie_id=%s, review=%s, rating=%s, user_id=%s, modified=%s]\n",
				review_id, movie_id, review, rating, user_id, modified);
	}

//	@Override
//	public String toString() {
//		return "Reviews [id=" + review_id + ", movie_id=" + movie_id + ", review=" + review + ", rating=" + rating
//				+ ", user_id=" + user_id + ", modified=" + modified + "]";
//	}
	
	
	
	
	
}
