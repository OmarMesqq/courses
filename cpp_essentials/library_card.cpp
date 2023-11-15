#include <format>
#include <iostream>

using sint = short int;

struct LibraryCard { 
	const char* title{};
	const char* author{};
	const char* publisher{};
	const char* subject{};
	const char* isbn{};
	const char* oclc{};
	sint ddc1{};
    sint ddc2{};	
	sint yearPublished{}; 
	sint yearAcquired{};
	sint quantity{};
};

int main() {
	LibraryCard lordOfTheFlies {
		"Lord of the Flies", 
		"William Golding",
		"Penguin Books",
		"Fiction", 
		"978-0399501487", 
		"47677622", 
		823,
		00,
    	1954,
		2023,
		1,	
	};
	
	std::cout << std::format("Title: {}\n", lordOfTheFlies.title);
	std::cout << std::format("Author: {}\n", lordOfTheFlies.author);
	std::cout << std::format("Publisher: {}\n", lordOfTheFlies.publisher);
	std::cout << std::format("Subject: {}\n", lordOfTheFlies.subject);
	std::cout << std::format("ISBN: {}\n", lordOfTheFlies.isbn);
	std::cout << std::format("OCLC: {}\n", lordOfTheFlies.oclc);
	std::cout << std::format("Dewey decimal: {}.{}\n", lordOfTheFlies.ddc1, lordOfTheFlies.ddc2);
	std::cout << std::format("Year published: {}\n", lordOfTheFlies.yearPublished);
	std::cout << std::format("Year acquired: {}\n", lordOfTheFlies.yearAcquired);
	std::cout << std::format("Quantity: {}\n", lordOfTheFlies.quantity);
	
	return 0; 
}
