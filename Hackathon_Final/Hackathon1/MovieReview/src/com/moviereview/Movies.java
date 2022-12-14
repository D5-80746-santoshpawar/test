package com.moviereview;

import java.util.*;
import java.util.Objects;

public class Movies {
	
	int movie_id;
	String title;
	Date releases;
	
	public Movies() {
		// TODO Auto-generated constructor stub
	}
	
	public Movies(int movie_id, String title, Date releases) {
		super();
		this.movie_id = movie_id;
		this.title = title;
		this.releases = releases;
	}
	
	
	public int getMovie_id() {
		return movie_id;
	}
	public void setMovie_id(int movie_id) {
		this.movie_id = movie_id;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public Date getReleases() {
		return releases;
	}
	public void setReleases(Date release) {
		this.releases = release;
	}

	@Override
	public int hashCode() {
		return Objects.hash(movie_id, releases, title);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Movies other = (Movies) obj;
		return movie_id == other.movie_id && Objects.equals(releases, other.releases)
				&& Objects.equals(title, other.title);
	}

	@Override
	public String toString() {
		return String.format("Movies [movie_id=%s, title=%s, releases=%s]\n", movie_id, title, releases);
	}

//	@Override
//	public String toString() {
//		return "Movies [movie_id=" + movie_id + ", title=" + title + ", releases=" + releases + "]";
//	}
	
	
	
	
	
}
