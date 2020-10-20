// Joan Andrés (@Andres6936) Github.

#include "File.hpp"

using namespace Gt;

bool File::equals(const File& _other) const noexcept
{
	return this->name == _other.name and this->path == _other.path;
}
