// code dash retry 3-12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//car rental system with 3 options, standard, family sized, exotic
// rental depends on length of days the car will be rented
// system should be used by multiple user
// the company expanded. providing 3 tiers of cleaning services
// and 3 additional features with maximum 2 baby seats, exapned back, trailer
// user can store multiple orders

#include <iostream>
using namespace std;

int main()
{
	int bill, payment, change, days,seats,seatsBaby;
	char carChoice, againRent, cleanWant,cleanTier,feature;
	bool invalidCar, rentAgain, invalidRentAgain, invalidCleanWant,invalidTier, invalidFeature,cleanAgain,featureAgain;

	//Loop condition for renting again
	do {
		seatsBaby = 0;
		rentAgain = false;
		cout << "Welcome to Rent a Car"<<endl;

		//Loop condition for invalid car chosen
		do {
			bill = 0;
			invalidCar = false;
			cout << "Please select an option" << endl;
			cout << "1. Standard     - $50" << endl;
			cout << "2. Family Sized - $100" << endl;
			cout << "3. Exotic       - $150" << endl;
			cin >> carChoice;

			//Car Choice
			switch (carChoice)
			{
			case '1':
				bill += 50;
				cout << "You have chosen Standard" << endl;
				break;
			case'2':
				bill += 100;
				cout << "You have selected Family Sized" << endl;
				break;
			case'3':
				bill += 150;
				cout << "You have selected Exotic" << endl;
				break;
			default:
				cout << "Invalid option" << endl;
				invalidCar = true;
				break;
			}

			//Loop condition for invalid car chosen
		} while (invalidCar);

		//Allows user to select another feature
		do {
			//Loop condition for invalid feature
			do {
				invalidFeature = false;

				//Car feature selection
				cout << "Select a feature that you want to apply to your vehicle" << endl;
				cout << "1. Baby Seats (max 2)" << endl;
				cout << "2. Expanded Back" << endl;
				cout << "3. Trailer" << endl;
				cout << "4. Done selecting features" << endl;
				cin >> feature;
				switch (feature)
				{
				case'1':
					cout << "You have selected Baby Seats" << endl;
					cout << "Enter number of seats($5 per seat): " << endl;
					cin >> seats;
					//Ensures baby seats is within maximum range
					while (seats > 2)
					{
						cout << "Number of seats not applicable" << endl;
						cout << "Enter number of seats: " << endl;
						cin >> seats;
					}
					//Ensures baby seats is within maximum range
					if (seatsBaby == 1 && seats >= 2)
					{
						cout << "Not applicable for current amount of baby seats"<<endl;
					}
					//Ensures baby seats is within maximum range
					else if (seatsBaby == 2)
					{
						cout << "Maximum number of baby seats has been reached" << endl;
					}
					//Baby seats within maximum range
					else
					{
						seatsBaby += seats;
					}

					featureAgain = true;
					break;
				case'2':
					cout << "You have selected Expanded Back" << endl;
					cout << "Enter number of seats($5 per seat): " << endl;
					cin >> seats;
					featureAgain = true;
					break;
				case'3':
					cout << "You have selected Trailer" << endl;
					cout << "Enter number of trailers($5 per trailer): " << endl;
					cin >> seats;
					featureAgain = true;
					break;
				case'4':
					featureAgain = false;
					break;
				default:
					cout << "Invalid answer" << endl;
					invalidFeature = true;
					featureAgain = false;
					break;
				}
				//Loop condition for invalid feature
			} while (invalidFeature);

			bill += seats;
		} while (featureAgain);
		//Days the car will be rented
		cout << "How many days would you like to rent the car?" << endl;
		cout << "Enter number of days: ";
		cin >> days;
		bill = days * bill;

		//Loop condition for invalid clean service answer
		do {
			invalidCleanWant = false;
			cout << "Would you like to avail for our cleaning services?(y/n)" << endl;
			cin >> cleanWant;
			switch (cleanWant)
			{
			case'y':
				//Allows user to clean as much as they want
				do {
					//Loop condition for invalid tier
					do {
						//Cleaning Service
						invalidTier = false;
						cout << "Select a tier for cleaning\n";
						cout << "1. Water only    - $10" << endl;
						cout << "2. Water w/ Soap - $30\n";
						cout << "3. Brushing only - $10\n";
						cout << "4. Done cleaning" << endl;
						cout << "Enter number of answer: ";
						cin >> cleanTier;
						switch (cleanTier)
						{
						case'1':
							bill += 10;
							cout << "You have chosen water only" << endl;
							cleanAgain = true;
							break;
						case'2':
							bill += 30;
							cout << "You have chosen water with soap" << endl;
							cleanAgain = true;
							break;
						case '3':
							bill += 10;
							cout << "You have chosen brushing only" << endl;
							cleanAgain = true;
							break;
						case'4':
							cleanAgain = false;
							break;
						default:
							cout << "Invalid answer" << endl;
							cleanAgain = false;
							invalidTier = true;
							break;
						}
						//Loop condition for invalid tier
					} while (invalidTier);
				//Allows user to clean as much as they want
				} while (cleanAgain);
				break;
			case'n':
				break;
			default:
				cout << "Invalid answer" << endl;
				invalidCleanWant = true;
				break;
			}

			//Loop condition for invalid clean service answer
		} while (invalidCleanWant);

		//Payment
		cout << "Please pay $" << bill << endl;
		cout << "Enter payment: ";
		cin >> payment;
		change = payment - bill;

		//Ensures payment is sufficient
		while (change < 0)
		{
			cout << "Payment insufficient, please pay again" << endl;
			cout << "Please pay $" << bill << endl;
			cout << "Enter payment: ";
			cin >> payment;
			change = payment - bill;
		}
		//Displays change
		cout << "Your change is $" << change << endl;

		//Condition for invalid rent again answer
		do {
			invalidRentAgain = false;
			cout << "Would you like to rent again?(y/n)";
			cin >> againRent;
			switch (againRent)
			{
			case'y':
				rentAgain = true;
				break;
			case 'n':
				break;
			default:
				cout << "Invalid answer" << endl;
				invalidRentAgain = true;
				break;
			}
		//Condition for invalid rent again answer
		} while (invalidRentAgain);
	//Loop condition for renting again
		system("cls");
	} while (rentAgain);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
