#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct book{
    string availability;
    string title;
    string author;
    string status;
    string  ISBN;

    bool operator==(const book& other) const {
        return availability == other.availability &&
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
                "Update book information --> 8\n";
        cin >> input;
        switch (input){
            case(0):
            cout << "Exiting from the system...\n";
            return 0;
            case(1):
            cout << "Adding a new book...\n";
            add_book(bookDatabase);
            break;
            case(2):
            cout << "Find a book by title...\n";
            find_by_title(bookDatabase);
            break;
            case(3):
            cout << "Find a book by author...\n";
            find_by_author(bookDatabase);
            break;
            case(4):
            cout << "Display all books in database...\n";
            display_all(bookDatabase);
            break;
            case(5):
            cout << "Deleting everything...\n";
            bookDatabase.clear();
            cout << "Operation is completed successfully";
            break;
            case(6):
            cout << "Deleting a book by his title...\n";
            delete_by_title(bookDatabase);
            break;
            case(7):
            cout << "Deleting a book by his author...\n";
            delete_by_author(bookDatabase);
            break;
            case(8):
            cout << "Start changing book information...\n";
            update_book(bookDatabase);
            break;
            default:
            break;
        }
    }
}


void add_book(vector<book>& bookDatabase){
    string availability;
    string title;
    string author;
    string  ISBN;

    book somebody;


    cout << "\nEnter book author: ";
    cin >> availability;
    somebody.availability = availability;


    cout << "Enter title of a book: ";
    cin >> title;
    somebody.title = title;


    cout << "Enter author of a book: ";
    cin >> author;
    somebody.author = author;


    cout << "Enter status of a book: ";
    cin >> status;
    somebody.status = status;

    cout << "Enter ISBN of a book: ";
    cin >> ISBN;
    somebody.ISBN;




    bookDatabase.push_back(somebody);
}


void display(book bk){
    cout << "\nbook author: " << bk.availability << endl;
    cout << "book title: " << bk.title << endl;
    cout << "book author: " << bk.author << endl;
    cout << "book status: " << bk.status << endl;
    cout << "book ISBN: " << bk.ISBN << endl;
}


void display_all(vector<book> bookDatabase){
    for (book bk: bookDatabase){
        cout << "\n---------------------------------------------\n";
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
    } else{
        cout << "Operation is completed successfully\n";
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
    } else{
        cout << "Operation is completed successfully\n";
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
    } else{
        cout << "Operation is completed successfully\n";
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
    } else{
        cout << "Operation is completed successfully\n";
    }
}

void update(book bk){
    while(true){
        display(bk);
        int input;
        cout << "\navailability --> 0\n" <<
        "title --> 1\n" <<
        "author --> 2\n" <<
        "status --> 3\n" <<
        "ISBN --> 4\n" <<
        "End of changes --> 5\n";
        cin >> input;

        string availability;
        string new_title;
        string new_author;
        string new_status;
        int new_ISBN;
        int end = 0;

        switch (input){
            case(0):
            cout << "Enter new availability: ";
            cin >> availability;
            bk.availability = availability;
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
                success ++;
                somebody.id_in_bookDatabase = index_in_database;
                break;
            }
            index_in_database ++;
        }
        if(success == 0){
            cout << "Program is feild to find a book with such title. Check your spelling next time\n";
        } else{
            cout << "Operation is completed successfully\n";
        }
        break;
        case(1):
        cout << "Enter a book author: ";
        cin >> author;


        for (book bk: bookDatabase){
            if(bk.author == author){
                somebody.bk = bk;
                bk.availability
                success ++;
                somebody.id_in_bookDatabase = index_in_database;
                break;
                index_in_database ++;
            }
        }
        if(success == 0){
            cout << "Program is feild to find a book with such author. Check your spelling next time\n";
        } else{
            cout << "Operation is completed successfully\n";
        }
        break;

    // There are a lot of things to polish I don't have time to finish it... Probably later?? There is not a lot of possibility on that.
}

}
