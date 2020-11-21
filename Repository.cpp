// Joan Andrés (@Andres6936) Github.

#include <iostream>
#include <stdexcept>

#include "Status.hpp"
#include "Repository.hpp"

using namespace Gt;

// Construct

Repository::Repository(std::string_view path)
{
	// The method will automatically detect if 'path' is a normal or bare
	// repository or fail is 'path' is neither.
	// C++17 Initialize variable in if-block
	if (const int status = git_repository_open(&repository, path.data()); status not_eq 0)
	{
		std::cerr << "Not is possible open the directory.\n";
	}
}

// Destructor

Gt::Repository::~Repository()
{
	git_repository_free(repository);
}

// Methods

std::vector<std::string> Repository::getUntrackedFiles()
{
	Status status {repository};
	return status.getUntrackedFiles();
}
