#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"contacts.h"
#include"contactHelpers.h"


// getName:
void getname(struct Name* name) {

	//Contact Name Input:
	printf("Please enter the contact's first name: ");

	scanf("%30[^\n]s", name->firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	clearKeyboard();
	if (yes() == 1)
	{
		printf("Please enter the contact's middle initial(s): ");

		scanf("%6[^\n]s", name->middleInitial);
		clearKeyboard();
	}
	else
	{
		name->middleInitial[0] = '\0';
	}

	printf("Please enter the contact's last name: ");
	
	scanf("%35[^\n]s", name->lastName);
	clearKeyboard();
}
// getAddress:
void getaddress(struct Address* address) {
	int tempnumber = 0;
	do
	{
	printf("Please enter the contact's street number: ");
	
	tempnumber = getInt();
	
	} while (tempnumber<=0);

	address->streetNumber = tempnumber;
	
	printf("Please enter the contact's street name: ");

	scanf("%[^\n]s", address->street);
	clearKeyboard();
	printf("Do you want to enter an apartment number? (y or n): ");
	
	if (yes() == 1)
	{
		
		
		do
		{
		printf("Please enter the contact's apartment number: ");
		tempnumber = getInt();

		} while (tempnumber<=0);
		address->apartmentNumber = tempnumber;
	}

	printf("Please enter the contact's postal code: ");

	scanf("%7[^\n]s", address->postalCode);
	clearKeyboard();
	printf("Please enter the contact's city: ");
	
	scanf("%[^\n]s", address->city);
	clearKeyboard();
}
// getNumbers:
void getnumber(struct Numbers* number) {


	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(number->cell);

	printf("Do you want to enter a home phone number? (y or n): ");

	if (yes() == 1)
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(number->home);
	}
	else
	{
		number->home[0] = '\0';
	}

	printf("Do you want to enter a business phone number? (y or n): ");

	if (yes() == 1)
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(number->business);
	}
	else
	{
		number->business[0] = '\0';
	}
}
// getContact:
void getContact(struct Contact* contact) {


	getname(&contact->name);
	getaddress(&contact->address);
	getnumber(&contact->numbers);



}
