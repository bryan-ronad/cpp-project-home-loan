#pragma once
#include <map>
#include <string>
using namespace std;

class CalcServiceImpl {

public:
	static float emiCalc(long int LoanAmt, long int IntrestRate, long int Tenure) {
		float RATE_OF_INTEREST = (float)IntrestRate / 1200;
		float compounded_rate = pow(1 + RATE_OF_INTEREST, Tenure * 12);
		float denominator = (double)(compounded_rate - 1);
		float numerator = LoanAmt * RATE_OF_INTEREST * compounded_rate;

		float EMI = numerator / denominator;
		return EMI;
		
	}
	static map<string, string> getEmi(long int LoanAmt, long int IntrestRate, long int Tenure) {
		map<string, string> response;
		float EMI = CalcServiceImpl::emiCalc(LoanAmt, IntrestRate, Tenure);
		
		float TotalPayableAmt = EMI * Tenure * 12;
		float PayableIntrest = TotalPayableAmt - LoanAmt;
		//////////

		response["loan_emi"] = to_string(int(EMI));
		response["payable_intrest"] = to_string(int(PayableIntrest));
		response["total_payment"] = to_string(int(TotalPayableAmt));

		return response;

	}
	static map<string, string> getEligibilityCheck(long int salary,long int property_cost) {


		float PART_OF_THE_SALARY = 0.6;
		
		float eligible_amt =int((PART_OF_THE_SALARY * salary/12 * property_cost) / (CalcServiceImpl::emiCalc(property_cost, 8.5, 10))); // Special Bank offer EMI
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