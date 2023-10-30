#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string.h>
# include <stdint.h>

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"
# define GREEN "\001\033[1;92m\002"

struct Data
{
    unsigned int    id;
    std::string     name;
};

class Serializer
{
    public:
        Serializer( void );
		~Serializer( void );
		Serializer( const Serializer &copy );
		Serializer	&operator=(const Serializer &copy);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif