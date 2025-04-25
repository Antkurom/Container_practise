#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;


struct book{
    string genre;
    string title;
    string author;
    string status;
    string  ISBN;

    bool operator==(const book& other) const {
        return genre == other.genre &&
               title == other.title &&
               status == other.status &&
               author == other.author &&
               ISBN == other.ISBN;
    }
};

struct borrowers{
    string name;
    book bk;
    int id_in_bookDatabase;

    bool operator==(const borrowers& other) const {
        return name == other.name &&
               bk == other.bk &&
               id_in_bookDatabase == other.id_in_bookDatabase;
    }
};


void add_book(vector<book>& bookDatabase);
void display(book bk);
void display_all(vector<book> bookDatabase);
void find_by_title(vector<book> bookDatabase);
void find_by_author(vector<book> bookDatabase);
void delete_book(vector<book> bookDatabase, book bk);
void delete_by_title(vector<book> bookDatabase);
void delete_by_author(vector<book> bookDatabase);
void update_book(vector<book> bookDatabase);
void add_borrowers(vector<borrowers> borrowersDatabase, vector<book> bookDatabase);
void return_book_delete_borrower(vector<borrowers> borrowersDatabase, vector<book> bookDatabase);
void display_all_borrower(vector<borrowers> borrowersDatabase, vector<book> bookDatabase);



int main(){
    vector<book> bookDatabase;
    vector<borrowers> borrowersDatabase;
    cout << "You are in a book Database. There is several options what you can do: \n";
    while (true){
        int input;
        cout << "\nTo exit from a program: --> 0\n"<<
                "Add a new book: --> 1\n" <<
                "Find a book by title: --> 2\n" <<
                "Find a book by author: --> 3\n" <<
                "Display all books: --> 4\n" <<
                "Delete all: --> 5\n" <<
                "Delete by title: --> 6\n" <<
                "Delete by author: --> 7\n" <<
                "Update book information --> 8\n" <<
                "Borrow a book --> 9\n" <<
                "Return a book --> 10\n" <<
                "Display all borrowers and books that are borrowed --> 11\n";
        cin >> input;
        switch (input){
            case(0):
            cout << "Exiting from the system...\n";
            Sleep(500);
            return 0;
            case(1):
            cout << "Adding a new book...\n";
            Sleep(500);
            add_book(bookDatabase);
            break;
            case(2):
            cout << "Find a book by title...\n";
            Sleep(500);
            find_by_title(bookDatabase);
            break;
            case(3):
            cout << "Find a book by author...\n";
            Sleep(500);
            find_by_author(bookDatabase);
            break;
            case(4):
            cout << "Display all books in database...\n";
            Sleep(500);
            display_all(bookDatabase);
            break;
            case(5):
            cout << "Deleting everything...\n";
            Sleep(500);
            bookDatabase.clear();
            cout << "Operation is completed successfully";
            Sleep(500);
            break;
            case(6):
            cout << "Deleting a book by his title...\n";
            Sleep(500);
            delete_by_title(bookDatabase);
            break;
            case(7):
            cout << "Deleting a book by his author...\n";
            Sleep(500);
            delete_by_author(bookDatabase);
            break;
            case(8):
            cout << "Start changing book information...\n";
            Sleep(500);
            update_book(bookDatabase);
            break;
            case(9):
            cout << "Borrowing a book...\n";
            Sleep(500);
            add_borrowers(borrowersDatabase, bookDatabase);
            break;
            case(10):
            cout << "Returning a book...\n";
            Sleep(500);
            return_book_delete_borrower(borrowersDatabase, bookDatabase);
            break;
            case(11):
            cout << "Displaying all borrowers and their's book...\n";
            Sleep(500);
            display_all_borrower(borrowersDatabase, bookDatabase);
            break;
            default:
            break;
        }
    }
}


void add_book(vector<book>& bookDatabase){
    string genre;
    string title;
    string author;
    string  ISBN;

    book somebody;


    cout << "\nEnter book genre: ";
    cin >> genre;
    somebody.genre = genre;


    cout << "Enter title of a book: ";
    cin >> title;
    somebody.title = title;


    cout << "Enter author of a book: ";
    cin >> author;
    somebody.author = author;


    cout << "Status for a new book by default is Available. If you want to change it you will have to do it manually.";
    Sleep(500);
    somebody.status = "Available";

    cout << "Enter ISBN of a book: ";
    cin >> ISBN;
    somebody.ISBN;




    bookDatabase.push_back(somebody);
}


