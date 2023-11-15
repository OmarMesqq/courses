#include <format>
#include <iostream>

struct LibraryCard { 
	const char* title;
	const char* author;
	const char* publisher;
	const char* subject;
	const char* isbn;
	const char* oclc;
	double dewey; 
	int yearPublished; 
	int yearAcquired;
	int quantity;
};

int main() {
	LibraryCard lordOfTheFlies {
	"Lord of the Flies", 
	"William Golding",
	"Penguin",
	"Fiction", 
	"2989018429-247189047209", 
	"12555530", 
	124024.53,
        1999,
	2000,
	2,	
	};
	std::cout << std::format("Title: {}", lordOfTheFlies.title);

	return 0; 
}
