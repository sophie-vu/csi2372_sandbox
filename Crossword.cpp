#include "Crossword.h"
#include <iostream>
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
    questions.resize(1000); // Init size
    questions.shrink_to_fit(); // Resize
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
    questions.resize(1000); // Init size
    questions.shrink_to_fit();} // Resize

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
    Node entree;
    entree.question = question;
    entree.answer = answer;
    entree.mIndex = mIndex;
    entree.nIndex = nIndex;
    entree.isHori = isHori;
    questions.push_back(entree); // Add entree
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
    for (Node n : questions) {
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

ostream& operator<<(ostream& out, Crossword c) {
    // out << "goes there" << endl;
    for (Node q : c.questions) {
        out << "(" << q.mIndex << ", " << q.nIndex << ") – " << q.question;
        if (q.isHori) {
            out << " (Horizontal)";
        } else {
            out << " (Vertical)";
        }
    }
    return out;
}

void Crossword::print() {
    for (Node q : this->questions) {
        cout << "(" << q.mIndex << ", " << q.nIndex << ") – " << q.question;
        if (q.isHori) {
            cout << " (Horizontal)";
        } else {
            cout << " (Vertical)";
        }
    }
}