import java.sql.Timestamp;

public class Review {
    private int review_id;
    private int movie_id;
    private String review;
    private int rating;
    private int user_id;
    private java.sql.Timestamp modified;

    public Review() {
    }

    public Review(int review_id, int movie_id, String review, int rating, int user_id, Timestamp modified) {
        this.review_id = review_id;
        this.movie_id = movie_id;
        this.review = review;
        this.rating = rating;
        this.user_id = user_id;
        this.modified = modified;
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
    public String toString() {
        return "Review{" +
                "review_id=" + review_id +
                ", movie_id=" + movie_id +
                ", review='" + review + '\'' +
                ", rating=" + rating +
                ", user_id=" + user_id +
                ", modified=" + modified +
                '}';
    }
}
