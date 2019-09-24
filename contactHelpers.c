
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>




#include<string.h>
#include<ctype.h>


// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:

#include"contactHelpers.h"
#include"contacts.h"
// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); 
}

// pause:
void pause(void) {
	printf("(Press Enter to Continue)");
	while (getchar() != '\n');
}

// getInt:
int getInt(void) {
	char NL = 'x';
	int Value = 0;
	while (NL != '\n')
	{
		scanf("%d%c", &Value, &NL);
		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return Value;
}

// getIntInRange:
int getIntInRange(int min, int max) {
	int keeptry = 0;
	int Value = 0;
	while (keeptry == 0)
	{
		Value = getInt();
		if (Value > max || Value < min) { printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max); }
		else { keeptry = 1; }

	}
	return Value;
}

// yes:
int yes(void) {

	char NL = 'x';
	char Value = 0;
	int output = 0;

	while (NL != '\n') {

		scanf("%c%c", &Value, &NL);
		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else if (NL == '\n' && Value != 'y' && Value != 'Y' && Value != 'n' && Value != 'N') {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			NL = 'x';
		}
		else if (NL == '\n' && (Value == 'y' || Value == 'Y' || Value == 'n' || Value == 'N'))
		{
			if (Value == 'y' || Value == 'Y') { output = 1; }
			if (Value == 'N' || Value == 'n') { output = 0; }
		}

	}
	return output;
}

// menu:
int menu(void) {
	int max = 6;
	int min = 0;
	int output = 0;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	output = getIntInRange(min, max);

	return output;
}

