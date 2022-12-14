import java.io.DataInputStream;
import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class BookNameComparator implements Comparator<Book> {
	public int compare(Book arg0, Book arg1) {
		int dif = arg0.getName().compareTo(arg1.getName());
		return dif;
	}

}



	public class Library {
		
		
	
		
		public static void main(String[] args) {
			Scanner sc = new Scanner(System.in);
			List<Book> libraryList = new ArrayList<Book>();
			boolean flag = true;
			while (flag) {
				System.out.println("--------------------------------------------------");
				System.out.println("Select a choice : ");
				System.out.println("1. Add new book in list.");
				System.out.println("2. Display all books in forward order.");
				System.out.println("3. Search a book with given ISBN.");
				System.out.println("4. Delete book at given index.");
				System.out.println("5. Delete a book by ISBN.");
				System.out.println("6. Delete a book by name.");
				System.out.println("7. Sort by ISBN in asc order.");
				System.out.println("8. Sort by price in desc order.");
				System.out.println("9. Shuffle the list.");
				System.out.println("10. Save Books in file");// System.out.println("9. Shuffle the list.");
				System.out.println("11. load book from file");
				System.out.println("12. EXIT.");
				
				System.out.println("Enter choice");
				int choice = sc.nextInt();
				
				System.out.println("--------------------------------------------------");
				Book temp = null;
				switch (sc.nextInt()) {
				case 1: // add book
					temp = new Book();
					temp.acceptBook(sc);
					int index = libraryList.indexOf(temp);
					if (index == -1) {
						libraryList.add(temp);
						System.out.printf("Book Added !");
					} else {

						libraryList.get(index).setQty(libraryList.get(index).getQty() + temp.getQty());
						System.out.println("Book already exists, updating the qty - ");
						System.out.println("New qty = " + libraryList.get(index).getQty());
					}
					break;
				case 2:
					for (int i = 0; i < libraryList.size(); i++) {
						Book ele = libraryList.get(i);
						System.out.println(ele);
					}
					break;
				case 3:

					System.out.println("Enter ISBN to search : ");

					Book tempBook = new Book();
					tempBook.setIsbn(sc.next());

					int searchIndex = libraryList.indexOf(tempBook);

					if (searchIndex == -1) {

						System.out.println("BOOK NOT FOUND !");

					} else {
						System.out.println("Book Found at Index  - " + searchIndex);
					}
					break;
				case 4:
					System.out.println("Enter the index of the book to delete -  ");
					int deleteIndex = sc.nextInt();

					if (deleteIndex < 0 || deleteIndex > libraryList.size() - 1) {
						System.out
								.println("Invalid Index!, \nPlease enter a value between 0 and " + libraryList.size());

					} else {
						libraryList.remove(deleteIndex);
						System.out.println("Book Deleted !");
					}
					break;
				case 5: // delete a book by isbn
					Book delBook = new Book();
					System.out.println("Enter the ISBN of the book to delete - ");
					delBook.setIsbn(sc.next());
					int delIndex = libraryList.indexOf(delBook);
					if (delIndex == -1) {
						System.out.println("BOOK WITH THAT ISBN DOES NOT EXIST !");
					} else {
						libraryList.remove(delIndex);
						System.out.println("BOOK FOUND AT INDEX - " + delIndex + "AND SUCCESSFULLY DELETED !");
					}
					break;
				case 6: // delete book by name
					System.out.println("Enter the name of the book to delete - ");
					String name = sc.next();
					Book delByNameBook = new Book();
					delByNameBook.setName(name);
					int delByNameIndex = 0;
					for (int i = 0; i < libraryList.size(); i++) {
						delByNameIndex = libraryList.get(i).getName().compareToIgnoreCase(delByNameBook.getName());
						if (delByNameIndex == -1) {
							continue;
						} else {
							System.out.println("BOOK FOUND");
							libraryList.get(i);
							System.out.println("DELETING BOOK...");
							libraryList.remove(i);
							System.out.println("BOOK REMOVED !");
						}
					}
					break;
				case 7:
					class BookAscComparator implements Comparator<Book> {
						@Override
						public int compare(Book arg0, Book arg1) {

							return arg0.getIsbn().compareTo(arg1.getIsbn());
						}
					}
					libraryList.sort(new BookAscComparator());
					System.out.println(libraryList);
					break;
				case 8: // sort by price in desc order
					class BookDescComparator implements Comparator<Book> {
						@Override
						public int compare(Book arg0, Book arg1) {
							double temp = -arg0.getPrice() - arg1.getPrice();
							return (int) temp;
						}
					}

					Collections.sort(libraryList, new BookDescComparator());
					System.out.println(libraryList);
					break;
				case 9:

					Collections.shuffle(libraryList);
					System.out.println(libraryList);

					break;

				case 10:
					List<Book> list = new ArrayList<Book>();
					Collections.addAll(list, new Book("ASD", "EPFO", 45.50, "saga", 12), new Book("HADD", "EPO", 40.50, "Raga", 10)

					);
					try (FileOutputStream fout = new FileOutputStream("Books.db")) {
						try (ObjectOutputStream oout = new ObjectOutputStream(fout)) {
							oout.writeObject(list);
							
						} // oout.close();
					} // fout.close();
					catch (Exception e) {
						e.printStackTrace();
					}
					System.out.println("Books Saved: " + list.size());

					break;

				case 11:
					
					List<Book> list1 = null;
					try(FileInputStream fin = new FileInputStream("Books.db")) {
						try(ObjectInputStream oin = new ObjectInputStream(fin)) {
							list1 = (List<Book>) oin.readObject();
						} // oin.close();
					} // fin.close();
					catch (Exception e) {
						e.printStackTrace();
					}
					list1.forEach(e -> System.out.println(e));
				
				
				

		/*			List<Book> list1 = new ArrayList<Book>();
					try(FileInputStream fin = new FileInputStream("Books.db")) {
						try(DataInputStream din = new DataInputStream(fin)) {
							while(true) {
								Book m = new Book();
								m.setIsbn( din.readUTF() );
								m.setName( din.readUTF() );
								
								m.setAuthorName( din.readUTF() );
								m.setQty(din.readInt());
								//System.out.println(m);
								list1.add(m);
	//Book(String isbn, String name, double price, String authorName, int qty)							
								
							}
						} // din.close();
					} // fin.close();
					catch (EOFException e) {
						// do nothing -- close() is done auto -- AutoCloseable
					}
					catch (Exception e) {
						e.printStackTrace();
					}
					list1.forEach(e -> System.out.println(e));
					*/
					break;
				case 12:

					System.out.println("Bye !");
					flag = false;

					break;
				default:
					System.out.println("ENTER A VALID CHOICE !");
					break;
				}
			}
		}

	}

