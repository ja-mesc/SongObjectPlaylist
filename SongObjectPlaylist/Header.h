#include <iostream>


class Song {
private:
	std::string title;
	std::string artist;
	std::string genre;

public:
	Song(std::string new_title, std::string new_artist, std::string new_genre); //constructor
	//getter methods to access private string members
	std::string get_title();
	std::string get_artist();
	std::string get_genre();
	std::string print_song1();
	std::string print_song2();

};

struct Node {
	Song song;
	Node* next;

	Node(Song new_song); //constructor. Can this somehow contain the whole song object?
};

class LinkedList {
private:
	Node* head;

public:
	LinkedList();

	void insert_at_head(Song song);
	void insert_at_tail(Song song);
	void delete_head();
	void delete_node(Song song);
	void print_list();

	//destructor
	~LinkedList();

};