// contactManagerSystem:
void contactManagerSystem(void) {
	int menuitem = 0;
	int yesresult = 0;
	struct Contact contact[MAXCONTACTS]={ { { "Rick", {'\0'}, "Grimes" },
 { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
 { "4161112222", "4162223333", "4163334444" } },
 {
 { "Maggie", "R.", "Greene" },
 { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
 { "9051112222", "9052223333", "9053334444" } },
 {
 { "Morgan", "A.", "Jones" },
 { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
 { "7051112222", "7052223333", "7053334444" } },
 {
 { "Sasha", {'\0'}, "Williams" },
 { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
 { "9052223333", "9052223333", "9054445555" } },
 };
	while (yesresult == 0) {

		menuitem = menu();
		
			//printf("\n<<< Feature %d is unavailable >>>\n\n", menuitem);
			//pause();
			switch (menuitem)
			{
			case 1: 
				printf("\n");
				displayContacts(contact,MAXCONTACTS);
				break;
			case 2:
				printf("\n");
				addContact(contact, MAXCONTACTS);
				break;
			case 3:
				printf("\n");
				updateContact(contact, MAXCONTACTS);
				break;
			case 4:
				printf("\n");
				deleteContact(contact, MAXCONTACTS);
				break;
			case 5:
				printf("\n");
				searchContacts(contact, MAXCONTACTS);
				break;
				case 6:
				sortContacts(contact, MAXCONTACTS);
				break;
			case 0:
		
			     printf("\nExit the program? (Y)es/(N)o: ");
			     yesresult = yes();
			     if (yesresult == 1) {
				 printf("\nContact Management System: terminated\n");
				 yesresult = 2;
			      }
			      //else{
				   //printf("\n");
			      //}
			
		    }
			
			if (menuitem!=0)
			{
				printf("\n");
				pause();
				printf("\n");
			}
			else
			{
				printf("\n");
			}
	}
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;
	int l = 0;
	int k = 0;
	while (needInput == 1) {
		 k = 0;
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10) {

			for ( l = 0; l < 10; l++) {
				if (isdigit(telNum[l]) == 0) { k = 1; l = 10; };
			}

			if (k != 1) {
				needInput = 0;

			}

			else {
				printf("Enter a 10-digit phone number: ");
			}

		}

		else
			printf("Enter a 10-digit phone number: ");


	}

}

// findContactIndex:
int findContactIndex(const struct Contact contact[], int a, const char b[]) {
	int value = -1;
	int i = 0;

	for (i = 0; i < a; i++)
	{
		if (strcmp(contact[i].numbers.cell, b) == 0) {
			value = i;
			i = a;
		}

	}



	return value;
}

// displayContactHeader
void displayContactHeader(void) {
	
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

	
}


// displayContactFooter
void displayContactFooter(int a) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n", a);
}

// displayContact:
void displayContact(const struct Contact* a) {
	printf(" %s", a->name.firstName);
	if (a->name.middleInitial[0]== '\0')
	{
		printf(" %s", a->name.middleInitial);
		printf(" %s\n", a->name.lastName);
	}
	else { printf(" %s\n", a->name.lastName); }

	printf("    C: %-10s   H: %-10s   B: %-10s\n", a->numbers.cell, a->numbers.home, a->numbers.business);

	printf("       %d %s, ", a->address.streetNumber, a->address.street);
	if (a->address.apartmentNumber > 0)
	{
		printf("Apt# %d, ", a->address.apartmentNumber);
	}
	printf("%s, %s\n", a->address.city, a->address.postalCode);
}
// displayContacts:
void displayContacts(const struct Contact a[], int b) {
	int i = 0;
	int j = 0;
	//int k = 0;
	displayContactHeader();
	
	for ( i = 0; i < b; i++)
	{
		
		if (a[i].numbers.cell != '\0') { displayContact(&a[i]); j++; }
	}

	displayContactFooter(j);

}
// searchContacts:
void searchContacts(const struct Contact a[], int b) {
	char phonenumber[11];
	int i = 0;
	
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phonenumber);
	
	i = findContactIndex(a, b, phonenumber);
	if (i!=-1){
		printf("\n");
		displayContact(&a[i]);
		//printf("\n");
	}
	else
	{
		printf("*** Contact NOT FOUND ***");
		printf("\n");
	}
		
}


// addContact:
void addContact(struct Contact a[], int b) {
	int i = 0;
	int j = b;
	for (i = 0; i < b; i++)
	{
		if (strlen(a[i].numbers.cell)==0)
		{
			j = i;
			i = b;
		}
		
	}
	if(j==b){
		printf("*** ERROR: The contact list is full! ***");
		printf("\n");
		}
	else
	{
		getContact(&a[j]);
		printf("--- New contact added! ---\n");
	}

}


// updateContact:
void updateContact(struct Contact a[], int b) {
	char telephon[11];
	int j = 0;
	int k = 0;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(telephon);
	j = findContactIndex(a, b, telephon);

	if (j == -1) {
		
		printf("*** Contact NOT FOUND ***");
		printf("\n");
	}
	else
	{
		printf("\n");
		printf("Contact found:");
		printf("\n");
		displayContact(&a[j]);
		printf("\n");
		
		printf("Do you want to update the name? (y or n): ");
		
		if (yes()==1) {
			getname(&a[j].name);
			k = 1;
		}
		
		printf("Do you want to update the address? (y or n): ");
		
		if (yes() == 1) {
			getaddress(&a[j].address);
			k = 1;
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1) {
			getnumber(&a[j].numbers);
			k = 1;
		}
		if (k==1)
		{
			printf("--- Contact Updated! ---");
				printf("\n");
		}
	}

}


// deleteContact:
void deleteContact(struct Contact a[], int b) {
	char telephone[11];
	int j = 0;
	printf("Enter the cell number for the contact: ");
	//printf("\n");
	getTenDigitPhone(telephone);
	j = findContactIndex(a,b,telephone);
	if (j == -1) {
		printf("*** Contact NOT FOUND ***");
		printf("\n");
	}
	else
	{
		printf("\n");
		printf("Contact found:");
		printf("\n");
		displayContact(&a[j]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes()==1)
		{
			a[j].numbers.cell[0] = '\0';
			printf("--- Contact deleted! ---");
			printf("\n");
		}
	}
}


// sortContacts:

void sortContacts(struct Contact a[], int b) {
	struct Contact contact = { { {'\0'}, {'\0'}, {'\0'} },{ 0, {'\0'}, 0, {'\0'}, {'\0'} },{ {'\0'}, {'\0'}, {'\0'} } };
	int i = 0;
	int j = 0;

		for (i = b - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (strcmp(a[j].numbers.cell , a[j + 1].numbers.cell)>0) {
					contact = a[j];
					a[j] = a[j + 1];
					a[j + 1] = contact;
				}
			}
		}
	
		printf("\n--- Contacts sorted! ---\n");
}
