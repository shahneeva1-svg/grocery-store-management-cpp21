#include <iostream>
#include <iomanip>
#include "GroceryStore.h"

using namespace std;

// Function prototypes for menu operations
void displayMainMenu();
void productMenu(GroceryStore& store);
void customerMenu(GroceryStore& store);
void supplierMenu(GroceryStore& store);
void processSaleMenu(GroceryStore& store);

int main() {
    try {
        GroceryStore store(100);
        
        cout << "\n========================================\n";
        cout << "  GROCERY STORE MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        
        // Load existing data on startup
        store.loadAllData();
        
        int mainChoice = 0;
        bool running = true;
        
        while (running) {
            displayMainMenu();
            cout << "Enter your choice: ";
            cin >> mainChoice;
            
            try {
                switch (mainChoice) {
                    case 1:
                        productMenu(store);
                        break;
                    case 2:
                        customerMenu(store);
                        break;
                    case 3:
                        supplierMenu(store);
                        break;
                    case 4:
                        processSaleMenu(store);
                        break;
                    case 5: {
                        cout << "\n===== REPORTS =====\n";
                        cout << "1. Sales Report\n";
                        cout << "2. Inventory Report\n";
                        cout << "3. Customer Report\n";
                        cout << "Enter choice: ";
                        int reportChoice;
                        cin >> reportChoice;
                        
                        if (reportChoice == 1) store.generateSalesReport();
                        else if (reportChoice == 2) store.generateInventoryReport();
                        else if (reportChoice == 3) store.generateCustomerReport();
                        break;
                    }
                    case 6:
                        cout << "Saving all data...\n";
                        store.saveAllData();
                        break;
                    case 7:
                        cout << "Loading all data...\n";
                        store.loadAllData();
                        break;
                    case 8:
                        cout << "\nThank you for using Grocery Store Management System!\n";
                        cout << "Saving data before exit...\n";
                        store.saveAllData();
                        running = false;
                        break;
                    default:
                        cout << "Invalid choice! Please try again.\n";
                }
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
    } catch (const exception& e) {
        cerr << "Fatal error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

void displayMainMenu() {
    cout << "\n========== MAIN MENU ==========\n";
    cout << "1. Product Management\n";
    cout << "2. Customer Management\n";
    cout << "3. Supplier Management\n";
    cout << "4. Process Sale (Main Transaction)\n";
    cout << "5. View Reports\n";
    cout << "6. Save Data\n";
    cout << "7. Load Data\n";
    cout << "8. Exit\n";
    cout << "===============================\n";
}

void productMenu(GroceryStore& store) {
    int choice = 0;
    bool inProductMenu = true;
    
    while (inProductMenu) {
        cout << "\n===== PRODUCT MENU =====\n";
        cout << "1. Add Product\n";
        cout << "2. Display All Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Product\n";
        cout << "5. Delete Product\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        try {
            switch (choice) {
                case 1: {
                    int id, qty;
                    string name, category;
                    double price;
                    
                    cout << "Enter Product ID: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Enter Product Name: ";
                    getline(cin, name);
                    cout << "Enter Price: ";
                    cin >> price;
                    cout << "Enter Quantity: ";
                    cin >> qty;
                    cin.ignore();
                    cout << "Enter Category: ";
                    getline(cin, category);
                    
                    Product p(id, name, price, qty, category);
                    store.addProduct(p);
                    cout << "Product added successfully!\n";
                    break;
                }
                case 2:
                    store.displayProducts();
                    break;
                case 3: {
                    int id;
                    cout << "Enter Product ID to search: ";
                    cin >> id;
                    Product* p = store.searchProduct(id);
                    if (p) {
                        cout << "\nProduct found:\n";
                        cout << std::left << std::setw(6) << "ID" 
                             << std::setw(25) << "Name" 
                             << std::setw(12) << "Price" 
                             << std::setw(10) << "Quantity" 
                             << std::setw(15) << "Category" << endl;
                        p->display();
                    } else {
                        cout << "Product not found!\n";
                    }
                    break;
                }
                case 4: {
                    int id, qty;
                    string name, category;
                    double price;
                    
                    cout << "Enter Product ID to update: ";
                    cin >> id;
                    cin.ignore();
                    
                    Product* p = store.searchProduct(id);
                    if (p) {
                        cout << "Enter new Product Name: ";
                        getline(cin, name);
                        cout << "Enter new Price: ";
                        cin >> price;
                        cout << "Enter new Quantity: ";
                        cin >> qty;
                        cin.ignore();
                        cout << "Enter new Category: ";
                        getline(cin, category);
                        
                        Product updated(id, name, price, qty, category);
                        store.updateProduct(id, updated);
                        cout << "Product updated successfully!\n";
                    } else {
                        cout << "Product not found!\n";
                    }
                    break;
                }
                case 5: {
                    int id;
                    cout << "Enter Product ID to delete: ";
                    cin >> id;
                    store.deleteProduct(id);
                    break;
                }
                case 6:
                    inProductMenu = false;
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}

void customerMenu(GroceryStore& store) {
    int choice = 0;
    bool inCustomerMenu = true;
    
    while (inCustomerMenu) {
        cout << "\n===== CUSTOMER MENU =====\n";
        cout << "1. Add Customer\n";
        cout << "2. Display All Customers\n";
        cout << "3. Search Customer\n";
        cout << "4. Update Customer\n";
        cout << "5. Delete Customer\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        try {
            switch (choice) {
                case 1: {
                    int id;
                    string name, phone, email, address;
                    
                    cout << "Enter Customer ID: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Enter Customer Name: ";
                    getline(cin, name);
                    cout << "Enter Phone Number: ";
                    getline(cin, phone);
                    cout << "Enter Email: ";
                    getline(cin, email);
                    cout << "Enter Address: ";
                    getline(cin, address);
                    
                    Customer c(id, name, phone, email, address);
                    store.addCustomer(c);
                    cout << "Customer added successfully!\n";
                    break;
                }
                case 2:
                    store.displayCustomers();
                    break;
                case 3: {
                    int id;
                    cout << "Enter Customer ID to search: ";
                    cin >> id;
                    Customer* c = store.searchCustomer(id);
                    if (c) {
                        cout << "\nCustomer found:\n";
                        cout << std::left << std::setw(6) << "ID" 
                             << std::setw(20) << "Name" 
                             << std::setw(15) << "Phone" 
                             << std::setw(20) << "Email" 
                             << std::setw(25) << "Address" 
                             << std::setw(12) << "Total Spent" << endl;
                        c->display();
                    } else {
                        cout << "Customer not found!\n";
                    }
                    break;
                }
                case 4: {
                    int id;
                    string name, phone, email, address;
                    
                    cout << "Enter Customer ID to update: ";
                    cin >> id;
                    cin.ignore();
                    
                    Customer* c = store.searchCustomer(id);
                    if (c) {
                        cout << "Enter new Customer Name: ";
                        getline(cin, name);
                        cout << "Enter new Phone Number: ";
                        getline(cin, phone);
                        cout << "Enter new Email: ";
                        getline(cin, email);
                        cout << "Enter new Address: ";
                        getline(cin, address);
                        
                        Customer updated(id, name, phone, email, address);
                        store.updateCustomer(id, updated);
                        cout << "Customer updated successfully!\n";
                    } else {
                        cout << "Customer not found!\n";
                    }
                    break;
                }
                case 5: {
                    int id;
                    cout << "Enter Customer ID to delete: ";
                    cin >> id;
                    store.deleteCustomer(id);
                    break;
                }
                case 6:
                    inCustomerMenu = false;
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}

void supplierMenu(GroceryStore& store) {
    int choice = 0;
    bool inSupplierMenu = true;
    
    while (inSupplierMenu) {
        cout << "\n===== SUPPLIER MENU =====\n";
        cout << "1. Add Supplier\n";
        cout << "2. Display All Suppliers\n";
        cout << "3. Search Supplier\n";
        cout << "4. Update Supplier\n";
        cout << "5. Delete Supplier\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        try {
            switch (choice) {
                case 1: {
                    int id;
                    string name, contact, phone, address, terms;
                    
                    cout << "Enter Supplier ID: ";
                    cin >> id;
                    cin.ignore();
                    cout << "Enter Supplier Name: ";
                    getline(cin, name);
                    cout << "Enter Contact Person: ";
                    getline(cin, contact);
                    cout << "Enter Phone Number: ";
                    getline(cin, phone);
                    cout << "Enter Address: ";
                    getline(cin, address);
                    cout << "Enter Payment Terms: ";
                    getline(cin, terms);
                    
                    Supplier s(id, name, contact, phone, address, terms);
                    store.addSupplier(s);
                    cout << "Supplier added successfully!\n";
                    break;
                }
                case 2:
                    store.displaySuppliers();
                    break;
                case 3: {
                    int id;
                    cout << "Enter Supplier ID to search: ";
                    cin >> id;
                    Supplier* s = store.searchSupplier(id);
                    if (s) {
                        cout << "\nSupplier found:\n";
                        cout << std::left << std::setw(6) << "ID" 
                             << std::setw(20) << "Name" 
                             << std::setw(20) << "Contact" 
                             << std::setw(15) << "Phone" 
                             << std::setw(25) << "Address" 
                             << std::setw(15) << "Terms" << endl;
                        s->display();
                    } else {
                        cout << "Supplier not found!\n";
                    }
                    break;
                }
                case 4: {
                    int id;
                    string name, contact, phone, address, terms;
                    
                    cout << "Enter Supplier ID to update: ";
                    cin >> id;
                    cin.ignore();
                    
                    Supplier* s = store.searchSupplier(id);
                    if (s) {
                        cout << "Enter new Supplier Name: ";
                        getline(cin, name);
                        cout << "Enter new Contact Person: ";
                        getline(cin, contact);
                        cout << "Enter new Phone Number: ";
                        getline(cin, phone);
                        cout << "Enter new Address: ";
                        getline(cin, address);
                        cout << "Enter new Payment Terms: ";
                        getline(cin, terms);
                        
                        Supplier updated(id, name, contact, phone, address, terms);
                        store.updateSupplier(id, updated);
                        cout << "Supplier updated successfully!\n";
                    } else {
                        cout << "Supplier not found!\n";
                    }
                    break;
                }
                case 5: {
                    int id;
                    cout << "Enter Supplier ID to delete: ";
                    cin >> id;
                    store.deleteSupplier(id);
                    break;
                }
                case 6:
                    inSupplierMenu = false;
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}

void processSaleMenu(GroceryStore& store) {
    cout << "\n===== PROCESS SALE (MAIN TRANSACTION) =====\n";
    
    try {
        int custID, prodID, quantity;
        
        cout << "Enter Customer ID: ";
        cin >> custID;
        cout << "Enter Product ID: ";
        cin >> prodID;
        cout << "Enter Quantity: ";
        cin >> quantity;
        
        store.processSale(custID, prodID, quantity);
    } catch (const exception& e) {
        cerr << "Error processing sale: " << e.what() << endl;
    }
}
