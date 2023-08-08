#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
using namespace std;


class store
{
private:
    char name[20];
    float pr;
    int quant;

    friend void Dispstore(const store storeItems[], int numProducts);

public:
    void get();
    void show() const;
    int stockcheck(char nm[30]);
    void withdrawal(int qty);
    void refil_product(int qty);
};


class Dealer
{
public:
    static void addNewproduct(store storeItems[], int& numProducts);
    static void refill_product(store storeItems[], int numProducts);
    static void remove_product(store storeItems[], int& numProducts);
};


class Customer
{
public:
    static void withdraw(store storeItems[], int numProducts);
};


class emp {
public:
    static void refill(store storeItems[], int numProducts);
};


const int MAX_PRODUCTS = 100;
store storeItems[MAX_PRODUCTS];
int numProducts = 0;

// function for buying product
void store::withdrawal(int qty)
{
    if (quant >= qty) {
        quant -= qty;
        cout << "\n\nStock updated.\n";
        cout << "\n\nTotal price to be paid: " << pr * qty;
        cout << "\n";
    } else {
        cout << "\n\nInsufficient stock";
        cout << "\n";
    }
    getchar();
}

//function for product refil
void store::refil_product(int qty)
{
    quant += qty;
    cout << "\n\nStock updated.";
    cout << "\n";
    getchar();
}

//function for stock check
int store::stockcheck(char nm[30])
{
    if (strcmp(nm, name) == 0)
        return 0;
    else
        return 1;
}


void store::get()
{
    cin >> name >> pr >> quant;
}


void store::show() const
{
    cout << "\n" << name << "\t\t\t" << quant << "\t\t\t" << pr;
}


void Dealer::addNewproduct(store storeItems[], int& numProducts)
{
    cout << "\nEnter the No. of Products that you wish to add: ";
    int n;
    cin >> n;

    if (n != 0) {
        for (int i = 0; i < n; i++) {
            cout << "\n\nInput the name, price and the quantity of item respectively\n\n";
            storeItems[numProducts].get();
            numProducts++;
            cout << "\n\nItem updated";
            cin.get();
        }
        cout << "\n\nStock Updated!!";
        cin.get();
    } else {
        cin.get();
        cout << "\n\nNo items to be added";
        cout << "\n";
    }
}

//function for product refill
void Dealer::refill_product(store storeItems[], int numProducts) {
    char temp[100];
    int qty;
    int i = 0;
    cout << "\n\nEnter the products name \n" << endl;
    cin >> temp;
    cout << "\n\nEnter quantity: \n" << endl;
    cin >> qty;
    for (i = 0; i < numProducts; i++) {
        if (storeItems[i].stockcheck(temp) == 0) {
            storeItems[i].refil_product(qty);
            break;
        }
    }
    if (i == numProducts) {
        cout << "\n\n!!Record not found!!";
        cout << "\n";
    }
    cin.get();
    cin.get();
}

// function for removing product
void Dealer::remove_product(store storeItems[], int& numProducts){
    int i = 0;
    char temp[30];
    cout << "\n\t\t\t\tDelete Record";
    cout << "\n\nEnter the name of the product:";
    cin >> temp;
    for (i = 0; i < numProducts; i++) {
        if (storeItems[i].stockcheck(temp) == 0) {
            storeItems[i].show();
            cout << "\n\n\t\tRecord deleted";
            cout << "\n";
            numProducts--;
            for (int j = i; j < numProducts; j++) {
                storeItems[j] = storeItems[j + 1];
            }
            break;
        }
    }
    if (i == numProducts) {
        cout << "\n\n!!Record not found!!";
        cout << "\n";
    }
    getchar();
}

//function for buying product
void Customer::withdraw(store storeItems[], int numProducts) {
    char temp[100];
    int qty;
    int i = 0;
    cout << "\n\nEnter the product's name \n" << endl;
    cin >> temp;
    cout << "\n\nEnter quantity: \n" << endl;
    cin >> qty;

    for (i = 0; i < numProducts; i++) {
        if (storeItems[i].stockcheck(temp) == 0) {
            storeItems[i].withdrawal(qty);
            break;
        }
    }

    if (i == numProducts) {
        cout << "\n\n!!Record not found!!";
        cout << "\n";
    }
    cin.get();
    getchar();
}

