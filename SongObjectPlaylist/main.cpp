#include <iostream>
#include "Header.h"

int main() {

	Song song1 = Song("gravy train", "bob", "death punk");
	Song song2 = Song("bucket", "spoons", "oiled reggae");
	Song song3 = Song("tumultous tamarind", "Sam Wigger", "ambient destruction");
	LinkedList playlist;

	playlist.insert_at_head(song1);
	playlist.insert_at_tail(song2);
	playlist.insert_at_head(song3);
	playlist.print_list();

	playlist.delete_node(song1);
	std::cout << "after deleting " << song1.get_title() << ", the playlist is:\n";
	playlist.print_list();

}