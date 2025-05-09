// Q5. You're building a tool to search and replace a specific word in a text file without

// rewriting the entire file.

// Requirements:



// 1. Create and populate a file named data.txt with a few sentences. (e.g., AI is the

// future. AI will transform the world. Embrace AI now.)

// 2. Prompt the user to enter:

// ○ A searchWord (e.g., "AI")

// ○ A replacementWord (e.g., "ML")

// 3. Open the file using fstream in ios::in | ios::out mode.

// 4. Search for the searchWord using seekg() and read sequentially.

// 5. When found:

// ○ Use tellg() to get the current read pointer location.

// ○ Use seekp() to position the write pointer.

// ○ Replace the word only if the replacement is of equal or smaller length to

// avoid shifting content.



// 6. If the word is replaced, pad with spaces if needed (e.g., replacing "AI" with "ML" or

// "XX").

// 7. After all replacements, display the updated file.



#include <iostream>

#include <fstream>

#include <string>

using namespace std;



int main(){



    ofstream file("data.txt", ios::out);

    if(!file){

        cout << "Failed to create file" << endl;

        return 1;

    }

    file << "AI is the future.AI will transform the world.Embrace AI now." <<endl;

    file.close();



    string searchWord;

    string replacementWord;

    cout << "Enter the word to search: " ;

    cin >> searchWord;

    cout << "Enter the replacement word (same length): ";

    cin >> replacementWord;



    if (searchWord.length() != replacementWord.length()) {

        cout << "Error: Words must be the same length for in-place replacement." << endl;

        return 1;

    }



    fstream fileOpen("data.txt",ios::out | ios::in);

    if(!fileOpen){

        cout << "Failed to create file" << endl;

        return 1;

    }



    char ch;

    string buffer;

    streampos matchPos;



    while(fileOpen.get(ch)){

        buffer += ch;



        if(buffer.length() > searchWord.length())

        buffer.erase(0,1);



        if (buffer == searchWord) {

            matchPos = fileOpen.tellg();

            fileOpen.seekp(matchPos - static_cast<streamoff>(searchWord.length()));

            string paddedReplacement = replacementWord;

            paddedReplacement.append(searchWord.length() - replacementWord.length(), ' ');



            fileOpen.write(paddedReplacement.c_str(), searchWord.length());

            fileOpen.flush();



            // Step 7: Clear buffer to avoid overlapping matches

            buffer.clear();

            fileOpen.seekg(matchPos);

        }

    }

    fileOpen.close();

    ifstream updatedFile("data.txt");

    string updatedLine;

    getline(updatedFile, updatedLine);

    cout << "\nUpdated file content:\n" << updatedLine << endl;

    updatedFile.close();



    



    return 0;

}
