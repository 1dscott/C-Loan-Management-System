/**************************************************************************
*C++
*Loan management system
*Ask user for loan amount, anual interest rate, and number of months
*************************************************************************/

#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <iomanip.h>


int main()
{
	/*Declare variables needed*/
   float Amount, InterestRate, InterestRate2, Payment, Principal, Interest, TotalPrincipal, TotalInterest, Balance;
   int pageCount = 1;
   char Continue;
   int Months;
   int k, i;  
   int w = 12; 
   clrscr();
   
	/*Prompt the user and save the users input to relevant variables*/
   cout << "Please enter the amount borrowed: ";
   cin  >> Amount;
   cout << endl << "Please enter the annual interest rate: ";
   cin  >> InterestRate;
   cout << endl << "Please enter the number of months of financing: ";
   cin  >> Months;

	/*Interest rate equations*/
   InterestRate = InterestRate/100;
   InterestRate2 = InterestRate * 100;
   Payment  = Amount*InterestRate/(12*(1 - pow(1 + InterestRate/12, -Months)));
   Balance = Amount;
   
   /*Output information to the user*/
   cout << setprecision(2);
   cout << setiosflags(ios::showpoint) << setiosflags(ios::fixed);
		
		cout << endl << "Page " << pageCount << ":" << endl;
		cout << "======" << endl << endl << endl;
		cout << "Amount Borrowed: " << Amount << endl;
		cout << "Annual Interest Rate: " << InterestRate2 << "%" << endl;
		cout << "Months of Financing: " << Months << endl << endl;
		cout << "Monthly Payment: " << Payment << endl << endl;
		cout << "======================================================" << endl << endl << endl;
		cout << "                                   " << "TOTAL" << "       " << "TOTAL" << endl;
		cout << setw(3) <<" MON" << setw(w) << "PRINCIPAL" << setw(w) << "INTEREST" << setw(w) << "PRINCIPAL" << setw(w) << "INTEREST" << setw(w) << "BALANCE" << endl;
		cout << " " << "===" << setw(w) << "=========" << setw(w) << "========" << setw(w) << "=========" << setw(w) << "========" << setw(w) << "=======" <<endl;

		

		/*go through up to 100 pages displaying the relevant information for the loan*/
		for (i = 1; i <= 100; i++)
		{	
				
			Interest = Balance * (InterestRate/12); 
			Principal = Payment - Interest;
			TotalPrincipal = TotalPrincipal + Principal;
			TotalInterest = TotalInterest + Interest; 
			Balance = Balance - Principal;

			cout << setw(3) << i << "." <<setw(w) << Principal << setw(w) << Interest << setw(w) << TotalPrincipal << setw(w) << TotalInterest << setw(w) << Balance << endl;
       
			if (i%12 == 0)
			{	
				pageCount=pageCount+1;			
				cout << "\n\nPress any key to continue ... " << endl;
				getch();
				clrscr();
				cout << endl << "Page " << pageCount << ":" << endl;
				cout << "======" << endl << endl << endl;
				cout << "Amount Borrowed: " << Amount << endl;
				cout << "Annual Interest Rate: " << InterestRate2 << "%" << endl;
				cout << "Months of Financing: " << Months << endl << endl;
				cout << "Monthly Payment: " << Payment << endl << endl;
				cout << "======================================================" << endl << endl << endl;
				cout << "                                   " << "TOTAL" << "       " << "TOTAL" << endl;
				cout << setw(3) <<" MON" << setw(w) << "PRINCIPAL" << setw(w) << "INTEREST" << setw(w) << "PRINCIPAL" << setw(w) << "INTEREST" << setw(w) << "BALANCE" << endl;
				cout << " " << "===" << setw(w) << "=========" << setw(w) << "========" << setw(w) << "=========" << setw(w) << "========" << setw(w) << "=======" <<endl;
			}
			// end if
		}
		return 0;
	
}
// end function main