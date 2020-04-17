// FILE: stattest.cpp
//Write your test code in this file


#include <cctype>    // Provides toupper
#include <iostream>  // Provides cout, cin
#include <cstdlib>   // Provides EXIT_SUCCESS
#include "stats.h"
using namespace std;

void printN(Node* head){
	if(head){
		cout << head->data << endl;
		printN(head->next);
	} else {
		return;
	}
}

int main(){
	statistician s1;
	s1.next(2);
	s1.next(3);
	s1.next(2.5);
	
	statistician s2;
	s2.next(11);
	s2.next(12);
	s2.next(13);
	s2.next(15);
	s2.next(16);

	statistician s3;
	s3.next(11.11);
	s3.next(12);
	s3.next(-133);
	s3.next(15);
	s3.next(-16.332);
	
	statistician s4 = 2 * s1;

	statistician s5;
	s5.next(11);
	s5.next(12);
	s5.next(13);
	s5.next(15);
	s5.next(16);

	statistician s6 = -1 * s1;

	statistician s7;
	s7.next(11.11);
	s7.next(12);
	s7.next(-133);
	s7.next(15);
	s7.next(-16.332);

	statistician s8;
	s8.next(4);
	s8.next(6);
	s8.next(5);

	cout << "length";
	assert(s1.length()==3);
	assert(s2.length()==5);
	assert(s3.length()==5);
	assert(s4.length()==3);
	assert((s3+s4).length()==8);
	cout << "     PASSED" << endl;

	cout << "sum";
	assert(s1.sum()==7.5);
	assert(s2.sum()==67.0);
	assert(s3.sum()==-111.222);
	assert(s4.sum()==15);
	assert((s1+s2).sum()==74.5);
	cout << "        PASSED" << endl;

	cout << "mean";
	assert(s1.mean()==7.5/3);
	assert(s2.mean()==67.0/5);
	assert(s3.mean()==-111.222/5);
	assert(s4.mean()==15/3);
	cout << "       PASSED" << endl;

	cout << "minimum";
	assert(s1.minimum()==2);
	assert(s2.minimum()==11);
	assert(s3.minimum()==-133);
	assert(s4.minimum()==4);
	assert((s1+s2).minimum()==2);
	cout << "    PASSED" << endl;

	cout << "maxium";
	assert(s3.maximum()==15);
	assert(s2.maximum()==16);
	assert(s1.maximum()==3);
	assert(s1.maximum()==3);
	assert((s3+s2).maximum()==16);
	cout << "     PASSED" << endl;

	cout << "operator+";
	assert((s3+s2).maximum()==16);
	assert((s1+s2).minimum()==2);
	assert((s1+s2).sum()==74.5);
	assert((s3+s4).length()==8);
	cout << "  PASSED" << endl;

	cout << "operator*";
	assert(s4.sum()==15);
	assert(s4.maximum()==6);
	assert(s4.minimum()==4);
	assert(s4.length()==3);
	assert(s4.mean()==5);
	assert(s6.sum()==-7.5);
	assert(s6.maximum()==-2);
	assert(s6.minimum()==-3);
	assert(s6.length()==3);
	assert(s6.mean()==-7.5/3);
	cout << "  PASSED" << endl;

	cout << "operator==";
	assert(s2==s5);
	assert(s3==s7);
	assert(s4==s8);
	cout << " PASSED" << endl;

	cout << "reset";
	statistician s;
	s1.reset();
	s2.reset();
	s3.reset();
	s4.reset();
	s5.reset();
	assert(s1==s);
	assert(s2==s);
	assert(s3==s);
	assert(s4==s);
	assert(s5==s);
	cout << "      PASSED" << endl;

	cout << "ALL TESTS  PASSED" << endl;



	
	

	return EXIT_SUCCESS;

}

