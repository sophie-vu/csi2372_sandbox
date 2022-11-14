#include "Crossword.h"
#include <exception>
#include <iostream>
#include <new>
#include <unordered_map>
#include <cstring>
#include <vector>
using namespace std;

/**
 * @brief Default constructor that inits a crossword with 10 columns and 0 rows.
 * 
 */
Crossword::Crossword() {
    this->n = 10;
    this->m = 0;
    this->puzzle = new char*[n];
    this->userView = new char*[n];
    for (int i = 0; i < n; i++) {
        puzzle[i] = new char[m];
        for (int j = 0; j < m; j++) {
            puzzle[i][j] = ' '; // Init blank
            userView[i][j] = ' '; 
        }
    }
    this->questions = new Node[n];
}

/**
 * @brief User constructor that inits a corssword with n columns and m rows.
 * 
 * @param n 
 * @param m 
 */
Crossword::Crossword(int n, int m) {
    this->n = n;
    this->m = m;
    this->puzzle = new char*[n];
    this->userView = new char*[n];
    for (int i = 0; i < n; i++) {
        puzzle[i] = new char[m];
        for (int j = 0; j < m; j++) {
            puzzle[i][j] = ' '; // Init blank
            userView[i][j] = ' '; 
        }
    }
    this->questions = new Node[n];
} 

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Crossword::add_questions(string question, string answer, int mIndex, int nIndex, bool isHori) {
    if (
        !validInput(mIndex, nIndex, question, answer, isHori) ||
        !match(answer, mIndex, nIndex, isHori)
        ) {
        
        return false;
    }
    // Init entree node
    int arrSize = (int) sizeof(questions)/sizeof(*questions);
    Node entree { question, answer, mIndex, nIndex, isHori };
    questions = addToArray(questions, entree, arrSize);// Add entree
    // questions.shrink_to_fit(); // Resize
    puzzle[mIndex][nIndex] = *answer.c_str();
    return true;
}

/**
 * @brief Attemps to add the letters of the answer one-by-one and fails if there is a mismatched crossover.
 * 
 * @param answer 
 * @param mIndex 
 * @param nIndex 
 * @param isHori 
 * @return true 
 * @return false 
 */
bool Crossword::match(string answer, int mIndex, int nIndex, bool isHori) {
    if (isHori) {
        for (int j = 0; j < answer.length(); j++) {
            for (int i = nIndex; i < n; i++) {
                if (puzzle[mIndex][i] != ' ') { // Word has neighbords
                    if (puzzle[mIndex][i] != answer[i]) { // Mismatch
                        return false;
                    } else {
                        puzzle[mIndex][i] = answer[i];
                    }
                }
            }
        }
    } else {
        for (int j = 0; j < answer.length(); j++) {
            for (int i = mIndex; i < m; i++) {
                if (puzzle[i][nIndex] != ' ') { // Word has neighbords
                    if (puzzle[i][mIndex] != answer[i]) { // Mismatch
                        return false;
                    } else {
                        puzzle[i][nIndex] = answer[i];
                    }
                }
            }
        }
    }
    return true;
}

/**
 * @brief Checks if the input for an entree is valid.
 * 
 * @param mIndex 
 * @param nIndex 
 * @param question 
 * @param answer 
 * @param isHori 
 * @return true 
 * @return false 
 */
bool Crossword::validInput(int mIndex, int nIndex, string question, string answer, bool isHori) {
    if (!(mIndex < m) || !(nIndex < n)) {
        cout << "Invalid indexes: (" << m << ", " << n << ")" << endl;
        return false;
    }
    if (
        (isHori && answer.length() > n) || 
        (!isHori && answer.length() > m)
        ) {
        cout << "The answer is too long: " << answer << " has " << answer.length() << " characters. " << endl;
        return false;
    }
    return true;
}

/**
 * @brief Adds an answer to the user grid if it is correct.
 * 
 * @param mIndex 
 * @param nIndex 
 * @param answer 
 */
void Crossword::solve(int mIndex, int nIndex, string answer) {
    int arrSize = (int) sizeof(questions)/sizeof(*questions);
    for (int i = 0; i < arrSize; i++) {
        Node n = questions[i];
        if ((n.mIndex == mIndex) && (n.mIndex == mIndex) && (n.answer == answer)) {
            cout << "correct!" << endl;
            for (int i = 0; i < n.answer.length(); i++) {
                for (int j = nIndex; j < this->n; j++) {
                    for (int k = mIndex; k < this->m; k++) {
                        userView[k][m] = answer[i];
                    }
                }
            }
        } else {
            return;
        }
    }
}

void Crossword::print() {
    int arrSize = (int) sizeof(questions)/sizeof(*questions);
    cout << arrSize << endl;
    for (int i = 0; i < arrSize; i++) {
        Node q = questions[i];
        cout << "(" << q.mIndex << ", " << q.nIndex << ") – " << q.question;
        if (q.isHori) {
            cout << " (Horizontal)";
        } else {
            cout << " (Vertical)";
        }
    }
}

Node* Crossword::addToArray(Node* list, const Node& entree, int& size) {
    Node* new_list = new Node[size + 1];
    for (int i = 0; i < size; i++) {
        new_list[i] = list[i];
    }
    new_list[size] = entree;
    delete[] list;
    ++size;
    return new_list;
}