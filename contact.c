#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria

    // Bubble sort
    Contact temp;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        for(int j=0;j<addressBook->contactCount-1-i;j++)
        {
            if(addressBook->contacts[j].name[0]>addressBook->contacts[j+1].name[0])
            {
                temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;
            }
        }
    }
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("|                                          LIST OF CONTACTS                                               |\n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("| %-6s %-50s %-14s %-30s|\n","S.No","ContactName","ContactNumber","Email ID                       ");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    //For printing the all contacts from the address book
    for(int i=0;i<addressBook->contactCount;i++)
    {
     printf("| %-6d  %-50s %-14s %-30s|\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    printf("-----------------------------------------------------------------------------------------------------------\n");
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


//For checking the name is valid or not
int validate_name(char *str)
{
    for(int i=0;str[i];i++)
    {
        if( ! (str[i]>='A' && str[i]<='Z'|| str[i]>='a' && str[i]<='z' || str[i]==' ' || str[i]== '.')) // not valid
        {
            printf("Name contains only alphabets,space or dot\n");
            return 0;
        }
    }
    return 1;
}

//For checking the phone number is valid or not
int validate_phone(char *str,AddressBook *addressBook)
{
    if(strlen(str)!=10)
    {
        printf("Phone number must have 10 digits\n");
        return 0;
    }
    for(int i=0;str[i];i++)
    {
        if(!(str[i]>='0' && str[i]<='9'))
        {
            printf("Number must contains only digits\n");
            return 0;
        }
    }
    //Checking the phone number is already exists or not in the address book
   for(int i=0;i<addressBook->contactCount;i++)
   {
        if(strcmp(str,addressBook->contacts[i].phone)==0)
        {
            printf("Phone number already exists\n");
            return 0;
        }
    }
    return 1;
}

//For checking the mail is valid or not
int validate_mail(char *str,AddressBook *addressBook)
{
    char *str1=".com";
    if(str[0]>='0' && str[0]<='9')
    {
        printf("Mail does not start with digits\n");
        return 0;
    }
    char ch='@';
    if(strchr(str,ch)==NULL)
    {
        printf("Mail must have @\n");
        return 0;
    }
    if(strchr(strchr(str,ch)+1,ch)!=NULL)
    {
        printf("Mail must contain only one @\n");
        return 0;
    }
    char *res=strstr(str,str1);
    if(res==NULL)
    {
        printf("Mail does not have '.com'\n");
        return 0;
    }
    for(int i=0;str[i];i++)
    {
        if(str[i]==' ')
        {
            printf("Mail does not contain space\n");
            return 0;
        }
        if(!(str[i]>='a' && str[i]<='z' || str[i]=='@' || str[i]=='.' || str[i]=='_' || str[i]>='0' && str[i]<='9'))
        {
            printf("Mail contains only lower case alphabets,dot,@,_,digits\n");
            return 0;
        }
        if(str[i]=='@')
        {
            if(str[i+1]=='.')
            {
                printf("In mail between @ and .com must have any character\n");
                return 0;
            }
        }
    }
    //Checking the mail is already exists or not in the address book
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(str,addressBook->contacts[i].email)==0)
        {
            printf("Email already exists\n");
            return 0;
        }
    }
    return 1;
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */

    char str1[30], str2[11], str3[30];
    int res;

    do
    {
        printf("Enter the name :");
        scanf(" %[^\n]", str1);
        res = validate_name(str1);
    }while(res == 0); // 0 means invalid

    do
    {
        printf("Enter the phone number :");
        scanf("%s", str2);
        res = validate_phone(str2,addressBook);
    }while(res == 0);

    do
    {
        printf("Enter the mail :");
        scanf(" %[^\n]", str3);
        res = validate_mail(str3,addressBook);
    }while(res == 0);
    //storing the contact details in the address book
    strcpy(addressBook->contacts[addressBook->contactCount].name, str1);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, str2);
    strcpy(addressBook->contacts[addressBook->contactCount].email, str3);

    addressBook->contactCount++;
    printf("Contact Created Successfully\n");

}
//searching the contact by name in the address book
int search_by_name(AddressBook *addressBook)
{
    char str[30];
    printf("Enter the name:");
    scanf(" %[^\n]",str);
    int count=0,k=0;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(str,addressBook->contacts[i].name)==0)
        {
            count++;
            printf("Contact found\n");
            printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            k=i;
        }
    }
    if(count==1)
    {
        return k;
    }
    //checking if multiple contacts have same name or not
    else if(count>1)
    {
        printf("Multiple contacts have same name\n");
        return search_by_phone(addressBook);
    }
    else
    {
        printf("Name not found");
        return -1;
    }

}

