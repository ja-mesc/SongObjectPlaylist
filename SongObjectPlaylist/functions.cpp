#include "Header.h"


Song::Song(std::string new_title, std::string new_artist, std::string new_genre) : title(new_title), artist(new_artist), genre(new_genre) {}; //constructor
//getter members
std::string Song::get_title() {
	return title;
}
std::string Song::get_artist() {
	return artist;
}
std::string Song::get_genre() {
	return genre;
}
std::string Song::print_song1() {
	return title + ", a " + genre + " song by " + artist;
}
std::string Song::print_song2() {
	return title + ", an " + genre + " song by " + artist;
}

Node::Node(Song new_song) : song(new_song), next(nullptr) {}; //constructor for the node

LinkedList::LinkedList() : head(nullptr) {}; //constructor initialises head to nulllptr

void LinkedList::insert_at_head(Song song) {
	Node* new_node = new Node(song); //pointer to new node (dynamic allocation)
	new_node->next = head; //new pointer points to head
	head = new_node; //new node becomes head

}

void LinkedList::insert_at_tail(Song song) {

	Node* new_node = new Node(song);

	if (head == nullptr) { //if list is empty, inserting at tail=assign to head
		head = new_node;
		return;
	}

	Node* current = head; //tracking from head to tail
	while (current->next != nullptr) { //condition for end of list
		current = current->next;
	}

	current->next = new_node; //add new_node to end of list
}

void LinkedList::delete_head() {
	if (head != nullptr) {
		Node* temp = head; //create a pointer to current head
		head = head->next;
		delete temp; //free up memory of old head
	}
}

void LinkedList::delete_node(Song new_song) {
	if (head == nullptr) {
		std::cout << "list is empty\n";
		return;
	}

	if (head->song.get_title() == new_song.get_title()) { //if the song is at the head of list
		delete_head();
		return;
	}

	Node* current = head; //track current and next nodes
	while (current->next != nullptr) {
		if (current->next->song.get_title() == new_song.get_title()) {
			Node* temp = current->next; //store the node to delete
			current->next = current->next->next; //connect current to skip over the node to be deleted
			delete temp;
			return;
		}
		current = current->next;
	}
	//if it gets to the end of the list, then the song doesnt exist without returning
	std::cout << "song not found";
}
	void LinkedList::print_list() {

		Node* current = head;
		std::string genre_string = current->song.get_genre();
		while (current != nullptr) { //grammar correct 'a' and 'an' 
			if (genre_string[0] == 'a' || genre_string[0] == 'e' || genre_string[0] == 'i' || genre_string[0] == 'o' || genre_string[0] == 'u') {
				std::cout << current->song.print_song2() << " -> ";
			}
			else {std::cout << current->song.print_song1() << " -> "; }
			current = current->next;
		}
		std::cout << "null" << std::endl;
	}

	LinkedList::~LinkedList() {
		while (head != nullptr) {
			delete_head();
		}
	}


