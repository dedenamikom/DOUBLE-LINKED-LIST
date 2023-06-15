#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Node{
	
	int data;
	Node *next, *prev;
};

Node *head, *tail, *print, *del, *newNode;

bool isEmpty();
void insertNode(int data);
void insertFromMiddle(int data);
void insertFromEnd(int data);
void deleteFromFront();
void deleteFromMiddle();
void deleteFromEnd();
void deleteAll();
void printNode();

int main(){
	
	int Menu;
	int data;
	char ulang;
	
	do
    {
        system("cls");
        cout<<endl;
        cout<<" ==================================="<<endl;
        cout<<" =   PROGRAM DOUBLE LINKED LIST    ="<<endl;
        cout<<" ==================================="<<endl;
        cout<<" = 1. Insert Node Depan            ="<<endl;
        cout<<" = 2. Insert Node Tengah           ="<<endl;
        cout<<" = 3. Insert Node Belakang         ="<<endl;
        cout<<" = 4. Delete Node Depan            ="<<endl;
        cout<<" = 5. Delete Node Tengah           ="<<endl;
        cout<<" = 6. Delete Node Belakang         ="<<endl;
        cout<<" = 7. Tampil Data                  ="<<endl;
        cout<<" = 8. Clear                        ="<<endl;
        cout<<" = 9. Exit                         ="<<endl;
        cout<<" ==================================="<<endl;
        cout<<" Masukan Pilihan : ";cin>>Menu;
        switch (Menu)
        {
            case 1: system("cls");{
            	cout<<" ==================================="<<endl;
        		cout<<" =   PROGRAM DOUBLE LINKED LIST    ="<<endl;
        		cout<<" ==================================="<<endl;
        		cout<<" = 1. Insert Node Depan            ="<<endl;	
        		cout<<" ==================================="<<endl;
                cout<<"Masukan Data = ";cin>>data;
                insertNode(data);
                break;
            }
            case 2: system("cls");{
            	cout<<" ==================================="<<endl;
        		cout<<" =   PROGRAM DOUBLE LINKED LIST    ="<<endl;
        		cout<<" ==================================="<<endl;
				cout<<" = 2. Insert Node Tengah           ="<<endl;
				cout<<" ==================================="<<endl;
                cout<<"Masukan Data = ";cin>>data;
                insertFromMiddle(data);
                break;
            }
            case 3: system("cls");{
            	cout<<" ==================================="<<endl;
        		cout<<" =   PROGRAM DOUBLE LINKED LIST    ="<<endl;
        		cout<<" ==================================="<<endl;
        		cout<<" = 3. Insert Node Belakang         ="<<endl;
        		cout<<" ==================================="<<endl;
                cout<<"Masukan Data = ";cin>>data;
                insertFromEnd(data);
                break;
            }
            case 4: system("cls");{
            	cout<<" ==================================="<<endl;
        		cout<<" =   PROGRAM DOUBLE LINKED LIST    ="<<endl;
        		cout<<" ==================================="<<endl;
        		cout<<" = 4. Delete Depan          		  ="<<endl;
        		cout<<" ==================================="<<endl;
                deleteFromFront();
                break;
            }
            case 5: system("cls");{
            	cout<<" ==================================="<<endl;
        		cout<<" =   PROGRAM DOUBLE LINKED LIST    ="<<endl;
        		cout<<" ==================================="<<endl;
        		cout<<" = 5. Delete Node Tengah       	  ="<<endl;
        		cout<<" ==================================="<<endl;
                deleteFromMiddle();
                break;
        	}
        	case 6: system("cls");{
            	cout<<" ==================================="<<endl;
        		cout<<" =   PROGRAM DOUBLE LINKED LIST    ="<<endl;
        		cout<<" ==================================="<<endl;
        		cout<<" = 6. Delete Node Belakang  		  ="<<endl;
        		cout<<" ==================================="<<endl;
                deleteFromEnd();
                break;
        	}
            case 7: system("cls");{
            	cout<<" ==================================="<<endl;
        		cout<<" =   PROGRAM DOUBLE LINKED LIST    ="<<endl;
        		cout<<" ==================================="<<endl;
        		cout<<" = 7. Tampil data                  ="<<endl;
        		cout<<" ==================================="<<endl<<endl;
                printNode();
                break;
            }
            case 8: system("cls");{
                deleteAll();
                break;
            }
            case 9: system("cls");{
                return 0;
                break;
            }default : system("cls");
            {
                cout<<"\n Maaf, Menu yang anda pilih tidak tersedia!";
            }
        }
        getch();
    }
    while (Menu!=9);
	cout << endl;
}

