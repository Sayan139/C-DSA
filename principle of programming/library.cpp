#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int bookId, string bookTitle, string bookAuthor, bool issued = false)
        : id(bookId), title(bookTitle), author(bookAuthor), isIssued(issued) {}

    void displayDetails() {
        cout << "ID: " << id
             << " | Title: " << title
             << " | Author: " << author
             << " | Status: " << (isIssued ? "Issued" : "Available") << endl;
    }
};

class Member {
public:
    int id;
    string name;
    vector<int> issuedBooks;

    Member(int memberId, string memberName) : id(memberId), name(memberName) {}

    void displayDetails() {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Issued Books: ";
        if (issuedBooks.empty()) {
            cout << "None";
        } else {
            for (int bookId : issuedBooks) {
                cout << bookId << " ";
            }
        }
        cout << endl;
    }
};

class LibraryManagementSystem {
private:
    vector<Book> books;
    vector<Member> members;
    int nextBookId;
    int nextMemberId;

public:
    LibraryManagementSystem() : nextBookId(1), nextMemberId(1) {}

    void addBook(string title, string author) {
        books.push_back(Book(nextBookId, title, author));
        cout << "Book added with ID: " << nextBookId << endl;
        nextBookId++;
    }

    void addMember(string name) {
        members.push_back(Member(nextMemberId, name));
        cout << "Member added with ID: " << nextMemberId << endl;
        nextMemberId++;
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        for (auto& book : books) {
            book.displayDetails();
        }
    }

    void displayMembers() {
        if (members.empty()) {
            cout << "No members in the system.\n";
            return;
        }
        for (auto& member : members) {
            member.displayDetails();
        }
    }

    void issueBook(int bookId, int memberId) {
        for (auto& book : books) {
            if (book.id == bookId) {
                if (book.isIssued) {
                    cout << "Book ID " << bookId << " is already issued.\n";
                    return;
                }
                for (auto& member : members) {
                    if (member.id == memberId) {
                        book.isIssued = true;
                        member.issuedBooks.push_back(bookId);
                        cout << "Book ID " << bookId << " issued to Member ID " << memberId << ".\n";
                        return;
                    }
                }
                cout << "Member ID " << memberId << " not found.\n";
                return;
            }
        }
        cout << "Book ID " << bookId << " not found.\n";
    }

    void returnBook(int bookId, int memberId) {
        for (auto& book : books) {
            if (book.id == bookId && book.isIssued) {
                for (auto& member : members) {
                    if (member.id == memberId) {
                        auto it = find(member.issuedBooks.begin(), member.issuedBooks.end(), bookId);
                        if (it != member.issuedBooks.end()) {
                            member.issuedBooks.erase(it);
                            book.isIssued = false;
                            cout << "Book ID " << bookId << " returned by Member ID " << memberId << ".\n";
                            return;
                        }
                    }
                }
                cout << "Member ID " << memberId << " did not issue Book ID " << bookId << ".\n";
                return;
            }
        }
        cout << "Book ID " << bookId << " not found or not issued.\n";
    }
};

int main() {
    LibraryManagementSystem lms;
    int choice, bookId, memberId;
    string title, author, name;

    while (true) {
        cout << "\nLibrary Management System Menu\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Display Books\n";
        cout << "4. Display Members\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            lms.addBook(title, author);
            break;

        case 2:
            cout << "Enter Member Name: ";
            cin.ignore();
            getline(cin, name);
            lms.addMember(name);
            break;

        case 3:
            lms.displayBooks();
            break;

        case 4:
            lms.displayMembers();
            break;

        case 5:
            cout << "Enter Book ID to Issue: ";
            cin >> bookId;
            cout << "Enter Member ID: ";
            cin >> memberId;
            lms.issueBook(bookId, memberId);
            break;

        case 6:
            cout << "Enter Book ID to Return: ";
            cin >> bookId;
            cout << "Enter Member ID: ";
            cin >> memberId;
            lms.returnBook(bookId, memberId);
            break;

        case 7:
            cout << "Exiting system.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
