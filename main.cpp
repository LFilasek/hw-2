#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//pass in space-delimited arguments when you call the executable
//Example: ./a.out 1 2 3.3
int main( int argc, char * argv[] )
{
	if (argc > 4) 
	{
		cout << "Too many arguments. Cannot pass in more than three." << endl;
		return -1;
	}

	int i = 1;
	double loan_amount, yearly_interest_rate, monthly_payment;

	double arguments [3];

	if (argc > 1)
	{
		while ( i < argc )
		{

			try
			{
				arguments[i-1] = stod(argv[i]);
			}
			catch(const std::invalid_argument&)
			{
				if(i==1)
					cout << "(Invalid loan amount): " << argv[i] << endl;
				else if (i==2)
					cout << "(Invalid interest rate): " << argv[i-1] << " " << argv[i] << endl;
				else
					cout << "(Invalid payment): " << argv[i-2] << " " << argv[i-1] << " " << argv[i] << endl;
				return -2;
			}
			i++;
		}
	}
	for (int i = 0; i < 4; i++){
		if(!isdigit(argv[i])){
			cout<<"invalid input"<<endl;
			return -1;
		}
	}

	loan_amount = arguments[0];
	
	yearly_interest_rate = arguments[1];
	
	monthly_payment = arguments[2];
	cout << loan_amount << " " << yearly_interest_rate << " " << monthly_payment << endl;



	//get the monthly 
	double Rate = yearly_interest_rate / 12;

	// interest_payment
	double interest_payment = (Rate*loan_amount)/100;

	// calculate the principle
	double principle = monthly_payment - interest_payment;

	int month = 1;

	double total_interest = 0;

	cout << endl;

// check for unpayable loan
	if (monthly_payment <= interest_payment){
		cout<<"impossible to pay loan"<<endl;
		return -1;
	}

	// AMORTIZATION TABLE
	cout << "*****************************************************************\n"
	<< "\tAmortization Table\n"
	<< "*****************************************************************\n"
	<< "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n"; 
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "0" << "	" << loan_amount << "		" << "N/A" << "     " << "N/A" << "	" << "N/A" << "		" << "N/A" << " " << endl;

	while (loan_amount > 0){
		if (principle > loan_amount) {
			principle = loan_amount;
			monthly_payment = loan_amount;
		}
		loan_amount -= principle;
		cout << month << "	" << loan_amount << "		" << monthly_payment << "   "  << Rate << "	" << interest_payment << "		" << principle << "	"  << endl;
		interest_payment = (Rate*loan_amount)/100;
		principle = monthly_payment - interest_payment;
		month++;
		total_interest += interest_payment;
		

	}

	cout << "It takes " << month << " months to pay off the loan." << endl;
	cout << " Total interest paid is: " << total_interest << endl;

	return 0;
}
//hello