#include <iostream>
using namespace std;

struct Node{
	double data;
	Node* next;
};

void ResetN(Node* head);

double sumN(Node* head);

double minN(Node* head, int len);

double maxN(Node* head, int len);

void scaleN(double n, Node* head);

class statistician{
	public:
		statistician();

		void next(double r);

		void reset( );

		int length( ) const;

		double sum() const;

		double mean( ) const;

		double minimum( ) const;

		double maximum( ) const;

		double getN(int n) const;

		Node* getH();

		friend statistician operator+(const statistician& s1, const statistician& s2);
		friend statistician operator *(double scale, const statistician& s);
		friend bool operator ==(const statistician& s1, const statistician& s2);
		

	private:
		Node* head;
		Node* tail;
		int len;
};

void ResetN(Node* head){
	if(head){
		ResetN(head->next);
		delete head;
	} else {
		return;
	}
}

double sumN(Node* head){
	if(head){
		return head->data + sumN(head->next);
	} else {
		return 0;
	}
}

double minN(Node* head, int len){
	double res = head->data;
	for(int i = 0; i < len; head = head->next){
		if(head->data < res){
			res = head->data;
		}
		i++;
	}
	return res;
}

double maxN(Node* head, int len){
	double res = head->data;
	for(int i = 0; i < len; head = head->next){
		if(head->data > res){
			res = head->data;
		}
		i++;
	}
	return res;
}

void scaleN(double n, Node* head){
	if(head){
		head->data = head->data * n;
		scaleN(n, head->next);
	} else {
		return;
	}
}

statistician::statistician(){
	head = new Node;
	head->data = 0; 
	head->next = NULL;
	tail = head;
}

void statistician::next(double r){
	tail->data = r;
	Node* n = new Node;
	n->data = 0;
	n->next = NULL;
	tail->next = n;
	tail = n;
	len++;
}

void statistician::reset( ){
	ResetN(head->next);
	head->data = 0;
	head->next = NULL;
	tail = head;
	len = 0;
}

int statistician::length( ) const{
	return len;
}

double statistician::sum() const{
	return sumN(head);
}

double statistician::mean( ) const{
	assert(len>0);
	return sum()/len;
}

double statistician::minimum( ) const{
	assert(len>0);
	return minN(head, len);
}

double statistician::maximum( ) const{
	assert(len>0);
	return maxN(head, len);
}

double statistician::getN(int n) const{
	Node *k = head;
	for(int i = 1; i < n; i++){
		k = k->next;
	}
	return k->data;
}


Node* statistician::getH(){
	return head;
}

statistician operator+(const statistician& s1, const statistician& s2){
	statistician s3;
	for(int i = 1; i <= s1.len; i++){
		s3.next(s1.getN(i));
	}
	for(int i = 1; i <= s2.len; i++){
		s3.next(s2.getN(i));
	}
	s3.len = s1.len + s2.len;
	return s3;
}

statistician operator *(double scale, const statistician& s){
	scaleN(scale, s.head);
	return s;
}

bool operator ==(const statistician& s1, const statistician& s2){
	if(s1.len==s2.len && s1.len == 0){
		return true;
	}
	return(s1.length()==s2.length() && s1.mean()==s2.mean() && 
		   s1.minimum()==s2.minimum() && s1.maximum()==s2.maximum() && s1.sum()==s2.sum());

}

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
	statistician s3 = s1 + s2;
	
	cout << s3.maximum() << endl;

	printN(s1.getH());
	statistician s4;
	s4.next(2);
	s4.next(3);
	s4.next(2.5);

	printN(s4.getH());

	cout << (s1==s4);

	

	return 0;

}