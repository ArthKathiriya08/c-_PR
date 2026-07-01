#include<iostream>
#include<string>
using namespace std;

// Abstract Base Class
class LibraryItem
{
private:
    string title, author;

public:
    // Set Title and Author
    void setData(string t, string a)
    {
        title = t;
        author = a;
    }

    // Get Title
    string getTitle()
    {
        return title;
    }

    // Get Author
    string getAuthor()
    {
        return author;
    }

    // Pure Virtual Functions
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void display() = 0;
};

// Book Class
class Book : public LibraryItem
{
public:
    // Check Out Book
    void checkOut()
    {
        cout<<"Book Checked Out\n";
    }

    // Return Book
    void returnItem()
    {
        cout<<"Book Returned\n";
    }

    // Display Book Details
    void display()
    {
        cout<<"\nBook Name : "<<getTitle();
        cout<<"\nAuthor : "<<getAuthor()<<endl;
    }
};

// DVD Class
class DVD : public LibraryItem
{
public:
    // Check Out DVD
    void checkOut()
    {
        cout<<"DVD Checked Out\n";
    }

    // Return DVD
    void returnItem()
    {
        cout<<"DVD Returned\n";
    }

    // Display DVD Details
    void display()
    {
        cout<<"\nDVD Name : "<<getTitle();
        cout<<"\nAuthor : "<<getAuthor()<<endl;
    }
};

int main()
{
    // Array of Base Class Pointers
    LibraryItem *item[10];

    int total = 0;
    int choice;

    // Menu Loop
    while(true)
    {
        cout<<"\n1.Add Book";
        cout<<"\n2.Add DVD";
        cout<<"\n3.Display";
        cout<<"\n4.CheckOut";
        cout<<"\n5.Return";
        cout<<"\n6.Exit";
        cout<<"\nEnter Choice : ";
        cin>>choice;

        // Add Book
        if(choice==1)
        {
            string title,author;

            cin.ignore();

            cout<<"Enter Book Name : ";
            getline(cin,title);

            cout<<"Enter Author : ";
            getline(cin,author);

            item[total]=new Book();
            item[total]->setData(title,author);
            total++;
        }

        // Add DVD
        else if(choice==2)
        {
            string title,author;

            cin.ignore();

            cout<<"Enter DVD Name : ";
            getline(cin,title);

            cout<<"Enter Author : ";
            getline(cin,author);

            item[total]=new DVD();
            item[total]->setData(title,author);
            total++;
        }

        // Display All Items
        else if(choice==3)
        {
            for(int i=0;i<total;i++)
                item[i]->display();
        }

        // Check Out Item
        else if(choice==4)
        {
            int n;
            cout<<"Enter Item Number : ";
            cin>>n;

            if(n<=0 || n>total)
                cout<<"Invalid Item";
            else
                item[n-1]->checkOut();
        }

        // Return Item
        else if(choice==5)
        {
            int n;
            cout<<"Enter Item Number : ";
            cin>>n;

            if(n<=0 || n>total)
                cout<<"Invalid Item";
            else
                item[n-1]->returnItem();
        }

        // Exit Program
        else if(choice==6)
        {
            for(int i=0;i<total;i++)
                delete item[i];

            break;
        }

        // Exception Handling
        else
        {
            try
            {
                throw "Invalid Choice";
            }
            catch(...)
            {
                cout<<"Exception Caught"<<endl;
            }
        }
    }

    return 0;
}