void display(book bk){
    cout << "\n---------------------------------------------\n";
    cout << "\nbook genre: " << bk.genre << endl;
    cout << "book title: " << bk.title << endl;
    cout << "book author: " << bk.author << endl;
    cout << "book status: " << bk.status << endl;
    cout << "book ISBN: " << bk.ISBN << endl;
    cout << "\n---------------------------------------------\n\n";
    Sleep(500);
}


void display_all(vector<book> bookDatabase){
    for (book bk: bookDatabase){
        display(bk);
    }
}


void find_by_title(vector<book> bookDatabase){
    string title;
    int success = 0;
    cout << "Enter title of a book: ";
    cin >> title;


    for (book bk: bookDatabase){
        if(bk.title == title){
            display(bk);
            success ++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a book with such title. Check your spelling\n";
        Sleep(500);
    } else{
        cout << "Operation is completed successfully\n";
        Sleep(500);
    }
}


void find_by_author(vector<book> bookDatabase){
    string author;
    int success = 0;
    cout << "Enter a book author: ";
    cin >> author;


    for (book bk: bookDatabase){
        if(bk.author == author){
            display(bk);
            success ++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a book with such author. Check your spelling\n";
        Sleep(500);
    } else{
        cout << "Operation is completed successfully\n";
        Sleep(500);
    }
}


void delete_book(vector<book> bookDatabase, book bk){
    bookDatabase.erase(remove(bookDatabase.begin(), bookDatabase.end(), bk), bookDatabase.end());
}


void delete_by_title(vector<book> bookDatabase){
    string title;
    int success = 0;
    cout << "Enter title of a book, that you want to delete from database: \n";
    cin >> title;


    for (book bk: bookDatabase){
        if(bk.title == title){
            delete_book(bookDatabase, bk);
            success ++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a book with such title. Check your spelling\n";
        Sleep(500);
    } else{
        cout << "Operation is completed successfully\n";
        Sleep(500);
    }
}


void delete_by_author(vector<book> bookDatabase){
    string author;
    int success = 0;


    cout << "Enter author of a book, that you want to delete: \n";
    cin >> author;


    for (book bk: bookDatabase){
        if(bk.author == author){
            delete_book(bookDatabase, bk);
            success++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a book with such author. Check your spelling\n";
        Sleep(500);
    } else{
        cout << "Operation is completed successfully\n";
        Sleep(500);
    }
}

void update(book bk){
    while(true){
        display(bk);
        int input;
        cout << "\ngenre --> 0\n" <<
        "title --> 1\n" <<
        "author --> 2\n" <<
        "status --> 3\n" <<
        "ISBN --> 4\n" <<
        "End of changes --> 5\n";
        cin >> input;

        string genre;
        string new_title;
        string new_author;
        string new_status;
        int new_ISBN;
        int end = 0;

        switch (input){
            case(0):
            cout << "Enter new genre: ";
            cin >> genre;
            bk.genre = genre;
            break;
            case(1):
            cout << "Enter new title: ";
            cin >> new_title;
            bk.title = new_title;
            break;
            case(2):
            cout << "Enter new author: ";
            cin >> new_author;
            bk.author = new_author;
            break;
            case(3):
            cout << "Enter new status: ";
            cin >> new_status;
            bk.status = new_status;
            break;
            case(4):
            cout << "Enter new ISBN: ";
            cin >> new_ISBN;
            bk.ISBN = new_ISBN;
            break;
            case(5):
            cout << "Ending of changes...\n";
            end ++;
            break;
        }
        if (end==1){
            break;
        }
    }
}

void update_book(vector<book> bookDatabase){
    int input;
    cout << "Search by title (0) or author (1):\n";
    cin >> input;
    string title;
    string author;
    int success = 0;
    switch(input){
        case(0):
        cout << "Enter title of a book, that you want to update: \n";
        cin >> title;


        for (book bk: bookDatabase){
            if(bk.title == title){
                success ++;
                cout << "book was found successfully. What would you like to change\n";
                update(bk);
                break;
            }
        }
        if(success == 0){
            cout << "Program is feild to find a book with such title. Check your spelling\n";
            Sleep(500);
        } 
        break;
        case(1):
        cout << "Enter a book author, that you want to update: \n";
        cin >> author;


        for (book bk: bookDatabase){
            if(bk.author == author){
                success ++;
                cout << "book was found successfully. What would you like to change\n";
                update(bk);
                break;
            }
        }
        if(success == 0){
            cout << "Program is feild to find a book with such author. Check your spelling\n";
            Sleep(500);
        } 

        }

}

void add_borrowers(vector<borrowers> borrowersDatabase, vector<book> bookDatabase){
    string name;
    int id;

    borrowers somebody;

    cout << "Enter your name: ";
    cin >> name;
    somebody.name = name;

    int input;
    cout << "Now let's find book that you want to borrow. Type 0 to find by title, or type 1 to find by author:\n";
    cin >> input;

    string title;
    string author;
    int success = 0;
    int index_in_database = 0;
    switch(input){
        case(0):
        cout << "Enter title of a book: ";
        cin >> title;


        for (book bk: bookDatabase){
            if(bk.title == title){
                somebody.bk = bk;
                bk.status = "Borrowed";
                success ++;
                somebody.id_in_bookDatabase = index_in_database;
                break;
            }
            index_in_database ++;
        }
        if(success == 0){
            cout << "Program is feild to find a book with such title. Check your spelling next time\n";
            Sleep(500);
        } else{
            cout << "Operation is completed successfully\n";
            Sleep(500);
        }
        break;
        case(1):
        cout << "Enter a book author: ";
        cin >> author;


        for (book bk: bookDatabase){
            if(bk.author == author){
                somebody.bk = bk;
                bk.status = "Borrowed";
                success ++;
                somebody.id_in_bookDatabase = index_in_database;
                break;
                index_in_database ++;
            }
        }
        if(success == 0){
            cout << "Program is feild to find a book with such author. Check your spelling next time\n";
            Sleep(500);
        } else{
            cout << "Operation is completed successfully. Book id is: " << index_in_database << endl;
            Sleep(500);
        }
        break;
    }
    borrowersDatabase.push_back(somebody);
}


void return_book_delete_borrower(vector<borrowers> borrowersDatabase, vector<book> bookDatabase){
    int input;
    cout << "Please choice the method how you want to identify your borrow: \nName of the Borrower --> Type 0\nId of the book --> Type 1\n";
    cin >> input;

    string name;
    int your_book;
    int id;
    switch (input){
        case(0):
        cout << "Enter your name: ";
        cin >> name;
        for (borrowers br: borrowersDatabase){
            if(br.name == name){
                display(br.bk);
                cout << "\nDoes this is your book? Yes --> 0, No --> 1\n";
                cin >> your_book;
                if(your_book == 0){
                    br.bk.status = "Available";
                    borrowersDatabase.erase(remove(borrowersDatabase.begin(), borrowersDatabase.end(), br), borrowersDatabase.end());
                    cout << "Operation is completed.\n";
                    Sleep(500);
                    break;
                } else if (your_book = 1){
                    cout << "I can't find your book, try again.\n";
                    Sleep(500);
                    break;
                } else{
                    cout<< "Incorrect input\n";
                    Sleep(500);
                    break;
                }
            }
        }
        break;
        case(1):
        cout << "Enter Id of your book: ";
        cin >> id;
        display(bookDatabase[id]);
        cout << "\nDoes this is your book? Yes --> 0, No --> 1\n";
        cin >> your_book;
        if(your_book == 0){
            bookDatabase[id].status = "Available";
            borrowersDatabase.erase(remove(borrowersDatabase.begin(), borrowersDatabase.end(), bookDatabase[id]), borrowersDatabase.end());
            cout << "Operation is completed.\n";
            Sleep(500);
            
            break;
            } else if (your_book = 1){
                cout << "I can't find your book, try again. With Id you can find correct book if no books was deleted from database during you carrying your book.\n";
                Sleep(500);
                break;
            } else{
                cout<< "Incorrect input\n";
                Sleep(500);
                break;
            }
        
    }
}


void display_all_borrower(vector<borrowers> borrowersDatabase, vector<book> bookDatabase){
    for (borrowers br: borrowersDatabase){
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Name of the borrower: " << br.name << endl;
        cout << "Book ID: " << br.id_in_bookDatabase << endl;
        display(br.bk);
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        Sleep(500);
    }
    cout << "END of list\n";
    Sleep(500);
}

