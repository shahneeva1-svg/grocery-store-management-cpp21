================================================================================
        GROCERY STORE MANAGEMENT SYSTEM - SUBMISSION PACKAGE
================================================================================

PROJECT: CPP21 - Grocery Store Management System
STUDENT ID: IU2541230444
SUBMISSION DATE: October 8, 2024

================================================================================
CONTENTS OF THIS PACKAGE
================================================================================

1. SOURCE CODE (Source/ folder)
   ✓ main.cpp - Menu-driven interface (16.7 KB)
   ✓ GroceryStore.h/cpp - Main controller class
   ✓ Product.h/cpp - Product entity
   ✓ Customer.h/cpp - Customer entity
   ✓ Supplier.h/cpp - Supplier entity
   ✓ Sale.h/cpp - Sale transaction entity
   ✓ FileManager.h/cpp - CSV file I/O utility
   
   Total: 13 source files (~1,400 lines of code)

2. DOCUMENTATION
   ✓ README.txt - Comprehensive project documentation
   ✓ QUICK_REFERENCE.txt - Quick lookup guide
   ✓ This file (SUBMISSION_README.txt)

3. UML DIAGRAMS (Diagrams/ folder)
   ✓ UseCase.txt - Use Case Diagram
   ✓ ClassDiagram.txt - Class Diagram  
   ✓ Sequence1_Sale.txt - Sale Transaction Sequence Diagram
   ✓ Sequence2_Update.txt - Product Update Sequence Diagram

4. SCREENSHOTS (Screenshots/ folder)
   ✓ SCREENSHOTS.txt - Description of all program screenshots

5. BUILD SCRIPT
   ✓ compile.bat - Compilation script for Visual Studio/MinGW

6. DATA DIRECTORY (Data/ folder)
   ✓ Empty at submission (populated at runtime)
   ✓ Runtime-generated CSV files:
     - products.txt
     - customers.txt
     - suppliers.txt
     - sales.txt

7. EXECUTABLE DIRECTORY (Executable/ folder)
   ✓ Empty at submission
   ✓ Contains compiled Project.exe after compilation

================================================================================
HOW TO USE THIS SUBMISSION
================================================================================

STEP 1: EXTRACT THE ZIP
   Unzip IU2541230444_CPP21_Project.zip to any directory

STEP 2: REVIEW DOCUMENTATION
   - Start with README.txt for full system documentation
   - Check QUICK_REFERENCE.txt for quick overview
   - Review UML diagrams in Diagrams/ folder

STEP 3: COMPILE THE PROJECT
   
   Option A - Using Visual Studio C++ Compiler:
   - Open compile.bat and ensure cl.exe is in PATH
   - Run: compile.bat
   - Output: Executable/Project.exe
   
   Option B - Using MinGW (g++):
   - Uncomment g++ lines in compile.bat
   - Comment out cl.exe lines
   - Run: compile.bat
   - Output: Executable/Project.exe
   
   Option C - Manual Compilation (Visual Studio):
   > cd Source
   > cl /EHsc /std:c++17 /Fo../Temp/ Product.cpp Customer.cpp Supplier.cpp Sale.cpp FileManager.cpp GroceryStore.cpp main.cpp /Fe../Executable/Project.exe

STEP 4: RUN THE PROGRAM
   - Navigate to Executable/ folder
   - Run: Project.exe
   - Follow on-screen menu prompts
   - All data saved automatically to Data/ folder on exit

STEP 5: VIEW DATA FILES
   - Check Data/products.txt, customers.txt, suppliers.txt, sales.txt
   - Files use CSV format (human-readable)
   - Data persists across sessions

================================================================================
PROJECT FEATURES
================================================================================

MAIN MENU (9 Operations):

1. PRODUCT MANAGEMENT
   ✓ Add Product to Inventory
   ✓ Display All Products
   ✓ Search Product by ID
   ✓ Update Product (Price/Quantity)
   ✓ Delete Product

2. CUSTOMER MANAGEMENT
   ✓ Add Customer
   ✓ Display All Customers
   ✓ Search Customer by ID

3. SUPPLIER MANAGEMENT
   ✓ Add Supplier
   ✓ Display All Suppliers
   ✓ Search and Update Supplier

4. SALES TRANSACTIONS
   ✓ Process Purchase with Full Validation
   ✓ Auto-Inventory Deduction
   ✓ Customer Spending Tracking
   ✓ Automatic Date Recording

5. BUSINESS REPORTS
   ✓ Sales Report (all transactions)
   ✓ Customer Spending Report (sorted)
   ✓ Supplier Report

6. DATA PERSISTENCE
   ✓ Auto-Save on Exit
   ✓ Auto-Load on Startup
   ✓ CSV File Format

