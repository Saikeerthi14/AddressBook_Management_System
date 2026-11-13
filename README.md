# 📒 Address Book Management System in C

A menu-driven **Address Book Management System** developed using C programming. This project allows users to efficiently create, search, edit, delete, and manage contact information using structures, pointers, file handling, and string manipulation.

## 📌 Project Overview

The Address Book Management System is designed to store and manage contact details through a command-line interface.

Each contact contains:

- 👤 Name
- 📞 Phone Number
- 📧 Email Address

The application allows users to create new contacts, list all saved contacts, search contacts using different fields, edit existing information, and delete contacts. Contact information is stored in a CSV file for permanent storage.

## ✨ Features

- ➕ **Create Contact:** Add new contact details to the address book.
- 📋 **List All Contacts:** Display all saved contacts with name, contact number, and email ID in a formatted table.
- 🔍 **Search Contact:** Search contacts using name, phone number, or email address.
- ✏️ **Edit Contact:** Update existing contact information.
- ❌ **Delete Contact:** Remove contacts from the address book after confirmation.
- 🔤 **Sort Contacts:** Arrange contacts alphabetically.
- 💾 **Save Contacts:** Store contact information permanently in a CSV file.
- 📂 **Load Contacts:** Retrieve previously saved contact information.
- ✅ **Input Validation:** Validate name, phone number, and email address before storing contact details.

## 🛠️ Technologies Used

- C Programming
- GCC Compiler
- Visual Studio Code
- Git and GitHub

## 🧠 C Programming Concepts Used

This project helped me implement and understand several important C programming concepts.

### 1. Structures

Used structures to organize contact information.

```c
typedef struct Contact
{
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct AddressBook
{
    Contact contacts[100];
    int contactCount;
} AddressBook;
```

### 2. Pointers

Used pointers to access and modify structure members and pass address book information between functions.

### 3. File Handling

Used file handling operations to save and retrieve contact information.

Functions used:

- `fopen()`
- `fprintf()`
- `fscanf()`
- `fclose()`

### 4. String Manipulation

Used string functions to compare, search, and manipulate contact details.

### 5. Searching Techniques

Implemented searching functionality using:

- Contact Name
- Phone Number
- Email Address

The application also handles multiple matching contacts with the same name.

### 6. Sorting Algorithm

Used Bubble Sort to arrange contacts alphabetically based on their names.

### 7. Input Validation

Implemented validation for:

- **Name:** Checks that the name contains only permitted characters according to the validation rules.
- **Phone Number:** Checks that the phone number contains only digits and has 10 digits.
- **Email:** Checks the email format, including the presence of `@` and `.com`, and validates other required characters.

### 8. Modular Programming

Separated the project into multiple source and header files to improve code organization, readability, and reusability.

## 🏗️ Project Structure

```text
AddressBook_Management_System/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── contact.csv
├── a.out
├── README.md
│
└── outputs/
    ├── Screenshot 2026-09-03 155938.png
    ├── Screenshot 2026-09-03 160025.png
    ├── Screenshot 2026-09-03 160115.png
    ├── Screenshot 2026-09-03 160144.png
    ├── Screenshot 2026-09-03 160226.png
    ├── Screenshot 2026-09-03 160253.png
    └── Screenshot 2026-09-03 165611.png
```

## 🔄 How the Project Works

1. Start the Address Book application.
2. Initialize the address book.
3. Load previously saved contacts.
4. Select an operation from the menu.
5. Create new contacts by entering valid details.
6. Validate the entered name, phone number, and email address.
7. List all saved contacts in a formatted table.
8. Search contacts using name, phone number, or email address.
9. Edit existing contact information.
10. Delete contacts after confirmation.
11. Save contact information into the CSV file.

## 💾 Data Storage

The project uses a CSV file named `contact.csv` to store contact information.

Example:

```text
#2
Name,Phone,Email
Sai,9876543210,sai@example.com
Keerthi,9876543211,keerthi@example.com
```

The contact count is stored at the beginning of the file, followed by individual contact records.

## 🚀 Build and Run

### Step 1: Clone the Repository

```bash
git clone https://github.com/Saikeerthi14/AddressBook_Management_System.git
```

### Step 2: Navigate to the Project Directory

```bash
cd AddressBook_Management_System
```

### Step 3: Compile the Program

```bash
gcc main.c contact.c file.c -o addressbook
```

### Step 4: Run the Application

```bash
./addressbook
```

## 📸 Project Outputs

### 1. List All Contacts

Displays all saved contacts with their names, phone numbers, and email addresses in a formatted table.

![List All Contacts](outputs/Screenshot%202026-09-03%20155938.png)

### 2. Main Menu and Contact List

Displays the Address Book menu and available contact records.

![Main Menu](outputs/Screenshot%202026-09-03%20165611.png)

### 3. Create Contact with Input Validation

Demonstrates adding a new contact and validating name, phone number, and email address.

![Create Contact](outputs/Screenshot%202026-09-03%20160025.png)

### 4. Search Contact by Name

Searches contacts using names and handles multiple matching contacts.

![Search by Name](outputs/Screenshot%202026-09-03%20160115.png)

### 5. Search Contact by Email

Demonstrates searching for a contact using an email address.

![Search by Email](outputs/Screenshot%202026-09-03%20160144.png)

### 6. Edit Contact

Updates existing contact information successfully.

![Edit Contact](outputs/Screenshot%202026-09-03%20160226.png)

### 7. Delete Contact

Demonstrates deleting a contact after confirmation.

![Delete Contact](outputs/Screenshot%202026-09-03%20160253.png)

## 📚 Learning Outcomes

Through this project, I gained practical experience in:

- Implementing structures and pointers in C.
- Reading and writing binary and text files.
- Managing contact records using CSV files.
- Implementing searching and sorting techniques.
- Performing string manipulation.
- Validating user inputs.
- Developing modular applications using header and source files.
- Debugging and solving programming errors.
- Building a menu-driven application using C programming.

## 🔮 Future Enhancements

- Implement duplicate contact detection.
- Improve input validation and error handling.
- Support dynamic memory allocation for larger contact databases.
- Add advanced search options.
- Improve the user interface.
- Add password protection.

## 👨‍💻 Author

**Sai Keerthi**

Electronics and Communication Engineering

GitHub: [Sai Keerthi](https://github.com/Saikeerthi14)

**Project Repository:** [Address Book Management System](https://github.com/Saikeerthi14/AddressBook_Management_System)

---

⭐ If you find this project useful for learning C programming, file handling, and contact management, feel free to explore the repository and share your feedback!
