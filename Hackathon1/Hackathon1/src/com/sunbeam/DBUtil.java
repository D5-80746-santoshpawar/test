package com.sunbeam;



import java.sql.Connection;
import java.sql.DriverManager;

public class DBUtil {
    private static final String DB_Driver = "com.mysql.cj.jdbc.Driver";
    private static final String DB_URL = "jdbc:mysql://localhost:3306/hackathon1";
    private static final String DB_User = "D5-80746-santoshpawar";
    private static final String Pass = "sunbeam";

    private static Connection con;

    static{
        try{
            Class.forName(DB_Driver);
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
    public static Connection getCon() throws Exception {
        con = DriverManager.getConnection(DB_URL, DB_User,Pass);
        return con;
    }
}