================================================================================
OOP CONCEPTS DEMONSTRATED
================================================================================

✓ ENCAPSULATION
  - Private data members, public interface via getters/setters
  - Validation logic in setters

✓ DYNAMIC MEMORY MANAGEMENT
  - Arrays allocated with 'new' in constructors
  - Deallocated with 'delete[]' in destructors

✓ EXCEPTION HANDLING
  - Try-catch blocks throughout
  - Custom validation exceptions

✓ CLASSES & OBJECTS
  - 6 distinct entity classes
  - Composition relationships
  - Association with FileManager

✓ SEPARATION OF CONCERNS
  - Model classes (Product, Customer, Supplier, Sale)
  - Controller class (GroceryStore)
  - Utility class (FileManager)

================================================================================
SYSTEM REQUIREMENTS
================================================================================

To Compile:
- C++ Compiler (C++17 or later):
  * Visual Studio Build Tools or Community Edition
  * MinGW/GCC
  * Clang
- Standard C++ libraries (<iostream>, <fstream>, <string>, <vector>, <ctime>)

To Run:
- Windows environment (or Linux/Mac with appropriate modifications)
- ~1 MB disk space for executable
- ~100 KB for data files

================================================================================
FILE STRUCTURE
================================================================================

IU2541230444_CPP21_Project/
│
├── Source/
│   ├── main.cpp
│   ├── GroceryStore.h
│   ├── GroceryStore.cpp
│   ├── Product.h
│   ├── Product.cpp
│   ├── Customer.h
│   ├── Customer.cpp
│   ├── Supplier.h
│   ├── Supplier.cpp
│   ├── Sale.h
│   ├── Sale.cpp
│   ├── FileManager.h
│   └── FileManager.cpp
│
├── Diagrams/
│   ├── UseCase.txt
│   ├── ClassDiagram.txt
│   ├── Sequence1_Sale.txt
│   └── Sequence2_Update.txt
│
├── Screenshots/
│   └── SCREENSHOTS.txt
│
├── Data/
│   ├── products.txt (created at runtime)
│   ├── customers.txt (created at runtime)
│   ├── suppliers.txt (created at runtime)
│   └── sales.txt (created at runtime)
│
├── Executable/
│   └── Project.exe (created after compilation)
│
├── Temp/
│   └── (Build artifacts, created during compilation)
│
├── README.txt
├── QUICK_REFERENCE.txt
├── compile.bat
└── SUBMISSION_README.txt (this file)

================================================================================
TESTING CHECKLIST
================================================================================

Before Submission, Verify:

✓ Source code compiles without errors
✓ Program starts and displays menu
✓ Add Product operation works with validation
✓ Display Products shows all entries
✓ Search Product finds by ID
✓ Update Product modifies data correctly
✓ Delete Product removes from system
✓ Add Customer works
✓ Display Customers shows spending
✓ Search Customer finds by ID
✓ Process Sale validates all inputs:
  - Customer exists
  - Product exists
  - Sufficient inventory
  - Correct amount calculation
  - Inventory deducted
  - Customer spending updated
✓ Sales Report displays all transactions
✓ Customer Report shows correct totals
✓ Data files created in Data/ folder
✓ Data persists after exit and restart
✓ UML diagrams present and readable
✓ Documentation complete

================================================================================
TROUBLESHOOTING
================================================================================

Issue: Compiler not found
Solution: Install Visual Studio Build Tools or MinGW
          Ensure compiler is in system PATH

Issue: Cannot find header files
Solution: Verify all .h files are in Source/ folder
          Check compiler include paths in compile.bat

Issue: Linker errors
Solution: Ensure all .cpp files are listed in compile.bat
          No duplicate symbols or missing definitions

Issue: Runtime errors - file not found
Solution: Data/ folder is created at runtime
          First run will generate empty CSV files

Issue: Data not saving
Solution: Check file permissions in Data/ folder
          Verify disk space available
          Look for error messages in console output

Issue: Inventory becomes negative after sale
Solution: This should not happen - validation prevents it
          If occurs, check updated Product::setQuantity() validation

================================================================================
CONTACT & SUPPORT
================================================================================

For questions regarding this submission:
- Review README.txt for detailed documentation
- Check QUICK_REFERENCE.txt for method signatures
- Examine Source code comments for implementation details
- Refer to UML diagrams for architecture overview

================================================================================
DECLARATION
================================================================================

I certify that this is my original work. The code has been written according to
the requirements specified in the CPP21 blueprint. All OOP concepts have been
properly implemented and documented.

Date: October 8, 2024
Student ID: IU2541230444

================================================================================
END OF SUBMISSION README
================================================================================
