#include <iostream>
#include <fstream>

int    ft_replace(std::string &content, std::string s1, std::string s2, std::string filename)
{
    std::ofstream    outfile(filename);
    if (!outfile.is_open())
    {
        std::cout << "Can't open the outfile." <<std::endl;
        return (1);
    }
    int pos;
    int i = 0;
    int lenght = content.size();
    while (i < lenght)
    {
        pos = content.find(s1, i);
        if (pos == i)
        {
            outfile << s2;
            i += s1.size() - 1;
        }
        else
            outfile << content[i];
        i++;
    }
    outfile.close();
    return (0);
}

int main ( int ac, char **av )
{
    if (ac != 4)
    {
        std::cout << "./<program> <filename> s1 s2" <<std::endl;
        return (1);
    }
    std::string filename = (std::string) av[1];
    std::ifstream   infile(filename);
    if (!infile.is_open())
    {
        std::cout << "Can't open the file." <<std::endl;
        return (1);
    }
    filename = filename + ".replace";
    std::string content;
    char c;
    while (infile.get(c))
        content += c;
    infile.close();
    ft_replace(content, (std::string) av[2], (std::string) av[3], filename);
    return (0);
}