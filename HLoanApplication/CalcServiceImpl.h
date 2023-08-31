#pragma once
#include <map>
#include <string>
#include<math.h>
using namespace std;

class CalcServiceImpl {

public:
	static float emiCalc(long int LoanAmt, long int IntrestRate, long int Tenure) {
		double RATE_OF_INTEREST = (double)IntrestRate / 1200;
		double compounded_rate = pow(1 + RATE_OF_INTEREST, Tenure * 12);
		double denominator = (double)(compounded_rate - 1);
		double numerator = LoanAmt * RATE_OF_INTEREST * compounded_rate;

		double EMI = numerator / denominator;
		return long int(EMI);
		
	}
	static long int getEmitenure(long int rp, float i, float e) {
		long int tenure = (log(e) - log(e - ((float)rp * i))) / log(1 + i);
		return tenure;

	}
	static map<string, string> getEmi(long int LoanAmt, long int IntrestRate, long int Tenure) {
		map<string, string> response;
		double EMI = CalcServiceImpl::emiCalc(LoanAmt, IntrestRate, Tenure);
		
		double TotalPayableAmt = EMI * Tenure * 12;
		double PayableIntrest = TotalPayableAmt - LoanAmt;
		//////////

		response["loan_emi"] = to_string(int(EMI));
		response["payable_intrest"] = to_string(int(PayableIntrest));
		response["total_payment"] = to_string(int(TotalPayableAmt));

		return response;

	}
	static map<string, string> getEligibilityCheck(long int salary,long int property_cost) {


		float PART_OF_THE_SALARY = 0.6;
		
		double eligible_amt =int((PART_OF_THE_SALARY * salary/12 * property_cost) / (CalcServiceImpl::emiCalc(property_cost, 8.5, 10))); // Special Bank offer EMI
		map<string, string> response;
		if (salary < 50000) {
			response["Cibil"] = "<600";
			response["ApprovalProbab"] = "Low";

			response["EligiblityAmt"] = to_string(eligible_amt);
		}
		else if (salary < 400000) {
			response["Cibil"] = "600-649";
			response["ApprovalProbab"] = "Difficult";

			response["EligiblityAmt"] = to_string(eligible_amt);
		}
		else if (salary < 800000) {
			response["Cibil"] = "650-699";
			response["ApprovalProbab"] = "Possible";
			response["EligiblityAmt"] = to_string(eligible_amt);
		}
		else if (salary < 1500000) {
			response["Cibil"] = "700-749";
			response["ApprovalProbab"] = "Good";
			response["EligiblityAmt"] = to_string(eligible_amt);
		}
		else if (salary >= 1500000) {
			response["Cibil"] = "750-900";
			response["ApprovalProbab"] = "Very High";
			response["EligiblityAmt"] = to_string(eligible_amt);
		}
		return response;

}

};