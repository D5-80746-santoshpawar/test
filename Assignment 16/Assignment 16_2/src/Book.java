

import java.io.Serializable;
import java.util.Scanner;

public class Book implements Serializable{

	private String isbn;
	private double price;
	private String name;
	private String authorName;
	private int qty;

	public Book() {

		this("default-isbn", "default-name", 0.0, "default-author", 0);

	}

	public Book(String isbn, String name, double price, String authorName, int qty) {
		super();
		this.isbn = isbn;
		this.name = name;
		this.price = price;
		this.authorName = authorName;
		this.qty = qty;
	}

	public String getIsbn() {
		return isbn;
	}

	public void setIsbn(String isbn) {
		this.isbn = isbn;
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) {
		this.price = price;
	}

	public String getAuthorName() {
		return authorName;
	}

	public void setAuthorName(String authorName) {
		this.authorName = authorName;
	}

	public int getQty() {
		return qty;
	}

	public void setQty(int qty) {
		this.qty = qty;
	}

	public String getName() {
		return this.name;
	}

	public void setName(String name) {
		this.name = name;
	}

	@Override
	public boolean equals(Object o) {
		if (o == null)
			return false;
		if (this == o)
			return true;
		if (o instanceof Book) {
			Book other = (Book) o;
			if (this.getIsbn().equals(other.getIsbn()))
				return true;
		}
		return false;
	}

	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append("Book [isbn=").append(isbn).append(", name=").append(name).append(", price=").append(price)
				.append(", authorName=").append(authorName).append(", qty=").append(qty).append("]");
		return builder.toString();
	}

	public void acceptBook(Scanner sc) {

		System.out.println("Enter the ISBN - ");
		this.isbn = sc.next();
		System.out.println("Enter the NAME - ");
		this.name = sc.next();

		System.out.println("Enter the price - ");
		this.price = sc.nextDouble();
		System.out.println("Enter the Author Name - ");
		this.authorName = sc.next();
		System.out.println("Enter the qty - ");
		this.qty = sc.nextInt();

	}

}

