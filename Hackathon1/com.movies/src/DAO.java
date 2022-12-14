import java.sql.Connection;
public class DAO implements AutoCloseable {
    protected Connection con;
    protected DAO() throws Exception {
            con = DbUtil.getConnection();
        }

        @Override
        public void close() {
            try {
                if (con != null)
                    con.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

