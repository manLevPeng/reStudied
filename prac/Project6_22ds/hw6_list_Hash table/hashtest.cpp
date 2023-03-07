#include<iostream>
#include<list>
#include<cstring>
using namespace std;
#define HTSIZE 137	//prime # used
struct Node {
	Node(char* n, float v) : val(v) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}  
	char* name;  
	float val;
};

list<Node> HT[HTSIZE];	// Hash Table

int hashfcn(char* name) {
	return name[0] * name[strlen(name) - 1] % HTSIZE;
}  

bool GetFromHT(char* name, float& val) {
	int hashval = hashfcn(name);
	list<Node>::iterator iter;
	for (iter = HT[hashval].begin(); iter != HT[hashval].end(); iter++ )
		if (!strcmp(iter->name, name)) // Found the value
			{ val = iter->val; return true;	}
	return false;
}  

void StoreIntoHT(char* name, float val) {// HashTable에 name을 키로, val을 값으로 하는 노드를 저장하라 
	int hashval = hashfcn(name);
	list<Node>::iterator iter;
	for (iter = HT[hashval].begin(); iter != HT[hashval].end(); iter++)
		if (!strcmp(iter->name, name))
			{ iter->val = val; return;	}	// 새 값으로 바꾸고 return
	//새로운 자료를 삽입하자 (충돌 방지법 : 리스트 앞에 넣자)
	HT[hashval].push_front(Node(name, val));
}  

void PrintValue(char* name) {
	float val; 
	if (!GetFromHT(name, val))
		cout << name << "doesnotexist" << endl;  
	else  cout << name << "" << val << endl; 
} 

int main() {
	StoreIntoHT("abro", 23); // StoreIntoHT((char*)"abro", 23); 로 하면 경고없음 
	StoreIntoHT("bb", 34.5);  
	StoreIntoHT("haha", 9);  
	StoreIntoHT("bb", 1234.5);

	PrintValue("bb"); 
	PrintValue("haha");  
	PrintValue("hoho"); 
}
/*
bb 1234.5  
haha 99  
hoho does not exist

[참고]위에서 사용된 list함수
push_front앞에넣기
begin() 맨 앞 노드의 iterator 를 return 
end()맨 뒤 노드를 지난 뒤의 iterator 를return
*/