/*
 * 파일이름: HighCreditAccount.h
 * 작성자: 윤성우
 * 업데이트 정보: [2010, 01, 01] 파일버전 0.7 
 */

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int ID, int money, char * name, int rate, int special)
		: NormalAccount(ID, money, name, rate), specialRate(special)
	{  }	
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);        // 원금과 이자추가 
		Account::Deposit(money*(specialRate/100.0));   // 특별이자추가
	}
};
#endif