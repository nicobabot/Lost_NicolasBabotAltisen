#ifndef _DMYLIST_H_
#define _DMYLIST_H_
typedef unsigned int uint;
template<class TYPE>
class Dlist{
public:
	class DNode{
	public:
		TYPE data;
		DNode *next = nullptr;
		DNode *previous = nullptr;
	public:
		DNode(const TYPE &data) : data(data){
		}

	};
	DNode *first;
public:
	Dlist(){
	}
	bool empty()const{
		return first == nullptr;
	}
	unsigned int Size()const{
		unsigned int i = 0;
		DNode  *temp = first;
		while (temp != nullptr){
			temp = temp->next;
			i++;
		}
		return i;
	}
	DNode* end()const{
		DNode  *temp = first;
		while (temp != nullptr){
			if (temp->next == nullptr){
				return temp;
			}
			temp = temp->next;
		}
	}

	void pushback(const TYPE &data){
		DNode* temp = first;
		DNode* nnode = new DNode(data);
		if (temp == nullptr){
			first = nnode;
		}
		else{
			while (temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = nnode;
			nnode->previous = temp;
		}
	}

	void pushfront(const TYPE &data){
		DNode* temp = first;
		DNode* nnode = new DNode(data);
		if (temp == nullptr){
			first = nnode;
		}
		else{
			nnode->next = temp;
			temp->previous = nnode;
			first = nnode;
		}
	}

	void pop_back(){
		if (first != nullptr){
			if (first->next != nullptr){
				DNode* temp = first;
				DNode* temp2 = first;
				while (temp->next != nullptr){
					temp = temp->next;
				}
				while (temp2->next != temp){
					temp2 = temp2->next;
				}
				temp2->next = nullptr;
				delete temp;
			}
			else{
				DNode* temp = first;
				first = nullptr;
				delete temp;

			}
		}
	}

	bool pop_front(){
		DNode* temp = first;
		if (first != nullptr){
			if (first != nullptr && first->next != nullptr){
				first = first->next;
				first->previous = nullptr;
				delete temp;

			}
			else{
				DNode* temp = first;
				first = nullptr;
				delete temp;
			}
			return true;
		}
		return false;
	}

	void erase(DNode* othernode){
		if (Size() > 1 && othernode != first){
			if (othernode->previous == nullptr){
				first = othernode->next;
				first->previous = nullptr;
			}
			else if (othernode->next == nullptr){
				othernode->previous->next = nullptr;
			}
			else{
				othernode->previous->next = othernode->next;
				othernode->next->previous = othernode->previous;
			}
			delete othernode;
		}
		else{
			first = nullptr;
			delete othernode;
		}
	}

	void insert(DNode* newnodo, TYPE Data){
		DNode* nnode = new DNode(Data);
		if (first != nullptr){
			if (newnodo->previous == nullptr){
				nnode->next = newnodo;
				newnodo->previous = nnode;
				first = nnode;
			}
			else{
				nnode->previous = newnodo->previous;
				newnodo->previous->next = nnode;
				newnodo->previous = nnode;
				nnode->next = newnodo;
			}
		}
		else{
			first = nnode;
		}
	}
	//SWAP

};
#endif