bool isEmpty(){
	return ( head == NULL );
	return ( tail == NULL );
}

void insertNode(int data){
	
	newNode = new Node;
	
	newNode -> data = data;
	
	newNode -> next = NULL;
	
	newNode -> prev = NULL;
	
	if ( isEmpty() == 1 ){
		
		head = newNode;
		head -> next = NULL;
		head -> prev = NULL;
		
		tail = head;
	} else{
		
		tail -> next = newNode;
		newNode -> prev = tail;
		tail = newNode;
	}
}

void insertFromMiddle(int data){

	if (head == NULL){

		cout << "Node awal tidak boleh kosong" << endl << endl;
		return;
	}

	newNode = new Node;

	newNode -> data = data;

	newNode -> next = head -> next;

	head -> next = newNode;

	newNode -> prev = head;

	if (newNode -> next != NULL){

		newNode -> next -> prev = newNode;
	}
}

void insertFromEnd(int data){

	newNode = new Node;

	newNode -> data = data;

	newNode -> next = NULL;

	Node* temp = head;

	if (head == NULL){

		newNode -> prev = NULL;
		head = newNode;
		return;
	}

	while (temp -> next != NULL)
	{
		temp = temp -> next;

	}

	temp -> next = newNode;

	newNode -> prev = temp;
	
}

void deleteFromFront(){
	
	int simpan;
	
	if ( head != NULL ){
		
		if ( head -> next != NULL){
			
			del = head;
			
			simpan = head -> data;
			
			cout << "\n" << simpan << " telah dihapus" << endl;
			
			head = head -> next;
			head -> prev = NULL;
			delete del;
		} else {
			
			simpan = head -> data;
			cout << "\n" << simpan << " telah dihapus" << endl;
			head = NULL;
		}
		
	} else {
		
		cout << "\nLinked List kosong, penghapusan tidak dapat dilakukan" << endl; 
	}
}

void deleteFromMiddle() {
    if (head == NULL) {
        cout << "List masih kosong" << endl;
        return;
    }

    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    int middlePosition = count / 2 + 1;

    current = head;
    Node* prevNode = NULL;
    int currentPosition = 1;

    while (current != NULL && currentPosition < middlePosition) {
        prevNode = current;
        current = current->next;
        currentPosition++;
    }

    if (current == NULL || current == head || current->next == NULL) {
        cout << "Tidak ada node di tengah linked list" << endl;
        return;
    }

    prevNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = prevNode;
    }

    int deletedData = current->data;
    delete current;
    cout << "Data " << deletedData << " telah dihapus" << endl;
}

void deleteFromEnd(){

	if ( head == NULL ){

		cout << "List masih kosong" << endl;
		return;
	} else if ( head == tail ){

		delete head;
		head = NULL;
		tail = NULL;
	} else {

		Node *current = head;
		while ( current -> next != tail ){
			current = current -> next;
		}

		delete tail;
		current -> next = NULL;
		tail = current;
	}
}

void deleteAll(){

	Node *current = head;
	while ( current != NULL ){

		Node *nextNode = current -> next;
		delete current;
		current = nextNode;
	}

	head = tail = NULL;
}

void printNode(){
	
	print = head;
	
	if ( head != NULL ){
			
		cout << "Isi Linked List: ";	
		while (print != NULL){
			
			cout << print -> data << " -> ";
			print = print -> next; 
			} 
			
			cout << endl;
		} else {
			
			cout << "\nTidak ada data dalam linked list" << endl;
		}
}
