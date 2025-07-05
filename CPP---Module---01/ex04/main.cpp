/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-28 15:25:08 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-09-28 15:25:08 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

static void checkArgs(int& argc)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./losers [filename] [s1] [s2]" << std::endl;
		std::cout << "Test: [filename] = test.txt, [s1] = sun, [s2] = moon" << std::endl;
		exit(1);
	}
}

static void checkStrings(std::string& s1, std::string& s2)
{
	if (s1.empty() || s2.empty())
	{
		std::cout << "Error: Empty string." << std::endl;
		exit(2);
	}
}

/**
 * Function: fileToString
 * -----------------------
 * Reads the contents of a specified file and returns it as a single string. The function
 * opens the file, checks for successful opening, reads each line, and accumulates the
 * lines into a single string, which includes newline characters to preserve the original
 * formatting of the file.
 *
 * Parameters:
 *  - filename: A pointer to a character array representing the name of the file to be read.
 *
 * Process:
 *  - Attempts to open the specified file using an ifstream object.
 *  - If the file cannot be opened, an error message is displayed, and the program exits
 *    with a status code of 3.
 *  - Initializes an empty string to hold the file's contents and a string to read each line.
 *  - Uses a while loop to read each line from the file, appending it to the content string
 *    along with a newline character.
 *  - Closes the file after reading all contents and returns the accumulated string.
 *
 * Usage:
 *  - This function is useful for loading the entire content of a file into a string for
 *    further processing, such as parsing or analyzing the data.
 *  - Example usage: std::string fileContent = fileToString("example.txt"); // Reads content from example.txt.
 */
static std::string fileToString(const char* filename)
{
	std::ifstream inFile(filename);

	if(!inFile)
	{
		std::cerr << "Error: Could not open file." << std::endl;
		exit(3);
	}

	std::string content;
	std::string line;

	while(std::getline(inFile, line))
		content += line + "\n";

	inFile.close();
	return (content);
}

/**
 * Function: replaceSubstring
 * ---------------------------
 * Replaces all occurrences of a specified substring (s1) within a given content string 
 * with another substring (s2) and returns the modified string. The function iteratively 
 * searches for occurrences of s1 and constructs the output string by appending portions 
 * of the content and the replacement substring.
 *
 * Parameters:
 *  - content: The original string in which the substring replacements will be made.
 *  - s1: The substring to be replaced within the content string.
 *  - s2: The substring that will replace each occurrence of s1.
 *
 * Process:
 *  - Initializes an empty string for the output and sets the starting position for the 
 *    search in the content string.
 *  - Uses a while loop to find occurrences of s1 in the content string.
 *    - find()
 *    -----
 *    The find() function in the C++ Standard Library's std::string class is used 
 *    to search for a specific substring or character within a string. It returns 
 *    the position of the first occurrence of the substring or character. 
 *    If the substring or character is not found, it returns std::string::npos.
 *
 *    - std::string::npos 
 *    -----------------
 *    is a constant value defined in the C++ Standard 
 *    Library, specifically for the std::string class. 
 *    It represents the largest possible value for the type std::string::size_type, 
 *    and it is used to indicate that no valid position or result was found 
 *    during string operations.
 *
 *  - For each found occurrence:
 *    - Appends the portion of the content string from the last found position to the 
 *      current found position to the output string.
 *    - Appends the replacement substring (s2) to the output string.
 *    - Updates the current position to search for the next occurrence.
 *
 *  - After all occurrences have been replaced, appends any remaining part of the content 
 *    string to the output.
 *
 * Usage:
 *  - This function is useful for performing bulk replacements of substrings within a 
 *    larger text, such as editing documents or processing user input.
 *  - Example usage: std::string result = replaceSubstring("Hello world", "world", "C++"); 
 *    // result will be "Hello C++".
 */

static std::string replace(std::string content, std::string s1, std::string s2)
{
	std::string output;
	std::size_t pos = 0;
	std::size_t found;

	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		output += content.substr(pos, found - pos);
		output += s2;
		pos = found + s1.length();
	}

	output += content.substr(pos);

	return (output);
}

/**
 * Function: main
 * ---------------
 * The entry point of the program that performs string replacement in a file. 
 * This function reads a file specified by the user, replaces all occurrences 
 * of a specified substring (s1) with another substring (s2), and writes the 
 * modified content to a new file. The name of the new file is derived from 
 * the original file name by appending ".replace" to it.
 *
 * Parameters:
 *  - argc: The argument count indicating the number of command-line arguments passed.
 *  - argv: An array of C-style strings containing the command-line arguments.
 *    - argv[1]: The name of the input file to read.
 *    - argv[2]: The substring to be replaced (s1).
 *    - argv[3]: The substring that will replace s1 (s2).
 *
 * Process:
 *  - Calls the checkArgs function to validate the command-line arguments.
 *  - Assigns the values of s1 and s2 from the command-line arguments.
 *  - Calls checkStrings to validate the contents of s1 and s2.
 *  - Calls fileToString to read the entire content of the specified input file 
 *    into the content string.
 *  - Calls replace to perform the substring replacement in the content string, 
 *    storing the result in the output string.
 *  - Attempts to create an output file with the name of the input file plus 
 *    the ".replace" suffix.
 *    - If the output file cannot be created, an error message is displayed 
 *      and the program returns an error code.
 *  - Writes the modified content (output) to the new output file and closes it.
 *
 * Usage:
 *  - This function serves as the main driver for the program, enabling users 
 *    to specify the file and the substrings to replace through command-line 
 *    arguments. It ensures that file operations and string replacements are 
 *    handled properly.
 *  - Example usage: ./replace file.txt oldString newString 
 *    // Replaces all occurrences of oldString with newString in file.txt 
 *    and saves the result in file.txt.replace.
 */

int main(int argc, char **argv)
{
	std::string s1;
	std::string s2;
	std::string content;
	std::string output;

	checkArgs(argc);

	s1 = argv[2];
	s2 = argv[3];
	checkStrings(s1, s2);

	content = fileToString(argv[1]);

	output = replace(content, s1, s2);

	std::ofstream outFile((std::string(argv[1]) + ".replace").c_str());
	if (!outFile)
	{
		std::cerr << "Error: Could not create output file." << std::endl;
		return(4);
	}

	outFile << output;
	outFile.close();
}