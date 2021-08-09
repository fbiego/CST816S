/*
   MIT License

  Copyright (c) 2021 Felix Biego

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#ifndef MPESASTK_H
#define MPESASTK_H

#include <Arduino.h>


#define	SANDBOX		"https://sandbox.safaricom.co.ke/"
#define PRODUCTION	"https://api.safaricom.co.ke/"

#define	PAYBILL		"CustomerPayBillOnline"
#define	BUY_GOODS	"CustomerBuyGoodsOnline"


#define TEST_CODE	174379

class MpesaSTK {
	
	public:
		MpesaSTK(String consumer_key, String consumer_secret, String pass_key, String environment = SANDBOX);
		void begin(int code = TEST_CODE, String type = PAYBILL, String url = "http://mycallbackurl.com/checkout.php", int gmt = 3, bool set = true);
		String pay(String number, int amount, String reference, String description);
		
	private:	
		bool getToken();
		String encoder64(String input);
		String stkPush();
		void setTime(int gmt, int dst = 0);
		String getTime(String format);
		tm getTimeStruct();
		
		int _amount;
		int _business_code;
		String _consumer_key;
		String _consumer_secret;
		String _pass_key;
		String _callback_url;
		String _transaction_type;
		String _token;
		String _number;
		String _reference;
		String _description;
		String _environment;
};


#endif
