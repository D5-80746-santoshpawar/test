
package com.moviereview;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class MoviesDao extends Dao{
public MoviesDao() throws Exception {
// TODO Auto-generated constructor stub
}

public List<Movies> displayAllMovies() throws Exception {
List<Movies> allMovies = new ArrayList<>();
String sql = "SELECT * FROM movies";
try(PreparedStatement stmt = con.prepareStatement(sql)) {
try(ResultSet rs = stmt.executeQuery()) {
while(rs.next()) {
int movieId = rs.getInt("movie_id");
String title = rs.getString("title");
Date releases = DateUtil.sqlToUtilDate(rs.getDate("releases"));
allMovies.add(new Movies(movieId, title, releases));
}
} // rs.close();
} // stmt.close();
return allMovies;
}
}