//function for refilling products
void emp::refill(store storeItems[], int numProducts) {
    char temp[100];
    int qty;
    int i = 0;
    cout << "\n\nEnter the products name \n" << endl;
    cin >> temp;
    cout << "\n\nEnter quantity: \n" << endl;
    cin >> qty;

    for (i = 0; i < numProducts; i++) {
        if (storeItems[i].stockcheck(temp) == 0) {
            storeItems[i].refil_product(qty);
            break;
        }
    }

    if (i == numProducts) {
        cout << "\n\n!!Record not found!!\n";
    }

    cin.get();
    cin.get();
}

//function for displaying products
void Dispstore(const store storeItems[], int numProducts) {
    int i = 1;

    cout << "\n\n=THE STOCK ITEMS ARE=";

    cout << "\n\nPRODUCT NAME \tSTOCK AVAILABLE\t\t\t PRICE";
    cout << "\n\n============================================================\n";

    for (i = 0; i < numProducts; i++) {
        storeItems[i].show();
    }

    if (i == 0) {
        cout << "\n\n\t\t\t!!Empty record room!!";
        getchar();
    }
}

int main() {
    int i, j;
    cout << " WELCOME TO ONLINE STORE MANAGEMENT\n\n\n";
    getchar();
mainmenu:
    cout << "\nSTORE MANAGEMENT SYSTEM\n";

    cout << "\n\n   1. Dealer Menu\n   2. Customer Menu\n   3. Employee Menu";

    cout << "\n\nEnter Your Preference:";
    cin >> j;

    if (j == 1)
        {

        string passs;
        cout << "\n\nEnter Password to Login : ";


        cin >> passs;


        if (passs == "DEALER")

            {

            cout << "\n\n\nCongrats!!Access Granted!!\n\n";
            getchar();

        dealermenu:


            cout << "\n\n   DEALER MENU\n1. Add new product";
            cout << "\n2. Display stock";
            cout << "\n3. Refil";
            cout << "\n4. Remove an item";
            cout << "\n5. Return to main menu";
            cout << "\n6. Exit: ";
            cout << "\n\n\nEND OF MENU ";
            cout << "\n\n Enter your Preference :\t";
            cin >> i;

            if (i == 1) {
                Dealer::addNewproduct(storeItems, numProducts);
                getchar();
                goto dealermenu;
            } else if (i == 2) {
                Dispstore(storeItems, numProducts);
                getchar();
                goto dealermenu;
            } else if (i == 3) {
                Dealer::refill_product(storeItems, numProducts);
                goto dealermenu;
            } else if (i == 4) {
                Dealer::remove_product(storeItems, numProducts);
                getchar();
                goto dealermenu;
            } else if (i == 5) {
                goto mainmenu;
            } else {
                getchar();
                exit(0);
            }

        }

        else
            {
            cout << "\n\n\n!!!Admin Panel Only!!!\n\n";
            getchar();
            exit(0);
        }
    }
    else if (j == 2)
    {
    custmenu:

        cout << "\n\n    CUSTOMER MENU\n1. Purchase\n2. Display stock\n3. Return to main menu\n4. Exit:";
        cout << "\n\n\nEND OF MENU ";
        cout << "\n\n Enter your Choice :\t";
        cin >> i;

        if (i == 1)
            {
            Customer::withdraw(storeItems, numProducts);
            getchar();
            goto custmenu;
        }
        else if (i == 2)
            {
            Dispstore(storeItems, numProducts);
            getchar();
            goto custmenu;
        }
        else if (i == 3)
        {
            goto mainmenu;
        }
        else
            {
            getchar();
            exit(0);
        }
    }

    else if (j == 3)

        {
            string passss;

        cout << "\n\n\nEnter the Password : ";

        cin >> passss;


        if (passss == "emp")
            {
                cout << "\n!!Congrats!! You have got access"<<endl;
        empmenu:

            cout << "\n\nEMPLOYEE MENU\n1. Display stock\n2. Refill\n3. Return to main menu\n4. Exit";
            cout << "\n\n\nEND OF MENU ";
            cout << "\n\n Enter your Choice :\t";
            cin >> i;

            if (i == 1)
                {
                Dispstore(storeItems, numProducts);
                getchar();
                goto empmenu;
            }
            else if (i == 2)
                {
                emp::refill(storeItems, numProducts);
                goto empmenu;
            }
            else if (i == 3)
                {
                goto mainmenu;
            }
            else
            {
                cout << "\n\n\n!!Thank You!!";
                getchar();
                exit(0);
            }
        }
         else
            {
            cout << "\n\n..Sorry!! You can't access..\n\n";
            getchar();
            exit(0);
        }
    }

    getchar();
}
