package com.sunbeam;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class ReviewDao implements AutoCloseable{
    private Connection con;
    private PreparedStatement stmtCreateReview;
    private PreparedStatement stmtEditReview;
    private PreparedStatement stmtDeleteReview;
    private PreparedStatement stmtDisplayAllReview;
    private PreparedStatement stmtDisplayMyReviews;

    public ReviewDao() throws Exception{
        con = DBUtil.getCon();

        stmtCreateReview = con.
                prepareStatement("Insert into reviews values(default, ?,?,?,?,?)");
        stmtEditReview = con.prepareStatement("Update reviews set review = ? rating = ? modified = now()");
        stmtDeleteReview = con.prepareStatement("Delete reviews where id = ?");
        stmtDisplayAllReview = con.prepareStatement("Select * from reviews");
        stmtDisplayMyReviews = con.prepareStatement("select * from reviews where user_ id = ?");
    }

    public int createReview(ReviewsPOJO r) throws Exception{
        stmtCreateReview.setInt(1, r.getMovie_id());
        stmtCreateReview.setString(2, r.getReview());
        stmtCreateReview.setInt(3, r.getRating());
        stmtCreateReview.setInt(4, r.getUser_id());
        stmtCreateReview.setTimestamp(5, r.getModified());
        return stmtCreateReview.executeUpdate();
    }

    public int editReview(int id) throws Exception{
    	MoviesPOJO m= new MoviesPOJO();
    	String sql = "update reviews set id=?";
    	   stmtEditReview.setInt(1, id);
    	    stmtEditReview.setString(id, get);
    	
		try(PreparedStatement stmt = con.prepareStatement(sql)) {
			stmt.setInt(1, id);
			int cnt = stmt.executeUpdate();
			return cnt;
			
		}

    }


    public int deleteReview(int id) throws Exception  {
    	MoviesPOJO m= new MoviesPOJO();
    	String sql = "DELETE FROM reviews WHERE id=?";
		try(PreparedStatement stmt = con.prepareStatement(sql)) {
			stmt.setInt(1, id);
			int cnt = stmt.executeUpdate();
			return cnt;
		}
    	
    	
    }


    public void displayAllReviews(){}


    public void displayMyReviews(){}

    @Override
    public void close() throws Exception {
        con.close();
    }
}
