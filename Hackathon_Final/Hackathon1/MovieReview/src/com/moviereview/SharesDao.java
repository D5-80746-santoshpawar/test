
package com.moviereview;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class SharesDao extends Dao{
	public SharesDao() throws Exception{
	}
	
	public List<Reviews> displayReviewsSharedWithMe(int userid) throws Exception {
		List<Reviews> reviewsSharedWithMe = new ArrayList<>();
		String sql = "SELECT * FROM reviews where review_id =ANY (SELECT review_id FROM shares WHERE user_id=?)";
		try(PreparedStatement stmt = con.prepareStatement(sql)) {
			stmt.setInt(1, userid);
			try(ResultSet rs = stmt.executeQuery()) {
				while(rs.next()) {
					int reviewid = rs.getInt("review_id");
					int movieId = rs.getInt("movie_id");
					String review = rs.getString("review");
					int rating = rs.getInt("rating");
					Timestamp modified = rs.getTimestamp("modified");
					reviewsSharedWithMe.add(new Reviews(reviewid, movieId, review, rating, userid, modified)) ;
				}
			} // rs.close();
		} // stmt.close();
		return reviewsSharedWithMe;
	}
	public Map<Integer, String> getEmailId() throws Exception {
		Map<Integer, String> emails = new HashMap<Integer, String>();
		String sql = "SELECT user_id, email FROM users";
		try(PreparedStatement stmt = con.prepareStatement(sql)) {
		try(ResultSet rs = stmt.executeQuery()) {
		while(rs.next()) {
		int userid = rs.getInt("user_id");
		String email = rs.getString("email");
		emails.put(userid, email);
		}
		} // rs.close();
		} // stmt.close();
		return emails;
		}

	public int shareReview(int reviewid, int userid) throws Exception {
		String sql = "INSERT INTO shares VALUES(?, ?)";
		
		try(PreparedStatement stmt = con.prepareStatement(sql)) {
		stmt.setInt(1, reviewid);
		stmt.setInt(2, userid);
		int cnt = stmt.executeUpdate();
		return cnt;
		} //stmt.close();
		}
}