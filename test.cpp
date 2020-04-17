#include <iostream>
using namespace std;

struct Node{
	double data;
	Node* next;
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


/*
double minN(Node* head){
	if(head->next == NULL || head->next->next == NULL){
		return head->data;
	} else {
		if(head->data < minN(head->next)){
			return head->data;
		} else return minN(head->next);
	}
}
*/

class statistician{
	public:
		statistician(){
			head = new Node;
			head->data = 0; 
			head->next = NULL;
			tail = head;
			len = 0;
		}

		void next(double r){
			tail->data = r;
			Node* n = new Node;
			n->data = 0;
			n->next = NULL;
			tail->next = n;
			tail = n;
			len++;
		}

		void reset( ){
			ResetN(head->next);
			head->data = 0;
			head->next = NULL;
			tail = head;
			len = 0;
		}

		int length( ) const{
			return len;
		}

		double sum() const{
			return sumN(head);
		}

		double mean( ) const{
			return sum()/len;
		}

		double minimum( ) const{
			return minN(head, len);
		}

		double maximum( ) const{
			return maxN(head, len);
		}

		double getN(int n) const{
			Node *k = head;
			for(int i = 1; i < n; i++){
				k = k->next;
			}
			return k->data;
		}

		Node* getH() const{
			return head;
		}

		Node* getT() const{
			return tail;
		}

	friend statistician operator+(const statistician& s1, const statistician& s2);
	friend statistician operator *(double scale, const statistician& s);
	friend bool operator ==(const statistician& s1, const statistician& s2);

	private:
		Node* head;
		Node* tail;
		int len;
};

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
	statistician s2;
	for(int i = 1; i <= s.len; i++){
		s2.next(s.getN(i));
	}
	s2.len=s.len;
	scaleN(scale, s2.head);
	return s2;
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


	cout<<s1.length() <<endl;
	cout<<s2.length() <<endl;
	cout<<s3.length() <<endl;
	
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