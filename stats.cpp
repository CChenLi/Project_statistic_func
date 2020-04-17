// stats.cpp - implements statistician class as defined in stats.h
// Chen Li, 1/20/2019

#include <cassert>  // provides assert
#include "stats.h"  // defines what must be implemented

statistician::statistician(){
	head = new Node;
	head->data = 0; 
	head->next = NULL;
	tail = head;
	len = 0;
}

statistician::~statistician(){
	this->reset();
	delete head;
	tail = 0;
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