//searching the contact by phone number in the address book
int search_by_phone(AddressBook *addressBook)
{
    char str[20];
    printf("Enter the phone number ");
    scanf("%s",str);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(str,addressBook->contacts[i].phone)==0)
        {
            printf("Contact found\n");
            printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            return i;
        }
    }
    printf("Phone number not found");
    return -1;
}
//searching the contact by email in the address book
int search_by_mail(AddressBook *addressBook)
{
    char str[40];
    printf("Enter the email ");
    scanf("%s",str);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(str,addressBook->contacts[i].email)==0)
        {
            printf("Contact found\n");
            printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            return i;
        }
     }
    printf("Email not found");
    return -1;
}
//for searching the contact by name,phone number or email in the address book
void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */

    int choise;

    // print promt
    printf("search  by:\n 1.Name\n 2.Phone\n 3.Email\n 4.Exit\n");
    printf("Enter the choise: ");
    scanf("%d", &choise);

    switch(choise)
    {
        case 1:
            search_by_name(addressBook);
            break;
        case 2:
            search_by_phone(addressBook);
            break;
        case 3:
            search_by_mail(addressBook);
            break;
        case 4:
            return;
        default:
           printf("Invalid choise,try again\n");
    }
}
//for editing the contact by name,phone number or email in the address book
void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    printf("Search by:\n");
    printf("1.Name\n 2.Phone\n 3.Email\n 4.Exit\n");
    int choice;
    printf("Enter the choice ");
    scanf("%d",&choice);
    int ind;
    //For editing first we have to search the contact by name,phone number or email in the address book
    switch(choice)
    {
        case 1:
           ind=search_by_name(addressBook);
           break;
        case 2:
           ind=search_by_phone(addressBook);
           break;
        case 3:
           ind=search_by_mail(addressBook);
           break;
        case 4:
           return;
        default:
           printf("Invalid choise,try again\n");
    }
    if(ind==-1)
       return;
    printf("Enter the field to edit\n");
    printf("1.Name\n 2.Phone\n 3.Email\n 4.Exit\n");
    printf("Enter the choice ");
    scanf("%d",&choice);
    char str[40];
    int res;
    //User can enter the choice to edit the contacts
    switch(choice)
    {
        case 1:
           do
            {
             printf("Enter name ");
             scanf(" %[^\n]",str);
             res=validate_name(str);
             if(res==0)
                printf("Invalid name\n");
            } while(res==0);
           strcpy(addressBook->contacts[ind].name,str);
           printf("Name updated successfully\n");
           break;
        case 2:
           do
            {
             printf("Enter phone number ");
             scanf("%s",str);
             res=validate_phone(str,addressBook);
             if(res==0)
                printf("Invalid phone number\n");
            } while(res==0);
           strcpy(addressBook->contacts[ind].phone,str);
           printf("Phone number updated successfully\n");
           break;
        case 3:
            do
            {
             printf("Enter Email ");
             scanf("%s",str);
             res=validate_mail(str,addressBook);
             if(res==0)
               printf("Invalid email\n");
            } while(res==0);
            strcpy(addressBook->contacts[ind].email,str);
            printf("Email updated successfully\n");
            break;
        case 4:
           return;
        default:
           printf("Invalid choise,try again\n"); 
    }
}
//For deleting the contact by name,phone number or email in the address book
void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    char ch;
    printf("If you want to delete the contact give as y/n(yes or no)\n");
    scanf(" %c",&ch);
    if(ch=='n')
        return;
    else
    {
    //For deleting first we have to search the contact by name,phone number or email in the address book 
    printf("Search to delete contact:\n");
    printf("1.Name\n 2.Phone\n 3.Email\n 4.Exit\n");
    int choice;
    printf("Enter the choice ");
    scanf("%d",&choice);
    int ind;
    switch(choice)
    {
        case 1:

           ind=search_by_name(addressBook);
           break;
        case 2:
           ind=search_by_phone(addressBook);
           break;
        case 3:
           ind=search_by_mail(addressBook);
           break;
        case 4:
           return;
        default:
           printf("Invalid choise,try again\n");
    }
    if(ind==-1)
       return;
    //After searching the contact we have to delete the contact from the address book by shifting the contacts
    for(int i=ind;i<addressBook->contactCount-1;i++)
    {
        addressBook->contacts[i]=addressBook->contacts[i+1];
    }
    addressBook->contactCount--;  
    printf("Contact deleted successfully\n");
}
}
