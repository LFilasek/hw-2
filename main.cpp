#include <iostream>

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

	loan_amount = arguments[0];
	yearly_interest_rate = arguments[1];
	monthly_payment = arguments[2];
	cout << loan_amount << " " << yearly_interest_rate << " " << monthly_payment << endl;

	//get the monthly 
	int Rate = yearly_interest_rate / 12;

	// interest_payment
	int interest_payment = (Rate*loan_amount)/100;

	// calculate the principle
	int principle = monthly_payment - interest_payment;

	int month = 0;

	int total_interest = 0;

	cout << endl;
	// AMORTIZATION TABLE
	cout << "*****************************************************************\n"
	<< "\tAmortization Table\n"
	<< "*****************************************************************\n"
	<< "Month\tBalance\tPayment\tRate\tInterest\tPrincipal\n"; 
	
	while (loan_amount > 0){
		cout << loan_amount << endl;
		loan_amount -= principle;
		interest_payment = (Rate*loan_amount)/100;
		principle = monthly_payment - interest_payment;
		month++;
		cout << month << endl;

	}

	return 0;
}
//hello